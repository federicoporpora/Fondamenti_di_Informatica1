void somma_tra_brani(int h, int min, int sec, int* h_fin, int* min_fin, int* sec_fin) {
    *sec_fin += sec;
    if (*sec_fin >= 60) {
        *min_fin += 1;
        *sec_fin -= 60;
    }
    *min_fin += min;
    if (*min_fin >= 60) {
        *h_fin += 1;
        *min_fin -= 60;
    }
}