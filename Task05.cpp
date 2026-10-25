#include <iostream>
using namespace std;

int arr[7] = {55, 25, 75, 15, 65, 35, 45};
int comparisons = 0;

void printArray(int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int low, int high) {
    int pivot = arr[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[low];
    arr[low] = arr[i];
    arr[i] = t;
    cout << "Pivot: " << pivot << ", array: ";
    printArray(7);
    return i;
}

void quickSort(int low, int high) {
    if (low < high) {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

int main() {
    cout << "Original array: ";
    printArray(7);
    quickSort(0, 6);
    cout << "Sorted array: ";
    printArray(7);
    cout << "Total comparisons: " << comparisons << endl;
    return 0;
}
