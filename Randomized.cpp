#include <bits/stdc++.h>
using namespace std;


void Interchange(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int Partition(vector<int>& arr, int p, int q) {
    int pivot = arr[p];
    int i = p;
    int j = q;

    while (i < j) {
        do
         {
            i++;
        } while (i < q && arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);



        if (i < j)
        {
            Interchange(arr, i, j);
        }
    }

    Interchange(arr, p, j);
    return j;
}


void RQuickSort(vector<int>& arr, int p, int q)
{
    if (p < q)
    {

        if ((q - p) > 5)
        {

            int randomIndex = p + rand() % (q - p + 1);
            Interchange(arr, randomIndex, p);
        }


        int j = Partition(arr, p, q + 1);


        RQuickSort(arr, p, j - 1);
        RQuickSort(arr, j + 1, q);
    }
}


void QuickSort2(vector<int>& arr, int p, int q)
{
    stack<int> stk;
    stk.push(p);
    stk.push(q);

    while (!stk.empty())
    {
        q = stk.top();
        stk.pop();
        p = stk.top();
        stk.pop();

        if (p < q)
        {
            int j = Partition(arr, p, q + 1);


            if ((j - p) < (q - j))
            {
                stk.push(j + 1);
                stk.push(q);
                stk.push(p);
                stk.push(j - 1);
            }
            else
            {
                stk.push(p);
                stk.push(j - 1);
                stk.push(j + 1);
                stk.push(q);
            }
        }
    }
}


int main()
{
    srand(time(0));

    std::random_device rd;
    std::mt19937 gen(rd());


    int min = 1;
    int max = 100;


    std::uniform_int_distribution<> distr(min, max);

    vector<int> arr1;


    for (int i = 0; i < 100; ++i)
     {
        int random_number = distr(gen);
        cout<< random_number <<endl;
        arr1.push_back(random_number);
    }


    vector<int> arr2 = arr1;
    int n = arr1.size();


    QuickSort2(arr1, 0, n - 1);


    RQuickSort(arr2, 0, n - 1);


    cout << "Sorted array (Iterative QuickSort): ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;


    cout << "Sorted array (Randomized QuickSort): ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
