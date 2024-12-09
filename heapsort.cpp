
//Heap Program

#include<bits/stdc++.h>

using namespace std;


void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] < arr[largest])
		largest = l;
	if (r < n && arr[r] < arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--) {

		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}



void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
int main()
{
	int s;
    cout<<"Enter the Number of Patient = ";
    cin>>s;
    int arr[s];
    for(int i=0;i<s;i++)
    arr[i]=rand()%100;
    	for(int i=s/2 -1;i>=0;i--)
        {
            heapify(arr,s,i);
        }
cout << "After Heapifying Age of Patient : \n";
	printArray(arr, s);
	heapSort(arr, s);
	cout << "The Oldest Patient Age List : \n";
	printArray(arr, s);


return 0;
}


