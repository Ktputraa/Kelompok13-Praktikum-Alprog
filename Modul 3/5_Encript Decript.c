#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void ulang();

int validasiangka(){
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

int enkripsi(){
	char s[100];
	int i, key;
	printf("==============================================================================================================\n");
	printf("..............................................................................................................\n");
	printf("\n\t\t\tMasukan pesan yang akan dienkripsi	: ");
	gets(s);
	printf("\n\t\t\tMasukan jumlah pergeseran		: ");
	key=validasiangka();
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'A' && s[i] <= 'Z') {
        	s[i] = s[i] + 32;
      	}
      
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = s[i] + key;
			if(s[i] > 'z'){
				s[i] = s[i] - 26;
			}
			s[i] = s[i] -32;
		}
	}
	printf("\n\n\t\t\tHasil Enkripsi				: %s", s);
	return 0;
}

int dekripsi(){
	char s[100];
	int i, key;
	printf("==============================================================================================================\n");
	printf("..............................................................................................................\n");
	printf("\n\t\t\tMasukan Pesan yang akan didekripsi	: ");
	gets(s);
	printf("\n\t\t\tMasukan jumlah pergeseran		: ");
	key=validasiangka();
	for(i = 0; s[i] != '\0'; ++i){
		if(s[i] >= 'a' && s[i] <= 'z') {
        	s[i] = s[i] - 32;
      	}
      
		if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = s[i] - key;
			if(s[i] < 'A'){
				s[i] = s[i] + 26;
			}
			s[i] = s[i] +32;
		}
	}
	printf("\n\n\t\t\tHasil Dekripsi				: %s", s);
	return 0;
}

int main(){
	int pilihan;
	fflush(stdin);
	printf("..............................................................................................................\n\n");
	system("COLOR 0E");
	printf("\t(KELOMPOK 13)\n\n");
	printf("\t2105551023	I Ketut Putra Jaya\n");
	printf("\t2105551052	Kadek Cahyadi Yogachandra\n");
	printf("\t2105551102	Dyah Putri Maheswari\n");
	printf("\t2105551104	Velicia Varrel Valiant\n");
	printf("\t2105551105	Greace Amanda R.Y\n");
	printf("\t2105551125	A.A. Sagung Mirah Indira Wardhana\n\n");
	printf("==============================================================================================================\n");
	printf("..............................................................................................................\n");
	printf(".\t\t\t\t\t[PROGRAM ENKRIPSI DAN DEKRIPSI]\t\t\t\t     .\n");
	printf(".\t\t\t\t\t[1] Enkripsi                         \n");
	printf(".\t\t\t\t\t[2] Dekripsi                         \n");
	printf(".\t\t\t\t\t[3] Exit                         \n");
	printf("..............................................................................................................\n");
	printf("==============================================================================================================\n");

	printf("\tMasukkan Pilihan: ");
	pilihan = validasiangka();
	switch(pilihan){
		case 1:
   		system("cls");
   		printf("\n\t\t\t\t\t[PROGRAM ENKRIPSI]\t\t\t\t\n");
      	enkripsi();
      	break;
   	case 2:
   		system("cls");
   		printf("\n\t\t\t\t\t[PROGRAM DEKRIPSI]\t\t\t\t\n");
   		dekripsi();
   		break;
   	case 3:
   		system("cls");
   		printf("Terima kasih telah mencoba program ini :D\n");
   		exit(1);
   	default:
   		system("cls");
   		printf("Masukkan pilihan yang tersedia!\n");
   		main();
   }
	fflush(stdin);
	ulang();
}

void ulang(){
	int pilihan;
	printf("\n..............................................................................................................");
	printf("\n==============================================================================================================\n");
	printf("\t\t\tApakah anda ingin mengulang operasi?\n");
	printf("\t\t\t[1] Mengulang Program\n");
	printf("\t\t\t[2] Exit\n");
	fflush(stdin);
	printf("\t\t\tMasukkan pilihan yang tersedia : ");
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
