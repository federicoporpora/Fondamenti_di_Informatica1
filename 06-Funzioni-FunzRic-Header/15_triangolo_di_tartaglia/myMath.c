int fattoriale(int a) {
	if (a < 0) {
		return 0;
	}
	else if (a == 0 || a == 1) {
		return 1;
	}
	else {
		return a * fattoriale(a - 1);
	}
}

int coeff_bin(int n, int k) {
	return fattoriale(n) / (fattoriale(k) * fattoriale(n - k));
}