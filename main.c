#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10

// Hash Tablosu için Paket Yapýsý
typedef struct {
    int package_id;
    char destination_city[30];
    int is_occupied; // 0: Boþ, 1: Dolu
} Package;

// Graf için Þehir (Düðüm) Yapýsý
typedef struct CityNode {
    int city_id;
    struct CityNode* next;
} CityNode;

// Graf Yapýsý
typedef struct {
    int num_vertices;
    CityNode** adj_lists;
    int* visited;
} Graph;

#endif
