#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Eğer key, ortadaki elemana eşitse, ortadaki indeksi döndür
        if (arr[mid] == key)
            return mid;

        // Eğer key, ortadaki elemandan küçükse, sağ tarafı ara
        if (arr[mid] < key)
            low = mid + 1;
        // Eğer key, ortadaki elemandan büyükse, sol tarafı ara
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
        printf("Eleman bulunamadı.\n");
    else
        printf("Eleman %d indeksinde bulundu.\n", result);
    return 0;
}