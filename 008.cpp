#include <iostream>
using namespace std;

int main() {
    // Meminta pengguna untuk memasukkan nomor akun
    cout << "Masukkan nomor akun Anda: ";

    // Mendeklarasikan variabel untuk validasi
    int validation, valid, validation2, valid2;

    // Mendeklarasikan variabel untuk perhitungan
    long long account_number, mods, divide;

    // Memasukkan nomor akun
    cin >> account_number;

    // Menginisialisasi variabel untuk loop validasi
    mods = 100;
    divide = 10;
    validation = 0;

    // Memvalidasi nomor akun menggunakan algoritma Luhn
    do {
        valid = (((account_number % mods) / divide) * 2);
        if (valid >= 10 || valid < 0) {
            // Jika hasil penggandaan adalah dua digit, jumlahkan digitnya
            int digit_1, digit_2;
            digit_1 = valid % 10;
            digit_2 = valid / 10;
            valid = digit_1 + digit_2;
        } else {
            valid = valid;
        }
        validation = validation + valid;
        mods *= 100;
        divide *= 100;
    } while ((mods <= 10000000000000000) || (divide <= 1000000000000000));

    // Menginisialisasi variabel untuk loop validasi2
    mods = 10;
    divide = 1;
    validation2 = 0;

    // Memvalidasi nomor akun tanpa menggandakan digit
    do {
        valid2 = ((account_number % mods) / divide);
        validation2 = validation2 + valid2;
        mods *= 100;
        divide *= 100;
    } while ((mods <= 1000000000000000) || (divide <= 100000000000000));

    // Menghitung total checksum validasi
    int total_validation = validation + validation2;

    // Menentukan jenis kartu berdasarkan digit pertama dan checksum
    string card_type;
    if ((((account_number % 10000000000000000) / 1000000000000000) == 5) && (total_validation % 10 == 0)) {
        card_type = "MASTERCARD";
    } else if ((((account_number % 10000000000000000) / 1000000000000000) == 4) && (total_validation % 10 == 0)) {
        card_type = "VISA";
    } else {
        card_type = "invalid";
    }

    // Menampilkan hasil
    cout << "Nomor kartu Anda: " << account_number << endl;
    cout << "Jenis kartu Anda: " << card_type << endl;
    cout << "Checksum: " << total_validation << endl;
    return 0;
}