#define DIM_NOME 24
#define DIM_DESCR 256

typedef struct {
	int id;
	char nome[DIM_NOME], descr[DIM_DESCR];
} Foto;

typedef Foto element;
typedef enum { false, true } boolean;

//boolean isEqual(element e1, element e2);
//boolean isLess(element e1, element e2);
//element getElement();
//void printElement(element el);