/* File SEMENTARA untuk ngetes bagian Anggota 1. Jangan dipakai sebagai main.c final. */
#include <stdio.h>
#include <stdlib.h>
#include "../include/models.h"
#include "../include/file_io.h"
#include "../include/auth.h"

int main(void)
{
    Buku *buku = NULL;
    User *user = NULL;
    Peminjaman *pinjam = NULL;
    int n_buku = 0;
    int n_user = 0;
    int n_pinjam = 0;
    int i;
    const User *login;

    if (!file_ada(FILE_BUKU)) {
        if (import_buku_asli(FILE_BUKU_ASLI, FILE_BUKU, STOK_DEFAULT) < 0) {
            printf("Gagal membuka %s\n", FILE_BUKU_ASLI);
            return 1;
        }
    }

    if (!muat_buku(FILE_BUKU, &buku, &n_buku) ||
        !muat_user(FILE_USER, &user, &n_user) ||
        !muat_peminjaman(FILE_PEMINJAMAN, &pinjam, &n_pinjam)) {
        printf("Gagal memuat salah satu file data.\n");
        free(buku);
        free(user);
        free(pinjam);
        return 1;
    }

    printf("Buku: %d | User: %d | Peminjaman: %d\n", n_buku, n_user, n_pinjam);
    for (i = 0; i < 3 && i < n_buku; i++) {
        printf("%s | %s | %s | %d | %d hlm | stok %d\n",
               buku[i].ocaid, buku[i].title, buku[i].author,
               buku[i].year, buku[i].page_count, buku[i].stok);
    }

    simpan_buku("books_copy.txt", buku, n_buku);   /* tes tulis ulang */

    login = proses_login(user, n_user);
    if (login == NULL) {
        printf("Login gagal.\n");
    }

    free(buku);
    free(user);
    free(pinjam);
    return 0;
}
