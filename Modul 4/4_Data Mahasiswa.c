#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int reset;
typedef char data[100];
typedef struct{
    data nama;
    data nim;
}mahasiswa;

struct Mahasiswa{
    int nim;
	char nama[50];
};

int inputMenu(int *select) {
    char buff[1024];
    char term;
    if (fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", select, &term) == 1) {
 	   if (*select < 1 || *select > 6) {
            printf("Pilihan hanya dari 1 sampai 6 !\n");
            return 0;
        }
	return 1;
    }
    printf("Inputan Salah, Masukkan Angka!\n");
    return 0;
}

int validationMenu(int *variabel, char *statement) {
    while (1) {
    	printf(statement);
    	if(inputMenu(variabel))
			break;
	}
}

int inputMenuPilih(int *chooseAgain) {
    char buff[1024];
    char term;
    if (fgets(buff, sizeof(buff), stdin) != NULL && sscanf(buff, "%d %c", chooseAgain, &term) == 1) {
		if (*chooseAgain < 1 || *chooseAgain > 3) {
            printf("Input pilihan metode 1 sampai 3 !\n");
            return 0;
        }
    return 1;
    }
    printf("Inputan Salah, Masukkan Angka!\n");
    return 0;
}

int validationMenuPilih(int *varInt, char *promptInt) {
    while (1) {
        printf(promptInt);
        if (inputMenuPilih(varInt))
            break;
    }
}

float input(int desimal, int min, int batas_akhir){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int minus = 0;
    int salah = 0;
    float hasil;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[0] == '.'){
            salah = 1;
            masukan[0] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' || masukan[i] == '.' || (masukan[0] == '-' && min == 1)){
            if((masukan[i] == '.') && (desimal == 1)){
                titik = titik + 1;
                if(titik > 1 || masukan[i+1] == '\0'){
                    salah = 1;
                    masukan[i] = '\0';
                }
                status = 1;
            }else if((masukan[i] == '.') && (desimal == 0)){
                salah = 1;
                masukan[i] = '\0';
            }
            
            if(masukan[0] == '-' && min == 1){
                minus = 1;
            }else if(masukan[0] == '-' && min == 0){
                salah = 1;
                masukan[i] = '\0';
            }

            if(masukan[i]>='0' && masukan[i]<='9'){
                if(status == 1){
                    isi_belakang = (isi_belakang * 10) + (masukan[i] - 48);
                    belakang = belakang + 1;
                }else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }
    if(titik == 1){
        hasil = (float)isi_depan + (isi_belakang / (pow(10, belakang)));
    }else{
        hasil = isi_depan;
    }

    
    if(minus == 1 && min == 1){
        hasil = hasil - (hasil * 2);
    }else if(minus == 1 && min == 0){
        salah = 1;
        masukan[i] = '\0';
    }

    if(salah == 1){
        printf("Input salah!\nMasukkan pilihan : ");
        return input(desimal, min, batas_akhir);
    }else if(min == 0 && hasil == 0){
        printf("Input tidak boleh 0 !\nMasukkan pilihan : ");
        return input(desimal, min, batas_akhir);
    }else if(batas_akhir != 0 && hasil > batas_akhir){
        printf("Input tidak boleh lebih dari %d !\nMasukkan pilihan : ", batas_akhir);
        return input(desimal, min, batas_akhir);
    }else{
        return hasil;
    }
}

int clear(){
	while(getchar() != '\n');
	return 1;
}

void setDefaultDataTmp(struct Mahasiswa data_tmp[]){
    int i;
    for(i = 0; i < 100; i++){
        data_tmp[i].nim = 0;
    }
}

int validasiNim(){
    char masukan[100];
    int i = 0;
    int salah = 0;
    int hasil = 0;

    scanf("%[^\n]", &masukan);
    fflush(stdin);

    while(masukan[i] != '\0'){
        if(masukan[i] >= '0' && masukan[i] <= '9'){
            hasil = (hasil * 10) + (masukan[i] - 48);
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        printf("NIM berupa angka!\nMasukkan NIM : ");
        return validasiNim();
    }
	else if(i != 10){
        printf("NIM harus 10 digit!\nMasukkan NIM : ");
        return validasiNim();
    }
	else{
        return hasil;
    }
}

int validasiNama(char masukan[]){
    int i = 0;
    int salah = 0;

    while(masukan[i] != '\0'){
        if((masukan[i] >= 65 && masukan[i] <= 90) || (masukan[i] >= 97 && masukan[i] <= 122) || masukan[i] == ' ' || masukan[i] == '.' || masukan[i] == ','){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
    }

    if(salah == 1){
        return 0;
    }else{
        return 1;
    }
}

int cekNim(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if(data.nim == data_tmp[i].nim){
            ditemukan = 1;
            break;
        }
		else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int cekNimEdit(struct Mahasiswa data, struct Mahasiswa data_tmp[], int jumlah, int nomorEdit){
    int i;
    int ditemukan = 0;

    for(i = 0; i < jumlah; i++){
        if((data.nim == data_tmp[i].nim) && (data_tmp[i].nim != data_tmp[nomorEdit].nim)){
            ditemukan = 1;
            break;
        }
		else{
            ditemukan = 0;
        }
    }

    return ditemukan;
}

int prosesReadDataTmp(struct Mahasiswa data_tmp[]){
    int jumlah = 0;

    FILE *read_tmp = fopen("dataMahasiswa.txt","r");
    if(!read_tmp){
        jumlah = 1;
    }
	else{
	    while(!feof(read_tmp)){
	   	    fscanf(read_tmp,"%d#%[^\n]\n", &data_tmp[jumlah].nim, &data_tmp[jumlah].nama);
            jumlah++;
	    }
    }
	fclose(read_tmp);

    return jumlah;
}

void prosesInputData(struct Mahasiswa data){
    FILE *tambah = fopen("dataMahasiswa.txt", "a");
	fprintf(tambah,"%d#%s\n", data.nim, data.nama);
	fclose(tambah);
}

void prosesShowData(struct Mahasiswa data_tmp[], int jumlah){
    int i;
    if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("Tidak Ada Data\n");
    }
	else{
        for(i = 0; i < jumlah; i++){
            printf("[%d] %d - %s			  	  |\n", i+1, data_tmp[i].nim, data_tmp[i].nama);
        }
    }
}

void prosesUpdateData(struct Mahasiswa data_edit, struct Mahasiswa data_tmp[], int jumlah, int nomorEdit){
    int i, j;
    data_tmp[nomorEdit].nim = data_edit.nim;
    for(i = 0; i < 50; i++){
        data_tmp[nomorEdit].nama[i] = data_edit.nama[i];
    }

    FILE *perbaharui = fopen("dataMahasiswa.txt","w");
    for(i = 0; i < jumlah; i++){
        fprintf(perbaharui, "%d#%s\n", data_tmp[i].nim, data_tmp[i].nama);
    }
    fclose(perbaharui);
}

void prosesDeleteData(struct Mahasiswa data_tmp[], int jumlah, int nomorHapus){
    int i;
    FILE *hapus = fopen("dataMahasiswa.txt","w");
    for(i = 0; i < jumlah; i++){
        if(i == nomorHapus){
            continue;
        }
		else{
            fprintf(hapus, "%d#%s\n", data_tmp[i].nim, data_tmp[i].nama);
        }
    }
    fclose(hapus);
}


void tambah_data(){
    int statusNim;
    int statusNama;
    struct Mahasiswa data;
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);

    int jumlah = prosesReadDataTmp(data_tmp);  
    printf("===================================================\n");
    printf("|                PROGRAM MAHASISWA                |\n");
	printf("***************************************************\n");
	printf("|              TAMBAH DATA MAHASISWA              |\n");
	printf("===================================================\n");
	printf("Masukkan NIM  : ");
    data.nim = validasiNim();

    statusNim = cekNim(data, data_tmp, jumlah);
    while(statusNim == 1){
        printf("NIM Sudah Terdaftar !\nMasukkan NIM : ");
        data.nim = validasiNim();
        statusNim = cekNim(data, data_tmp, jumlah);
    }

	printf("Masukan Nama  : ");
    scanf("%[^\n]", &data.nama);
    fflush(stdin);

    statusNama = validasiNama(data.nama);
    while(statusNama == 0){
        printf("Input nama salah !\nMasukkan Nama : ");
        scanf("%[^\n]", &data.nama);
        fflush(stdin);
        statusNama = validasiNama(data.nama);
    }
    prosesInputData(data);
	printf("\n\n============================\n");
    printf("|Data Berhasil Ditambahkan!|\n");
	printf("============================\n");
    printf("|NIM  : %d	   |\n", data.nim);
    printf("|Nama : %s		   |\n", data.nama);
	printf("============================\n");

	printf("\n\n============================");
	printf("\n|\tMENU PILIHAN\t   |\n");
	printf("============================\n");
	printf("|1. Kembali ke Menu Utama  |\n");
	printf("|2. Ulang\t\t   |\n");
	printf("|3. Keluar\t\t   |\n");
	printf("============================\n");	
  	validationMenuPilih(&reset, "Pilihan anda : ");
    if (reset == 1) {
       	system("cls");
       	main();
    }else if (reset == 2) {
     	system("cls");
        tambah_data();
    }else if (reset == 3) {
    	system("cls");
        printf("\n------------------------------");
       	printf("\n|\tTERIMA KASIH\t     |\n");
       	printf("------------------------------\n");
    }
}


void lihat_data(){
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);

    int jumlah = prosesReadDataTmp(data_tmp);
	printf("===================================================\n");
    printf("|                PROGRAM MAHASISWA                |\n");
	printf("***************************************************\n");
	printf("|               LIHAT DATA MAHASISWA              |\n");
	printf("===================================================\n");
    prosesShowData(data_tmp, jumlah);

    if(jumlah != 1 || data_tmp[0].nim != 0){
 		printf("===================================================\n");
        printf("|Jumlah Data : %d				  |", jumlah);
    }
	printf("\n===================================================\n");

	printf("\n\n============================");
	printf("\n|\tMENU PILIHAN\t   |\n");
	printf("============================\n");
	printf("|1. Kembali ke Menu Utama  |\n");
	printf("|2. Ulang\t\t   |\n");
	printf("|3. Keluar\t\t   |\n");
	printf("============================\n");	
  	validationMenuPilih(&reset, "Pilihan anda : ");
    if (reset == 1) {
       	system("cls");
       	main();
    }else if (reset == 2) {
     	system("cls");
        lihat_data();
    }else if (reset == 3) {
    	system("cls");
        printf("\n------------------------------");
       	printf("\n|\tTERIMA KASIH\t     |\n");
       	printf("------------------------------\n");
    }
}

void edit_data(){
    int statusNim, statusNama;
    struct Mahasiswa data_edit;
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = prosesReadDataTmp(data_tmp);
    int nomorEdit = 0;
	printf("===================================================\n");
    printf("|                PROGRAM MAHASISWA                |\n");
	printf("***************************************************\n");
	printf("|               EDIT DATA MAHASISWA               |\n");
	printf("===================================================\n");
    prosesShowData(data_tmp, jumlah);
	printf("===================================================\n");
    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("Pilih data (1 - %d) : ", jumlah);
        nomorEdit = input(0, 0, jumlah);
        nomorEdit = nomorEdit - 1;

		printf("\n============================\n");
        printf("   Masukkan Data yang Baru\n\n");
	    printf("Masukkan NIM  : ");
        data_edit.nim = validasiNim();

        statusNim = cekNimEdit(data_edit, data_tmp, jumlah, nomorEdit);
        while(statusNim == 1){
            printf("NIM sudah terdaftar !\nMasukkan NIM : ");
            data_edit.nim = validasiNim();
            statusNim = cekNimEdit(data_edit, data_tmp, jumlah, nomorEdit);
        }

	    printf("Masukkan Nama : ");
        scanf("%[^\n]", &data_edit.nama);
        fflush(stdin);

        statusNama = validasiNama(data_edit.nama);
        while(statusNama == 0){
            printf("Input salah !\nMasukkan Nama : ");
            scanf("%[^\n]", &data_edit.nama);
            fflush(stdin);
            statusNama = validasiNama(data_edit.nama);
        }
        prosesUpdateData(data_edit, data_tmp, jumlah, nomorEdit);
		printf("============================\n");
	    printf("| Data berhasil Di Update! |\n");
    }
	else if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("Masukan Data Terlebih Dahulu !\n");
    }
	printf("============================");

	printf("\n\n============================");
	printf("\n|\tMENU PILIHAN\t   |\n");
	printf("============================\n");
	printf("|1. Kembali ke Menu Utama  |\n");
	printf("|2. Ulang\t\t   |\n");
	printf("|3. Keluar\t\t   |\n");
	printf("============================\n");	
  	validationMenuPilih(&reset, "Pilihan anda : ");
    if (reset == 1) {
       	system("cls");
       	main();
    }else if (reset == 2) {
     	system("cls");
        edit_data();
    }else if (reset == 3) {
    	system("cls");
        printf("\n------------------------------");
       	printf("\n|\tTERIMA KASIH\t     |\n");
       	printf("------------------------------\n");
    }
}

void hapus_data(){
    struct Mahasiswa data_tmp[100];
    setDefaultDataTmp(data_tmp);
    int jumlah = prosesReadDataTmp(data_tmp);
    int nomorHapus = 0;
	printf("===================================================\n");
    printf("|                PROGRAM MAHASISWA                |\n");
	printf("***************************************************\n");
	printf("|               HAPUS DATA MAHASISWA              |\n");
	printf("===================================================\n");
	prosesShowData(data_tmp, jumlah);
	printf("===================================================\n");
    if(jumlah != 1 || data_tmp[0].nim != 0){
        printf("Pilih data : (1 - %d) : ", jumlah);
        nomorHapus = input(0, 0, jumlah);
        nomorHapus = nomorHapus - 1;
    	printf("============================\n");
    	prosesDeleteData(data_tmp, jumlah, nomorHapus);
        printf("|  Data Berhasil Dihapus!  |\n");
    }
	else if(jumlah == 1 && data_tmp[0].nim == 0){
        printf("Masukan Data Terlebih Dahulu\n");
    }
	printf("============================\n");

	printf("\n\n============================");
	printf("\n|\tMENU PILIHAN\t   |\n");
	printf("============================\n");
	printf("|1. Kembali ke Menu Utama  |\n");
	printf("|2. Ulang\t\t   |\n");
	printf("|3. Keluar\t\t   |\n");
	printf("============================\n");	
  	validationMenuPilih(&reset, "Pilihan anda : ");
    if (reset == 1) {
       	system("cls");
       	main();
    }else if (reset == 2) {
     	system("cls");
        hapus_data();
    }else if (reset == 3) {
    	system("cls");
        printf("\n------------------------------");
       	printf("\n|\tTERIMA KASIH\t     |\n");
       	printf("------------------------------\n");
    }
}

void cari_data(){
    int salah =0, jumlah =0;
    int searchNim;
    struct Mahasiswa data;

    printf("===================================================\n");
    printf("|                 PROGRAM MAHASISWA               |\n");
	printf("***************************************************\n");
	printf("|                CARI DATA MAHASISWA              |\n");
	printf("===================================================\n");
    printf("Masukkan NIM : ");
    scanf("%d",&searchNim);
    fflush(stdin);
    FILE *in=fopen("dataMahasiswa.txt","r");
    if(in==NULL){
        printf("\nDATA TIDAK TERDAFTAR\n");
    }
	else{
        while(!feof(in)){
            fflush(stdin);
            fscanf(in,"%d#%[^\n]\n", &data.nim, &data.nama);
            if(data.nim == searchNim){
            	printf("\n===================================================");
                printf("\n|\t\t   DATA MAHASISWA		  |\n");
				printf("===================================================\n");
                printf("|NIM       : %d                    \t  |\n",data.nim);
                printf("|Nama      : %s	      	 	  \t  |\n",data.nama);
				printf("===================================================\n");
                jumlah +=1;
            }
			else{
                salah +=1;
                jumlah +=1;
            }
        }
        if(salah == jumlah){
            printf("\nDATA TIDAK DITEMUKAN \n");
        }
        fclose(in);
    }

	printf("\n\n============================");
	printf("\n|\tMENU PILIHAN\t   |\n");
	printf("============================\n");
	printf("|1. Kembali ke Menu Utama  |\n");
	printf("|2. Ulang\t\t   |\n");
	printf("|3. Keluar\t\t   |\n");
	printf("============================\n");	
  	validationMenuPilih(&reset, "Pilihan anda : ");
    if (reset == 1) {
       	system("cls");
       	main();
    }else if (reset == 2) {
     	system("cls");
        cari_data();
    }else if (reset == 3) {
    	system("cls");
        printf("\n------------------------------");
       	printf("\n|\tTERIMA KASIH\t     |\n");
       	printf("------------------------------\n");
    }
}

int main(){
    system("cls");
    printf("+======================================================+\n");
    printf("|                                                      |\n");
    printf("|              PROGRAM DATA MAHASISWA                  |\n");
    printf("|         OLEH KELOMPOK 13 PRATIKUM ALPROG             |\n");
    printf("|                                                      |\n");
    printf("|======================================================|\n");
    printf("| Anggota:                                             |\n");
    printf("| 2105551023    I Ketut Putra Jaya                     |\n");
    printf("| 2105551052    Kadek Cahyadi Yogachandra              |\n");
    printf("| 2105551102    Dyah Putri Maheswari                   |\n");
    printf("| 2105551105    Greace Amanda R.Y                      |\n");
    printf("| 2105551104	Velicia Varrel Valiant                 |\n");
    printf("| 2105551125    A.A. Sagung Mirah Indira Wardhana      |\n");
    printf("+======================================================+\n\n");
    printf("Tekan apa saja untuk melanjutkan...");
    sleep(3);
    system("cls");
 
    int pilih;
    printf("===================================================\n");
    printf("|              PROGRAM DATA MAHASISWA             |\n");
	printf("===================================================\n");
	printf("|1. Tambah Data                                   |\n");
	printf("|2. Lihat Data                                    |\n");
	printf("|3. Edit Data                                     |\n");
	printf("|4. Hapus Data                                    |\n");
	printf("|5. Cari Data                                     |\n");	
	printf("|6. Keluar                                        |\n");	
	printf("===================================================\n");
    validationMenu(&pilih, "Masukkan pilihan : ");
	switch(pilih) {
		case 1 :
			system("cls");
			tambah_data();
			break;
			
		case 2 :
			system("cls");
			lihat_data();
			break;
			
		case 3 :
			system("cls");
			edit_data();
			break;
			
		case 4 :
			system("cls");		
			hapus_data();		
			break;
			
		case 5 :
			system("cls");
			cari_data();
			break;
			
		case 6 :
			system("cls");
			printf("\n------------------------------");
			printf("\n|\tTERIMA KASIH\t     |\n");
			printf("------------------------------\n");
			break;
	}
	return 0;
}
