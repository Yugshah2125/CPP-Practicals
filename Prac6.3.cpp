#include<iostream>
using namespace std;

int main()
{
    int m, n;

    cout << "Enter the size of 1st array: ";
    cin >> m;
    int *arr1 = new int[m];

    for(int i = 0; i < m; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr1[i];
    }

    cout << "Enter the size of 2nd array: ";
    cin >> n;
    int *arr2 = new int[n];

    for(int j = 0; j < n; j++)
    {
        cout << "Enter element " << j+1 << ": ";
        cin >> arr2[j];
    }

    int *merged = new int[m+n];

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if(arr1[i] <= arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    while(i < m){
        merged[k++] = arr1[i++];
    }

    while(j < n){
        merged[k++] = arr2[j++];
    }

    cout << "\nMerged array is:\n ";
    for(int i = 0; i < m+n; i++){
        cout << merged[i] << " ";
    }
    cout << endl << "Yug Shah\n24CE114";

    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}
