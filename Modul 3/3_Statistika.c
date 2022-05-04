#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void ulang();
void klp();
void statistika();
void judul();
int main();
int validasi();
	
void klp(){
	system("COLOR 0E");
	printf("\t(KELOMPOK 13)\n\n");
	printf("\t2105551023	I Ketut Putra Jaya\n");
	printf("\t2105551052	Kadek Cahyadi Yogachandra\n");
	printf("\t2105551102	Dyah Putri Maheswari\n");
	printf("\t2105551104	Velicia Varrel Valiant\n");
	printf("\t2105551105	Greace Amanda R.Y\n");
	printf("\t2105551125	A.A. Sagung Mirah Indira Wardhana\n\n");
}

void judul(){
	printf("==============================================================================================================\n");
	printf("..............................................................................................................\n");
	printf(".\t\t\t\t\t\t[PROGRAM STATISTIKA]\t\t\t\t\t     .\n");
	printf(".\t\t\t\t\tPERHITUNGAN MEDIAN, MODUS, DAN MEAN\t\t\t\t     .\n");
	printf("..............................................................................................................\n");
	printf("==============================================================================================================\n");
}

int validasi(){
	char ch, *data; 
	data= (char *) malloc (sizeof(char)); 
	int index=0;
	while ((ch=getch()) !=13){
		if (ch>='0' && ch<='9'){
			printf("%c", ch); 
			data[index]=ch; 
			index++;
		}
	}
	data [index]='\0';
	return atoi(data); 
}

float rumus_mean(float data[], int jumlah){
    float hasil = 0;
    int i;

    for(i = 0; i < jumlah; i++){
        hasil = hasil + data[i];
    }

    hasil = hasil / jumlah;

    return hasil;
}

float rumus_median(float data[], int jumlah){
    float hasil;
    int tengah = jumlah / 2;

    if(jumlah % 2 == 0){
        hasil = (data[tengah-1] + data[tengah]) / 2;
    }else{
        hasil = data[tengah];
    }

    return hasil;
}

int rumus_modus(float bil[], int jumlah, float mod[]){
    int n_angka[jumlah];
    int i, j;
    int jumlah_tmp;
    int max = 0;
    int z = 0;
    int status;
    int a = 0;

    for(i = 0; i < jumlah; i++){
        mod[i] = 0;
        jumlah_tmp = 0;
        for(j = 0; j < jumlah; j++){
            if(bil[i] == bil[j]){
                jumlah_tmp++;
            }
        }
        if(jumlah_tmp > max){
            max = jumlah_tmp;
        }
        n_angka[i] = jumlah_tmp;
    }

    for(i = 0; i < jumlah; i++){
        status = 0;
        if(n_angka[i] == max){
            z++;
            for(j = 0; j < jumlah; j++){
                if(bil[i] == mod[j]){
                    status = 1;
                }
            }
            if(status == 0){
                mod[a] = bil[i];
                a++;
            }
        }
    }

    if(jumlah == z){
        return 0;
    }else{
        return a;
    }
}

void sorting_nilai(float data[], int jumlah){
    int i, j;
    float temp;
    for(i = 0; i < jumlah - 1; i++){
	    for(j = 0; j < jumlah - 1; j++){
		    if(data[j+1] < data[j]){
			    temp      = data[j];
			    data[j]   = data[j+1];
    			data[j+1] = temp;
		    }
    	}
	}
}

void ulang(){
   int pilihan;
   printf("\n\n\t\t\t\t================================================\n\n");
   printf("\t\t\t\tApakah anda ingin mengulang operasi?\n");
   printf("\t\t\t\t[1] Untuk Mengulang Perhitungan\n");
   printf("\t\t\t\t[2] Untuk kembali Keluar Dari Program\n");
   fflush(stdin);
   printf("\t\t\t\tMasukkan pilihan yang tersedia : ");
   scanf("%d", &pilihan);
   switch(pilihan){
		case 1:
			system("cls");
      		main();
      		break;
   		case 2:
   			system("cls");
   			printf("Terima kasih telah mencoba program ini :D");
      		exit(0);
      		break;
    	default:
      		system("cls");
      		printf("\t\t\tMasukkan pilihan yang tersedia");
      		ulang();
    	  	break;
	}
}

int main(){
    int jumlah, i, pilihan;
    float hasil_mean, hasil_median, hasil_modus, *alamat;
	printf("..............................................................................................................\n\n");
	klp();
	judul();
    printf("\n\tMasukkan Jumlah Data: ");
    jumlah = validasi();

	float data[jumlah];
    alamat = &data;

    for(i = 0; i < jumlah; i++){
        printf("\n\tMasukan Angka ke - %d : \t", i+1);
        alamat[i] = validasi();
    }

    sorting_nilai(data, jumlah);
	printf("\n..............................................................................................................\n");
    printf("\tUrutan Data	: ");
        for(i = 0; i < jumlah; i++){
            printf("%.0f  ", data[i]);
    }

    hasil_mean = rumus_mean(data, jumlah);
    hasil_median = rumus_median(data, jumlah);
    float mod[jumlah];
    hasil_modus = rumus_modus(data, jumlah, mod);

    printf("\n\tMean		: %.2f", hasil_mean);
    printf("\n\tMedian		: %.2f", hasil_median);

    if(hasil_modus == 0){
        printf("\tTidak Ada Modus\n");
    }else{
        printf("\n\tModus		: ");
        for(i = 0; i < hasil_modus; i++){
            if(i == 0){
                printf("%.0f", mod[i]);
            }else{
                printf(", %.0f", mod[i]);
            }
        }
    }
	ulang();
}
