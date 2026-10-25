#include <iostream>
using namespace std;

int arr[8] = {78, 45, 92, 63, 45, 88, 51, 70};
int temp[8];
int mergeCount = 0;

void printArray(int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
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
    mergeCount++;
    cout << "Merge " << mergeCount << " [" << low << ".." << high << "]: ";
    printArray(8);
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
    cout << "Original array: ";
    printArray(8);
    mergeSort(0, 7);
    cout << "Sorted array: ";
    printArray(8);
    cout << "Total merge operations: " << mergeCount << endl;
    return 0;
}
