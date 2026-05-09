#include "types.h"

// Dýþarýdan fonksiyonlarý çaðýrýyoruz
extern void initHashTable();
extern void insertPackage(int id, const char* city);
extern Graph* createGraph(int vertices);
extern void addEdge(Graph* graph, int src, int dest);
extern void DFS(Graph* graph, int vertex);
extern Package hashTable[HASH_SIZE];

// Bellek Ýzleme Raporu
void printMemoryReport(Graph* graph) {
    printf("\n=== BELLEK IZLEME RAPORU ===\n");
    
    printf("\n[1] HASH TABLOSU (Paketler - Statik Dizi Adresleri)\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        if (hashTable[i].is_occupied) {
            printf("Indis %d | Paket ID: %d | Hedef: %-10s | RAM Adresi: %p\n", 
                   i, hashTable[i].package_id, hashTable[i].destination_city, (void*)&hashTable[i]);
        }
    }

    printf("\n[2] GRAF YAPISI (Dinamik Tahsis Edilmiþ Düðümler)\n");
    printf("Graf Ana Struct RAM Adresi: %p\n", (void*)graph);
    for (int i = 0; i < graph->num_vertices; i++) {
        CityNode* temp = graph->adj_lists[i];
        printf("Þehir %d Baþlangýç Noktasý (Array Adresi): %p\n", i, (void*)&graph->adj_lists[i]);
        while (temp) {
            printf("  -> Hedef Þehir: %d | Node Adresi: %p | Next Pointer: %p\n", 
                   temp->city_id, (void*)temp, (void*)temp->next);
            temp = temp->next;
        }
    }
    printf("============================\n");
}

int main() {
    // 1. Sistemleri Baþlat
    initHashTable();
    Graph* map = createGraph(5); // 0'dan 4'e kadar 5 þehir

    printf("--- Lojistik Paket Ekleme (Hash Tablosu) ---\n");
    // En az 5 veri giriþi. Çakýþma (Collision) yaratmak için bilerek Mod 10'da ayný kalaný verecek ID'ler kullanýyoruz (102 ve 202 gibi)
    insertPackage(102, "Istanbul");
    insertPackage(202, "Ankara");   // Çakýþma olacak, 102'nin yanýna (Açýk Adresleme) yerleþecek.
    insertPackage(305, "Izmir");
    insertPackage(408, "Bursa");
    insertPackage(505, "Antalya");  // Çakýþma olacak, 305'in yanýna yerleþecek.

    printf("\n--- Þehir Baðlantýlarý Ekleme (Graf) ---\n");
    addEdge(map, 0, 1);
    addEdge(map, 0, 2);
    addEdge(map, 1, 3);
    addEdge(map, 2, 4);

    printf("\n--- Rota Gezinme (DFS) ---\n");
    DFS(map, 0);

    // 2. RAM Raporunu Al
    printMemoryReport(map);

    // Gerçek bir C projesinde malloc ile alýnan bellekler free() ile temizlenmelidir.
    // Þimdilik raporu görmek için kodu burada sonlandýrýyoruz.
    return 0;
}
