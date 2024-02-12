#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FILE_LEN 128

//campo della data da lasciare cosi
//se i primi due campi sono punti interrogativi cancella la riga
//se tutti i campi tranne i primi due sono punti interrogativi cancella la riga
//occhio alla prima riga che va copiata pari pari
//sostituisci tutti i punti interrogativi con -999
//compara i primi 5 fattori e se sono uguali cancella

typedef struct {
	char* timestamp, *mis1, *mis2, *mis3, *mis4, *mis5, *resto;
} Riga;

char* leggi_fino_a(FILE* file, char carattere); //legge fino ad un determinato carattere e lo mette in una stringa dinamicamente allocata
char* replaceQuestionMarks(const char* input); //rimpiazza tutti i punti interrogativi in una stringa
void leggiRiga(FILE* input, FILE* output); //per leggere la prima riga e metterla direttamente nel file modificato
int contaRighe(FILE* fp); //conta le righe per decidere quanto far durare il loop while
void strConSpazi(char* stringa, int dim); //per prendere da standard input stringhe contenenti anche gli spazi

int main() {

	FILE* lettura;
	FILE* scrittura;

	//nomi dei file
	char nomeFileLettura[FILE_LEN + 5];
	char nomeFileScrittura[FILE_LEN + 11];
	printf("Inserire il nome del file (max %d caratteri): ", FILE_LEN);
	strConSpazi(nomeFileLettura, FILE_LEN);
	strcpy(nomeFileScrittura, nomeFileLettura);
	strcat(nomeFileLettura, ".txt");
	strcat(nomeFileScrittura, " Corretto.txt");

	if ((lettura = fopen(nomeFileLettura, "r")) == NULL) {
		perror("Il file non esiste");
		exit(1);
	}
	
	if ((scrittura = fopen(nomeFileScrittura, "w")) == NULL) {
		perror("Non è stato possibile creare il file in scrittura");
		exit(2);
	}

	int righe = contaRighe(lettura) - 1;

	leggiRiga(lettura, scrittura);	//scrittura della prima riga nel secondo file

	Riga temp, temp2;
	int daStampare = 0;

	temp.timestamp = leggi_fino_a(lettura, '\t');
	temp.mis1 = leggi_fino_a(lettura, '\t');
	temp.mis2 = leggi_fino_a(lettura, '\t');
	temp.mis3 = leggi_fino_a(lettura, '\t');
	temp.mis4 = leggi_fino_a(lettura, '\t');
	temp.mis5 = leggi_fino_a(lettura, '\t');
	temp.resto = leggi_fino_a(lettura, '\n');
	for (int i = 0; temp.resto[i] != '\0'; i++) {
		if (temp.resto[i] != '?' && temp.resto[i] != '\t') { // se c'è almeno un carattere nel resto che non sia \t o ? dice che è una riga da stampare
			daStampare = 1;
			break;
		}
	}
	if ((temp.mis1[0] != '?' && temp.mis2[0] != '?' && temp.mis3[0] != '?' && temp.mis4[0] != '?' && temp.mis5[0] != '?') && daStampare == 1) {
		daStampare = 1; //controlla che i primi 5 campi siano tutti presenti e nel resto ci sia scritto qualcosa
	}
	else { daStampare = 0; }
	temp.resto = replaceQuestionMarks(temp.resto); //rimpiazza i ? con -999
	if (daStampare == 1) { //stampa
		fprintf(scrittura, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", temp.timestamp, temp.mis1, temp.mis2, temp.mis3, temp.mis4, temp.mis5, temp.resto);
	}

	for (int j = 0; j < righe - 1; j++) {
		daStampare = 0;

		//prendere tutte le stringhe e metterle nella struttura temporanea
		temp2.timestamp = leggi_fino_a(lettura, '\t');
		temp2.mis1 = leggi_fino_a(lettura, '\t');
		temp2.mis2 = leggi_fino_a(lettura, '\t');
		temp2.mis3 = leggi_fino_a(lettura, '\t');
		temp2.mis4 = leggi_fino_a(lettura, '\t');
		temp2.mis5 = leggi_fino_a(lettura, '\t');
		temp2.resto = leggi_fino_a(lettura, '\n');
		for (int i = 0; temp2.resto[i] != '\0'; i++) {
			if (temp2.resto[i] != '?' && temp2.resto[i] != '\t') { // se c'è almeno un carattere nel resto che non sia \t o ? dice che è una riga da stampare
				daStampare = 1;
				break;
			}
		}
		if ((temp2.mis1[0] != '?' && temp2.mis2[0] != '?' && temp2.mis3[0] != '?' && temp2.mis4[0] != '?' && temp2.mis5[0] != '?') && daStampare == 1) {
			daStampare = 1; //controlla che i primi 5 campi siano tutti presenti e nel resto ci sia scritto qualcosa
		}
		else { daStampare = 0; }
		temp2.resto = replaceQuestionMarks(temp2.resto); //rimpiazza i ? con -999
		if ((strcmp(temp.resto, temp2.resto) == 0)) {
			daStampare = 0;
		}
		else {
			temp = temp2;
		}
		if (daStampare == 1) { //stampa
			fprintf(scrittura, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", temp2.timestamp, temp2.mis1, temp2.mis2, temp2.mis3, temp2.mis4, temp2.mis5, temp2.resto);
		}
		
	}

	fclose(lettura);
	fclose(scrittura);

	printf("COMPLETATO! (premere invio per uscire)");
	scanf("%*c");

	return 0;

}

char* leggi_fino_a(FILE* file, char carattere) {
	int dimensione_buffer = 100; // Dimensione iniziale del buffer
	int posizione = 0; // Posizione attuale nel buffer
	char* buffer = (char*)malloc(dimensione_buffer * sizeof(char)); // Allocazione iniziale del buffer

	if (buffer == NULL) {
		return NULL; // Errore di allocazione
	}

	char c;
	while ((c = fgetc(file)) != carattere && c != EOF) {
		if (posizione >= dimensione_buffer - 1) {
			// Se raggiungiamo la fine del buffer, riallochiamo il buffer con una dimensione maggiore
			dimensione_buffer *= 2;
			char* temp = (char*)realloc(buffer, dimensione_buffer * sizeof(char));
			if (temp == NULL) {
				free(buffer);
				return NULL; // Errore di riallocazione
			}
			buffer = temp;
		}
		buffer[posizione++] = c;
	}

	buffer[posizione] = '\0'; // Terminatore della stringa

	// Rialloca la memoria per adattarla alla dimensione effettiva della stringa
	char* risultato = (char*)malloc((posizione + 1) * sizeof(char));
	if (risultato == NULL) {
		free(buffer);
		return NULL; // Errore di allocazione
	}

	// Copia il contenuto dal buffer alla stringa risultato
	for (int i = 0; i <= posizione; i++) {
		risultato[i] = buffer[i];
	}

	free(buffer); // Libera il buffer temporaneo

	return risultato;
}

char* replaceQuestionMarks(const char* input) {
	size_t input_length = strlen(input);
	// Allochiamo dinamicamente la memoria per la nuova stringa
	char* result = (char*)malloc((input_length * 4 + 1) * sizeof(char)); // +1 per il terminatore null

	if (result == NULL) {
		printf("Errore: impossibile allocare memoria.\n");
		exit(1);
	}

	// Inizializziamo l'indice per la nuova stringa
	size_t result_index = 0;

	// Scorriamo la stringa di input
	for (size_t i = 0; i < input_length; i++) {
		if (input[i] == '?') {
			// Sostituiamo il '?' con "-999"
			result[result_index++] = '-';
			result[result_index++] = '9';
			result[result_index++] = '9';
			result[result_index++] = '9';
		}
		else {
			// Copiamo il carattere invariato
			result[result_index++] = input[i];
		}
	}

	// Aggiungiamo il terminatore null alla fine della nuova stringa
	result[result_index] = '\0';

	return result;
}

void leggiRiga(FILE* input, FILE* output) {
	char carattere;

	// Leggi carattere per carattere fino a quando non trovi '\n' o EOF
	while ((carattere = fgetc(input)) != '\n' && carattere != EOF) {
		fputc(carattere, output); // Scrivi il carattere nel file di output
	}

	// Aggiungi un carattere di nuova riga nel file di output
	fputc('\n', output);
}

int contaRighe(FILE* fp) {
	int righe = 0;
	char carattere;

	// Legge il file carattere per carattere fino alla fine del file
	while ((carattere = fgetc(fp)) != EOF) {
		if (carattere == '\n') {
			righe++;
		}
	}

	// Conteggio finale della riga se il file non termina con un newline
	if (carattere != '\n' && righe != 0) {
		righe++;
	}

	rewind(fp);

	return righe;
}

void strConSpazi(char* stringa, int dim) {
	int c;
	int i = 0;

	while ((c = getchar()) != '\n' && c != EOF && i < dim - 1) {
		stringa[i++] = c;
	}

	stringa[i] = '\0';
}