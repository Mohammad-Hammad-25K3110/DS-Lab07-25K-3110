#include <iostream>
using namespace std;

int arr[8] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
int leftArr[8], rightArr[8];
int comparisons = 0;

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    cout << "Left: ";
    printArray(leftArr, n1);
    cout << "Right: ";
    printArray(rightArr, n2);
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        comparisons++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
}

int main() {
    mergeSort(0, 7);
    cout << "Sorted prices: ";
    printArray(arr, 8);
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
