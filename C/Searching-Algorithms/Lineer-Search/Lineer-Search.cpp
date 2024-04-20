#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

int main() {
    int arr[] = {12, 45, 23, 6, 78, 43, 21};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key = 6; 
    int result = linearSearch(arr, n, key);
    if (result != -1) {
        printf("Anahtar %d indeksinde bulundu.\n", result);
    } else {
        printf("Anahtar bulunamadı.\n");
    }
    return 0;
}