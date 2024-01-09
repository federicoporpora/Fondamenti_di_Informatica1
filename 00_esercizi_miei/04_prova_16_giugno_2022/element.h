typedef struct {
	char ISBN[24], titolo[64];
	int copie;
} Libro;

typedef struct {
	int cliente;
	char titolo[64];
} Richiesta;
typedef Richiesta element;
typedef enum { false, true } boolean;

//boolean isEqual(element e1, element e2);
//boolean isLess(element e1, element e2);
//element getElement();
void printElement(element el);