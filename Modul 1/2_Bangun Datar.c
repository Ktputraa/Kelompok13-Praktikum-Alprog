#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#include <conio.h>
#define PI 3.14

void start();
void pilihanBangunDatar();
void luasBangunDatar();
void kelilingBangunDatar();
void luasSegitigaSembarang();
void luasBelahKetupat();
void luasJajarGenjang();
void luasTrapesium();
void luasLingkaran();
void kelilingSegitigaSembarang();
void kelilingBelahKetupat();
void kelilingJajarGenjang();
void kelilingTrapesium();
void kelilingLingkaran();
void lanjut();
void lanjut2();

int main(){
	system("COLOR F0");
	printf("=================================================\n");
	printf("           KELOMPOK 13 PRAKTIKUM ALPROG          \n\n");
	printf("  2105551023-I Ketut Putra Jaya\n");
	printf("  2105551052-Kadek Cahyadi Yogachandra\n");
	printf("  2105551102-Dyah Putri Maheswari\n");
	printf("  2105551104-Velicia Varrel Valiant\n");
	printf("  2105551105-Greace Amanda R.Y\n");
	printf("  2105551125-A.A. Sagung Mirah Indira Wardhana\n");
	printf("=================================================\n\n");
	start();
	return 0;
}

//Validasi
int validasi(){
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
	}
	data [index]='\0';
		
	return atoi(data); 
}
float validasiBil(){
	char ch; 
	char *data; 
	data= (char *) malloc (sizeof(char)); 
	
	int index=0;
	
	while ((ch=_getch()) !=13) {
		if (ch>='0' && ch<='9'){
			printf("%c", ch); 
			data[index]=ch; 
			index++;
		}
		else if (ch=='.'){
			printf("%c", ch); 
			data[index]=ch; 
			index++;
		}
	}
	data [index]='\0';
		
	return atof(data); 
}

//Starting program
void start(){
	int pilihan;
	
	printf("=================================================\n\n");
	printf(" PROGRAM MENGHITUNG LUAS & KELILING BANGUN DATAR \n\n");
	printf("=================================================\n\n");
	printf(" 1. Hitung luas bangun datar \n 2. Hitung keliling bangun datar \n 3. Keluar\n\n");
	printf("=================================================\n\n");
	printf ("Masukkan pilihan : ");
	pilihan= validasi();
	system("cls");

	switch (pilihan){
		case 1:
			luasBangunDatar();
			break;
		case 2:
 			kelilingBangunDatar();
 			break;
 		case 3:
 			exit(0);
 			break;
 		default: 
			printf("\nMasukkan pilihan yang benar! (1-3)\n\n");	
			start(); 
	}
	
}

//Pilihan Menu
void pilihanBangunDatar(){
	printf("=================================================\n\n");
	printf("           Pilihan Bangun Datar \n\n");
	printf("=================================================\n\n");
	printf(" 1. Segitiga Sembarang \n 2. Belah Ketupat \n 3. Jajar Genjang \n 4. Trapesium \n 5. Lingkaran \n 6. Kembali \n 7. Keluar\n\n");
	printf("=================================================\n\n");
}
void luasBangunDatar(){
	pilihanBangunDatar();
	int pilihan;
	printf("Masukkan pilihan bangun datar yang akan dihitung luasnya: ");
	pilihan=validasi();
	system("cls");
	
	switch(pilihan){
		case 1:
			luasSegitigaSembarang();
			break; 
		case 2:
			luasBelahKetupat();
			break; 
		case 3:
			luasJajarGenjang();
			break; 
		case 4:
			luasTrapesium();
			break; 
		case 5:
			luasLingkaran();
			break; 
		case 6:
 			start();
 			break;
	 	case 7:
 			exit(0);
 			break;
		default: 
			printf("\nMasukkan pilihan yang benar! (1-7)\n\n");
			luasBangunDatar();
			break;
	}
	lanjut();
		
}
void kelilingBangunDatar(){
	pilihanBangunDatar();
	
	int pilihan;
	
	printf("Masukkan pilihan bangun datar yang akan dihitung kelilingnya: ");
	pilihan=validasi();
	system("cls");
	
		switch(pilihan){
		case 1:
			kelilingSegitigaSembarang();
			break; 
		case 2:
			kelilingBelahKetupat();
			break; 
		case 3:
			kelilingJajarGenjang();
			break; 
		case 4:
			kelilingTrapesium();
			break; 
		case 5:
			kelilingLingkaran();
			break; 
		case 6:
 			start();
 			break;
	 	case 7:
 			exit(0);
 			break;
		default: 
			printf("Masukkan pilihan yang benar! (1-7)\n\n");
			luasBangunDatar();
			break;
	}	
	lanjut2();
}

//Penghitungan dan print hasil luas
void luasSegitigaSembarang(){
	printf("=================================================\n\n");
	printf("       Menghitung Luas Segitiga Sembarang \n\n");
	printf("=================================================\n\n");
	
	float sisi1, sisi2, sisi3; 
	printf("Masukkan panjang sisi ke-1: ");
	sisi1= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-2: ");
	sisi2= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-3: ");
	sisi3= validasiBil();
	
	float s = (sisi1+sisi2+sisi3)/2;
	float luas = sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3));
	
	printf("\n\nLuas segitiga sembarang adalah %f", luas);
}
void luasBelahKetupat(){
	printf("=================================================\n\n");
	printf("          Menghitung Luas Belah Ketupat \n\n");
	printf("=================================================\n\n");
	
	float d1, d2; 
	printf("Masukkan diagonal1: ");
	d1= validasiBil();
	printf("\n");
	printf("Masukkan diagonal2: ");
	d2=validasiBil();
	
	float luas= d1*d2/2;
	printf ("\n\nLuas bangun belah ketupat adalah %f", luas);
	
}
void luasJajarGenjang(){
	printf("=================================================\n\n");
	printf("          Menghitung Luas Belah Ketupat \n\n");
	printf("=================================================\n\n");
	
	float alas, tinggi; 
	printf("Masukkan alas: ");
	alas= validasiBil(); 
	printf("\n");
	printf("Masukkan tinggi: ");
	tinggi= validasiBil();
	float luas = alas*tinggi;
	printf ("\n\nLuas bangun jajar genjang adalah %f", luas);
}
void luasTrapesium(){
	printf("=================================================\n\n");
	printf("            Menghitung Luas Trapesium \n\n");
	printf("=================================================\n\n");
	
	float sisi1, sisi2, tinggi;
	printf("Masukkan panjang sisi ke-1: ");
	sisi1= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-2: ");
	sisi2= validasiBil();
	printf("\n");
	printf("Masukkan panjang tinggi: ");
	tinggi= validasiBil();
	float luas =(sisi1+sisi2)*tinggi/2;
	printf ("\n\nLuas bangun trapesium adalah %f", luas);
	
}
void luasLingkaran(){
	printf("=================================================\n\n");
	printf("         Menghitung Luas Lingkaran \n\n");
	printf("=================================================\n\n");
	
	float r;
	printf("Masukkan nilai jari-jari: ");
	r= validasiBil(); 
	float luas = PI*r*r;
	printf ("\n\nLuas bangun lingkaran adalah %f", luas);
	
}
//Penghitungan dan print hasil keliling
void kelilingSegitigaSembarang(){
	printf("=================================================\n\n");
	printf("     Menghitung Keliling Segitiga Sembarang \n\n");
	printf("=================================================\n\n");
	
	float sisi1, sisi2, sisi3;
	printf("Masukkan panjang sisi ke-1: ");
	sisi1= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-2: ");
	sisi2= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-3: ");
	sisi3= validasiBil();
	float keliling = sisi1+sisi2+sisi3;
	printf("\n\nKeliling bangun lingkaran adalah %f", keliling);
}
void kelilingBelahKetupat(){
	printf("=================================================\n\n");
	printf("        Menghitung Keliling Belah Ketupat \n\n");
	printf("=================================================\n\n");
	
	float sisi; 
	printf("Masukkan panjang sisi: ");
	sisi= validasiBil();
	float keliling = 4*sisi;
	printf("\n\nKeliling bangun belah ketupat adalah %f", keliling);
}
void kelilingJajarGenjang(){
	printf("=================================================\n\n");
	printf("        Menghitung Keliling Jajar Genjang \n\n");
	printf("=================================================\n\n");
	
	float sisialas, sisimiring;
	printf("Masukkan panjang sisi alas: ");
	sisialas= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi miring: ");
	sisimiring= validasiBil();
	float keliling = 2*(sisialas+sisimiring);
	printf("\n\nKeliling bangun jajar genjang adalah %f", keliling);
}
void kelilingTrapesium(){
	printf("=================================================\n\n");
	printf("          Menghitung Keliling Trapesium \n\n");
	printf("=================================================\n\n");
	
	float sisi1, sisi2, sisi3, sisi4;
	printf("Masukkan panjang sisi ke-1: ");
	sisi1= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-2: ");
	sisi2= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-3: ");
	sisi3= validasiBil();
	printf("\n");
	printf("Masukkan panjang sisi ke-4: ");
	sisi4= validasiBil();
	float keliling =sisi1+sisi2+sisi3+sisi4;
	printf ("\n\nKeliling bangun trapesium adalah %f", keliling);
}
void kelilingLingkaran(){
	printf("=================================================\n\n");
	printf("          Menghitung Keliling Lingkaran \n\n");
	printf("=================================================\n\n");
	
	float r;
	printf("Masukkan nilai jari- jari: ");
	r= validasiBil(); 
	printf("\n");
	float keliling = 2*PI*r;
	printf ("\n\nKeliling bangun lingkaran adalah %f", keliling);
}

//Lanjutan
void lanjut(){
	int pilihan; 
	printf("\n\n=================================================\n");
	printf (" 1.Menu utama \n 2.Kembali \n 3.Keluar");
	printf("\n=================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			start();
		case 2:
			luasBangunDatar();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-2)");
			lanjut();
	}
}
void lanjut2(){
	int pilihan; 
	printf("\n\n=================================================\n");
	printf (" 1.Menu utama \n 2.Kembali \n 3.Keluar");
	printf("\n=================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			start();
		case 2:
			kelilingBangunDatar();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-2)");
			lanjut2();
	}
}
