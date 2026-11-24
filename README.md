# Sistem Manajemen Perpustakaan Berbasis CLI (Project UAS)

<<<<<<< HEAD
Aplikasi Sistem Manajemen Perpustakaan berbasis antarmuka baris perintah (*Command Line Interface* / CLI) yang dibangun menggunakan bahasa pemrograman **C Standar (ANSI/C)**. Proyek ini dikembangkan untuk memenuhi tugas Ujian Akhir Semester (UAS) Praktikum Pemrograman Kelas A, Program Studi Informatika, FMIPA Universitas Syiah Kuala.
=======
Aplikasi Sistem Manajemen Perpustakaan berbasis antarmuka baris perintah (*Command Line Interface* / CLI) yang dibangun menggunakan bahasa pemrograman **C (standar C99)**. Proyek ini dikembangkan untuk memenuhi tugas Ujian Akhir Semester (UAS) Praktikum Pemrograman Kelas A, Program Studi Informatika, FMIPA Universitas Syiah Kuala.
>>>>>>> tes-run

---

## Anggota Kelompok

| No. | Nama Lengkap | NPM | Peran / Modul Tanggung Jawab |
| --- | --- | --- | --- |
| 1 | Raffi Akbar | 260810701100055 | Arsitek Data, Autentikasi, & File Handling |
| 2 | Aishara | 260810701100058 | Modul Hak Akses Admin (CRUD & Laporan) |
| 3 | Bunga Thahira Putri Akram | 260810701100003 | Modul Hak Akses User (Sirkulasi & Pencarian) |
| 4 | Syarifah Keisya Kirany | 260810701100056 | Modul Algoritma Sorting, Main Controller, & Repo |

---

## Deskripsi & Fitur Utama

<<<<<<< HEAD
Aplikasi ini mengelola sirkulasi peminjaman buku dan katalog perpustakaan dengan penyimpanan data persisten berbasis berkas teks (`.txt`):

1. **Autentikasi & Manajemen Hak Akses (*Role-Based Access*):**
    - Mendukung login interaktif maupun melalui *Command Line Arguments* (CLA).
    - Pemisahan hak akses antara **Admin (Pustakawan)** dan **User (Mahasiswa/Anggota)**.
2. **Fitur Admin:**
    - **CRUD Katalog:** Menambah, melihat, memperbarui, dan menghapus data buku di `Books.txt`.
    - **Laporan Transaksi:** Melihat riwayat peminjaman seluruh pengguna secara global dari `peminjaman.txt`.
3. **Fitur User:**
    - Melihat katalog buku tersedia dan mencari buku berdasarkan ID (`ocaid`) atau Judul (`title`).
    - Melakukan transaksi **Peminjaman** (otomatis mengurangi stok) dan **Pengembalian** (otomatis menambah stok).
    - Melihat daftar peminjaman pribadi yang sedang aktif.
4. **Pengurutan Katalog (3 Algoritma Manual):**
    - Implementasi mandiri tanpa fungsi bawaan `qsort` untuk **Bubble Sort**, **Selection Sort**, dan **Insertion Sort**.
    - Mendukung pengurutan *Ascending* maupun *Descending* berdasarkan ID Buku (`ocaid`), Judul (`title`), Tahun Terbit (`year`), dan Jumlah Halaman (`page_count`) / Stok.

---

## Arsitektur Aplikasi & Struktur File

Program dirancang secara modular untuk memudahkan pemeliharaan kode (*clean code*) dan kolaborasi tim:

```
├── main.c             # Entry point program, alur menu utama, dan manajemen sesi
├── models.h           # Definisi struct utama (Buku, User, Peminjaman)
├── file_handler.h     # Deklarasi fungsi I/O berkas teks
├── file_handler.c     # Implementasi parsing dan sinkronisasi data (.txt)
├── auth.h             # Deklarasi fungsi autentikasi pengguna
├── auth.c             # Implementasi login (CLI & CLA) dan validasi role
├── admin.h            # Deklarasi fungsi fitur Admin
├── admin.c            # Implementasi CRUD buku dan laporan transaksi global
├── user.h             # Deklarasi fungsi fitur User
├── user.c             # Implementasi pencarian, peminjaman, dan pengembalian
├── sorting.h          # Deklarasi fungsi algoritma pengurutan
├── sorting.c          # Implementasi manual Bubble, Selection, dan Insertion Sort
├── Makefile           # Otomatisasi proses kompilasi (compiling & linking)
├── Books.txt          # Basis data katalog buku perpustakaan
├── user.txt           # Basis data kredensial akun (username, password, role)
├── peminjaman.txt     # Basis data rekaman transaksi peminjaman
└── README.md          # Dokumentasi proyek
=======
Aplikasi ini mengelola katalog dan sirkulasi peminjaman buku dengan penyimpanan data persisten berbasis berkas teks (`.txt`):

1. **Autentikasi & Hak Akses (*Role-Based Access*):**
    - Login interaktif (username & password) dengan maksimal **3 kali percobaan**.
    - Pemisahan hak akses antara **Admin (Pustakawan)** dan **User (Mahasiswa/Anggota)** berdasarkan kolom `role` pada `user.txt`.
2. **Fitur Admin:**
    - **CRUD Katalog:** menambah, menampilkan, mengubah, dan menghapus data buku (disimpan ke `books_data.txt`).
    - **Pengurutan Katalog:** menu pengurutan langsung dari menu admin.
    - **Laporan Transaksi:** melihat seluruh riwayat peminjaman semua pengguna dari `peminjaman.txt`.
3. **Fitur User:**
    - **Cari Buku** berdasarkan ID (`ocaid`) atau potongan Judul (`title`, *case-sensitive*).
    - **Pinjam Buku** (stok otomatis berkurang, tanggal diinput format `DD-MM-YYYY`).
    - **Kembalikan Buku** (stok otomatis bertambah; hanya bisa mengembalikan transaksi milik akun sendiri).
    - **Riwayat Peminjaman** pribadi (semua status: `DIPINJAM` dan `KEMBALI`).
4. **Pengurutan Katalog (3 Algoritma Manual):**
    - Implementasi mandiri tanpa `qsort` untuk **Insertion Sort**, **Bubble Sort**, dan **Selection Sort**.
    - Mendukung *Ascending* maupun *Descending* berdasarkan ID Buku, Judul, Tahun Terbit, Jumlah Halaman, atau Stok.
5. **Import Otomatis Dataset:**
    - Jika `data/books_data.txt` belum ada, program otomatis mengimpor `data/Books.txt` (dataset master) ke `books_data.txt` dengan format pipa `|` dan menambahkan kolom stok (default **3** per buku).

---

## Struktur Folder & File

```
Sistem-Manajemen-Perpustakaan/
├── Makefile               # Otomatisasi kompilasi (hasil: src/app)
├── README.md              # Dokumentasi proyek
├── data/
│   ├── Books.txt          # Dataset master katalog (hanya dibaca saat import awal)
│   ├── books_data.txt     # Data buku operasional (ocaid|title|author|year|page_count|stok)
│   ├── user.txt           # Kredensial akun (username password role)
│   └── peminjaman.txt     # Rekaman transaksi (id username ocaid tanggal status)
├── include/
│   ├── models.h           # Definisi struct Buku, User, Peminjaman & konstanta
│   ├── file_io.h          # Deklarasi fungsi I/O berkas & path data
│   ├── auth.h             # Deklarasi fungsi autentikasi
│   ├── admin.h            # Deklarasi fitur Admin
│   ├── user.h             # Deklarasi fitur User
│   └── sorting.h          # Deklarasi algoritma pengurutan
└── src/
    ├── main.c             # Entry point, menu utama, alur sesi
    ├── file_io.c          # Parsing, import, muat & simpan data .txt
    ├── auth.c             # Proses login & validasi kredensial
    ├── admin.c            # CRUD buku & laporan transaksi
    ├── user.c             # Cari, pinjam, kembalikan, riwayat
    └── sorting.c          # Bubble, Selection, Insertion Sort & menu sorting
>>>>>>> tes-run
```

---

## Panduan Kompilasi (Compile) & Menjalankan Program (Run)

### 1. Prasyarat

<<<<<<< HEAD
- Compiler C standar (`gcc`)
- Utilitas `make` (opsional, jika menggunakan `Makefile`)

### 2. Kompilasi Program

Buka terminal pada direktori utama proyek, lalu jalankan perintah berikut:

**Menggunakan `Makefile` (Direkomendasikan):**
=======
- Compiler C (`gcc`)
- Utilitas `make` (opsional, tetapi direkomendasikan)

### 2. Kompilasi

Jalankan dari **direktori root proyek** (folder yang berisi `Makefile`).

**Menggunakan `Makefile` (direkomendasikan):**
>>>>>>> tes-run

```bash
make
```

<<<<<<< HEAD
**Atau kompilasi manual menggunakan `gcc`:**

```bash
gcc -Wall -Wextra -std=c99 main.c file_handler.c auth.c admin.c user.c sorting.c -o perpustakaan
```

### 3. Menjalankan Program

Setelah proses kompilasi berhasil dan menghasilkan file executable (`perpustakaan` atau `perpustakaan.exe` pada Windows), jalankan aplikasi dengan salah satu cara berikut:

**Mode Interaktif Standar:**

```bash
./perpustakaan
```

**Mode Command Line Arguments (Langsung Login):**

```bash
./perpustakaan <username> <password>
```

*(Contoh: `./perpustakaan admin1 rahasia123`)*

### 4. Membersihkan File Hasil Kompilasi

Untuk menghapus file objek (`.o`) dan executable hasil build:
=======
**Atau manual menggunakan `gcc`:**

```bash
gcc -Wall -Wextra -std=c99 -Iinclude src/main.c src/admin.c src/auth.c src/file_io.c src/sorting.c src/user.c -o app
```


### 3. Menjalankan Program


**Cara termudah (dari root):**

```bash
make run
```

**Atau manual:**

```bash
cd src
./app
atau
.\src\app.exe
```


### 4. Membersihkan Hasil Kompilasi
>>>>>>> tes-run

```bash
make clean
```

---

<<<<<<< HEAD
## Akun Pengujian Default (Testing Credentials)

Gunakan kredensial berikut (sesuai isi `user.txt`) untuk menguji fitur masing-masing peran:
=======
## Akun Pengujian Default

`data/user.txt`:
>>>>>>> tes-run

| Role | Username | Password |
| --- | --- | --- |
| **Admin** | `admin` | `admin123` |
<<<<<<< HEAD
| **User** | `mahasiswa1` | `mhs123` |
=======
| **User** | `budi` | `budi123` |
| **User** | `siti` | `siti123` |

---

## Format Berkas Data

| Berkas | Format per baris |
| --- | --- |
| `books_data.txt` | `ocaid\|judul\|penulis\|tahun\|halaman\|stok` |
| `user.txt` | `username password role` (dipisah spasi) |
| `peminjaman.txt` | `id username ocaid DD-MM-YYYY status` (status: `DIPINJAM` / `KEMBALI`) |

---
>>>>>>> tes-run
