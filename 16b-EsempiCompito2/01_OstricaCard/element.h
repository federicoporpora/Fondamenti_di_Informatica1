#define DIM 256

typedef struct {
	int id;
	char entr[DIM], exit[DIM];
} Evento;

typedef struct {
	char entr[DIM], exit[DIM];
	float price;
} Tariffa;

typedef Evento element;
typedef enum { false, true } boolean;

//boolean isEqual(element e1, element e2);
//boolean isLess(element e1, element e2);
//element getElement();
//void printElement(element el);