#include <iostream>
using namespace std;

int arr[7] = {40, 20, 70, 10, 60, 30, 50};
int partitionCount = 0;

void printArray(int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int low, int high) {
    int pivot = arr[high];
    cout << "Pivot: " << pivot << ", low: " << low << ", high: " << high << endl;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    partitionCount++;
    cout << "After partition: ";
    printArray(7);
    return i + 1;
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
    cout << "Partition operations: " << partitionCount << endl;
    return 0;
}
