#include <stdio.h>
#include <string.h>

int main() {
    char teks[1000], kata[100];
    int i, j, ditemukan, posisi[100], hitung, k;
    int panjangKata, panjangTeks;
    char pilihan;

    do {
        puts("Teks yang ditulis: ");
        fgets(teks, sizeof(teks), stdin);
        teks[strcspn(teks, "\n")] = 0;

        puts("Masukkan kata yang ingin dicari: ");
        fgets(kata, sizeof(kata), stdin);
        kata[strcspn(kata, "\n")] = 0;

        char *kataTeks[100];
        int jumlahKataTeks = 0;
        char *token = strtok(teks, " ");
        while (token != NULL) {
            kataTeks[jumlahKataTeks] = token;
            jumlahKataTeks++;
            token = strtok(NULL, " ");
        }

        char *kataCari[100];
        int jumlahKataCari = 0;
        token = strtok(kata, " ");
        while (token != NULL) {
            kataCari[jumlahKataCari] = token;
            jumlahKataCari++;
            token = strtok(NULL, " ");
        }

        hitung = 0;
        k = 0;
        for (i = 0; i < jumlahKataTeks; i++) {
            ditemukan = 0;
            for (j = 0; j < jumlahKataCari; j++) {
                if (strcmp(kataTeks[i], kataCari[j]) == 0) {
                    ditemukan = 1;
                    break;
                }
            }

            if (ditemukan == 1) {
                posisi[hitung] = i + 1;
                hitung++;
                k++;
            }
        }

        if (hitung > 0) {
            printf("Kata '%s' ditemukan pada posisi ", kata, hitung);
            for (i = 0; i < k; i++) {
                printf("%d", posisi[i]);
                if (i < k - 1) {
                    printf(" dan ");
                }
            }
            printf(".\n");
        } else {
            printf("Kata '%s' tidak ditemukan di teks.\n", kata);
        }

        printf("Apakah Anda ingin mencari lagi? (1=Ya, 0=Tidak): ");
        scanf(" %c", &pilihan);
        getchar();
    } while (pilihan == '1');

return 0;
}
