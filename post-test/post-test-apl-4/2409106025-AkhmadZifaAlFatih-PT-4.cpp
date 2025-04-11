#include <iostream>
#include <string>
using namespace std;

#define MAX_IKAN 100
#define MAX_PENGGUNA 100

struct DataIkan {
    string nama;
    string jenis;
    int harga;
};

struct DataPengguna {
    string nama;
    string nim;
    DataIkan ikan[MAX_IKAN];
    int jumlahIkan = 0;
};

DataPengguna dataPengguna[MAX_PENGGUNA];
int jumlahPengguna = 0;

// Deklarasi fungsi dan prosedur
void tampilkanMenuUtama();
void prosesLogin();
void prosesRegister();
void menuManajemenIkan(int indexPengguna);
void tampilkanIkan(int indexPengguna);
void tambahIkan(int indexPengguna);
void ubahIkan(int indexPengguna);
void hapusIkan(int indexPengguna);
int hitungIkanRekursif(int indexPengguna, int index = 0); // Fungsi rekursif
void tampilkanInfo(const string &nama); // Overloading
void tampilkanInfo(const string &nama, const string &nim); // Overloading

int main() {
    tampilkanMenuUtama();
    return 0;
}

// Implementasi fungsi dan prosedur

void tampilkanMenuUtama() {
    while (true) {
        cout << "\n=== Login Toko Ikan Hias ===" << endl;
        cout << "1. Login\n2. Register\n3. Exit\n";
        cout << "============================" << endl;
        cout << "Pilih menu (1-3): ";
        
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: prosesLogin(); break;
            case 2: prosesRegister(); break;
            case 3: exit(0);
            default: cout << "\nPilihan tidak valid.\n";
        }
    }
}

void prosesLogin() {
    string nama, nim;
    static int percobaan = 0;
    
    while (percobaan < 3) {
        cout << "\nMasukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        bool loginBerhasil = false;
        int indexPengguna = -1;

        for (int i = 0; i < jumlahPengguna; i++) {
            if (dataPengguna[i].nama == nama && dataPengguna[i].nim == nim) {
                loginBerhasil = true;
                indexPengguna = i;
                break;
            }
        }

        if (loginBerhasil) {
            percobaan = 0;
            cout << "\nLogin berhasil! Selamat Datang " << nama << endl;
            tampilkanInfo(nama, nim); // Memanggil fungsi overloading
            menuManajemenIkan(indexPengguna);
            return;
        } else {
            percobaan++;
            cout << "\nLogin gagal. Sisa percobaan: " << 3 - percobaan << endl;
        }
    }
    cout << "\nAnda telah melebihi batas percobaan login.\n";
}

void prosesRegister() {
    if (jumlahPengguna >= MAX_PENGGUNA) {
        cout << "\nBatas pengguna telah tercapai.\n";
        return;
    }

    cout << "\n=== Register Pengguna ===" << endl;
    cout << "Masukkan nama: ";
    getline(cin, dataPengguna[jumlahPengguna].nama);
    cout << "Masukkan NIM: ";
    getline(cin, dataPengguna[jumlahPengguna].nim);
    
    jumlahPengguna++;
    cout << "\nPengguna berhasil terdaftar!\n";
    tampilkanInfo(dataPengguna[jumlahPengguna-1].nama); // Memanggil fungsi overloading
}

void menuManajemenIkan(int indexPengguna) {
    while (true) {
        cout << "\n===================================";
        cout << "\n=== Program Manajemen Ikan Hias ===";
        cout << "\n===================================";
        cout << "\n1. Tampilkan Ikan                 |";
        cout << "\n2. Tambah Ikan                    |";
        cout << "\n3. Ubah Ikan                      |";
        cout << "\n4. Hapus Ikan                     |";
        cout << "\n5. Keluar Program                 |";
        cout << "\n===================================";
        cout << "\nPilih menu: ";
        
        int pilihanMenu;
        cin >> pilihanMenu;
        cin.ignore();

        switch (pilihanMenu) {
            case 1: 
                tampilkanIkan(indexPengguna); 
                // Panggil fungsi rekursif secara internal
                cout << "\nTotal ikan (dihitung secara rekursif): " 
                     << hitungIkanRekursif(indexPengguna) << endl;
                break;
            case 2: tambahIkan(indexPengguna); break;
            case 3: ubahIkan(indexPengguna); break;
            case 4: hapusIkan(indexPengguna); break;
            case 5: return;
            default: cout << "\nPilihan tidak valid.\n";
        }
    }
}

void tampilkanIkan(int indexPengguna) {
    if (dataPengguna[indexPengguna].jumlahIkan == 0) {
        cout << "\nBelum ada ikan yang tersedia.\n";
    } else {
        cout << "\n=== Daftar Ikan Hias ===\n";
        for (int i = 0; i < dataPengguna[indexPengguna].jumlahIkan; i++) {
            cout << "Ikan ke-" << i+1 << ":\n";
            cout << "  Nama: " << dataPengguna[indexPengguna].ikan[i].nama << "\n";
            cout << "  Jenis: " << dataPengguna[indexPengguna].ikan[i].jenis << "\n";
            cout << "  Harga: Rp" << dataPengguna[indexPengguna].ikan[i].harga << "\n";
            cout << "-----------------------\n";
        }
    }
}

void tambahIkan(int indexPengguna) {
    if (dataPengguna[indexPengguna].jumlahIkan >= MAX_IKAN) {
        cout << "\nKapasitas penuh!\n";
        return;
    }

    cout << "\n=== Tambah Ikan ===\n";
    DataIkan ikanBaru;
    
    cout << "Nama ikan: ";
    getline(cin, ikanBaru.nama);
    cout << "Jenis ikan: ";
    getline(cin, ikanBaru.jenis);
    cout << "Harga ikan: Rp";
    cin >> ikanBaru.harga;
    cin.ignore();

    dataPengguna[indexPengguna].ikan[dataPengguna[indexPengguna].jumlahIkan] = ikanBaru;
    dataPengguna[indexPengguna].jumlahIkan++;
    
    cout << "\nIkan berhasil ditambahkan!\n";
}

void ubahIkan(int indexPengguna) {
    if (dataPengguna[indexPengguna].jumlahIkan == 0) {
        cout << "\nBelum ada ikan yang tersedia.\n";
        return;
    }

    tampilkanIkan(indexPengguna);
    cout << "\nPilih nomor ikan yang akan diubah: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > dataPengguna[indexPengguna].jumlahIkan) {
        cout << "\nNomor tidak valid.\n";
        return;
    }

    cout << "\n=== Ubah Ikan ===\n";
    cout << "Nama baru: ";
    getline(cin, dataPengguna[indexPengguna].ikan[index-1].nama);
    cout << "Jenis baru: ";
    getline(cin, dataPengguna[indexPengguna].ikan[index-1].jenis);
    cout << "Harga baru: Rp";
    cin >> dataPengguna[indexPengguna].ikan[index-1].harga;
    cin.ignore();

    cout << "\nData ikan berhasil diubah!\n";
}

void hapusIkan(int indexPengguna) {
    if (dataPengguna[indexPengguna].jumlahIkan == 0) {
        cout << "\nBelum ada ikan yang tersedia.\n";
        return;
    }

    tampilkanIkan(indexPengguna);
    cout << "\nPilih nomor ikan yang akan dihapus: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > dataPengguna[indexPengguna].jumlahIkan) {
        cout << "\nNomor tidak valid.\n";
        return;
    }

    for (int i = index-1; i < dataPengguna[indexPengguna].jumlahIkan-1; i++) {
        dataPengguna[indexPengguna].ikan[i] = dataPengguna[indexPengguna].ikan[i+1];
    }
    dataPengguna[indexPengguna].jumlahIkan--;

    cout << "\nIkan berhasil dihapus!\n";
}

// Fungsi rekursif untuk menghitung jumlah ikan
int hitungIkanRekursif(int indexPengguna, int index) {
    if (index >= dataPengguna[indexPengguna].jumlahIkan) {
        return 0;
    }
    return 1 + hitungIkanRekursif(indexPengguna, index + 1);
}

// Overloading fungsi tampilkanInfo
void tampilkanInfo(const string &nama) {
    cout << "\nInfo Pengguna:\n";
    cout << "Nama: " << nama << "\n";
}

void tampilkanInfo(const string &nama, const string &nim) {
    tampilkanInfo(nama); // Memanggil versi pertama
    cout << "NIM: " << nim << "\n";
}