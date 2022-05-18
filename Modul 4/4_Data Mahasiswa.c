#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct mhs{
	char nim[300];
	char nama[300];
}mhs;

void menu();
void kelompok();
void tambah_data();
void cari_data();
char exite();
char validasi(char *masukan);
char valid_pesan(char *masukan);
char validasi_nim(char *masukan);
char valid_nim();
int cek_menu();
int cek_menu2();

char nim[300],nama[300];

int main(){
char cek;
int pilih;

kelompok();
do{
    fflush(stdin);
    system("cls");
    menu();
    pilih=cek_menu();
    fflush(stdin);
    if(pilih==1){
        tambah_data();
        system("cls");
    }else if(pilih==2){
        cari_data();
        system("cls");
    }else{
        printf("Terimakasi\n");
        return 0;
    }
    printf("-----------------------------------\n");
    printf("Tekan Y/y Jika Ingin Kembali Ke Menu Awal Lagi");
	printf("Tekan N/n Jika Ingin Keluar Dari Program\n\n");
    printf("-----------------------------------\n");
    printf("Silahkan Masukan Pilihan[Y/N]: ");
    cek=exite();
}while(cek=='y'|| cek=='Y');
printf("Terimakasi");
return 0;
}

void tambah_data(){
int cek,pilih,d;
char data[10];
FILE *cekdata;
FILE * input;

 do{
    fflush(stdin);
    system("cls");
    printf("===============================================\n");
    printf("==          MENU INPUT DATA MAHASISWA        ==\n");
    printf("===============================================\n");
    printf("Masukan NIM :");
    validasi_nim(&mhs.nim);

    fflush(stdin);
    printf("Masukan nama :");
    validasi(&mhs.nama);

    cek=0;
    fflush(stdin);
    cekdata = fopen("sim.txt","r");
    if(cekdata == NULL){
        printf("File txt Tidak Tersedia\n");
    }else{
        while(!feof(cekdata)){
            fscanf(cekdata,"%s\n#%s#\n",&nim,&nama);
            if(strcmp(mhs.nim,nim)==0){
                fflush(stdin);
                printf("NIM Sudah Tersedia!\n");
                cek=1;
            }
        }
         fclose(cekdata);
    }
    fflush(stdin);
   if(cek !=1){
        input=fopen("sim.txt","a");
        fprintf(input,"%s\n#%s#\n",mhs.nim,mhs.nama);
        fclose(input);
        cek=4;
   }
   if(cek==4){
        printf("\n\nData Berhasil ditambahkan\n");
   }
    printf("-----------------------------------\n");
    printf("1.Tekan 1 Jika Ingin Menambah Data Lagi");
	printf("2.Tekan 2 Jika Ingin Keluar Dari Menu Input Data\n");
    printf("-----------------------------------\n");
    printf("Silahkan Masukan Pilihan[1/2]: ");
    pilih=cek_menu_2();
    }while(pilih==1);

}

void cari_data(){
char nim[10];
int pilih;
int a,cek;

do{
    fflush(stdin);
    system("cls");
    printf("===============================================\n");
    printf("==          MENU CARI DATA MAHASISWA         ==\n");
    printf("===============================================\n");
    cek=0;
    fflush(stdin);
    printf("\nMasukan NIM Anda :");
    validasi_nim(&nim);

    FILE *cekdata;

    cekdata=fopen("sim.txt","r");

    if(cekdata==NULL){
        printf("file txt tidak ada!");
    }else{
        while(!feof(cekdata)){
            fscanf(cekdata,"%s\n# %[^#] #\n",&mhs.nim,&mhs.nama);
            if(strcmp(mhs.nim,nim)==0){
               fflush(stdin);
               printf("---------DATA MAHASISWA-------\n");
               printf("NIM  : %s",mhs.nim);
               printf("\n");
               printf("tNama Mahasiswa: %s",mhs.nama);
               printf("\n");
               printf("----------------------------------\n");
               cek=1;
            }

        }
         fclose(cekdata);
    }
    if(cek !=1){
        printf("\n\n\t\t\tNIM yang Anda Masukan Tidak Ditemukan\n");
    }
    printf("-----------------------------------\n");
    printf("1.Tekan 1 Jika Ingin Mencari Data Lagi");
	printf("2.Tekan 2Jika Ingin Keluar Dari Menu Cari Data\n");
    printf("-----------------------------------\n");
    printf("Silahkan Masukan Pilihan[1/2]: ");
    pilih=cek_menu_2();
}while(pilih==1);

}

void kelompok(){
    system("color 1F");
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
   	printf("Tekan enter untuk melanjutkan...");
    getch();
}

void menu(){
   printf("===================================================\n");
    printf("|              PROGRAM DATA MAHASISWA             |\n");
	printf("===================================================\n");
	printf("|1. Tambah Data                                   |\n");
	printf("|2. Cari Data                                     |\n");	
	printf("|3. Keluar                                        |\n");	
	printf("===================================================\n");
    printf("|Silahkan Masukan Menu Pilihan : ");
}

int cek_menu(){
    int input;
    while(1){
        input=valid_input();
        if(input>=1 && input<=3){
            return input;
        }
        printf("tidak valid!,coba lagi:");
    }
}

int cek_menu_2(){
    int input;
    while(1){
        input=valid_input();
        if(input>=1 && input<=2){
            return input;
        }
        printf("tidak valid!,coba lagi:");
    }
}


char exite(){
    char masukan[100];
    while(1){
        int i=0;
        int salah;
        scanf("%[^\n]",&masukan);
        fflush(stdin);
        if(masukan [i+1] =='\0'){
            if(masukan[0]=='y'  || masukan[0]=='Y' && masukan[1]=='\0'){
                return masukan[0];
            }else if (masukan[0]=='n'  || masukan [0]=='N' && masukan[1]=='\0'){
                return masukan[0];
            }else{
                salah=1;
            }
        }
        salah=1;
        if(salah==1){
            printf("tidak valid,coba lagi :");
        }
    }
}

char valid_pesan(char *masukan){
    int i,salah;
    i=0;
    salah=0;
    scanf("%[^\n]", masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            if(masukan[0]==' '|| masukan[i+1]=='\0'|| masukan[0]=='\0'){
                salah = 1;
                masukan[i] = '\0';
            }else{
                i++;
            }
        }else if(masukan[i]>='a' && masukan[i]<='z' || masukan[i] >= 'A' && masukan[0] <= 'Z'){
            if(masukan[i]>='a' && masukan[i]<='z'|| masukan[i]>='A' && masukan[i]<='Z'){
                i++;
            }else{
                salah=1;
                masukan[i]='\0';
            }
        }else if(masukan[i]>='0'&& masukan[i]<='9'){
            salah=1;
            masukan[i]='\0';
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
        // a1hj
    }if(masukan[0]=='\0'){
        salah=1;
        masukan[i]='\0';
    }if(salah == 1){
        printf("ttidak valid!,coba lagi:");
        return 0;
    }else{
        return masukan;
    }
}

char validasi(char *masukan){
    while(1){
        if(valid_pesan(masukan)){
            fflush(stdin);
            return masukan;
        }
    }
}

char validasi_nim(char *nims){

    while(1){
        if(valid_nim(nims)){
            fflush(stdin);
            return nims;
        }
    }
}

char valid_nim(char *masukan){
    int i,salah;
    i=0;
    salah=0;
    scanf("%[^\n]", masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            if(masukan[0]==' '|| masukan[i+1]=='\0'){
                salah = 1;
                masukan[i] = '\0';
            }else{
                i++;
            }
        }else if(masukan[i]>='0' && masukan[i]<='9'){
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
        // a1hj
    }if(masukan[0]=='\0'){
        salah=1;
        masukan[i]='\0';
    }if(salah == 1){
        printf("tidak valid!,coba lagi:");
        return 0;
    }else{
        return masukan;
    }
}

int valid_input(){
    char masukan[100];
    int i = 0;
    int belakang = 0;
    int isi_depan = 0;
    int isi_belakang = 0;
    int status = 0;
    int titik = 0;
    int salah = 0;
    int minus = 0;
    int hasil;
    
    scanf("%[^\n]", &masukan);
    fflush(stdin);
    while(masukan[i] != '\0'){
        if(masukan[i] == '.'){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i] == ' '){
            salah = 1;
            masukan[i] = '\0';
        }else if(masukan[i]>='0' && masukan[i]<='9' ||  masukan[0] == '-'){
            if(masukan[i] == '-'){
                minus=minus + 1;
                if(minus >1 || masukan[i+1]=='\0'){
                    salah=1;
                    masukan[i]='\0';
                }
            } else if(masukan[i]>='0' && masukan[i]<='9'){
                if(masukan[0]=='0'){
                    salah=1;
                    masukan[i]='\0';
                }else{
                    isi_depan = (isi_depan * 10) + (masukan[i] - 48);
                }
            }else{
                salah=1;
                masukan[i]='\0';
            }
            i++;
        }else{
            salah = 1;
            masukan[i] = '\0';
        }
        // a1hj
    }//end while
    if(masukan[0]=='\0'){
        salah=1;
    }
    hasil = isi_depan;
    if(minus == 1){
        hasil = hasil - (hasil * 2);
    }
    if(salah == 1){
        printf("tidak valid! coba lagi: ");
    }else{
        return hasil;
    }
return valid_input();
}

