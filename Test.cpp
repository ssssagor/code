#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 1. Token Class

class Token
{
private:
    string key;
    string value;
    Token* nextToken;

public:
    Token(const string& k, const string& v) : key(k), value(v), nextToken(nullptr) {}

    const string& getKey() const { return key; }
    const string& getValue() const { return value; }

    Token* getNext() const { return nextToken; }
    void setNext(Token* nxt) { nextToken = nxt; }
};


// 2. Scope Class

class Scope
{
private:
    Token** buckets;
    int bucketCount;
    Scope* parentScope;
    string scopeId;
    int childCount;

    unsigned long hashFunction(const string& s) const
    {
        unsigned long hash = 0;
        for (char c : s)
            hash = c + (hash << 6) + (hash << 16) - hash;
        return hash;
    }

    int getIndex(const string& key) const
    {
        return hashFunction(key) % bucketCount;
    }

public:
    Scope(int size, Scope* parent = nullptr, const string& ID = "1")
        : bucketCount(size), parentScope(parent), scopeId(ID), childCount(0)
    {
        buckets = new Token*[bucketCount];
        for (int i = 0; i < bucketCount; i++)
            buckets[i] = nullptr;
    }

    ~Scope()
    {
        for (int i = 0; i < bucketCount; i++)
        {
            Token* temp = buckets[i];
            while (temp)
            {
                Token* del = temp;
                temp = temp->getNext();
                delete del;
            }
        }
        delete[] buckets;
    }

    string generateChildId()
    {
        childCount++;
        return scopeId + "." + to_string(childCount);
    }

    // Insert a token
    bool insertToken(const string& key, const string& value)
    {
        int index = getIndex(key);
        Token* temp = buckets[index];

        int pos = 0;
        while (temp)
        {
            if (temp->getKey() == key)
            {
                cout << "<" << key << "," << value << "> already exists in current Scope\n\n";
                return false;
            }
            temp = temp->getNext();
            pos++;
        }

        Token* newTok = new Token(key, value);

        if (!buckets[index])
            buckets[index] = newTok;
        else
        {
            Token* tail = buckets[index];
            while (tail->getNext())
                tail = tail->getNext();
            tail->setNext(newTok);
        }

        cout << "Inserted in Scope# " << scopeId
             << " at position " << index << ", " << pos << "\n\n";
        return true;
    }

    // Search only inside this scope
    bool searchTokenLocal(const string& key, int& bucketOut, int& posOut) const
    {
        int index = getIndex(key);
        Token* temp = buckets[index];
        int pos = 0;

        while (temp)
        {
            if (temp->getKey() == key)
            {
                bucketOut = index;
                posOut = pos;
                return true;
            }
            temp = temp->getNext();
            pos++;
        }
        return false;
    }

    // Delete token from current scope
    bool deleteToken(const string& key, int& bucketOut, int& posOut)
    {
        int index = getIndex(key);
        Token* temp = buckets[index];
        Token* prev = nullptr;
        int pos = 0;

        while (temp)
        {
            if (temp->getKey() == key)
            {
                if (!prev)
                    buckets[index] = temp->getNext();
                else
                    prev->setNext(temp->getNext());

                bucketOut = index;
                posOut = pos;
                delete temp;
                return true;
            }
            prev = temp;
            temp = temp->getNext();
            pos++;
        }
        return false;
    }

    // Print only this scope
    void printScope() const
    {
        cout << "ScopeTable # " << scopeId << "\n";
        for (int i = 0; i < bucketCount; i++)
        {
            cout << i << " --> ";
            Token* temp = buckets[i];

            while (temp)
            {
                cout << "<" << temp->getKey() << " : " << temp->getValue() << ">";
                if (temp->getNext()) cout << " ";
                temp = temp->getNext();
            }
            cout << "\n";
        }
        cout << "\n";
    }

    Scope* getParent() const { return parentScope; }
    const string& getId() const { return scopeId; }
};

// 3. Symbol Manager

class SymbolManager
{
private:
    Scope* activeScope;
    int bucketSize;

public:
    SymbolManager(int size) : bucketSize(size)
    {
        activeScope = new Scope(bucketSize, nullptr, "1");
    }

    ~SymbolManager()
    {
        while (activeScope)
        {
            Scope* parent = activeScope->getParent();
            delete activeScope;
            activeScope = parent;
        }
    }

    void enterNewScope()
    {
        string newId = activeScope->generateChildId();
        activeScope = new Scope(bucketSize, activeScope, newId);
        cout << "New ScopeTable with id " << newId << " created\n\n";
    }

    void exitScope()
    {
        if (!activeScope->getParent())
            return;

        string removedId = activeScope->getId();
        Scope* parent = activeScope->getParent();
        delete activeScope;
        activeScope = parent;

        cout << "ScopeTable with id " << removedId << " removed\n\n";
    }

    void insertSymbol(const string& key, const string& value)
    {
        activeScope->insertToken(key, value);
    }

    void deleteSymbol(const string& key)
    {
        int b, p;
        if (activeScope->deleteToken(key, b, p))
            cout << "Deleted Entry " << b << ", " << p << " from current ScopeTable\n\n";
        else
        {
            cout << "Not found\n\n";
            cout << key << " not found\n\n";
        }
    }

    void searchSymbol(const string& key)
    {
        Scope* temp = activeScope;
        while (temp)
        {
            int b, p;
            if (temp->searchTokenLocal(key, b, p))
            {
                cout << "Found in ScopeTable# " << temp->getId()
                     << " at position " << b << ", " << p << "\n\n";
                return;
            }
            temp = temp->getParent();
        }
        cout << "Not found\n\n";
    }

    void printCurrentScope()
    {
        activeScope->printScope();
    }

    void printAllScopes()
    {
        Scope* temp = activeScope;
        while (temp)
        {
            temp->printScope();
            temp = temp->getParent();
        }
    }
};

// 4. Main Program

int main()
{
    ifstream input("input.txt");
    if (!input.is_open())
    {
        cerr << "Error: Cannot open input.txt\n";
        return 1;
    }

    string line;
    getline(input, line);

    int bucketSize = stoi(line);
    SymbolManager manager(bucketSize);

    while (getline(input, line))
    {
        if (line.empty()) continue;

        cout << line << "\n\n";

        stringstream ss(line);
        char cmd;
        ss >> cmd;

        if (cmd == 'I')
        {
            string k, v;
            ss >> k >> v;
            manager.insertSymbol(k, v);
        }
        else if (cmd == 'L')
        {
            string k;
            ss >> k;
            manager.searchSymbol(k);
        }
        else if (cmd == 'D')
        {
            string k;
            ss >> k;
            manager.deleteSymbol(k);
        }
        else if (cmd == 'P')
        {
            char type;
            ss >> type;
            if (type == 'A') manager.printAllScopes();
            else if (type == 'C') manager.printCurrentScope();
        }
        else if (cmd == 'S')
        {
            manager.enterNewScope();
        }
        else if (cmd == 'E')
        {
            manager.exitScope();
        }
    }

    return 0;
}
