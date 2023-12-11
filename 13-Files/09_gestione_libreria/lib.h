typedef struct {
	char nome[65], cognome[65];
} auth;

typedef struct {
	int codice, copie;
	char titolo[65];
	auth autore;
} libro;

auth creaAutore();
int creaLibro(libro* dest);
int creaVettore(libro v[], int dim);
void ricercaLibro(libro v[], int len);
void caricaInBin(FILE* fb, libro arr[], int lenV);
void scaricaDaBin(FILE* fb, libro arr[], int dim, int lenV);