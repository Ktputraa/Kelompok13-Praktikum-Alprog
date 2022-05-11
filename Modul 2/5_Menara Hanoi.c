#include <stdio.h>	//library untuk input output, seperti printf; scanf; puts
#include <stdlib.h>	//library untuk atoi dan atof
#include <conio.h>	//library untuk getch
#include <math.h>		//library untuk operasi matematika, seperti pow (untuk menghitung pangkat)

char tower[3] = {'A', 'B', 'C'};

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

//PROSEDUR MENARA HANOI REKURSIF
void hanoiRekursif(int jumlah_cakram, int from, int middle, int to){
   if (jumlah_cakram > 0){
   	hanoiRekursif(jumlah_cakram - 1, from, to, middle);
      printf("\t\t\t    Memindahkan piringan dari %c ke %c\n", tower[from], tower[to]);
      hanoiRekursif(jumlah_cakram - 1, middle, from, to);
   }
}

//PROSEDUR MENARA HANOI ITERATIF
void hanoiIteratif(int total_langkah){
   for (int i = 1; i < total_langkah; i++){
   	printf("\t\t\t    Memindahkan piringan dari %c ke %c\n", tower[(i - (i & -i)) % 3], tower[(i + (i & -i)) % 3]);
   }
}

//FUNGSI MAIN
int main(){
   int pilihan, jumlah_cakram, total_langkah;
   klp();
	puts("==========================================================================================");
   puts("\t\t\t\tPROGRAM DERET FIBONACCI");
   puts("\t\t\t\t[1] Menara Hanoi Rekursif");
   puts("\t\t\t\t[2] Menara Hanoi Iteratif");
   puts("\t\t\t\t[3] Keluar Program");
	puts("==========================================================================================");
	printf("\tMasukkan Pilihan	: ");
	pilihan = validasi();
	switch(pilihan){
		case 1:
			system("cls");
			puts("\t\t\t\t    [METODE REKURSIF]");
			printf("\n\tMasukkan banyak cakram	: ");
			jumlah_cakram=validasi();
			total_langkah = (int)pow(2, jumlah_cakram);
			printf("\n\n");
         hanoiRekursif(jumlah_cakram, 0, 1, 2);
         break;
      case 2:
      	system("cls");
      	puts("\t\t\t\t    [METODE ITERATIF]");
      	printf("\n\n\tMasukkan banyak cakram	: ");
			jumlah_cakram=validasi();
			total_langkah = (int)pow(2, jumlah_cakram);
			printf("\n\n");
         hanoiIteratif(total_langkah);
         break;
   	case 3:
   		system("cls");
   		printf("Terima kasih telah mencoba program ini :D\n");
   		exit(1);
   	default:
   		system("cls");
   		printf("\tMasukkan pilihan yang tersedia!\n");
   		main();
   }
	printf("\n\t\t     Jumlah langkah minimum yang dibutuhkan adalah %d\n\n", total_langkah - 1);
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
   }
   return 0;
}
