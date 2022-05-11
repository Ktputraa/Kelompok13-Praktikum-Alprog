#include <stdio.h>	//library untuk input output, seperti printf; scanf; puts
#include <stdlib.h>	//library untuk atoi dan atof
#include <conio.h>	//library untuk getch

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

//FUNGSI VALIDASI (TIDAK BISA MENGINPUT SELAIN ANGKA DAN TITIK)
int validasiBunga(){
	char ch, *data; 
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

//FUNGSI MAIN
int main(){
	double biayapokok,angsuranPokok,bungaPinjaman,totalBunga=0,totalAngsuran=0, bunga;
	int durasiPinjam, i, pilihan;
	puts("\n------------------------------------------------------------------------------------------");
   puts("\t\t\t\tPROGRAM MENGHITUNG ANGSURAN PINJAMAN");
	puts("------------------------------------------------------------------------------------------");
	printf("Masukkan pokok pinjaman			: "); biayapokok=validasi();
	printf("\nMasukkan besar bunga			: "); bunga=validasiBunga();
	printf("\nDurasi meminjam (dalam bulan)		: "); durasiPinjam=validasi();
	system("cls");
	bunga = bunga/100; angsuranPokok = biayapokok/durasiPinjam;
   puts("------------------------------------------------------------------------------------------");
   puts("BULAN    \tBUNGA    \t\tANGSURAN POKOK  \t\tANGSURAN PERBULAN \t");
   puts("------------------------------------------------------------------------------------------");
   for(i = 1;i<=durasiPinjam;i++){
      bungaPinjaman = (biayapokok-((i-1)*angsuranPokok))*(bunga/12);
      totalBunga +=bungaPinjaman;
      totalAngsuran += (angsuranPokok+bungaPinjaman);
   	printf("%d    \t\tRp.%.2f    \t\tRp.%.2f \t\t\tRp.%.2f\n",i,bungaPinjaman,angsuranPokok,angsuranPokok+bungaPinjaman);
   }
   puts("------------------------------------------------------------------------------------------");
   printf("\t\t\t\tTOTAL BUNGA   : Rp.%.2f\n", totalBunga);
   printf("\t\t\t\tTOTAL ANGSURAN: Rp.%.2f\n", totalAngsuran);
   puts("------------------------------------------------------------------------------------------");
   puts("\n\t\t\t\t     ULANGI PROGRAM?");
	puts("\t\t\t\t     1. YA  2. TIDAK");
	printf("\t\t\t\t    Masukkan Pilihan: ");
	pilihan=validasi();
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
      	printf("PILIHAN TIDAK TERSEDIA! PROGRAM DIULANGI OTOMATIS");
      	main();
      	break;
	return 0;
	}
}
