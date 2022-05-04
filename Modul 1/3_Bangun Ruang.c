#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <conio.h>
#define PHI 3.14

//  PROSEDUR
void halamanUtama();
void luasPermukaanBangunRuang();
void volumeBangunRuang();
void lPTabung();
void lPBola();
void lPLimasSegiEmpat();
void lPPrismaSegitiga();
void lPKerucut();
void vTabung();
void vBola();
void vLimasSegiEmpat();
void vPrismaSegitiga();
void vKerucut();

//MAIN
int main(){
	system("COLOR F0");
   halamanUtama();
   return 0;
}

//FUNGSI LUAS PERMUKAAN
float hitung_LPTabung(float jari, float tinggi){
	float luas = (2*PHI*(jari*jari))+(2*PHI*jari*tinggi);
	return luas;
}
float hitung_LPBola(float jari){
	float luas = 4*PHI*jari*jari;
	return luas;
}
float hitung_LPLimasSegiEmpat(float sisi, float tinggi){
	float tinggiSegitiga = sqrt(pow(sisi/2,2) + pow(tinggi,2));
	float luas = (sisi*sisi)+(4*(0.5*sisi*tinggiSegitiga));
	return luas;
}
float hitung_LPPrismaSegitiga(float tinggi, float sisi1, float sisi2, float sisi3){
	float s = (sisi1+sisi2+sisi3)/2;
	float luas = (tinggi*(sisi1+sisi2+sisi3))+(2*sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3)));
	return luas;
}
float hitung_LPKerucut(float jari, float tinggi){
	float pelukis = sqrt(pow(jari,2) + pow(tinggi,2));
	float luas = (PHI*(jari*jari))+(PHI*jari*pelukis);
	return luas;
}

//FUNGSI VOLUME
float hitung_VTabung(float jari, float tinggi){
	float vol = PHI*(jari*jari)*tinggi;
	return vol;
}
float hitung_VBola(float jari){
	float vol = 4.0/3.0*PHI*jari*jari*jari;
	return vol;
}
float hitung_VLimasSegiEmpat(float sisi, float tinggi){
	float vol = 1.0/3.0*(sisi*sisi)*tinggi;
	return vol;
}
float hitung_VPrismaSegitiga(float sisi1, float sisi2, float sisi3, float tinggi){
	float s = (sisi1+sisi2+sisi3)/2.0;
	float vol = (sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3)))*tinggi;
	return vol;
}
float hitung_VKerucut(float jari, float tinggi){
	float vol = 1.0/3.0*PHI*jari*jari*tinggi;
	return vol;
}

//FUNGSI VALIDASI INPUT
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
      val = atoi(angka);
      if(val>=1 && val<=6){
      	return val;
      }else{
         printf("\n [WARNING! MENU TIDAK ADA]\n Masukkan Pilihan yang Tersedia: ");
         validasi_halamanUtama();
      }
   }
}

int validasiPilihan() {
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

float validasiBil(){
	
	char ch; 
	char *data; 
	data= (char *) malloc (sizeof(char)); 
	
	int index=0;
	
	while ((ch=getch()) !=13) {
		if (ch>='0' && ch<='9'){
			printf("%c", ch); 
			data[index]=ch; 
			index++;
		}
		else if (ch==46){
				printf("%c", ch); 
				data[index]=ch; 
				index++;
		}
	}
	data [index]='\0';
		
	return atof(data); 
	
}

//PROSEDUR
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
	printf("\t    PERHITUNGAN LUAS & VOLUME \n\t\t  BANGUN RUANG\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	printf("===================================================\n\n");
	printf("\t   [D A F T A R  P I L I H A N]\n\n");
	printf("\t   [1]  Luas Bangun Ruang\n");
	printf("\t   [2]  Volume Bangun Ruang\n");
	printf("\t   [3]  Keluar\n");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
   switch (pilihan){
	   case 1:
	   	luasPermukaanBangunRuang();
	   	break;
	   case 2:
	   	volumeBangunRuang();
	   	break;
	   default:
      	printf("TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI :D\n");
      	exit(0);
	   	break;
	}
}

//Luas Permukaan Bangun Ruang
void luasPermukaanBangunRuang(){
  	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("     PERHITUNGAN LUAS PERMUKAAN BANGUN RUANG\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\t   [D A F T A R  P I L I H A N]\n\n");
   printf("\t   [1]  TABUNG\n");
	printf("\t   [2]  BOLA\n");
	printf("\t   [3]  LIMAS SEGI EMPAT\n");
	printf("\t   [4]  PRISMA SEGITIGA\n");
	printf("\t   [5]  KERUCUT\n");
	printf("\t   [6]  Kembali\n");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasi_halamanUtama();
   system("cls");
   switch (pilihan){
	   case 1:
	   	lPTabung();
	   	break;
	   case 2:
	   	lPBola();
	   	break;
	   case 3:
	   	lPLimasSegiEmpat();
	   	break;
	   case 4:
	   	lPPrismaSegitiga();
	   	break;
	   case 5:
	   	lPKerucut();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	 }
}

void lPTabung(){
   float jari, tinggi, luas;
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("      PERHITUNGAN LUAS PERMUKAAN TABUNG\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Masukkan Panjang Jari-jari (cm)	: ");
   jari = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   luas = hitung_LPTabung(jari, tinggi);
   printf("\n Luas Permukaan Tabung adalah		: %.2f cm2\n",luas);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf("\n Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	lPTabung();
	   	break;
		case 2:
	   	luasPermukaanBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

void lPBola(){
   float jari, luas;
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("       PERHITUNGAN LUAS PERMUKAAN BOLA\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n Masukkan Panjang Jari-jari (cm)	: ");
   jari = validasiBil();
   luas = hitung_LPBola(jari);
   printf("\n Luas Permukaan Bola adalah		: %.2f cm2\n",luas);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf("\n Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	lPBola();
	   	break;
	   case 2:
	   	luasPermukaanBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

void lPLimasSegiEmpat(){
   float sisi, tinggi, luas;
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("   PERHITUNGAN LUAS PERMUKAAN LIMAS SEGI EMPAT\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n Masukkan Panjang Sisi Alas (cm)	: ");
   sisi = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   luas = hitung_LPLimasSegiEmpat( sisi, tinggi);
   printf("\n Luas Permukaan Limas Segi Empat adalah	: %.2f cm2\n",luas);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	lPLimasSegiEmpat();
	   	break;
	   case 2:
	   	luasPermukaanBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

void lPPrismaSegitiga(){
   float tinggi, sisi1, sisi2, sisi3, luas;
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("    PERHITUNGAN LUAS PERMUKAAN PRISMA SEGITIGA\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   printf("\n Masukkan Panjang Sisi a Segitiga (cm)	: ");
   sisi1 = validasiBil();
   printf("\n Masukkan Panjang Sisi b Segitiga (cm)	: ");
   sisi2 = validasiBil();
   printf("\n Masukkan Panjang Sisi c Segitiga (cm)	: ");
   sisi3 = validasiBil();
   luas = hitung_LPPrismaSegitiga(tinggi, sisi1, sisi2, sisi3);
   printf("\n Luas Permukaan Prisma Segitiga adalah	: %.2f cm2\n",luas);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	lPPrismaSegitiga();
	   	break;
	   case 2:
	   	luasPermukaanBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

void lPKerucut(){
   float jari, tinggi, luas;
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("	  PERHITUNGAN LUAS PERMUKAAN KERUCUT\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n Masukkan Panjang Jari-jari (cm)	: ");
   jari = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   luas = hitung_LPKerucut( jari, tinggi);
   printf("\n Luas Permukaan Kerucut adalah		: %.2f cm2\n",luas);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf("\n Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	lPKerucut();
	   	break;
	   case 2:
	   	luasPermukaanBangunRuang();
			break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

//Volume Bangun Ruang
void volumeBangunRuang(){
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\tPERHITUNGAN VOLUME BANGUN RUANG\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\t   [D A F T A R  P I L I H A N]\n\n");
   printf("\t   [1]  TABUNG\n");
	printf("\t   [2]  BOLA\n");
	printf("\t   [3]  LIMAS SEGI EMPAT\n");
	printf("\t   [4]  PRISMA SEGITIGA\n");
	printf("\t   [5]  KERUCUT\n");
	printf("\t   [6]  Kembali\n");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasi_halamanUtama();
   system("cls");
	switch (pilihan){
	   case 1:
	   	vTabung();
	   	break;
	   case 2:
	   	vBola();
	   	break;
	   case 3:
	   	vLimasSegiEmpat();
	   	break;
	   case 4:
	   	vPrismaSegitiga();
	   	break;
	   case 5:
	   	vKerucut();
	   	break;
	   default:
	   	halamanUtama();
	   break;
	}

}

// Volume Tabung
void vTabung(){
	float jari, tinggi, vol;
	int pilihan;
	
	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t   PERHITUNGAN VOLUME TABUNG\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Masukkan Panjang Jari-Jari Alas (cm)	: ");
   jari = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   vol = hitung_VTabung(jari, tinggi);
   printf("\n Volume Tabung adalah			: %.2f cm3\n",vol);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf("\n Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	vTabung();
	   	break;
	   case 2:
	   	volumeBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

// Volume Bola
void vBola(){
   float jari, vol;
   int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t     PERHITUNGAN VOLUME BOLA\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf("\n Masukkan Panjang Jari-Jari (cm)	: ");
   jari = validasiBil();
   vol = hitung_VBola(jari);
   printf("\n Volume Bola adalah			: %.2f cm3\n",vol);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama\n");
	printf("....................................................\n");
	printf("\n Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	vBola();
	   	break;
	   case 2:
	   	volumeBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

// Volume Limas Segi Empat
void vLimasSegiEmpat(){
	float tinggi, sisi, vol;
	int pilihan;

   	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t PERHITUNGAN VOLUME LIMAS SEGI EMPAT\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Masukkan Panjang Sisi Alas (cm)	: ");
   sisi = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   vol = hitung_VLimasSegiEmpat( sisi, tinggi);
   printf("\n Volume Limas Segi Empat adalah		: %.2f cm3\n",vol);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	vLimasSegiEmpat();
	   	break;
	   case 2:
	   	volumeBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

// Volume Prisma Segitiga
void vPrismaSegitiga(){
	float sisi1, sisi2, sisi3, tinggi, vol;
	int pilihan;

   printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t PERHITUNGAN VOLUME PRISMA SEGITIGA\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Masukkan Panjang Sisi 1 Segitiga (cm)	: ");
   sisi1 = validasiBil();
   printf("\n Masukkan Panjang Sisi 2 Segitiga (cm)	: ");
   sisi2 = validasiBil();
   printf("\n Masukkan Panjang Sisi 3 Segitiga (cm)	: ");
   sisi3 = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   vol = hitung_VPrismaSegitiga(sisi1, sisi2, sisi3, tinggi);
   printf("\n Volume Prisma Segitiga adalah		: %.2f cm3\n",vol);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	vPrismaSegitiga();
	   	break;
	   case 2:
	   	volumeBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}

// Volume Kerucut
void vKerucut(){
	float jari, tinggi, vol;
	int pilihan;

	printf(":::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	printf("\t   PERHITUNGAN VOLUME KERUCUT\n");
	printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
   printf(" Masukkan Panjang Jari-Jari (cm)	: ");
   jari = validasiBil();
   printf("\n Masukkan Tinggi (cm)			: ");
   tinggi = validasiBil();
   vol = hitung_VKerucut( jari, tinggi);
   printf("\n Volume Kerucut adalah			: %.2f cm3\n",vol);
   printf("\n....................................................\n");
   printf("    1.Ulangi      2.Kembali       3.Halaman Utama");
	printf("\n....................................................\n");
	printf(" Masukkan Pilihan yang Tersedia: ");
   pilihan = validasiPilihan();
   system("cls");
	switch(pilihan){
	   case 1:
	   	vKerucut();
	   	break;
	   case 2:
	   	volumeBangunRuang();
	   	break;
	   default:
	   	halamanUtama();
	   	break;
	}
}
