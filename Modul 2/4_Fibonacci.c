#include <stdio.h>	//library untuk input output, seperti printf; scanf; puts
#include <stdlib.h>	//library untuk atoi dan atof
#include <conio.h>	//library untuk getch

int main();

//IDENTITAS KELOMPOK
void klp(){
	puts("\n\t\t\t\t\t|                (KELOMPOK 13)                   |");
	puts("\t\t\t\t\t|2105551023	I Ketut Putra Jaya               |");
	puts("\t\t\t\t\t|2105551052	Kadek Cahyadi Yogachandra        |");
	puts("\t\t\t\t\t|2105551102	Dyah Putri Maheswari             |");
	puts("\t\t\t\t\t|2105551104	Velicia Varrel Valiant           |");
	puts("\t\t\t\t\t|2105551105	Greace Amanda R.Y                |");
	puts("\t\t\t\t\t|2105551125	A.A. Sagung Mirah Indira Wardhana|");
}

//FUNGSI VALIDASI (TIDAK BISA MENGINPUT SELAIN ANGKA)
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

//FUNGSI REKURSIF FIBONACCI
int fiboRekursif(int bilangan){
	fflush(stdin);
   if (bilangan == 0 || bilangan == 1){
      return bilangan;
   }return fiboRekursif(bilangan - 2) + fiboRekursif(bilangan - 1);
}

//PROSEDUR REKURSIF FIBONACCI
void deretFiboRekursif(int jumlah_deret){
	printf("\n\n\tMasukkan jumlah deret yang diinginkan : ");
    jumlah_deret=validasi();
    printf("\n\t");
	fflush(stdin);
	for (int i = 0; i < jumlah_deret; i++){
    	printf("%d ", fiboRekursif(i));
	}printf("\n");
}

//PROSEDUR ITERATIF FIBONACCI
void deretFiboIteratif(int jumlah_deret){
	printf("\n\n\tMasukkan jumlah deret yang diinginkan : ");
    jumlah_deret=validasi();
    printf("\n\t");
	fflush(stdin);
	int bilangan1 = 0, bilangan2 = 1;
	int tampung;
	for (int i = 0; i < jumlah_deret; i++){
    	if (i == 0 || i == 1){
        	printf("%d ", i);
    	}else{
      		tampung = bilangan1 + bilangan2;
        	bilangan1 = bilangan2;
      		bilangan2 = tampung;
      		printf("%d ", tampung);
    	}
	}printf("\n");
}

void ulang1(){
	int pilihan, jumlah_deret;
	puts("\n\t\t\t\t\t     PILIH DI BAWAH INI");
	puts("\t\t\t\t     1.ULANGI  2.MENU UTAMA 3.KELUAR");
	printf("\t\t\t\t\t      Masukkan Pilihan: ");
	pilihan=validasi();
   	switch(pilihan){
   		case 1:
			system("cls");
    	  	deretFiboRekursif(jumlah_deret);
    	  	break;
 		case 2:
 			system("cls");
 	    	main();
 	    	break;
	   	case 3:
	   		system("cls");
	   		printf("Terima kasih telah mencoba program ini :D\n");
	      	exit(0);
	      	break;
	    default:
   			system("cls");
    	  	printf("PILIHAN TIDAK TERSEDIA! PROGRAM DIULANGI OTOMATIS");
    	  	main();
   		  	break;
	}ulang1();
}

void ulang2(){
	int pilihan, jumlah_deret;
	puts("\n\t\t\t\t\t     PILIH DI BAWAH INI");
	puts("\t\t\t\t     1.ULANGI  2.MENU UTAMA 3.KELUAR");
	printf("\t\t\t\t\t      Masukkan Pilihan: ");
	pilihan=validasi();
   	switch(pilihan){
   		case 1:
			system("cls");
    	  	deretFiboIteratif(jumlah_deret);
    	  	break;
 		case 2:
 			system("cls");
 	    	main();
 	    	break;
	   	case 3:
	   		system("cls");
	   		printf("Terima kasih telah mencoba program ini :D\n");
	      	exit(0);
	      	break;
	    default:
   			system("cls");
    	  	printf("PILIHAN TIDAK TERSEDIA! PROGRAM DIULANGI OTOMATIS");
    	  	main();
   		  	break;
	}ulang2;
}

//FUNGSI MAIN
int main(){
	int pilihan, jumlah_deret;
	klp();
	puts("==========================================================================================");
	puts("\t\t\t\tPROGRAM DERET FIBONACCI");
	puts("\t\t\t\t[1] Fibonacci Rekursif");
	puts("\t\t\t\t[2] Fibonacci Iteratif");
	puts("\t\t\t\t[3] Keluar Program");
	puts("==========================================================================================");
	printf("\tMasukkan Pilihan: ");
	pilihan = validasi();
	switch(pilihan){
		case 1:
   			deretFiboRekursif(jumlah_deret);
   			ulang1();
    	  	break;
	   	case 2:
   			deretFiboIteratif(jumlah_deret);
			ulang2();
			break;
		case 3:
			system("cls");
			exit(0);
			break;
   }
   return 0;
}
