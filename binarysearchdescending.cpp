#include <iostream>
using namespace std;

int binarySearchDescending(int arr[], int l, int r, int x) {
   while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == x) {
         cout << "Element found at index " << mid << endl;
         return mid;
      }
      else if (arr[mid] < x) {
         cout << "Checking left half of the array." << endl;
         r = mid - 1; // bedanya di sini
      }
      else {
         cout << "Checking right half of the array." << endl;
         l = mid + 1; // dan ini
      }
   }
   return -1;
}

int main() {
   int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // descending array
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 7;

   int result = binarySearchDescending(arr, 0, n - 1, x);
   if (result == -1) {
      cout << "Element not found in the array" << endl;
   }
   return 0;
}