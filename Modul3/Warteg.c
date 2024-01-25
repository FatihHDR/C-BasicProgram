#include <stdio.h>

enum Makanan { NASI_GORENG = 55000, MIE_GORENG = 45000, AYAM_GORENG = 65000, AYAM_GEPREK = 50000, NASI_BAKAR = 45000 };
enum Minuman { AIR_MINERAL = 13000, ES_TEH = 15000, JUS_JERUK = 20000, ES_KELAPA = 30000, SODA_GEMBIRA = 20000 };

int main() {
    int pilihanMakanan, pilihanMinuman, totalBelanja, uangDibayarkan;
    char isMember;

    printf("Selamat datang di Rumah Makan Kami!\n");
    printf("Silahkan pilih menu makanan:\n1. Nasi Goreng Rp. 55000\n2. Mie Goreng Rp. 45000\n3. Ayam Goreng Rp. 65000\n4. Ayam Geprek Rp. 50000\n5. Nasi Bakar Rp. 45000\n ");
    printf("Pilih menu makanan (1-5): ");
    scanf("%d", &pilihanMakanan);

    printf("Silahkan pilih menu minuman:\n1. Air Mineral Rp. 13000\n2. Es Teh Rp. 15000\n3. Jus Jeruk Rp. 20000\n4. Es Kelapa Rp. 30000\n5. Soda Gembira Rp. 20000\n ");
    printf("Pilih menu minuman: ");
    scanf("%d", &pilihanMinuman);

    printf("Apakah Anda adalah member? (y/n)\n");
    scanf(" %c", &isMember);

    totalBelanja = 0;

    switch(pilihanMakanan) {
        case 1: totalBelanja += NASI_GORENG; break;
        case 2: totalBelanja += MIE_GORENG; break;
        case 3: totalBelanja += AYAM_GORENG; break;
	case 4: totalBelanja += AYAM_GEPREK; break;
	case 5: totalBelanja += NASI_BAKAR; break;
	}
    switch(pilihanMinuman) {
        case 1: totalBelanja += AIR_MINERAL; break;
        case 2: totalBelanja += ES_TEH; break;
        case 3: totalBelanja += JUS_JERUK; break;
	case 4: totalBelanja += ES_KELAPA; break;
	case 5: totalBelanja += SODA_GEMBIRA; break;
	}

    if (isMember == 'y' || isMember == 'Y') {
        totalBelanja *= 0.9;  
    }

    printf("Total belanja: Rp. %d\n", totalBelanja);
    printf("Alamat memori total belanja: %p\n", &totalBelanja);

    printf("Masukkan jumlah uang yang dibayarkan:\n");
    scanf("%d", &uangDibayarkan);

    if (uangDibayarkan >= totalBelanja) {
        printf("Kembalian: Rp. %d\n", uangDibayarkan - totalBelanja);
    } else if (uangDibayarkan < totalBelanja) {
        printf("Uang kurang.\n");
    } else {
        printf("Terima kasih!\n");
    }

    return 0;
}
