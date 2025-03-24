#include <iostream>
#include <string>
using namespace std;

#define MAX_IKAN 100 // Ukuran maksimum array ikan per pengguna
#define MAX_PENGGUNA 100 // Ukuran maksimum array pengguna

// Struct untuk menyimpan data ikan
struct DataIkan {
    string nama;
    string jenis;
    int harga;
};

// Struct untuk menyimpan data pengguna
struct DataPengguna {
    string nama;
    string nim;
    DataIkan ikan[MAX_IKAN]; // Setiap pengguna memiliki array ikan
    int jumlahIkan = 0; // Jumlah ikan yang dimiliki pengguna
};

// Variabel array untuk menyimpan data pengguna
DataPengguna dataPengguna[MAX_PENGGUNA];
int jumlahPengguna = 0; // Jumlah pengguna saat ini

int main() {
    // Variabel untuk login
    string nama, nim;
    int percobaan = 0;

    while (true) {
        cout << "=== Login Toko Ikan Hias ===" << endl;
        cout << "1. Login\n2. Register\n3. Exit\n" << endl;
        cout << "============================" << endl;
        cout << "Pilih menu (1-3): ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) { // Login
            while (percobaan < 3) {
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan NIM: ";
                getline(cin, nim);
                cout << endl << endl;

                bool loginBerhasil = false;
                int indexPengguna = -1;

                // Cek apakah nama dan NIM cocok
                for (int i = 0; i < jumlahPengguna; i++) {
                    if (dataPengguna[i].nama == nama && dataPengguna[i].nim == nim) {
                        loginBerhasil = true;
                        indexPengguna = i; // Simpan index pengguna yang login
                        break;
                    }
                }

                if (loginBerhasil) {
                    cout << "Login berhasil! Selamat Datang " << nama << endl << endl;

                    // Menu manajemen ikan setelah login berhasil
                    while (true) {
                        cout << "===================================\n";
                        cout << "=== Program Manajemen Ikan Hias ===\n";
                        cout << "===================================\n";
                        cout << "|1. Tampilkan Ikan                |\n";
                        cout << "|2. Tambah Ikan                   |\n";
                        cout << "|3. Ubah Ikan                     |\n";
                        cout << "|4. Hapus Ikan                    |\n";
                        cout << "|5. Keluar Program                |\n";
                        cout << "===================================\n";
                        cout << "Pilih menu: ";
                        int pilihanMenu;
                        cin >> pilihanMenu;
                        cin.ignore();

                        switch (pilihanMenu) {
                            case 1: // Tampilkan Ikan
                                if (dataPengguna[indexPengguna].jumlahIkan == 0) {
                                    cout << "\nBelum ada ikan yang tersedia." << endl;
                                } else {
                                    cout << "\n=== Daftar Ikan Hias ===" << endl;
                                    for (int i = 0; i < dataPengguna[indexPengguna].jumlahIkan; i++) {
                                        cout << "Ikan ke-" << i + 1 << ":" << endl;
                                        cout << "  Nama: " << dataPengguna[indexPengguna].ikan[i].nama << endl;
                                        cout << "  Jenis: " << dataPengguna[indexPengguna].ikan[i].jenis << endl;
                                        cout << "  Harga: Rp" << dataPengguna[indexPengguna].ikan[i].harga << endl;
                                        cout << "-------------------------" << endl;
                                    }
                                }
                                break;

                            case 2: // Tambah Ikan
                                if (dataPengguna[indexPengguna].jumlahIkan < MAX_IKAN) {
                                    cout << "\n=== Tambah Ikan ===" << endl;
                                    cout << "Masukkan nama ikan: ";
                                    getline(cin, dataPengguna[indexPengguna].ikan[dataPengguna[indexPengguna].jumlahIkan].nama);
                                    cout << "Masukkan jenis ikan: ";
                                    getline(cin, dataPengguna[indexPengguna].ikan[dataPengguna[indexPengguna].jumlahIkan].jenis);
                                    cout << "Masukkan harga ikan: ";
                                    cin >> dataPengguna[indexPengguna].ikan[dataPengguna[indexPengguna].jumlahIkan].harga;
                                    cin.ignore();
                                    dataPengguna[indexPengguna].jumlahIkan++;
                                    cout << "Ikan berhasil ditambahkan!" << endl;
                                } else {
                                    cout << "\nKapasitas penuh! Tidak bisa menambah ikan lagi." << endl;
                                }
                                break;

                            case 3: // Ubah Ikan
                                if (dataPengguna[indexPengguna].jumlahIkan == 0) {
                                    cout << "\nBelum ada ikan yang tersedia untuk diubah." << endl;
                                } else {
                                    cout << "\n=== Ubah Ikan ===" << endl;
                                    cout << "Masukkan nomor ikan yang akan diubah: ";
                                    int index;
                                    cin >> index;
                                    cin.ignore();

                                    if (index > 0 && index <= dataPengguna[indexPengguna].jumlahIkan) {
                                        cout << "Masukkan nama ikan baru: ";
                                        getline(cin, dataPengguna[indexPengguna].ikan[index - 1].nama);
                                        cout << "Masukkan jenis ikan baru: ";
                                        getline(cin, dataPengguna[indexPengguna].ikan[index - 1].jenis);
                                        cout << "Masukkan harga ikan baru: ";
                                        cin >> dataPengguna[indexPengguna].ikan[index - 1].harga;
                                        cin.ignore();
                                        cout << "Ikan berhasil diubah!" << endl;
                                    } else {
                                        cout << "\nNomor ikan tidak valid." << endl;
                                    }
                                }
                                break;

                            case 4: // Hapus Ikan
                                if (dataPengguna[indexPengguna].jumlahIkan == 0) {
                                    cout << "\nBelum ada ikan yang tersedia untuk dihapus." << endl;
                                } else {
                                    cout << "\n=== Hapus Ikan ===" << endl;
                                    cout << "Masukkan nomor ikan yang akan dihapus: ";
                                    int index;
                                    cin >> index;
                                    cin.ignore();

                                    if (index > 0 && index <= dataPengguna[indexPengguna].jumlahIkan) {
                                        for (int i = index - 1; i < dataPengguna[indexPengguna].jumlahIkan - 1; i++) {
                                            dataPengguna[indexPengguna].ikan[i] = dataPengguna[indexPengguna].ikan[i + 1];
                                        }
                                        dataPengguna[indexPengguna].jumlahIkan--;
                                        cout << "Ikan berhasil dihapus!" << endl;
                                    } else {
                                        cout << "\nNomor ikan tidak valid." << endl;
                                    }
                                }
                                break;

                            case 5: // Keluar
                                cout << "\nTerima kasih! Kembali ke menu utama." << endl;
                                goto keluarMenu; // Keluar dari menu manajemen ikan

                            default:
                                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                                break;
                        }
                    }
                keluarMenu:
                    break;
                } else {
                    percobaan++;
                    cout << "Login gagal. Sisa percobaan: " << 3 - percobaan << endl;
                    break;
                }
            }
        } else if (pilihan == 2) { // Register
            if (jumlahPengguna >= MAX_PENGGUNA) {
                cout << "Batas pengguna telah tercapai. Tidak bisa mendaftar lagi." << endl;
            } else {
                cout << "\n=== Register Pengguna ===" << endl;
                cout << "Masukkan nama: ";
                getline(cin, dataPengguna[jumlahPengguna].nama);
                cout << "Masukkan NIM: ";
                getline(cin, dataPengguna[jumlahPengguna].nim);
                jumlahPengguna++;
                cout << "Pengguna berhasil terdaftar!" << endl;
            }
        } else if (pilihan == 3) { // Exit
            cout << "\nTerima kasih! Program selesai." << endl;
            return 0;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}