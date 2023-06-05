#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk menyimpan tugas
struct Task {
    string nama;
    bool selesai;
};

// Fungsi untuk menambahkan tugas baru ke dalam daftar
void tambahkanTugas(vector<Task>& daftarTugas, const string& namaTugas) {
    Task tugas;
    tugas.nama = namaTugas;
    tugas.selesai = false;
    daftarTugas.push_back(tugas);
    cout << "Tugas \"" << namaTugas << "\" berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan daftar tugas
void tampilkanDaftarTugas(const vector<Task>& daftarTugas) {
    if (daftarTugas.empty()) {
        cout << "Daftar tugas kosong." << endl;
    } else {
        cout << "Daftar tugas:" << endl;
        for (size_t i = 0; i < daftarTugas.size(); ++i) {
            const Task& tugas = daftarTugas[i];
            cout << "[" << (tugas.selesai ? 'v' : 'x') << "] " << tugas.nama << endl;
        }
    }
}

// Fungsi untuk menandai tugas sebagai selesai
void tandaiSelesai(vector<Task>& daftarTugas, int indeks) {
    if (indeks >= 0 && indeks < daftarTugas.size()) {
        Task& tugas = daftarTugas[indeks];
        tugas.selesai = true;
        cout << "Tugas \"" << tugas.nama << "\" telah ditandai sebagai selesai." << endl;
    } else {
        cout << "Indeks tugas tidak valid." << endl;
    }
}

int main() {
    vector<Task> daftarTugas;

    while (true) {
        cout << "===== TODO LIST =====" << endl;
        cout << "Pilih operasi yang ingin Anda lakukan:" << endl;
        cout << "1. Tambahkan tugas baru" << endl;
        cout << "2. Tampilkan daftar tugas" << endl;
        cout << "3. Tandai tugas sebagai selesai" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";

        int pilihan;
        cin >> pilihan;

        if (pilihan == 0) {
            break;
        } else if (pilihan == 1) {
            cout << "Masukkan nama tugas: ";
            string namaTugas;
            cin.ignore();
            getline(cin, namaTugas);
            tambahkanTugas(daftarTugas, namaTugas);
        } else if (pilihan == 2) {
            tampilkanDaftarTugas(daftarTugas);
        } else if (pilihan == 3) {
            cout << "Masukkan indeks tugas yang ingin Anda tandai sebagai selesai: ";
            int indeks;
            cin >> indeks;
            tandaiSelesai(daftarTugas, indeks);
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    }

    cout << "Terima kasih telah menggunakan program todo list." << endl;

    return 0;
}

