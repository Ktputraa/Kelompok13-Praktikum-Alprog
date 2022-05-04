#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pengerjaan();
void ulang();
clock_t tempo;
double durasi[2];
int x, y, temp;

int main(){
	int pilihan;
	system("COLOR 0E");
	printf("..............................................................................................................\n\n");
	printf("\t(KELOMPOK 13)\n\n");
	printf("\t2105551023	I Ketut Putra Jaya\n");
	printf("\t2105551052	Kadek Cahyadi Yogachandra\n");
	printf("\t2105551102	Dyah Putri Maheswari\n");
	printf("\t2105551104	Velicia Varrel Valiant\n");
	printf("\t2105551105	Greace Amanda R.Y\n");
	printf("\t2105551125	A.A. Sagung Mirah Indira Wardhana\n\n");
	printf("==============================================================================================================\n");
	printf("..............................................................................................................\n");
	printf(".\t\t\t\t [PENGURUTAN DATA DENGAN BUBBLE SORT]\t\t\t\t\t     .\n");
   printf(".\t\t\t\t1. Bubble Sort 1000 Data\t\t\t\t\t\t     .\n");
   printf(".\t\t\t\t2. Bubble Sort 16000 Data\t\t\t\t\t\t     .\n");
   printf(".\t\t\t\t3. Bubble Sort 64000 Data\t\t\t\t\t\t     .\n");
   printf(".\t\t\t\t4. Keluar dari program\t\t\t\t\t\t\t     .\n");
	printf("..............................................................................................................\n");
	printf("==============================================================================================================\n");
   printf("\tMasukkan Pilihan: ");
	pilihan = validasi();
	switch(pilihan){
		case 1:
   		system("cls");
      	pengerjaan(1000);
      	break;
   	case 2:
   		system("cls");
   		pengerjaan(16000);
   		break;
   	case 3:
   		system("cls");
   		pengerjaan(64000);
   		break;
   	case 4:
   		system("cls");
   		printf("Terima kasih telah mencoba program ini :D\n");
   		exit(1);
   	default:
   		system("cls");
   		printf("Masukkan pilihan yang tersedia!\n");
   		main();
   }
   ulang();
   return 0;
}

void bubblesort_carabiasa(int a1[], int n){
	for(x=0; x<n-1; x++){
		for(y=0; y<n-1-x; y++){
			if(a1[y] > a1[y+1]){
				temp = a1[y];
				a1[y] = a1[y+1];
				a1[y+1] = temp;
			}
		}
	}
}

void bubblesort_carapointer(int *pa2[], int n){
	for(x=0; x<n-1; x++){
		for(y=0; y<n-1-x; y++){
			if(*(pa2+y) > *(pa2+y+1)){
				temp = *(pa2+y);
				*(pa2+y) = *(pa2+y+1);
				*(pa2+y+1) = temp;
			}
		}
	}
}

void pengerjaan(int n){
   int a1[n], a2[n], pilihan;

   for(x=0; x<n; x++){
		a1[x] = rand();
		a2[x] = a1[x];
	}
	for(x=0; x<n; x++){
   	printf("\t\t\t");
      for(y=0; y<=10; y++){
      	printf("%d ", a1[x]);
      }
      printf("\n\n");
	}
	printf("..............................................................................................................\n");
	printf(".\t\t\t\t     %d bilangan acak berhasil ditampilkan\t\t\t\t     .\n", n);
	printf("..............................................................................................................\n");
   printf("\n\t\t\tTekan sesuatu untuk mulai pengurutan data ...\n");
   getch();
	tempo = clock();
	bubblesort_carabiasa(a1, n);	
   tempo = clock() - tempo;
   durasi[0] = (double)(tempo) / CLOCKS_PER_SEC;
   tempo = clock();
	bubblesort_carapointer(a2, n);
	tempo = clock() - tempo;
	durasi[1] = (double)(tempo) / CLOCKS_PER_SEC;
	
	system("cls");
	printf("\t\t\tHasil Pengurutan\n\n");
	for(x=0; x<n; x++){
		printf("\t\t\t");
		for(y=0; y<=10; y++){
	      printf("%d ", a1[x]);
	   }
		printf("\n\n");
	}
	printf("..............................................................................................................\n");
	printf(".\t\t\t\t\t     PENGURUTAN DATA SELESAI\t\t\t\t             .\n", n);
	printf("..............................................................................................................\n");
	printf("\n\n");
	printf("\t\t\t\t     +-----------------------------------+\n");
	printf("\t\t\t\t     Waktu Yang Dibutuhkan        \n");
	printf("\t\t\t\t     +-----------------------------------+\n");
	printf("\t\t\t\t     Cara biasa : %f detik               \n", durasi[0]);
	printf("\t\t\t\t     Pointer    : %f detik               \n", durasi[1]);
	printf("\t\t\t\t     +-----------------------------------+\n");
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

void ulang(){
   int pilihan;
   printf("\n\t\t\t\t     .....................................\n\n");
   printf("\t\t\t\t     Ulang Operasi?\n");
   printf("\t\t\t\t     [1] Mengulang Pengurutan Data\n");
   printf("\t\t\t\t     [2] Exit\n");
   fflush(stdin);
   printf("\t\t\t\t     Masukkan pilihan yang tersedia : ");
   scanf("%d", &pilihan);
   switch(pilihan){
   	case 1:
			system("cls");
      	main();
      	break;
   	case 2:
   		system("cls");
   		printf("Terima kasih telah mencoba program ini :D\n");
      	exit(0);
      	break;
      default:
      	system("cls");
      	printf("\t\t\tMasukkan pilihan yang tersedia");
      	ulang();
      	break;
   }
}
