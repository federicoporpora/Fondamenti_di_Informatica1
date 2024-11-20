#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_SONGS 1000

// Struttura per rappresentare una canzone
typedef struct {
    char title[256];
} Song;

// Funzione per leggere le canzoni da un file CSV
int readSongsFromFile(const char* filename, Song songs[]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Errore nell'apertura del file");
        return -1;
    }

    char line[MAX_LINE];
    int count = 0;

    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ",");
        if (token && count < MAX_SONGS) {
            strncpy(songs[count].title, token, sizeof(songs[count].title) - 1);
            songs[count].title[sizeof(songs[count].title) - 1] = '\0'; // Garantire terminazione
            count++;
        }
    }

    fclose(file);
    return count;
}

// Funzione per verificare se una canzone è presente in un array
int isSongInList(const Song* song, const Song list[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (strcmp(song->title, list[i].title) == 0) {
            return 1; // Trovata
        }
    }
    return 0; // Non trovata
}

int main() {
    char file1[256], file2[256];
    Song playlist1[MAX_SONGS], playlist2[MAX_SONGS];
    int count1, count2;

    // Chiedere i nomi dei file
    printf("Inserisci il nome del primo file (inclusa l'estensione .csv): ");
    scanf("%255s", file1);
    printf("Inserisci il nome del secondo file (inclusa l'estensione .csv): ");
    scanf("%255s", file2);

    // Leggere le canzoni dai file
    count1 = readSongsFromFile(file1, playlist1);
    if (count1 < 0) return 1;

    count2 = readSongsFromFile(file2, playlist2);
    if (count2 < 0) return 1;

    // Stampare le canzoni nella prima playlist ma non nella seconda
    printf("Canzoni presenti solo nella prima playlist:\n");
    for (int i = 0; i < count1; i++) {
        if (!isSongInList(&playlist1[i], playlist2, count2)) {
            printf("%s\n", playlist1[i].title);
        }
    }

    return 0;
}
