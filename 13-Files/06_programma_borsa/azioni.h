typedef struct {
	char nome[64];
	float apertura, chiusura;
	int giorno;
} azione;

int leggi(FILE* fp, azione dest[], int dim, char* nome);
azione trovaMin(azione src[], int dim, float* val);
azione trovaMax(azione src[], int dim, float* val);
float myMin(float a, float b);
float myMax(float a, float b);