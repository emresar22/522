#include "types.h"

Package hashTable[HASH_SIZE];

// Init HashTable
void initHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i].is_occupied = 0;
    }
}

// Tip A: Modüler Hash Fonksiyonu
int hashFunctionTypeA(int key) {
    return key % HASH_SIZE;
}

// Açýk Adresleme (Linear Probing) ile Ekleme
void insertPackage(int id, const char* city) {
    int index = hashFunctionTypeA(id);
    int original_index = index;

    while (hashTable[index].is_occupied) {
        printf("Çakýþma tespit edildi (Paket ID: %d, Indis: %d). Açýk adresleme uygulanýyor...\n", id, index);
        index = (index + 1) % HASH_SIZE;
        
        if (index == original_index) {
            printf("Hash tablosu dolu!\n");
            return;
        }
    }

    hashTable[index].package_id = id;
    strcpy(hashTable[index].destination_city, city);
    hashTable[index].is_occupied = 1;
    printf("Paket %d baþarýyla eklendi. (Indis: %d)\n", id, index);
}
