#include <iostream>
using namespace std;

int *arr;
int *temp;
int recursiveCalls = 0, mergeCount = 0, comparisons = 0;

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    mergeCount++;
    while (i <= mid && j <= high) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= high) {
        temp[k++] = arr[j++];
    }
    for (int x = low; x <= high; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int low, int high) {
    recursiveCalls++;
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Error: n must be greater than 0" << endl;
        return 1;
    }
    arr = new int[n];
    temp = new int[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Recursive calls: " << recursiveCalls << endl;
    cout << "Merge operations: " << mergeCount << endl;
    cout << "Comparisons: " << comparisons << endl;
    delete[] arr;
    delete[] temp;
    return 0;
}
