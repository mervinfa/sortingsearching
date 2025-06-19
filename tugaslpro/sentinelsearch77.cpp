//Nama      : Mervin Fauzhan Atkly
//NIM       : A11.2024.15679
//Kelompok  : A11.4204

#include <iostream>
using namespace std;

void sentinelSearchAll(int arr[], int n, int x) {
    int last = arr[n - 1];       
    arr[n - 1] = x;              
    int i = 0;
    bool found = false;

    while (i < n) {
        while (arr[i] != x) {
            i++;
        }
        if ((i < n - 1) || (arr[n - 1] == x)) {
            cout << "Elemen ketemu di index ke -" << i << endl;
            found = true;
        }

        i++; 
        if (i >= n - 1 && last != x) break; 
    }

    arr[n - 1] = last; 

    if (!found) {
        cout << "Elemen tidak ada di array" << endl;
    }
}

int main() {
    int arr[] = {3, 5, 2, 9, 7, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    sentinelSearchAll(arr, n, x);
    return 0;
}