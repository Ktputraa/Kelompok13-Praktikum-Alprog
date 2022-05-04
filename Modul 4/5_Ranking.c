#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void keluar();
void judul();
void reset();
void sort_data();
void output();

struct Mahasiswa{
	char nama[20];
	int nilai;
};

void keluar(){
	system("cls");
	printf("\n==========================================================");
	printf("\n|         TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM!         |");
    printf("\n==========================================================");
    printf("\n");
    exit(0);
}

void judul(){
	printf("======================================================\n");
    printf("|                                                    |\n");
    printf("|             PROGRAM RANGKING NILAI QUIZ            |\n");
    printf("|                   KELOMPOK 13                      |\n");
    printf("|                                                    |\n");
    printf("| Anggota:                                           |\n");
    printf("| 2105551023	I Ketut Putra Jaya                   |\n");
    printf("| 2105551052    Kadek Cahyadi Yogachandra            |\n");
    printf("| 2105551102	Dyah Putri Maheswari                 |\n");
    printf("| 2105551104	Velicia Varrel Valiant               |\n");
    printf("| 2105551105    Greace Amanda R.Y                    |\n");
    printf("| 2105551125    A.A. Sagung Mirah Indira Wardhana    |\n");
    printf("|                                                    |\n");
    printf("======================================================\n");
    printf("\n\n Membaca file asistenin.txt.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
}
void reset(){
    char huruf_ulang[1];
    
    printf("\n  Ingin Ulang Atau Keluar ?");
    printf("\n  [Y] Ulang				[Q] Keluar  \n");
    printf("\n  Masukkan Pilihan : ");
    scanf("%s", &huruf_ulang);
    fflush(stdin);

    if((strcmp(huruf_ulang, "q") != 0) && (strcmp(huruf_ulang, "y") != 0)){
        printf("Masukkan input dengan benar!\n");
        reset();
    }
	else if((strcmp(huruf_ulang, "y") == 0)){
        system("cls");
		main();
    }
	else{
        keluar();
    }
}

int sorting(){
    char huruf_sort[1];
	int hasil = 0;
    
    printf("======================================================\n\n");
    printf("  Urutkan Nilai ?");
    printf("\n  [Y] Ya 			[N] Tidak \n");
    printf("\n  Masukkan Pilihan : ");
    scanf("%s", &huruf_sort);
    fflush(stdin);

    if((strcmp(huruf_sort, "y") != 0) && (strcmp(huruf_sort, "n") != 0)){
        printf("Masukkan input dengan benar!\n\n");
        sorting();
    }
	else if((strcmp(huruf_sort, "y") == 0)){
		hasil = 1;
    }
	else{
		hasil = 0;
    }
	return hasil;
}

int baca_asistenin(struct Mahasiswa data[]){
	int a = 0;
	FILE *in = fopen("asistenin.txt","r");
	if(!in){
		printf("File asistenin.txt tidak ditemukan\n");
		printf("Silahkan buat file asistenin.txt terlebih dahulu\n");
	}
	else{
        printf("Data Nilai Mahasiswa : \n");
		while(!feof(in)){
			printf("    ");
			fscanf(in,"%[^\n]\n", &data[a].nama);
		    fscanf(in,"%d\n", &data[a].nilai);
            fflush(stdin);
		    printf("%d. %s : %d\n", a+1, data[a].nama, data[a].nilai);
		    a++;
		}
	}
	fclose(in);
	return a;
}

void sort_data(struct Mahasiswa data[], int a){
	struct Mahasiswa temp;
	int i, j;
	for(i = 0; i < a - 1; i++){
		for(j = 0; j < a - 1; j++){
			if(data[j+1].nilai > data[j].nilai){
				temp = data[j+1];
				data[j+1] = data[j];
    			data[j] = temp;
			}
    	}
	}
}

void output(struct Mahasiswa data[], int a){
	int i;
	FILE *out = fopen("asistenout.txt","w");
	fprintf(out, "Nilai Mata Kuliah Algoritma dan Pemrograman\n");
	for(i = 0; i < a; i++){
		fprintf(out,"%d. %s %d\n", i+1, data[i].nama, data[i].nilai);
	}
	fclose(out);
}

int main(){
    struct Mahasiswa data[50];
	struct Mahasiswa temp;
	int a = 0;
	int i, j, k;
	int sort;
	char tempNama[20];
	int tempNilai;

	judul();
	system("cls");
	printf("======================================================\n");
    printf("|                                                    |\n");
    printf("|             PROGRAM RANGKING NILAI QUIZ            |\n");
    printf("|                   KELOMPOK 13                      |\n");
    printf("|                                                    |\n");
    printf("| Anggota:                                           |\n");
    printf("| 2105551023	I Ketut Putra Jaya                   |\n");
    printf("| 2105551052    Kadek Cahyadi Yogachandra            |\n");
    printf("| 2105551102	Dyah Putri Maheswari                 |\n");
    printf("| 2105551104	Velicia Varrel Valiant               |\n");
    printf("| 2105551105    Greace Amanda R.Y                    |\n");
    printf("| 2105551125    A.A. Sagung Mirah Indira Wardhana    |\n");
    printf("|                                                    |\n");
    printf("======================================================\n");
    
	/* Membaca data dalam asistenin.txt lalu disimpan ke array */
	a = baca_asistenin(data);

	printf("\n");
	sort = sorting();

	if(sort == 1){
		/* Pengurutan nilai dan nama */
		sort_data(data, a);
		printf("\n");

		/* Pencetakan ke asistenout.txt */
		output(data, a);
		printf("\n======================================================\n\n");	
		printf("Data Berhasil Di Urutkan !\n");
		printf("Silahkan Cek File asistenout.txt\n");
	}
	printf("\n======================================================\n");
	reset();
    return 0;
}
