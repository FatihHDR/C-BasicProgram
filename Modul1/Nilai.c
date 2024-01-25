#include <stdio.h>

int main() {
    float nilaiKalkulus, nilaiPancasila, nilaiOrkom;

    printf("Masukkan Nilai Kalkulus: ");
    scanf("%f", &nilaiKalkulus);

    printf("Masukkan Nilai Pancasila: ");
    scanf("%f", &nilaiPancasila);

    printf("Masukkan Nilai Orkom: ");
    scanf("%f", &nilaiOrkom);

    printf("\nNilai Kalkulus Kamu: %.2f\n", nilaiKalkulus);
    printf("Nilai Pancasila Kamu: %.2f\n", nilaiPancasila);
    printf("Nilai Orkom Kamu: %.2f\n", nilaiOrkom);

    return 0;
}
