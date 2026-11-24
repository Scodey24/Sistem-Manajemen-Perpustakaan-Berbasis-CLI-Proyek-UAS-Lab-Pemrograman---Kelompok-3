# Sistem Manajemen Perpustakaan Berbasis CLI (Project UAS)

Aplikasi Sistem Manajemen Perpustakaan berbasis antarmuka baris perintah (*Command Line Interface* / CLI) yang dibangun menggunakan bahasa pemrograman **C (standar C99)**. Proyek ini dikembangkan untuk memenuhi tugas Ujian Akhir Semester (UAS) Praktikum Pemrograman Kelas A, Program Studi Informatika, FMIPA Universitas Syiah Kuala.

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
```

---

## Panduan Kompilasi (Compile) & Menjalankan Program (Run)

### 1. Prasyarat

- Compiler C (`gcc`)
- Utilitas `make` (opsional, tetapi direkomendasikan)

### 2. Kompilasi

Jalankan dari **direktori root proyek** (folder yang berisi `Makefile`).

**Menggunakan `Makefile` (direkomendasikan):**

```bash
make
```

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

```bash
make clean
```

---

## Akun Pengujian Default

`data/user.txt`:

| Role | Username | Password |
| --- | --- | --- |
| **Admin** | `admin` | `admin123` |
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