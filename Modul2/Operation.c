#include <stdio.h>
#include <stdbool.h>

int main() {
	
    float matematika, fisika, biologi, rata_rata; 
    float *ptr_matematika = &matematika;
    float *ptr_fisika = &fisika;
    float *ptr_biologi = &biologi;
    char str[49];
    const int JUMLAH_SKS = 9; //Constant

	printf("=== Penghitungan Nilai rata-rata ===\n\n"); //Int Input 
	
    printf("Masukkan nilai Matematika: ");
    scanf("%f", ptr_matematika);

    printf("Masukkan nilai Fisika: ");
    scanf("%f", ptr_fisika);

    printf("Masukkan nilai Biologi: ");
    scanf("%f", ptr_biologi);
    
    rata_rata = ((*ptr_matematika * 4) + (*ptr_fisika * 3) + (*ptr_biologi * 2))/JUMLAH_SKS; //Operator Aritmetika
    sprintf(str, "\nNilai rata-rata: %.2f\n", rata_rata); //String Input
    printf("%s", str);
    
    if (rata_rata > 80) { //Boolean
        bool lulus = true;
        printf("Selamat, Anda lulus!\n");        
    } 
	else if (rata_rata >= 60) {
        bool lulus = false;
        printf("Kamu harus mengulang beberapa mata kuliah.\n");        
    } 
	else {
        bool lulus = false;
        printf("Maaf, Kamu tidak lulus.\n");
    }

return 0;

}
