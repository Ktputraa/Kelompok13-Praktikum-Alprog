#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void start();
void judul();
void menu();
void lanjut();

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

int validasi(){
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
	}
	data [index]='\0';
	
	return atoi(data); 
}

void start(){
	int pilihan; 
	judul();
	printf("1. Lanjut ke program \n2. Keluar program\n\n"); 
	printf("=================================================\n");
	printf("Masukkan pilihan:"); 
	pilihan= validasi();
	system ("cls"); 
	
	switch (pilihan){
		case 1:  
			menu(); 
			break;
		case 2:
			exit(0);
			break; 
		default :
			printf ("Masukkan pilihan yang benar (1-2)\n");
			start();
	}

}

void judul(){
	int pilihan; 
	printf("=================================================\n\n");
	printf("             PROGRAM MENENTUKAN ZODIAK\n\n");
	printf("=================================================\n\n");
}

void menu(){
	int tanggal, bulan, tahun;
	judul();
	printf("Daftar Tanggal dan Bulan\n");
	printf("1. Januari (1-31) \t 7.  Juli(1-31)\n");
	printf("2. Februari (1-29)\t 8.  Agustus (1-31)\n");
	printf("3. Maret (1-31)   \t 9.  September (1-30)\n");
	printf("4. April (1-30)   \t 10. Oktober (1-31)\n");
	printf("5. Mei (1-31)     \t 11. November(1-30)\n");
	printf("6. Juni (1-30)    \t 12. Desember (1-31)\n\n");
	printf("===============================================\n");
	
	printf("Masukkan tanggal lahir: ");
	tanggal=validasi();
	
	printf("\nMasukkan bulan lahir  : ");
	bulan= validasi();
	
	printf("\nMasukkan tahun lahir  : ");
	tahun=validasi();
	printf("\n===============================================\n");
	printf("Tekan enter untuk melihat hasil . . .");  
	getchar();
	system("cls");
	judul();
	printf("\t\t Zodiak Anda adalah \n");
	if((tanggal>=21 && tanggal<=31 && bulan==3)||(tanggal>=1 && tanggal<=19 &&bulan==4)){
		printf("\t\t       ARIES\n");
	}
	else if ((tanggal>=20&&tanggal<=30&&bulan==4)||(tanggal>=1&&tanggal<=20&&bulan==5)){
		printf("\t\t       TAURUS\n");
	}
	else if((tanggal>=21&&tanggal<=31&&bulan==5)||(tanggal>=1&&tanggal<=20&&bulan==6)){
		printf("\t\t       GEMINI\n");
	}
	else if((tanggal>=21&&tanggal<=30&&bulan==6)||(tanggal>=1&&tanggal<=22&&bulan==7)){
		printf("\t\t       CANCER\n");
	}
	else if((tanggal>=23&&tanggal<=31&&bulan==7)||(tanggal>=1&&tanggal<=22&&bulan==8)){
		printf("\t\t        LEO\n");
	}
	else if((tanggal>=23&&tanggal<=31&&bulan==8)||(tanggal>=1&&tanggal<=22&&bulan==9)){
		printf("\t\t       VIRGO\n");
	}
	else if((tanggal>=23&&tanggal<=30&&bulan==9)||(tanggal>=1&&tanggal<=22&&bulan==10)){
		printf("\t\t       LIBRA\n");
	}
	else if((tanggal>=23&&tanggal<=31&&bulan==10)||(tanggal>=1&&tanggal<=21&&bulan==11)){
		printf("\t\t      SCORPIO\n");
	}
	else if((tanggal>=22&&tanggal<=30&&bulan==11)||(tanggal>=1&&tanggal<=21&&bulan==12)){
		printf("\t\t    SAGITTARIUS\n");
	}
	else if((tanggal>=22&&tanggal<=31&&bulan==12)||(tanggal>=1&&tanggal<=19&&bulan==1)){
		printf("\t\t     CAPRICORN\n");
	}
	else if((tanggal>=20&&tanggal<=31&&bulan==1)||(tanggal>=1&&tanggal<=18&&bulan==2)){
		printf("\t\t     AQUARIUS\n");
	}
	else if((tanggal>=19&&tanggal<=28&&bulan==2)||(tanggal>=1&&tanggal<=20&&bulan==3)){
		printf("\t\t        PISCES\n");
	}
	else if (tanggal==29&&(bulan==2 && tahun%4==0)){
		printf ("\t\t       PISCES\n");
	}
	else{
		printf("Zodiak tidak ditemukan\n");
	}
	lanjut();
}

void lanjut (){
	int pilihan; 
	printf("\n================================================\n");
	printf("1. Ulangi program \n2. Keluar program\n");
	printf("=================================================\n");
	printf("Masukkan pilihan:"); 
	pilihan = validasi(); 
	system ("cls"); 
	
	switch (pilihan){
	case 1:  
		menu(); 
		break;
	case 2:
		exit(0);
		break; 
	default :
		printf ("Masukkan pilihan yang benar (1-2)\n");
		start();
	}
	
}
