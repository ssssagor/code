#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;
using namespace chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int randomizedPartition(vector<int>& arr, int low, int high) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(low, high);

    int randomIndex = dis(gen);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

vector<int> generateArray(int n, int type) {
    vector<int> arr(n);
    if (type == 1) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, n);
        for (int& x : arr) x = dis(gen);
    } else if (type == 2) {
        for (int i = 0; i < n; i++) arr[i] = i + 1;
    } else if (type == 3) {
        for (int i = 0; i < n; i++) arr[i] = n - i;
    } else if (type == 4) {
        fill(arr.begin(), arr.end(), 5);
    }
    return arr;
}


void measurePerformance(int n, int type) {
    vector<int> arr = generateArray(n, type);


    vector<int> arr1 = arr;
    auto start = high_resolution_clock::now();
    quickSort(arr1, 0, arr1.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start).count();


    vector<int> arr2 = arr;
    start = high_resolution_clock::now();
    randomizedQuickSort(arr2, 0, arr2.size() - 1);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end - start).count();

    cout << "Array Size: " << n << "\n";
    cout << "Quick Sort Time: " << duration1 << " ms\n";
    cout << "Randomized Quick Sort Time: " << duration2 << " ms\n\n";
}

int main() {
    vector<int> sizes = {10, 100, 1000,10000, 100000};
    vector<int> types = {1};

    for (int type : types) {
        cout << "Testing Array : " << type << "\n";
        for (int size : sizes) {
            measurePerformance(size, type);
        }
    }

    return 0;
}

