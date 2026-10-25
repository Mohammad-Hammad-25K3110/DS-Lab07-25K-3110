#include <iostream>
using namespace std;

int trackingIDs[12] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
int output[12];
int n = 12;

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void countingSort(int exp) {
    int count[10] = {0};
    cout << "Original array: ";
    printArray(trackingIDs, n);
    for (int i = 0; i < n; i++) {
        count[(trackingIDs[i] / exp) % 10]++;
    }
    cout << "Frequency count: ";
    printArray(count, 10);
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    cout << "Cumulative count: ";
    printArray(count, 10);
    for (int i = n - 1; i >= 0; i--) {
        int d = (trackingIDs[i] / exp) % 10;
        output[count[d] - 1] = trackingIDs[i];
        count[d]--;
    }
    cout << "Output array: ";
    printArray(output, n);
    for (int i = 0; i < n; i++) {
        trackingIDs[i] = output[i];
    }
    cout << "After copying output back: ";
    printArray(trackingIDs, n);
}

int radixSort() {
    int maxVal = trackingIDs[0];
    for (int i = 1; i < n; i++) {
        if (trackingIDs[i] > maxVal) {
            maxVal = trackingIDs[i];
        }
    }
    int pass = 0;
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        pass++;
        cout << "Pass " << pass << " (digit place " << exp << ")" << endl;
        countingSort(exp);
        cout << endl;
    }
    return pass;
}

int main() {
    int passes = radixSort();
    cout << "Sorted tracking IDs: ";
    printArray(trackingIDs, n);
    cout << "Total passes: " << passes << endl;
    return 0;
}
