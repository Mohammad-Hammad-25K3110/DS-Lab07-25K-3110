#include <iostream>
using namespace std;

int arr[7] = {91, 8, 1024, 56, 305, 7, 120};
int output[7];
int n = 7;

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void countingSort(int exp) {
    int count[10] = {0};
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int d = (arr[i] / exp) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort() {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    int pass = 1;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(exp);
        cout << "After pass " << pass++ << ": ";
        printArray(arr, n);
    }
}

int main() {
    cout << "Original array: ";
    printArray(arr, n);
    radixSort();
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}
