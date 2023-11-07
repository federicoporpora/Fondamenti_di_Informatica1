void ms_to_norm(int ms_i, int* min, int* sec, int* ms_f) {
    *ms_f = ms_i % 1000;
    *sec = (ms_i / 1000) % 60;
    *min = (ms_i / 1000) / 60;
}