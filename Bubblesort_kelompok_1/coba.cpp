#include <iostream>
using namespace std;

void tampilkanarray(int arr[], int n){
    cout << "Sebelum Diurutkan : ";
    for (int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n ; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
        cout << "Step " << i+1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " " ;
        }
        cout << endl;
    }
    
}
void hasilarray(int arr[], int n){
    cout << "Setelah Diurutkan : ";
    for (int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {29, 10, 14, 37, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    tampilkanarray(arr, n);
    bubbleSort(arr, n);
    hasilarray(arr,n);
    return 0;
}