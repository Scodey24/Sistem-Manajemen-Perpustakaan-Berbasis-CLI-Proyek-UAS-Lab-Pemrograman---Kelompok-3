#ifndef AUTH_H
#define AUTH_H

#include "models.h"

const User *cari_user_login(const User *daftar, int jumlah,
                            const char *username, const char *password);

const User *proses_login(const User *daftar, int jumlah);

#endif
