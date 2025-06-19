#include <iostream>
using namespace std;

void sentinelSearchAll(int arr[], int n, int x) {
    int last = arr[n - 1];       // Simpan elemen terakhir
    arr[n - 1] = x;              // Set elemen terakhir sebagai sentinel
    int i = 0;
    bool found = false;

    // Loop sampai i melewati batas n-1
    while (i < n) {
        while (arr[i] != x) {
            i++;
        }

        // Jika posisi bukan sentinel terakhir
        if ((i < n - 1) || (arr[n - 1] == x)) {
            cout << "Element found at index " << i << endl;
            found = true;
        }

        i++; // lanjut cari yang lain
        if (i >= n - 1 && last != x) break; // keluar kalau sentinel tidak cocok
    }

    arr[n - 1] = last; // Kembalikan elemen terakhir

    if (!found) {
        cout << "Element not found in the array" << endl;
    }
}

int main() {
    int arr[] = {3, 5, 2, 9, 7, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    sentinelSearchAll(arr, n, x);
    return 0;
}