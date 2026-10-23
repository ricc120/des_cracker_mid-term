#include <iostream>
#include <crypt.h>
#include <omp.h>

int main() {
    // OpenMP Test
#pragma omp parallel
    {
#pragma omp single
        std::cout << "[OK] OpenMP running. Total thread executing: "
                  << omp_get_num_threads() << "\n";
    }

    // libcrypt test (thread-safe)
    struct crypt_data data;
    data.initialized = 0; // Initialization to 0 is mandatory before the use

    const char* password_prova = "secret";
    const char* salt = "HX";

    // crypt_r needs struct pointer of the local data to avoid race conditions
    char* hash = crypt_r(password_prova, salt, &data);

    if (hash != nullptr) {
        std::cout << "[OK] libcrypt running.\n"
                  << "     Password: " << password_prova << "\n"
                  << "     Salt: " << salt << "\n"
                  << "     Hash (DES): " << hash << "\n";
    } else {
        std::cerr << "[ERROR] Failed hash generation.\n";
    }

    return 0;
}