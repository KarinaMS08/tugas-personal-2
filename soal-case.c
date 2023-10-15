#include <stdio.h>
#include <string.h>

//Fungsi untuk menghitung jumlah karakter vokal pada string
int vokal(char *bulan) {
    int hitung = 0;
    for (int i = 0; bulan[i] != '\0'; i++) {
        char c = bulan[i];
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o' ||
            c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {
            hitung++;
        }
    }
    return hitung;
}

//Fungsi untuk menghitung jumlah karakter non vokal/konsonan pada string
int nonVokal(char *bulan) {
    int hitung = 0;
    for (int i = 0; bulan[i] != '\0'; i++) {
        char c = bulan[i];
        if ((c >= 'a' && c <= 'z' && c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o') ||
            (c >= 'A' && c <= 'Z' && c != 'A' && c != 'I' && c != 'U' && c != 'E' && c != 'O')) {
            hitung++;
        }
    }
    return hitung;
}

int main() {
    char hurufAwal;
    char *bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    char ulangi;
    do {
        int inputValid = 0;  //Variabel untuk mengecek apakah input huruf sesuai atau tidak

        while (!inputValid) {
            printf("Masukkan huruf A-Z: ");
            char input[2];
            scanf(" %1s", input);

            if (strlen(input) == 1 && ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'))) {
                hurufAwal = input[0];

                int bulanValid[12];
                int hitungBulanValid = 0;

                //Mencari bulan yang dimulai dengan huruf yang dimasukkan
                for (int i = 0; i < 12; i++) {
                    if (bulan[i][0] == hurufAwal || bulan[i][0] == hurufAwal - 'a' + 'A') {
                        bulanValid[hitungBulanValid] = i;
                        hitungBulanValid++;
                    }
                }

                if (hitungBulanValid == 0) {
                    printf("Tidak ada bulan yang dimulai dengan huruf '%c'. Silakan coba lagi.\n", hurufAwal);
                } else {
                    inputValid = 1;  //Keluar dari loop jika huruf yang dimasukkan sudah sesuai
                    printf("Bulan yang dimulai dengan huruf '%c'\n", hurufAwal);
                    for (int i = 0; i < hitungBulanValid; i++) {
                        printf("%d. %s\n", i + 1, bulan[bulanValid[i]]);
                    }

                    int pilihan;
                    do {
                        //Meminta user memilih salah satu dari bulan yang sesuai
                        printf("Pilih salah satu (1-%d): ", hitungBulanValid);
                        if (scanf("%d", &pilihan) != 1) {
                            //Menangani jika user memasukkan non-angka
                            printf("Masukkan harus berupa angka. Silakan coba lagi.\n");
                            while (getchar() != '\n');  // Membersihkan buffer input
                            continue;
                        }

                        if (pilihan < 1 || pilihan > hitungBulanValid) {
                            //Menangani pilihan yang tidak valid
                            printf("Pilihan Tidak Valid. Silakan Coba Lagi.\n");
                        }
                    } while (pilihan < 1 || pilihan > hitungBulanValid);

                    pilihan--;
                    int bulanTerpilih = vokal(bulan[bulanValid[pilihan]]);
                    int hitungKonsonanBulan = nonVokal(bulan[bulanValid[pilihan]]);
                    //Menampilkan jumlah karakter vokal dan karakter konsonan pada bulan yang dipilih di baris yang berbeda
                    printf("\nBulan %s:\n", bulan[bulanValid[pilihan]]);
                    printf("Jumlah Karakter Vokal: %d\n", bulanTerpilih);
                    printf("Jumlah Karakter Konsonan: %d\n\n", hitungKonsonanBulan);
                }
            } else {
                //Menangani jika user memasukkan karakter selain huruf
                printf("Masukkan harus berupa huruf A-Z. Silakan coba lagi.\n");
                while (getchar() != '\n');  // Membersihkan buffer input
            }
        }

        //Meminta user apakah ingin mengulangi program dengan batasan input
        do {
            printf("Ulangi Program? (y/n): ");
            scanf(" %c", &ulangi);
            while (getchar() != '\n');
        } while (ulangi != 'y' && ulangi != 'Y' && ulangi != 'n' && ulangi != 'N');

        printf("\n");

    } while (ulangi == 'y' || ulangi == 'Y');


    printf("Terima Kasih Telah Menggunakan Program Ini.\n");

    return 0;
}
