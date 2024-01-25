#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int a[3][3], b[3][3], hasil[3][3];
    int pilih, baris, kolom;

    while(1) {
        printf("===Operasi Matriks===");
        printf("\n1. Penjumlahan\n");
        printf("2. Pengurangan\n");
        printf("3. Perkalian\n");
        printf("Pilih salah satu (1/2/3): ");
        scanf("%d", &pilih);

        printf("\nMasukkan angka matriks a:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        
         printf("Masukkan angka matriks b:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
printf("\nMatriks a:\n");
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d\t", a[i][j]);
        } 
printf("\n");
    }
printf("\nMatriks b:\n");
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d\t", b[i][j]);
        }
printf("\n");
    }
        if (pilih == 1) {
            for (baris = 0; baris < 3; baris++) {
                for (kolom = 0; kolom < 3; kolom++) {
                    hasil[baris][kolom] = a[baris][kolom] + b[baris][kolom];
                }
            }
        } else if (pilih == 2) {
            for (baris = 0; baris < 3; baris++) {
                for (kolom = 0; kolom < 3; kolom++) {
                    hasil[baris][kolom] = a[baris][kolom] - b[baris][kolom];
                }
            }
        } else if (pilih == 3) {
            int c[3][3];
            for (baris = 0; baris < 3; baris++) {
                for (kolom = 0; kolom < 3; kolom++) {
                    c[baris][kolom] = 0;
                    for (int i = 0; i < 3; i++) {
                        c[baris][kolom] += a[baris][i] * b[i][kolom];
                    }
                }
            }
            memcpy(hasil, c, sizeof(c));
        } else {
            printf("INPUTAN TIDAK VALID\n");
            exit(0);
        }
    
        printf("\nMatriks Hasil: \n");
        for (baris = 0; baris < 3; baris++) {
            for (kolom = 0; kolom < 3; kolom++) {
                printf("%d\t", hasil[baris][kolom]);
            }
            printf("\n");
        } break;
    }
    
    return 0;
}
