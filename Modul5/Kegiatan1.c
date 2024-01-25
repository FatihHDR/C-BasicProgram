#include <stdio.h>

int main() {
    int n; // Jumlah elemen yang akan diinput
    int i; // Variabel untuk perulangan
    int j = 0;
    int k = 0;

    printf("Masukkan jumlah elemen yang akan diinput: ");
    scanf("%d", &n);

    int array[n]; // Array untuk menyimpan elemen yang diinput
    int arrayGanjil[n];
    int arrayGenap[n];

    printf("Input %d elemen: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] % 2 == 0) { // Jika elemen genap masukkan ke array genap
            arrayGenap[k] = array[i];
            k++;
        } else { // Jika elemen ganjil masukkan ke array ganjil
            arrayGanjil[j] = array[i];
            j++;
        }
    }

    printf("Bilangan Ganjil dalam array: ");
    for (i = 0; i < j; i++) {
        printf("%d ", arrayGanjil[i]);
    }
    printf("\n");

    printf("Bilangan Genap dalam array: ");
    for (i = 0; i < k; i++) {
        printf("%d ", arrayGenap[i]);
    }
    printf("\n");

    return 0;
}
