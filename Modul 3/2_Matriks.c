#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

void judul();
void start();
void menu();
void penjumlahan();
void perkalian();
void transpose();
void lanjut();
void lanjut2();
void lanjut3();

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
		else if (ch=='-'){
			printf("%c", ch); 
			data[index]=ch; 
			index++;
		}
	}
	data [index]='\0';
	return atoi(data); 
}

void judul(){
	int pilihan; 
	printf("=================================================\n\n");
	printf("       PROGRAM OPERASI MATEMATIKA MATRIKS\n");
	printf("     (PENJUMLAHAN, PERKALIAN DAN TRANSPOSE)\n\n");
	printf("=================================================\n\n");
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

void menu (){
	int pilihan; 
	judul();
	printf("Daftar operasi matriks: \n");
	printf("1. Penjumlahan\n");
	printf("2. Perkalian \n");
	printf("3. Transpose\n");
	printf("4. Keluar program\n");
	printf("\n=================================================\n");
	printf("Masukkan pilihan:"); 
	pilihan= validasi();
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			penjumlahan();
			break;
		case 2 : 
			perkalian();
			break; 
		case 3: 
			transpose(); 
			break; 
		case 4: 
			exit (0); 
			break;
		default :
			printf ("Masukkan pilihan yang benar (1-4)\n");
			menu();
	}
}

void penjumlahan(){
	int baris, kolom, i, j, matriks1[30][30], matriks2[30][30], matriks3[30][30]; 
		
	printf("=================================================\n\n");
	printf("           Operasi Penjumlahan Matriks \n\n");
	printf("=================================================\n");	
	printf("Masukkan jumlah baris pada matriks: ");
	baris= validasi(); 
	printf("\nMasukkan jumlah kolom pada matriks: ");
	kolom=validasi(); 
	printf("\n=================================================");
	
	for (i=1;i<=baris; i++){
		for (j=1; j<=kolom; j++){
			printf ("\nMasukkan nilai matriks1 [%d][%d]: ",i,j);
			matriks1[i][j]= validasi();
		}
	}
	printf("\nMatriks1:");
	for (i=1;i<=baris; i++ ){
		printf("\n");
		for (j=1;j<=kolom;j++){
			printf(" %d\t", matriks1[i][j]);
		}
	}
	printf("\n=================================================");	
	for (i=1;i<=baris; i++){
		for (j=1; j<=kolom; j++){
			printf ("\nMasukkan nilai matriks2 [%d][%d]: ",i,j);
			matriks2[i][j]= validasi();
		}
	}
	printf("\nMatriks2:");
	for (i=1;i<=baris; i++ ){
		printf("\n");
		for (j=1;j<=kolom;j++){
			printf(" %d\t", matriks2[i][j]);
		}
	}
	printf("\n=================================================\n");
	printf("\nTekan enter untuk melihat hasil . . .");  
	getchar();
	system ("cls"); 
	judul();
	printf ("Hasil penjumlahan matriks adalah ");
	for (i=1;i<=baris; i++ ){
		printf("\n");
		for (j=1;j<=kolom;j++){
			matriks3[i][j]= matriks1[i][j]+ matriks2[i][j];
			printf(" %d\t", matriks3[i][j]);
		}
	}
	lanjut();
}

void perkalian (){
	int baris, kolom, baris2, kolom2, i, j, k, matriks1[30][30], matriks2[30][30], matriks3[30][30], jumlah=0; 
		
	printf("=================================================\n\n");
	printf("            Operasi Perkalian Matriks \n\n");
	printf("=================================================\n");
	printf("Masukkan jumlah baris pada matriks: ");
	baris= validasi(); 
	printf("\nMasukkan jumlah kolom pada matriks: ");
	kolom=validasi(); 
	baris2=kolom;
	kolom2=baris;
	printf("\n=================================================");
	printf ("\nMatriks1 adalah matriks %d x %d \nMatriks2 adalah matriks %d x %d", baris, kolom,baris2, kolom2);
	printf("\n=================================================");
	
	for (i=1;i<=baris; i++){
		for (j=1; j<=kolom; j++){
			printf ("\nMasukkan nilai matriks1 [%d][%d]: ",i,j);
			matriks1[i][j]= validasi();
		}
	}
	printf("\nMatriks1:");
	for (i=1;i<=baris; i++){
		printf("\n");
		for (j=1;j<=kolom;j++){
			printf(" %d\t", matriks1[i][j]);
		}
	}
	printf("\n=================================================");	
	for (i=1;i<=baris2; i++){
		for (j=1; j<=kolom2; j++){
			printf ("\nMasukkan nilai matriks2 [%d][%d]: ",i,j);
			matriks2[i][j]= validasi();
		}
	}
	printf("\nMatriks2:");
	for (i=1;i<=baris2; i++){
		printf("\n");
		for (j=1;j<=kolom2;j++){
			printf(" %d\t", matriks2[i][j]);
		}
	}
	for (i=1;i<=baris; i++ ){
		for (j=1;j<=kolom2; j++){
			for (k=1; k<=baris2; k++){
				jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
			}
			matriks3[i][j] = jumlah;
			jumlah = 0;
		}
	}
	printf("\n=================================================\n");
	printf("\nTekan enter untuk melihat hasil . . .");  
	getchar();
	system ("cls"); 
	judul();
	printf ("Hasil perkalian matriks adalah ");
	for (i=1; i<=baris; i++){
		printf("\n");
		for (j=1;j<=kolom2; j++){
			printf (" %d\t", matriks3[i][j]);
		}
	}
	lanjut2();
}

void transpose (){
	int baris, kolom, i, j, matriks1[30][30], matriks2[30][30]; 
		
	printf("=================================================\n\n");
	printf("           Operasi Transpose Matriks \n\n");
	printf("=================================================\n");
	printf("Masukkan jumlah baris pada matriks: ");
	baris= validasi(); 
	printf("\nMasukkan jumlah kolom pada matriks: ");
	kolom=validasi(); 
	printf("\n=================================================");
	for (i=1;i<=baris; i++){
		for (j=1; j<=kolom; j++){
			printf ("\nMasukkan nilai matriks [%d][%d]: ",i,j);
			matriks1[i][j]= validasi();
		}
	}
	printf("\nMatriks:");
	for (i=1;i<=baris; i++ ){
		printf("\n");
		for (j=1;j<=kolom;j++){
			printf(" %d\t", matriks1[i][j]);
		}
	}
	for (i=1;i<=baris; i++){
		for (j=1;j<=kolom;j++ ){
			matriks2[j][i]= matriks1[i][j]; 
		}
	}
	printf("\n=================================================\n");
	printf("\nTekan enter untuk melihat hasil . . .");  
	getchar();
	system ("cls"); 
	judul();
	printf ("Hasil transpose matriks adalah ");
	for (i=1;i<=kolom; i++){
		printf("\n");
		for (j=1; j<=baris; j++){
			printf(" %d\t", matriks2[i][j]);
		}
	} 
	lanjut3();
}

void lanjut(){
	int pilihan; 
	
	printf("\n\n=================================================\n");
	printf (" 1.Menu utama \n 2.Kembali \n 3.Keluar program");
	printf("\n=================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			menu();
		case 2:
			penjumlahan();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-3)");
			lanjut();
	}
}
void lanjut2(){
	int pilihan; 
	
	printf("\n\n=================================================\n");
	printf (" 1.Menu utama \n 2.Kembali \n 3.Keluar program");
	printf("\n=================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			menu();
		case 2:
			perkalian();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-3)");
			lanjut2();
	}
}
void lanjut3(){
	int pilihan; 
	
	printf("\n\n=================================================\n");
	printf (" 1.Menu utama \n 2.Kembali \n 3.Keluar program");
	printf("\n=================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			menu();
		case 2:
			transpose();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-3)");
			lanjut3();
	}
}
