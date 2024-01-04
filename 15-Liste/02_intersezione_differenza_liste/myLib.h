typedef struct list_element {
	int value;
	struct list_element* next;
} item;

typedef item* list;

int myMin(int a, int b);
int myMax(int a, int b);
int myMCD(int a, int b);
int myMcm(int a, int b);
int myFattoriale(int a);
int myPow(int a, int b);
int myCoeffBin(int n, int k);
double myLog(double a, double b);
int mySumUnder(int a);
void mySwap(int* a, int* b);
int myLen(int a);
int myPalindromo(int x);
int mySqrt(int x);
void myStampaVettori(int arr[], int len);
int myRiempiVettori(int arr[], int size);
int myRemoveDuplicates(int arr[], int len1, int noDupl[]);
int myRicercaValori(int arr[], int len, int x);
void strConSpazi(char* stringa, int dim);
list insert(int e, list l);
int ricerca(int e, list l);