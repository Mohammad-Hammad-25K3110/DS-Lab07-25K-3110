#include <iostream>
using namespace std;

int arr[10] = {7314, 314, 731, 34, 3147, 147, 47, 7314, 4, 314};
int output[10];
int n = 10;

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

int radixSort() {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(exp);
        pass++;
        cout << "After pass " << pass << ": ";
        printArray(arr, n);
    }
    return pass;
}

int main() {
    cout << "Original array: ";
    printArray(arr, n);
    int passes = radixSort();
    cout << "Sorted array: ";
    printArray(arr, n);
    cout << "Maximum passes required: " << passes << endl;
    return 0;
}
