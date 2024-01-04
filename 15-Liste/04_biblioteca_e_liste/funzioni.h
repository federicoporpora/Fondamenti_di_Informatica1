typedef struct {
	char autore[24], titolo[56];
	int numero_possedute, numero_prestito;
} volume;

int creaVettoreDaFile(FILE* fp, volume V[]);
void stampaV(volume V[], int len);
list creaLista(volume V[], int len);
float stampaRapporti(volume V[], list L, int len);
int piuDisponibili(list L);
void stampaRiga(FILE* fp, int riga);