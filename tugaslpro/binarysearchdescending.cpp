//Nama      : Mervin Fauzhan Atkly
//NIM       : A11.2024.15679
//Kelompok  : A11.4204

#include <iostream>
using namespace std;

int binarySearchDescending(int arr[], int left, int right, int x) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == x) {
         cout << "Elemen ketemu di index ke-" << mid << endl;
         return mid;
      }
      else if (arr[mid] < x) {
         cout << "Mengecek dari tengah ke kiri array." << endl;
         right = mid - 1; 
      }
      else {
         cout << "Mengecek dari tengah ke kanan array." << endl;
         left = mid + 1; 
      }
   }
   return -1;
}

int main() {
   int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 7;

   int result = binarySearchDescending(arr, 0, n - 1, x);
   if (result == -1) {
      cout << "Elemen tidak ada di array" << endl;
   }
   return 0;
}