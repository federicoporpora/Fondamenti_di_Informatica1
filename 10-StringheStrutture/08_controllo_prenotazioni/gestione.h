typedef struct Booking {
    char name[1024];
    int seat;
} booking;
int assegna(booking arr[], int dim, int* nPrenotazioni, char name[], int seat);
int leggi(booking* dest);