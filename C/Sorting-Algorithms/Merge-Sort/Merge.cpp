#include <stdio.h>

// Merge iki alt diziyi birleştirir
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Geçici diziler oluştur
    int L[n1], R[n2];

    // Geçici dizileri doldur
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // İki alt diziyi birleştir
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kalan elemanları kopyala (eğer varsa)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort fonksiyonu
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Ortayı bul
        int m = l + (r - l) / 2;

        // İlk yarısını sırala
        mergeSort(arr, l, m);
        // İkinci yarısını sırala
        mergeSort(arr, m + 1, r);

        // İki sıralı yarım diziyi birleştir
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Sıralanmadan önce diziyi yazdır:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    printf("Sıralandıktan sonra diziyi yazdır:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}