#include <iostream>
#include <string>

using namespace std;

struct Mobil {
    string model;
    string warna;
    int tahun;
    double harga;
};

const int MAX_MOBIL = 10;
Mobil dealer[MAX_MOBIL];
int jumlahMobil = 5;

void tambahMobil(Mobil *arr, int *jml) {
    if (*jml >= MAX_MOBIL) {
        cout << "Kapasitas dealer penuh!\n";
        return;
    }
    Mobil m;
    cout << "Masukkan Model Mobil: ";
    cin.ignore();
    getline(cin, m.model);
    cout << "Masukkan Warna Mobil: ";
    getline(cin, m.warna);
    cout << "Masukkan Tahun Produksi: ";
    cin >> m.tahun;
    cout << "Masukkan Harga Mobil: ";
    cin >> m.harga;

    arr[*jml] = m;
    (*jml)++;

    cout << "Mobil berhasil ditambahkan!\n";
}

void tampilkanMobil(Mobil *arr, int *jml) {
    if (*jml == 0) {
        cout << "Tidak ada mobil di dealer.\n";
        return;
    }

    cout << "\nDaftar Mobil di Dealer Honda:\n";
    for (int i = 0; i < *jml; i++) {
        cout << "ID: " << i + 1 << endl;
        cout << "Model: " << arr[i].model << endl;
        cout << "Warna: " << arr[i].warna << endl;
        cout << "Tahun: " << arr[i].tahun << endl;
        cout << "Harga: " << arr[i].harga << endl;
        cout << "---------------------------\n";
    }
}

void ubahMobil(Mobil *arr, int *jml) {
    if (*jml == 0) {
        cout << "Tidak ada mobil di dealer.\n";
        return;
    }

    int id;
    cout << "Masukkan ID mobil yang ingin diubah: ";
    cin >> id;

    if (id < 1 || id > *jml) {
        cout << "ID mobil tidak valid!\n";
        return;
    }

    id--;
    cout << "Masukkan Model Mobil Baru: ";
    cin.ignore();
    getline(cin, arr[id].model);
    cout << "Masukkan Warna Mobil Baru: ";
    getline(cin, arr[id].warna);
    cout << "Masukkan Tahun Produksi Baru: ";
    cin >> arr[id].tahun;
    cout << "Masukkan Harga Mobil Baru: ";
    cin >> arr[id].harga;

    cout << "Data mobil berhasil diubah!\n";
}

void hapusMobil(Mobil *arr, int *jml) {
    if (*jml == 0) {
        cout << "Tidak ada mobil di dealer.\n";
        return;
    }

    int id;
    cout << "Masukkan ID mobil yang ingin dihapus: ";
    cin >> id;

    if (id < 1 || id > *jml) {
        cout << "ID mobil tidak valid!\n";
        return;
    }

    id--;
    for (int i = id; i < *jml - 1; i++) {
        arr[i] = arr[i + 1];  // Menggeser array ke kiri
    }

    (*jml)--;

    cout << "Mobil berhasil dihapus!\n";
}

void tampilkanMenu() {
    cout << "\n Manajemen Dealer Mobil Honda\n";
    cout << "1. Tambah Mobil\n";
    cout << "2. Tampilkan Mobil\n";
    cout << "3. Ubah Mobil\n";
    cout << "4. Hapus Mobil\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi: ";
}

void isiDataAwal() {
    dealer[0] = {"Honda Civic", "Merah", 2020, 500000000};
    dealer[1] = {"Honda Accord", "Putih", 2019, 600000000};
    dealer[2] = {"Honda CR-V", "Hitam", 2021, 700000000};
    dealer[3] = {"Honda Jazz", "Biru", 2018, 300000000};
    dealer[4] = {"Honda HR-V", "Abu-abu", 2022, 750000000};
}

int main() {
    isiDataAwal();

    int pilihan;
    bool jalan = true;

    while (jalan) {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMobil(dealer, &jumlahMobil);
                break;
            case 2:
                tampilkanMobil(dealer, &jumlahMobil);
                break;
            case 3:
                ubahMobil(dealer, &jumlahMobil);
                break;
            case 4:
                hapusMobil(dealer, &jumlahMobil);
                break;
            case 5:
                jalan = false;
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}