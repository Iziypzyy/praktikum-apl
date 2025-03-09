#include <iostream>

using namespace std;

bool login() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Masukkan Nama: ";
        cin >> nama;
        cout << "Masukkan 3 digit terakhir NIM: ";
        cin >> nim;

        if (nama == "zifa" && nim == "025") {
            return true;
        } else {
            percobaan++;
            cout << "Login gagal! Percobaan " << percobaan << " dari 3." << endl;
        }
    }
    return false;
}

int Menu_utama() {
    int pilihan;
    cout << "                   Selamat Datang                        " << endl << endl;
    cout << "=========================================================" << endl;
    cout << "|                 MENU KONVERSI SUHU                    |" << endl;
    cout << "=========================================================" << endl;
    cout << "| 1. Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin |" << endl;
    cout << "| 2. Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin |" << endl;
    cout << "| 3. Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin |" << endl;
    cout << "| 4. Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur |" << endl;
    cout << "| 5. Keluar dari Program                                |" << endl;
    cout << "=========================================================" << endl;
    cout << "Pilih satuan suhu yang ingin di konversi (1-5): ";
    cin >> pilihan;
    return pilihan;
}

int main() {
    if (!login()) {
        cout << "Sorry ye udah login 3 kali nieh ye. coba niekstim." << endl;
        return 0;
    }

    int pilihan;
    while (true) {
        pilihan = Menu_utama();

        if (pilihan == 5) {
            cout << "THANKS BANG/MBA UDA MAU COBA PROGRAMNYA, RESPECT!" << endl << endl;
            break;
        }

        double suhu;
        cout << "Masukkan nilai suhu: ";
        cin >> suhu;

        switch (pilihan) {
            case 1: // Konversi Celcius ke Fahrenheit, Reamur, dan Kelvin
                cout << "Fahrenheit: " << (suhu * 9 / 5) + 32 << endl;
                cout << "Reamur: " << suhu * 4 / 5 << endl;
                cout << "Kelvin: " << suhu + 273.15 << endl;
                break;
            case 2: // Konversi Fahrenheit ke Celcius, Reamur, dan Kelvin
                cout << "Celcius: " << (suhu - 32) * 5 / 9 << endl;
                cout << "Reamur: " << (suhu - 32) * 4 / 9 << endl;
                cout << "Kelvin: " << (suhu - 32) * 5 / 9 + 273.15 << endl;
                break;
            case 3: // Konversi Reamur ke Celcius, Fahrenheit, dan Kelvin
                cout << "Celcius: " << suhu * 5 / 4 << endl;
                cout << "Fahrenheit: " << (suhu * 9 / 4) + 32 << endl;
                cout << "Kelvin: " << suhu * 5 / 4 + 273.15 << endl;
                break;
            case 4: // Konversi Kelvin ke Celcius, Fahrenheit, dan Reamur
                cout << "Celcius: " << suhu - 273.15 << endl;
                cout << "Fahrenheit: " << (suhu - 273.15) * 9 / 5 + 32 << endl;
                cout << "Reamur: " << (suhu - 273.15) * 4 / 5 << endl;
                break;
            default: //buat yang milih <1 dan 5>
                cout << "Pilihan tidak valid!" << endl;
                break;
        }

    }

    return 0;
}