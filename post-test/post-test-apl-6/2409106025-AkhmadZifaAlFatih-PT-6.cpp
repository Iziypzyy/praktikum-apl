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
    DataIkan* ikan; // Menggunakan pointer untuk array ikan
    int jumlahIkan = 0;
};

DataPengguna* dataPengguna = nullptr; // Menggunakan pointer untuk array pengguna
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
int hitungIkanRekursif(int indexPengguna, int index = 0);
void tampilkanInfo(const string &nama);
void tampilkanInfo(const string &nama, const string &nim);
void sortByNamaAscending(int indexPengguna);  // Bubble Sort
void sortByHargaDescending(int indexPengguna); // Selection Sort
void sortByJenisAscending(int indexPengguna);  // Insertion Sort
void SortirIkan(int indexPengguna);           // Menu sorting

int main() {
    // Alokasi memori dinamis untuk array dataPengguna
    dataPengguna = new DataPengguna[MAX_PENGGUNA];
    for (int i = 0; i < MAX_PENGGUNA; i++) {
        dataPengguna[i].ikan = new DataIkan[MAX_IKAN];
    }
    
    tampilkanMenuUtama();
    
    // Dealokasi memori sebelum program berakhir
    for (int i = 0; i < MAX_PENGGUNA; i++) {
        delete[] dataPengguna[i].ikan;
    }
    delete[] dataPengguna;
    
    return 0;
}

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
            if ((dataPengguna + i)->nama == nama && (dataPengguna + i)->nim == nim) {
                loginBerhasil = true;
                indexPengguna = i;
                break;
            }
        }

        if (loginBerhasil) {
            percobaan = 0;
            cout << "\nLogin berhasil! Selamat Datang " << nama << endl;
            tampilkanInfo(nama, nim);
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
    getline(cin, (dataPengguna + jumlahPengguna)->nama);
    cout << "Masukkan NIM: ";
    getline(cin, (dataPengguna + jumlahPengguna)->nim);
    
    jumlahPengguna++;
    cout << "\nPengguna berhasil terdaftar!\n";
    tampilkanInfo((dataPengguna + jumlahPengguna - 1)->nama);
}

void menuManajemenIkan(int indexPengguna) {
    DataPengguna* pengguna = dataPengguna + indexPengguna;
    
    while (true) {
        cout << "\n===================================";
        cout << "\n=== Program Manajemen Ikan Hias ===";
        cout << "\n===================================";
        cout << "\n1. Tampilkan Ikan                 |";
        cout << "\n2. Tambah Ikan                    |";
        cout << "\n3. Ubah Ikan                      |";
        cout << "\n4. Hapus Ikan                     |";
        cout << "\n5. Sortir Ikan                    |";  // Menu baru untuk sorting
        cout << "\n6. Keluar Program                 |";
        cout << "\n===================================";
        cout << "\nPilih menu: ";
        
        int pilihanMenu;
        cin >> pilihanMenu;
        cin.ignore();

        switch (pilihanMenu) {
            case 1: 
                tampilkanIkan(indexPengguna); 
                cout << "\nTotal ikan (dihitung secara rekursif): " 
                     << hitungIkanRekursif(indexPengguna) << endl;
                break;
            case 2: tambahIkan(indexPengguna); break;
            case 3: ubahIkan(indexPengguna); break;
            case 4: hapusIkan(indexPengguna); break;
            case 5: SortirIkan(indexPengguna); break;  // Diperbaiki di sini
            case 6: return;
            default: cout << "\nPilihan tidak valid.\n";
        }
    }
}

void tampilkanIkan(int indexPengguna) {
    DataPengguna* pengguna = &dataPengguna[indexPengguna];
    
    if (pengguna->jumlahIkan == 0) {
        cout << "\nBelum ada ikan yang tersedia.\n";
    } else {
        cout << "\n=== Daftar Ikan Hias ===\n";
        for (int i = 0; i < pengguna->jumlahIkan; i++) {
            DataIkan* ikan = pengguna->ikan + i;
            cout << "Ikan ke-" << i+1 << ":\n";
            cout << "  Nama: " << ikan->nama << "\n";
            cout << "  Jenis: " << ikan->jenis << "\n";
            cout << "  Harga: Rp" << ikan->harga << "\n";
            cout << "-----------------------\n";
        }
    }
}

void tambahIkan(int indexPengguna) {
    DataPengguna* pengguna = dataPengguna + indexPengguna;
    
    if (pengguna->jumlahIkan >= MAX_IKAN) {
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

    *(pengguna->ikan + pengguna->jumlahIkan) = ikanBaru;
    pengguna->jumlahIkan++;
    
    cout << "\nIkan berhasil ditambahkan!\n";
}

void ubahIkan(int indexPengguna) {
    DataPengguna* pengguna = &dataPengguna[indexPengguna];
    
    if (pengguna->jumlahIkan == 0) {
        cout << "\nBelum ada ikan yang tersedia.\n";
        return;
    }

    tampilkanIkan(indexPengguna);
    cout << "\nPilih nomor ikan yang akan diubah: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > pengguna->jumlahIkan) {
        cout << "\nNomor tidak valid.\n";
        return;
    }

    cout << "\n=== Ubah Ikan ===\n";
    DataIkan* ikan = pengguna->ikan + (index - 1);
    cout << "Nama baru: ";
    getline(cin, ikan->nama);
    cout << "Jenis baru: ";
    getline(cin, ikan->jenis);
    cout << "Harga baru: Rp";
    cin >> ikan->harga;
    cin.ignore();

    cout << "\nData ikan berhasil diubah!\n";
}

void hapusIkan(int indexPengguna) {
    DataPengguna* pengguna = dataPengguna + indexPengguna;
    
    if (pengguna->jumlahIkan == 0) {
        cout << "\nBelum ada ikan yang tersedia.\n";
        return;
    }

    tampilkanIkan(indexPengguna);
    cout << "\nPilih nomor ikan yang akan dihapus: ";
    int index;
    cin >> index;
    cin.ignore();

    if (index < 1 || index > pengguna->jumlahIkan) {
        cout << "\nNomor tidak valid.\n";
        return;
    }

    for (int i = index-1; i < pengguna->jumlahIkan-1; i++) {
        *(pengguna->ikan + i) = *(pengguna->ikan + i + 1);
    }
    pengguna->jumlahIkan--;

    cout << "\nIkan berhasil dihapus!\n";
}

int hitungIkanRekursif(int indexPengguna, int index) {
    DataPengguna* pengguna = dataPengguna + indexPengguna;
    
    if (index >= pengguna->jumlahIkan) {
        return 0;
    }
    return 1 + hitungIkanRekursif(indexPengguna, index + 1);
}

void tampilkanInfo(const string &nama) {
    cout << "\nInfo Pengguna:\n";
    cout << "Nama: " << nama << "\n";
}

void tampilkanInfo(const string &nama, const string &nim) {
    tampilkanInfo(nama);
    cout << "NIM: " << nim << "\n";
}

void SortirIkan(int indexPengguna) {
    cout << "\n=== Menu Sortir Ikan ===";
    cout << "\n1. Sortir berdasarkan Nama (A-Z)";
    cout << "\n2. Sortir berdasarkan Harga (Tertinggi-Terendah)";
    cout << "\n3. Sortir berdasarkan Jenis (A-Z)";
    cout << "\nPilihan: ";
    int sortChoice;
    cin >> sortChoice;
    cin.ignore();
                
    switch(sortChoice) {
        case 1: 
            sortByNamaAscending(indexPengguna);
            cout << "\nIkan berhasil diurutkan berdasarkan Nama (A-Z)\n";
            break;
        case 2: 
            sortByHargaDescending(indexPengguna);
            cout << "\nIkan berhasil diurutkan berdasarkan Harga (Tertinggi-Terendah)\n";
            break;
        case 3: 
            sortByJenisAscending(indexPengguna);
            cout << "\nIkan berhasil diurutkan berdasarkan Jenis (A-Z)\n";
            break;
        default: cout << "\nPilihan tidak valid.\n";
    }
}

// Bubble Sort untuk mengurutkan nama ikan secara ascending (A-Z)
void sortByNamaAscending(int indexPengguna) {
    DataPengguna* pengguna = &dataPengguna[indexPengguna];
    
    for (int i = 0; i < pengguna->jumlahIkan-1; i++) {
        for (int j = 0; j < pengguna->jumlahIkan-i-1; j++) {
            if (pengguna->ikan[j].nama > pengguna->ikan[j+1].nama) {
                // Tukar posisi
                DataIkan temp = pengguna->ikan[j];
                pengguna->ikan[j] = pengguna->ikan[j+1];
                pengguna->ikan[j+1] = temp;
            }
        }
    }
}

// Selection Sort untuk mengurutkan harga ikan secara descending (terbesar ke terkecil)
void sortByHargaDescending(int indexPengguna) {
    DataPengguna* pengguna = &dataPengguna[indexPengguna];
    
    for (int i = 0; i < pengguna->jumlahIkan-1; i++) {
        int max_idx = i;
        for (int j = i+1; j < pengguna->jumlahIkan; j++) {
            if (pengguna->ikan[j].harga > pengguna->ikan[max_idx].harga) {
                max_idx = j;
            }
        }
        // Tukar posisi
        if (max_idx != i) {
            DataIkan temp = pengguna->ikan[i];
            pengguna->ikan[i] = pengguna->ikan[max_idx];
            pengguna->ikan[max_idx] = temp;
        }
    }
}

// Insertion Sort untuk mengurutkan jenis ikan secara ascending (A-Z)
void sortByJenisAscending(int indexPengguna) {
    DataPengguna* pengguna = &dataPengguna[indexPengguna];
    
    for (int i = 1; i < pengguna->jumlahIkan; i++) {
        DataIkan key = pengguna->ikan[i];
        int j = i - 1;
        
        while (j >= 0 && pengguna->ikan[j].jenis > key.jenis) {
            pengguna->ikan[j+1] = pengguna->ikan[j];
            j = j - 1;
        }
        pengguna->ikan[j+1] = key;
    }
}