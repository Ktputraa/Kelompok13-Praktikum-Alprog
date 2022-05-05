#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void judul();
void start();
void sorting();
void sorting1000();
void sorting16000();
void sorting64000();
void searching();
void searching1000();
void searching16000();
void searching64000();
void menu ();
void lanjut(); 
void lanjut2(); 

void swap(int *i1, int *i2){
	int temp = *i1;
	*i1 = *i2;
	*i2 = temp;
}
void bubbleSort(int arr[], int size){
	int i,a;
	for(i=0;i<size-1;i++){
		int flag = 0;
		for(a=0;a<size-i-1;a++){
			if(arr[a]>arr[a+1]){
				swap(&arr[a], &arr[a+1]);
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
	}
}
int Partition(int *A, int start, int end){
	int pivot =A[end];
	int i;
	int partitionIndex = start;
	for(i = start;i<end;i++){
		if(A[i]<=pivot){
			swap(&A[partitionIndex], &A[i]);
			partitionIndex++;
		}
	}
	swap(&A[partitionIndex], &A[end]);
	return partitionIndex;
}
void quickSort(int *A, int start, int end){
	if(start < end){
		int partitionIndex = Partition(A,start,end);
		quickSort(A,start,partitionIndex-1);
		quickSort(A,partitionIndex+1,end);
	}
}
void insertionSort(int angka[], int size){
	int i,j,patokan;

	for(i=1; i<size; i++){
		patokan = angka[i];

		j = i - 1;

		while(j >= 0 && angka[j] > patokan){
			angka[j+1] = angka[j];
			j--;
		}

		angka[j+1] = patokan;
	}
}

double sequentialSearch(int angka[], int size, int angkaDicari){
	clock_t waktu;
	double waktu_dibutuhkan;
	int i, counter=0;

	waktu = clock();
	for(i=0; i<size; i++){
		if(i == size - 1){
			angka[i];
		}
		else{
			angka[i];
		}
		if(angka[i] == angkaDicari){
			counter++;
		}
	}
	waktu = clock() - waktu;
	waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

	if(counter == 0){
		printf("\nTidak ada angka yang sesuai pada pencarian SEQUENTIAL SEARCH");
	}
	else{
		int indexAngkaDicari[counter];
		counter = 0;

		for(i=0; i<size; i++){
			if(angka[i] == angkaDicari){
				indexAngkaDicari[counter] = i;
				counter++;
			}
		}

		printf("\nAngka ditemukan pada index:");
		for(i=0; i<counter; i++){
			if(i == 0 && i == counter - 1 ){
				printf(" %d.", indexAngkaDicari[i]);
			}
			else{
				if(i == counter - 1 ){
					printf(" dan %d.", indexAngkaDicari[i]);
				}
				else{
					printf(" %d,", indexAngkaDicari[i]);
				}
			}
		}
	}
	return waktu_dibutuhkan;
}

double binarySearch(int angka[], int terkecil, int terbesar, int angkaDicari){
	clock_t waktu;
	double waktu_dibutuhkan;
	int i, counter=0;

	waktu = clock();
	while(terkecil <= terbesar){
		int tengah = terkecil + (terbesar - terkecil) / 2;

		if(angka[tengah] == angkaDicari){
			counter++;
			for(i = tengah + 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
				counter++;
			}
			for(i = tengah - 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
				counter++;
			}
			break;
		}
		else if(angka[tengah] > angkaDicari){
			terbesar = tengah - 1;
		}
		else{
			terkecil = tengah + 1;
		}
	}
	waktu = clock() - waktu;
	waktu_dibutuhkan = (double)(waktu) / CLOCKS_PER_SEC;

	if(counter == 0){
		printf("\nTidak ada angka yang sesuai pada pencarian BINARY SEARCH");
	}
	else{
		int indexAngkaDicari[counter];
		counter = 0;

		while(terkecil <= terbesar){
			int tengah = terkecil + (terbesar - terkecil) / 2;

			if(angka[tengah] == angkaDicari){
				indexAngkaDicari[counter] = tengah;
				counter++;
				for(i = tengah + 1; i < terbesar + 1 && angka[i] == angkaDicari; i++){
					indexAngkaDicari[counter] = i;
					counter++;
				}
				for(i = tengah - 1; i > 0 && angka[i] == angkaDicari; i--){
					indexAngkaDicari[counter] = i;
					counter++;
				}
				break;
			}
			else if(angka[tengah] > angkaDicari){
				terbesar = tengah - 1;
			}
			else{
				terkecil = tengah + 1;
			}
		}

		printf("\nAngka ditemukan pada index:");
		bubbleSort(indexAngkaDicari, counter);
		for(i=0; i<counter; i++){
			if(i == 0 && i == counter - 1 ){
				printf(" %d.", indexAngkaDicari[i]);
			}
			else{
				if(i == counter - 1 ){
					printf(" dan %d.", indexAngkaDicari[i]);
				}
				else{
					printf(" %d,", indexAngkaDicari[i]);
				}
			}
		}
	}

	return waktu_dibutuhkan;
}

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
	printf("         PROGRAM SORTING DAN SEARCHING\n\n");
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
	printf(" 1. Program Sorting\n");
	printf(" 2. Program Searching \n");
	printf(" 3. Kembali\n");
	printf(" 4. Keluar program\n");
	printf("\n=================================================\n");
	printf("Masukkan pilihan:"); 
	pilihan= validasi();
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			sorting();
			break;
		case 2 : 
			searching();
			break; 
		case 3: 
			main(); 
			break;
		case 4: 
			exit (0); 
			break;
		default :
			printf ("Masukkan pilihan yang benar (1-4)\n");
			menu();
	}
}

void sorting (){
	int pilihan; 
	
	printf("=================================================\n\n");
	printf("                 PROGRAM SORTING \n\n");
	printf("=================================================\n\n");
	printf(" 1. 1000 Angka\n");
	printf(" 2. 16000 Angka\n");
	printf(" 3. 64000 Angka\n");
	printf(" 4. Kembali\n");
	printf(" 5. Keluar program\n");
	printf("\n=================================================\n");
	printf("Masukkan pilihan:"); 
	pilihan= validasi();
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			sorting1000();
			break; 
		case 2: 
			sorting16000();
			break; 
		case 3: 
			sorting64000();
			break; 
		case 4: 
			menu();
			break; 
		case 5: 
			exit(0);
			break; 
		default :
			printf ("Masukkan pilihan yang benar (1-5)\n");
			sorting();
	}	
	lanjut();
}

void sorting1000(){
	int angka[1000], temp[1000];
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i;
	int size;
	int menu;
	int exit = 1;
				
	system("cls");
	size = sizeof(angka) / sizeof(angka[0]);
	srand((unsigned) time(NULL));

	for(i=0; i<size; i++){
		angka[i] = rand();
		temp[i] = angka[i];
	}
			
	//Insertion Sort
	waktu = clock();
	insertionSort(temp, size);
	waktu = clock() - waktu;
				
	waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;
	
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	
	//Bubble Sort
	waktu = clock();
	bubbleSort(temp, size);
	waktu = clock() - waktu;
	waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;
	
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	//Quick Sort
	waktu = clock();
	quickSort(temp,0, size-1);
	waktu = clock() - waktu;
	waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;
		
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	
	printf("\n\t\t\t\t\t\t>>>Daftar angka random<<< \n");
	printf ("Tekan enter untuk melihat hasil . . . ");
	getch();
	system("cls"); 
	
	printf("=====================================================================================\n");
	printf("INSERTION SEARCH membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[0]);
	printf("BUBBLE SORT membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[1]);
	printf("QUICK SORT membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[2]);
	printf("=====================================================================================\n\n");
	
	if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT membutuhkan waktu lebih cepat dari BUBBLE SORT dan QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[0] == waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT dan BUBBLE SORT membutuhkan waktu lebih cepat dari QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] == waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT dan QUICK SORT membutuhkan waktu lebih cepat dari BUBBLE SORT<<<");
	}
	else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT membutuhkan waktu lebih cepat dari INSERTION SORT dan QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[1] == waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT dan INSERTION SORT membutuhkan waktu lebih cepat dari QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] == waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT dan QUICK SORT membutuhkan waktu lebih cepat dari INSERTION SORT<<<");
	}
	else if(waktu_dibutuhkan[2] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[2] <= waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT membutuhkan waktu lebih cepat dari INSERTION SORT dan BUBBLE SORT <<<");
	}
	else if(waktu_dibutuhkan[2] == waktu_dibutuhkan[0] && waktu_dibutuhkan[2] <= waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT dan INSERTION SORT membutuhkan waktu lebih cepat dari  BUBBLE SORT <<<");
	}
	else if(waktu_dibutuhkan[2] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[2] == waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT dan BUBBLE SORT membutuhkan waktu lebih cepat dari INSERTION SORT <<<");
	}
}
void sorting16000(){
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i;
	int size;
	int menu;
	int angka[16000], temp[16000];
				
	system("cls");
	size = sizeof(angka) / sizeof(angka[0]);
	srand((unsigned) time(NULL));
				
	for(i=0; i<size; i++){
		angka[i] = rand();
		temp[i] = angka[i];
	}
				
	//Insertion Sort
	waktu = clock();
	insertionSort(temp, size);
	waktu = clock() - waktu;
	
	waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;
	
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	//Bubble Sort
	waktu = clock();
	bubbleSort(temp, size);
	waktu = clock() - waktu;
	waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;
	
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	//Quick Sort
	waktu = clock();
	quickSort(temp,0, size-1);
	waktu = clock() - waktu;
	waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;
		
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	printf("\n\t\t\t\t\t\t>>>Daftar angka random<<< \n");
	printf ("Tekan enter untuk melihat hasil . . . ");
	getch();
	system("cls"); 
	
/*
waktu_dibutuhkan[0]= INSERTION SORT
waktu_dibutuhkan[1]= BUBBLE SORT
waktu_dibutuhkan[2]= QUICK SORT
*/
	
	printf("=====================================================================================\n");
	printf("INSERTION SEARCH membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[0]);
	printf("BUBBLE SORT membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[1]);
	printf("QUICK SORT membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[2]);
	printf("=====================================================================================\n\n");
	
	if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT membutuhkan waktu lebih cepat dari BUBBLE SORT dan QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[0] == waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT dan BUBBLE SORT membutuhkan waktu lebih cepat dari QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] == waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT dan QUICK SORT membutuhkan waktu lebih cepat dari BUBBLE SORT<<<");
	}
	else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT membutuhkan waktu lebih cepat dari INSERTION SORT dan QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[1] == waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT dan INSERTION SORT membutuhkan waktu lebih cepat dari QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] == waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT dan QUICK SORT membutuhkan waktu lebih cepat dari INSERTION SORT<<<");
	}
	else if(waktu_dibutuhkan[2] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[2] <= waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT membutuhkan waktu lebih cepat dari INSERTION SORT dan BUBBLE SORT <<<");
	}
	else if(waktu_dibutuhkan[2] == waktu_dibutuhkan[0] && waktu_dibutuhkan[2] <= waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT dan INSERTION SORT membutuhkan waktu lebih cepat dari  BUBBLE SORT <<<");
	}
	else if(waktu_dibutuhkan[2] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[2] == waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT dan BUBBLE SORT membutuhkan waktu lebih cepat dari INSERTION SORT <<<");
	}

}


void sorting64000(){
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i;
	int size;
	int menu;
	int angka[64000], temp[64000];
				
	system("cls");
	size = sizeof(angka) / sizeof(angka[0]);
	srand((unsigned) time(NULL));
				
	for(i=0; i<size; i++){
		angka[i] = rand();
		temp[i] = angka[i];
	}
				
	//Insertion Sort
	waktu = clock();
	insertionSort(temp, size);
	waktu = clock() - waktu;
	
	waktu_dibutuhkan[0] = (double)(waktu) / CLOCKS_PER_SEC;
	
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	//Bubble Sort
	waktu = clock();
	bubbleSort(temp, size);
	waktu = clock() - waktu;
	waktu_dibutuhkan[1] = (double)(waktu) / CLOCKS_PER_SEC;
	
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	//Quick Sort
	waktu = clock();
	quickSort(temp,0, size-1);
	waktu = clock() - waktu;
	waktu_dibutuhkan[2] = (double)(waktu) / CLOCKS_PER_SEC;
		
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", temp[i]);
		}
		else{
			printf(" %d,", temp[i]);
		}
		temp[i] = angka[i];
	}
	printf("\n\t\t\t\t\t\t>>>Daftar angka random<<< \n");
	printf ("Tekan enter untuk melihat hasil . . . ");
	getch();
	system("cls"); 
	
	printf("=====================================================================================\n");
	printf("INSERTION SEARCH membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[0]);
	printf("BUBBLE SORT membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[1]);
	printf("QUICK SORT membutuhkan %f detik untuk mensortir data\n", waktu_dibutuhkan[2]);
	printf("=====================================================================================\n\n");
	
	if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT membutuhkan waktu lebih cepat dari BUBBLE SORT dan QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[0] == waktu_dibutuhkan[1] && waktu_dibutuhkan[0] <= waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT dan BUBBLE SORT membutuhkan waktu lebih cepat dari QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[0] <= waktu_dibutuhkan[1] && waktu_dibutuhkan[0] == waktu_dibutuhkan[2]){
		printf(">>> INSERTION SORT dan QUICK SORT membutuhkan waktu lebih cepat dari BUBBLE SORT<<<");
	}
	else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT membutuhkan waktu lebih cepat dari INSERTION SORT dan QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[1] == waktu_dibutuhkan[0] && waktu_dibutuhkan[1] <= waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT dan INSERTION SORT membutuhkan waktu lebih cepat dari QUICK SORT <<<");
	}
	else if(waktu_dibutuhkan[1] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[1] == waktu_dibutuhkan[2]){
		printf(">>> BUBBLE SORT dan QUICK SORT membutuhkan waktu lebih cepat dari INSERTION SORT<<<");
	}
	else if(waktu_dibutuhkan[2] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[2] <= waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT membutuhkan waktu lebih cepat dari INSERTION SORT dan BUBBLE SORT <<<");
	}
	else if(waktu_dibutuhkan[2] == waktu_dibutuhkan[0] && waktu_dibutuhkan[2] <= waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT dan INSERTION SORT membutuhkan waktu lebih cepat dari  BUBBLE SORT <<<");
	}
	else if(waktu_dibutuhkan[2] <= waktu_dibutuhkan[0] && waktu_dibutuhkan[2] == waktu_dibutuhkan[1]){
		printf(">>> QUICK SORT dan BUBBLE SORT membutuhkan waktu lebih cepat dari INSERTION SORT <<<");
	}
}

void searching (){
	int pilihan; 
	
	printf("=================================================\n\n");
	printf("                PROGRAM SEARCHING \n\n");
	printf("=================================================\n\n");
	printf(" 1. 1000 Angka\n");
	printf(" 2. 16000 Angka\n");
	printf(" 3. 64000 Angka\n");
	printf(" 4. Kembali\n");
	printf(" 5. Keluar\n");
	printf("\n=================================================\n");
	printf("Masukkan pilihan:"); 
	pilihan= validasi();
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			searching1000();
			break; 
		case 2: 
			searching16000();
			break; 
		case 3: 
			searching64000();
			break; 
		case 4: 
			menu();
			break; 
		case 5: 
			exit(0);
			break; 
		default :
			printf ("Masukkan pilihan yang benar (1-5)\n");
			searching();
	}
	lanjut2();
}
void searching1000(){
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i;
	int size;
	int angkaDicari;
	int angka[1000], temp[1000];
	system("cls");
	size = sizeof(angka) / sizeof(angka[0]);
	srand((unsigned) time(NULL));

	for(i=0; i<size; i++){
		angka[i] = rand();
	}
				
	quickSort(angka, 0, size-1);
	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", angka[i]);
		}
		else{
			printf(" %d,", angka[i]);
		}
	temp[i] = angka[i];
	}
	
	printf("\nMasukkan angka yang ingin dicari: ");
	angkaDicari=validasi();
	system("cls"); 
	printf("=======================================================================");

	waktu_dibutuhkan[0] = sequentialSearch(angka, size, angkaDicari);
	waktu_dibutuhkan[1] = binarySearch(angka, 0, size-1, angkaDicari);
	printf("\n=======================================================================\n");
	printf("SEQUENTIAL SEARCH membutuhkan waktu %f detik untuk mencari data\n", waktu_dibutuhkan[0]);
	printf("BINARY SEARCH membutuhkan waktu %f detik untuk mencari data\n", waktu_dibutuhkan[1]);
	printf("=======================================================================\n\n");
	
	if(waktu_dibutuhkan[0] < waktu_dibutuhkan[1]){
		printf("     >>>SEQUENTIAL SEARCH lebih cepat dari pada BINARY SEARCH<<<");
	}
	else if(waktu_dibutuhkan[0] == waktu_dibutuhkan[1]){
		printf(">>>Waktu yang dibutuhkan SEQUENTIAL SEARCH sama dengan BINARY SEARCH<<<");
	}
	else if (waktu_dibutuhkan[0] > waktu_dibutuhkan[1]){
		printf("     >>>SEQUENTIAL SEARCH lebih cepat dari pada BINARY SEARCH<<<");
	}
}
void searching16000(){
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i;
	int size;
	int angkaDicari;
	int angka[16000], temp[16000];
	system("cls");
	size = sizeof(angka) / sizeof(angka[0]);
	srand((unsigned) time(NULL));

	for(i=0; i<size; i++){
		angka[i] = rand();
	}

	quickSort(angka, 0, size-1);

	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", angka[i]);
		}
		else{
			printf(" %d,", angka[i]);
		}
	}	

	printf("\nMasukkan angka yang ingin dicari: ");
	angkaDicari=validasi();
	

	system("cls"); 
	printf("=======================================================================");
	waktu_dibutuhkan[0] = sequentialSearch(angka, size, angkaDicari);
	waktu_dibutuhkan[1] = binarySearch(angka, 0, size-1, angkaDicari);
	printf("\n=======================================================================\n");
	printf("SEQUENTIAL SEARCH membutuhkan waktu %f detik untuk mencari data\n", waktu_dibutuhkan[0]);
	printf("BINARY SEARCH membutuhkan waktu %f detik untuk mencari data\n", waktu_dibutuhkan[1]);
	printf("=======================================================================\n\n");
	
	if(waktu_dibutuhkan[0] < waktu_dibutuhkan[1]){
		printf("     >>>SEQUENTIAL SEARCH lebih cepat dari pada BINARY SEARCH<<<");
	}
	else if(waktu_dibutuhkan[0] == waktu_dibutuhkan[1]){
		printf(">>>Waktu yang dibutuhkan SEQUENTIAL SEARCH sama dengan BINARY SEARCH<<<");
	}
	else if (waktu_dibutuhkan[0] > waktu_dibutuhkan[1]){
		printf("     >>>SEQUENTIAL SEARCH lebih cepat dari pada BINARY SEARCH<<<");
	}
}
void searching64000(){
	clock_t waktu;
	double waktu_dibutuhkan[3];
	int i;
	int size;
	int angkaDicari;
	int angka[64000], temp[64000];
	system("cls");
	size = sizeof(angka) / sizeof(angka[0]);
	srand((unsigned) time(NULL));
	
	for(i=0; i<size; i++){
		angka[i] = rand();
	}

	quickSort(angka, 0, size-1);

	for(i=0; i<size; i++){
		if(i == size - 1){
			printf(" dan %d.", angka[i]);
		}
		else{
			printf(" %d,", angka[i]);
		}
	}	

	printf("\nMasukkan angka yang ingin dicari: ");
	angkaDicari=validasi();
	
	system("cls"); 
	printf("=======================================================================");

/*
waktu_dibutuhkan[0]= SEQUENTIAL SEARCH
waktu_dibutuhkan[1]= BINARY SEARCH
*/
	waktu_dibutuhkan[0] = sequentialSearch(angka, size, angkaDicari);
	waktu_dibutuhkan[1] = binarySearch(angka, 0, size-1, angkaDicari);
	printf("\n=======================================================================\n");
	printf("SEQUENTIAL SEARCH membutuhkan waktu %f detik untuk mencari data\n", waktu_dibutuhkan[0]);
	printf("BINARY SEARCH membutuhkan waktu %f detik untuk mencari data\n", waktu_dibutuhkan[1]);
	printf("=======================================================================\n\n");
	
	if(waktu_dibutuhkan[0] < waktu_dibutuhkan[1]){
		printf("     >>>SEQUENTIAL SEARCH lebih cepat dari pada BINARY SEARCH<<<");
	}
	else if(waktu_dibutuhkan[0] == waktu_dibutuhkan[1]){
		printf(">>>Waktu yang dibutuhkan SEQUENTIAL SEARCH sama dengan BINARY SEARCH<<<");
	}
	else if (waktu_dibutuhkan[0] > waktu_dibutuhkan[1]){
		printf("     >>>SEQUENTIAL SEARCH lebih cepat dari pada BINARY SEARCH<<<");
	}
}

void lanjut2(){
	int pilihan; 
	
	printf("\n\n=======================================================================\n");
	printf (" 1. Menu utama\n 2. Kembali \n 3. Keluar");
	printf("\n=======================================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			start();
		case 2:
			searching();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-3)");
			lanjut2();
	}
}

void lanjut(){
	int pilihan; 
	
	printf("\n\n=====================================================================================\n");
	printf (" 1. Menu utama\n 2. Kembali\n 3. Keluar");
	printf("\n=====================================================================================\n");
	printf ("Masukkan pilihan: ");
	pilihan= validasi(); 
	system ("cls"); 
	
	switch (pilihan){
		case 1: 
			start();
		case 2:
			sorting();
		case 3:
			exit(0);
		default :
			printf("Masukkan pilihan yang benar! (1-3)");
			lanjut();
	}
}
int main(){
	system("COLOR F0");
	printf("=================================================\n");
	printf("           KELOMPOK 13 PRAKTIKUM ALPROG          \n");
	printf("  2105551023-I Ketut Putra Jaya\n");
	printf("  2105551052-Kadek Cahyadi Yogachandra\n");
	printf("  2105551102-Dyah Putri Maheswari\n");
	printf("  2105551104-Velicia Varrel Valiant\n");
	printf("  2105551105-Greace Amanda R.Y\n");
	printf("  2105551125-A. A. Sagung Mirah Indira Wardhana\n");
	printf("=================================================\n\n");
	start();
	return 0;
}
