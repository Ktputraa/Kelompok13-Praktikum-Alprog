#include<stdio.h>
#include<stdlib.h>

int panjangSisi;

typedef struct {
    int panjang, luasPermukaan, volume;
}kubusStruct;

typedef union{
    int panjang, luasPermukaan, volume;
}kubusUnion;

int validasiint(int *var){
    system("color 2F");
	char buff[1024];
    char x;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
    if(sscanf(buff, "%d %c", var, &x) == 1) {
    return 1;
  }
 }
 return 0;
}

void main();

void repeat(){
    char pil[2];
    printf("\nApakah anda ingin mengulang program ini? (y/t) \n");
    scanf("%s",&pil);
    if(strcmpi(pil,"y")==0){
        system("cls");
        main();
    }else if(strcmpi(pil,"t")==0){
            printf("\n");
        printf("\t+===============================================+\n");
        printf("\t|                 Terima  Kasih                 |\n");
        printf("\t+===============================================+\n\n");
        exit(1);
    }else{
        printf("Silahkan Masukkan Pilihan Yang Benar!! ");
        repeat();
    }
getch();
}

void header(){
    system("cls");
  	system("color 2F");
    printf("+======================================================+\n");
    printf("|                                                      |\n");
    printf("|  PROGRAM PERHITUNGAN KUBUS DENGAN STRUCT DAN UNION   |\n");
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
}
    
void KubusStruct(){
    printf("+=====================+\n");
    printf("| KUBUS DENGAN STRUCT |\n");
    printf("+=====================+\n\n");
    printf("Masukkan Panjang Sisi Kubus : ");
    if(validasiint(&panjangSisi) != 1){
        system("cls");
        fflush(stdin);
        printf("\nInput salah! Input Harus Berupa Angka.\nSilahkan coba lagi.\n");
        KubusStruct();
    }
    printf("\n");

    kubusStruct structs = {.panjang = panjangSisi,
                           .luasPermukaan = 6 * panjangSisi * panjangSisi,
                           .volume = panjangSisi * panjangSisi * panjangSisi};

    
 printf("+==========================================================+\n");
 printf("|      	          KUBUS DENGAN STRUCK                      |\n");
 printf("|==========================================================|\n");
 printf("| Panjang Sisi               : %d                           |\n", structs.panjang);        
 printf("| Luas Permukaan             : %d                           |\n", structs.luasPermukaan);
 printf("| Volume                     : %d                           |\n", structs.volume);
 printf("| Ukuran Memory Kubus Struct : %d                          |\n", sizeof(structs));
 printf("+==========================================================+\n\n");

    repeat();
}

void KubusUnion(){
    printf("+====================+\n");
    printf("| KUBUS DENGAN UNION |\n");
    printf("+====================+\n\n");
    printf("Masukkan Panjang Sisi Kubus : ");
    if(validasiint(&panjangSisi) != 1){
        system("cls");
        fflush(stdin);
        printf("\nInput salah! Input Harus Berupa Angka \nSilahkan coba lagi.\n");
        KubusUnion();
    }
    printf("\n");

    kubusUnion unions[3];
    unions[0].panjang = panjangSisi;
    unions[1].luasPermukaan = 6 * panjangSisi * panjangSisi;
    unions[2].volume = panjangSisi * panjangSisi * panjangSisi;

 printf("+==========================================================+\n");
 printf("|      	           KUBUS DENGAN UNION                      |\n");
 printf("|==========================================================|\n");
 printf("|Panjang Sisi                : %d                           |\n", unions[0]);
 printf("|Luas Permukaan              : %d                          |\n", unions[1]);
 printf("|Volume Kubus                : %d                          |\n", unions[2]);
 printf("|Ukuran Memory Kubus Union   : %d                           |\n", sizeof(unions[0]));
 printf("+==========================================================+\n");
repeat();
}

void main(){
    header();
    printf("+==========================+\n");
    printf("|        MAIN  MENU        |\n");
    printf("+==========================+\n");
    printf("| 1. Kubus Dengan Struct   |\n");
    printf("| 2. Kubus Dengan Union    |\n");
    printf("| 3. Tutup Program         |\n");
    printf("+==========================+\n\n");
	printf("\nMasukkan pilihan   : ");
	int pilihan;
    if(validasiint(&pilihan) != 1){
	system("cls");
	fflush(stdin);
	main();
    }
    system("cls");
    switch(pilihan){
        case 1 :
            KubusStruct();  
			break;
        case 2 :
            KubusUnion();
            break;
        case 3 :
            printf("\n");
            printf("\t+===============================================+\n");
            printf("\t|                 Terima  Kasih                 |\n");
            printf("\t+===============================================+\n\n");
            exit(1);
        default :
            printf("Tidak ada pilihan tersebut pada menu,");
            printf(" Harap Masukkan pilihan yang tersedia pada menu\n\n");
            printf("\nInput salah! Input Harus Berupa Angka 1-3.\nSilahkan coba lagi.\n");
            system("PAUSE");
            main();
    }
}
