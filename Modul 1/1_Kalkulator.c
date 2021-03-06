#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//PROSEDUR
void halamanUtama();
void Penjumlahan();
void Pengurangan();
void Perkalian();
void Pembagian(); 
void Modulus(); 

//MAIN
int main(){
   system("COLOR F0");
   halamanUtama();
   return 0;
}

// FUNGSI
float hitungPenjumlahan(float bilangan1, float bilangan2){
   float hasil = bilangan1+bilangan2;
   return hasil; 
}
float hitungPengurangan(float bilangan1, float bilangan2){
   float hasil = bilangan1-bilangan2;
   return hasil;
} 
float hitungPerkalian(float bilangan1, float bilangan2){
   float hasil = bilangan1*bilangan2;
   return hasil;
} 
float hitungPembagian(float bilangan1, float bilangan2){
   float hasil = bilangan1/bilangan2;
   return hasil;
}
int hitungModulus(int bilangan1, int bilangan2){
   int hasil = bilangan1%bilangan2;
   return hasil; 
}

//FUNGSI VALIDASI
int validasi_halamanUtama() { 
   int i = 0, salah =0, val, array;
   char angka[100];

   scanf("%s", &angka);
   array=strlen(angka);
   for(i=0;i<array; i++){
		if(angka[i]>=49 && angka[i]<=54){ // PEMBATAS PADA ASCII DIMANA 49-54 BERNILAI "1-6"
		}else{
			salah += 1; 
		}
   }
   if(salah>0){
      printf("\n [WARNING! MENU TIDAK ADA]\n Masukkan Pilihan yang Tersedia: ");
      validasi_halamanUtama();
   }else{
		val = atoi(angka);	//mengubah alfabet ke bilangan bulat
		if(val>=1 && val<=6){
			return val;
      }else{ 
         printf("\n [WARNING! MENU TIDAK ADA]\n Masukkan Pilihan yang Tersedia: ");
         validasi_halamanUtama();
      }
   }
}
 
float validasiFloatPenjumlahan(){
   int i = 0, salah =0, titik=0, array;
   char angka[100];
   float val;
   float bilangan1, bilangan2;

   scanf("%s", &angka);
	array=strlen(angka);
   if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"
   }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"
	}else{ 
		salah += 1;
   }
   for(i=1;i<array; i++){ 
   	if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9" 
      }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 46 BERNILAI "."
      	titik += 1;
      }else{
         salah += 1; 
      }
   }
	if(salah>0 || titik>1){
		system("cls");
      printf("\n [WARNING! BILANGAN SALAH. ULANGI MEMASUKKAN NILAI]\n\n ");
   	Penjumlahan();
      validasiFloatPenjumlahan();
      
   }else{
      val = atof(angka);
      return val;
   }
} 

float validasiFloatPengurangan(){
   int i = 0, salah =0, titik=0, array;
   char angka[100];
   float val;
   float bilangan1, bilangan2;

   scanf("%s", &angka);
	array=strlen(angka);
   if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"
   }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"
	}else{ 
		salah += 1;
   }
   for(i=1;i<array; i++){ 
   	if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9" 
      }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 46 BERNILAI "."
      	titik += 1;
      }else{
         salah += 1; 
      }
   }
	if(salah>0 || titik>1){
		system("cls");
      printf("\n [WARNING! BILANGAN SALAH. ULANGI MEMASUKKAN NILAI]\n\n ");
   	Pengurangan();
      validasiFloatPengurangan();
      
   }else{
      val = atof(angka);
      return val;
   }
} 

float validasiFloatPerkalian(){
   int i = 0, salah =0, titik=0, array;
   char angka[100];
   float val;
   float bilangan1, bilangan2;

   scanf("%s", &angka);
	array=strlen(angka);
   if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"
   }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"
	}else{ 
		salah += 1;
   }
   for(i=1;i<array; i++){ 
   	if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9" 
      }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 46 BERNILAI "."
      	titik += 1;
      }else{
         salah += 1; 
      }
   }
	if(salah>0 || titik>1){
		system("cls");
      printf("\n [WARNING! BILANGAN SALAH. ULANGI MEMASUKKAN NILAI]\n\n ");
   	Perkalian();
      validasiFloatPerkalian();
      
   }else{
      val = atof(angka);
      return val;
   }
} 

float validasiFloatPembagian(){
   int i = 0, salah =0, titik=0, array, pilihan;
   char angka[100];
   float val;
   float bilangan1, bilangan2;

   scanf("%s", &angka);
	array=strlen(angka);
   if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"
   }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"
	}else{ 
		salah += 1;
   }
   for(i=1;i<array; i++){ 
   	if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9" 
      }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 46 BERNILAI "."
      	titik += 1;
      }else{
         salah += 1; 
      }
   }
	if(salah>0 || titik>1){
		system("cls");
      printf("\n [WARNING! BILANGAN SALAH. ULANGI MEMASUKKAN NILAI]\n\n ");
   	Pembagian();
      validasiFloatPembagian();
      
   }else{
      val = atof(angka);
      return val;
   }
} 

int validasiModulus(){
   int i = 0, salah =0, array;
   char angka[100];
   float val;

   scanf("%s", &angka);
   array=strlen(angka);
   if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9" 
   }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"
   }else{
		salah += 1; 
   }for(i=1;i<array; i++){
		if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"
 		}else{
			salah += 1;
      }
   }
   if(salah>0){ 
   	system ("cls");
      printf("\n [WARNING! BILANGAN SALAH]\n ");
      Modulus();
      validasiModulus();
   }else{
      val = atoi(angka); 
      return val;
   } 
}

int validasiPilihan(){
   int i = 0, salah =0, val, array;
   char angka[100];

   scanf("%s", &angka);
   array=strlen(angka);
   for(i=0;i<array; i++){
   	if(angka[i]>=49 && angka[i]<=51){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "1-3"
      }else{
      	salah += 1; 
      }
   }
   if(salah>0){
   	printf("\n [WARNING! MENU TIDAK ADA]\n Masukkan Pilihan yang Tersedia: ");
      validasiPilihan();
   }else{
      val = atoi(angka);
      if(val>=1 && val<=3){
      	return val;
      }else{
         printf("\n [WARNING! MENU TIDAK ADA]\n Masukkan Pilihan yang Tersedia: ");
         validasiPilihan();
      }
   }
}
 
void halamanUtama(){
	int pilihan;
	printf("...................................................\n\n");
	printf("  IDENTITAS KELOMPOK 13:\n");
	printf("  2105551023	I Ketut Putra Jaya\n");
	printf("  2105551052	Kadek Cahyadi Yogachandra\n");
	printf("  2105551102	Dyah Putri Maheswari\n");
	printf("  2105551104	Velicia Varrel Valiant\n");
	printf("  2105551105	Greace Amanda R.Y\n");
	printf("  2105551125	A.A. Sagung Mirah Indira Wardhana\n\n");
	printf("===================================================\n");
	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t\tPROGRAM KALKULATOR\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("===================================================\n\n");
	printf("\t   [D A F T A R  P I L I H A N]\n\n");
	printf("\t   [1]  Penjumlahan\n");
	printf("\t   [2]  Pengurangan\n");
	printf("\t   [3]  Perkalian\n");
	printf("\t   [4]  Pembagian\n");
	printf("\t   [5]  Modulus\n");
	printf("\t   [6]  Keluar\n");
	printf("\n...................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
	pilihan = validasi_halamanUtama();
   system("cls");
   switch (pilihan){ 
		case 1:
			Penjumlahan(); 
			break;
		case 2:
			Pengurangan();
			break;
		case 3:
			Perkalian(); 
			break;
		case 4:
			Pembagian();
			break;
		case 5:
			Modulus(); 
			break;
		default:
			printf("\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
			exit(0);
			break;
	}
} 

void Penjumlahan(){
	float bilangan1, bilangan2, hasil;
   int pilihan;
	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t\tPROGRAM PENJUMLAHAN\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Bilangan pertama	: ");
   bilangan1 = validasiFloatPenjumlahan();
   printf(" Bilangan kedua		: ");
   bilangan2 = validasiFloatPenjumlahan(); 
   printf("\t\t\t  ---------- (+) \n");
   hasil = hitungPenjumlahan(bilangan1, bilangan2); 
   printf("\t\t\t  %.2f\n", hasil);
   printf("\n...................................................\n");
   printf("1.Ulangi   2.Kembali   3.Keluar");
   printf("\n...................................................\n");
   printf("Masukkan Pilihan yang Tersedia: "); 
   pilihan = validasiPilihan();
   system("cls");
   switch(pilihan){
		case 1:
			Penjumlahan(); 
			break;
		case 2:
			halamanUtama();
			break;
		default: 
			printf("\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
			exit(0);
			break; 
	}
}

void Pengurangan(){
	float bilangan1, bilangan2, hasil; 
   int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t\tPROGRAM PENGURANGAN\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Bilangan pertama	: "); 
   bilangan1 = validasiFloatPengurangan();
   printf(" Bilangan kedua		: ");
   bilangan2 = validasiFloatPengurangan();
   printf("\t\t\t  ---------- (-) \n");
   hasil = hitungPengurangan(bilangan1, bilangan2);
   printf("\t\t\t  %.2f\n", hasil);
   printf("\n...................................................\n");
   printf("1.Ulangi   2.Kembali   3.Exit");
   printf("\n...................................................\n");
   printf("Masukkan Pilihan yang Tersedia: "); 
   pilihan = validasiPilihan();
   system("cls");
   switch(pilihan){ 
		case 1:
			Pengurangan();
			break;
		case 2:
			halamanUtama();
			break; 
		default: 
			printf("\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
			exit(0);
			break; 
	}
}
 
void Perkalian(){
   float bilangan1, bilangan2, hasil;
   int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t\tPROGRAM PERKALIAN\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Bilangan pertama	: ");
   bilangan1 = validasiFloatPerkalian();
   printf(" Bilangan kedua		: "); 
   bilangan2 = validasiFloatPerkalian();
   printf("\t\t\t  ---------- (X) \n");
   hasil = hitungPerkalian(bilangan1, bilangan2);
	printf("\t\t\t  %.2f\n", hasil);
   printf("\n...................................................\n");
   printf("1.Ulangi   2.Kembali   3.Exit");
   printf("\n...................................................\n");
   printf("Masukkan Pilihan yang Tersedia: "); 
   pilihan = validasiPilihan(); 
   system("cls");
   switch(pilihan){
		case 1:
			Perkalian();
			break; 
		case 2:
			halamanUtama();
			break;
		default: 
			printf("\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
			exit(0);
			break; 
	}
}

void Pembagian(){
	float bilangan1, bilangan2, hasil;
   int pilihan; 

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t\tPROGRAM PEMBAGIAN\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Bilangan pertama	: ");
   bilangan1 = validasiFloatPembagian(); 
   printf(" Bilangan kedua		: ");
   bilangan2 = validasiFloatPembagian();
   printf("\t\t\t  ---------- (:) \n");
   hasil = hitungPembagian(bilangan1, bilangan2);
   printf("\t\t\t  %.2f\n", hasil);
   printf("\n...................................................\n");
   printf("1.Ulangi   2.Kembali   3.Exit");
   printf("\n...................................................\n");
   printf("Masukkan Pilihan yang Tersedia: "); 
   pilihan = validasiPilihan();
   system("cls"); 
   switch(pilihan){
		case 1: 
			Pembagian();
			break;
		case 2:
			halamanUtama();
			break;
		default: 
			printf("\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
			exit(0);
			break; 
	}
}

void Modulus(){ 
	int bilangan1, bilangan2, hasil, pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t\tPROGRAM MODULUS\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Bilangan pertama	: ");
   bilangan1 = validasiModulus();
   printf(" Bilangan kedua		: ");
   bilangan2 = validasiModulus();
   printf("\t\t\t  ---------- (%%) \n");
   hasil = hitungModulus(bilangan1, bilangan2);
   printf("\t\t\t  %d\n", hasil);
   printf("\n...................................................\n");
   printf("1.Ulangi   2.Kembali   3.Exit");
   printf("\n...................................................\n");
   printf("Masukkan Pilihan yang Tersedia: "); 
   pilihan = validasiPilihan();
   system("cls"); 
   switch(pilihan){
		case 1:
			Modulus();
			break;
		case 2: 
			halamanUtama();
			break;
		default: 
			printf("\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
			exit(0);
			break; 
	} 
}
