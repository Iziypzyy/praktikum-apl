#include <iostream>
#include <string>
using namespace std;

#define MAX_IKAN 100 // Ukuran maksimum array ikan

// Variabel array untuk menyimpan data ikan
string namaIkan[MAX_IKAN];
string jenisIkan[MAX_IKAN];
int hargaIkan[MAX_IKAN];
int panjang = 0; // Jumlah elemen saat ini

int main() {
    // Variabel untuk login
    string nama, nim;
    string namavalid = "Zifa";
    string nimvalid = "025";
    int percobaan = 0;

 
    while (percobaan < 3) {
        cout << "=== Login Toko Ikan Hias ===" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        cout << endl;

        if (nama == namavalid && nim == nimvalid ) {
            cout << "Login berhasil! Selamat Datang Iciboss " << namavalid << endl << endl;
            break;
        } 
        
        else {
            percobaan++;
            cout << "kasi bener dong, sisa percobaan : " << 3 - percobaan << endl;
        }
    }

    if (percobaan == 3) {
        cout << "Yah input user pass nya salah mulu, program behenti." << endl;
        return 0;
    }

 
    int pilihan, index;
    while(true) {
        cout << "===================================\n";
        cout << "=== Program Manajemen Ikan Hias ===\n";
        cout << "===================================\n";
        cout << "|1. Tampilkan Ikan                |\n";
        cout << "|2. Tambah Ikan                   |\n";
        cout << "|3. Ubah Ikan                     |\n";
        cout << "|4. Hapus Ikan                    |\n";
        cout << "|5. Keluar Program                |\n";
        cout << "===================================\n";
        cout << "Masukan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: // Tampilkan Ikan
                if (panjang == 0) {
                    cout << "\nBelum ada ikan yang tersedia." << endl;
                } else {
                    cout << "\n=== Daftar Ikan Hias ===" << endl;
                    for (int i = 0; i < panjang; i++) {
                        cout << "Ikan ke-" << i + 1 << ":" << endl;
                        cout << "  Nama: " << namaIkan[i] << endl;
                        cout << "  Jenis: " << jenisIkan[i] << endl;
                        cout << "  Harga: Rp" << hargaIkan[i] << endl;
                        cout << "-------------------------" << endl;
                    }
                }
                break;

            case 2: // Tambah Ikan
                if (panjang < MAX_IKAN) {
                    cout << "\n=== Tambah Ikan ===" << endl;
                    cout << "Masukkan nama ikan: ";
                    getline(cin, namaIkan[panjang]);
                    cout << "Masukkan jenis ikan: ";
                    getline(cin, jenisIkan[panjang]);
                    cout << "Masukkan harga ikan: ";
                    cin >> hargaIkan[panjang];
                    cin.ignore();
                    panjang++;
                    cout << "Ikan berhasil ditambahkan!" << endl;
                } else {
                    cout << "\nKapasitas penuh! Tidak bisa menambah ikan lagi." << endl;
                }
                break;

            case 3: // Ubah Ikan
                if (panjang == 0) {
                    cout << "\nBelum ada ikan yang tersedia untuk diubah." << endl;
                } else {
                    cout << "\n=== Ubah Ikan ===" << endl;
                    cout << "Masukkan nomor ikan yang akan diubah: ";
                    cin >> index;
                    cin.ignore();

                    if (index > 0 && index <= panjang) {
                        cout << "Masukkan nama ikan baru: ";
                        getline(cin, namaIkan[index - 1]);
                        cout << "Masukkan jenis ikan baru: ";
                        getline(cin, jenisIkan[index - 1]);
                        cout << "Masukkan harga ikan baru: ";
                        cin >> hargaIkan[index - 1];
                        cin.ignore(); 
                        cout << "Ikan berhasil diubah!" << endl;
                    } else {
                        cout << "\nNomor ikan tidak valid." << endl;
                    }
                }
                break;

            case 4: // Hapus Ikan
                if (panjang == 0) {
                    cout << "\nBelum ada ikan yang tersedia untuk dihapus." << endl;
                } else {
                    cout << "\n=== Hapus Ikan ===" << endl;
                    cout << "Masukkan nomor ikan yang akan dihapus: ";
                    cin >> index;
                    cin.ignore();

                    if (index > 0 && index <= panjang) {
                        for (int i = index - 1; i < panjang - 1; i++) {
                            namaIkan[i] = namaIkan[i + 1];
                            jenisIkan[i] = jenisIkan[i + 1];
                            hargaIkan[i] = hargaIkan[i + 1];
                        }
                        panjang--;
                        cout << "Ikan berhasil dihapus!" << endl;
                    } else {
                        cout << "\nNomor ikan tidak valid." << endl;
                    }
                }
                break;

            case 5: // Keluar
                cout << "\nSemangat iciboss!, Terima kasih!" << endl;
                return 0; // Keluar dari program

            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    cout << "\nProgram selesai. Terima kasih!" << endl;
    return 0;
}