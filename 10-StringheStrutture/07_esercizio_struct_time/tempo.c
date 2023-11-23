#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

typedef struct time {
	int hour, minute, second;
} Time;

Time leggiTime() {

	int h, min, sec;
	Time time;

	printf("Inserire il valore delle ore, dei minuti e dei secondi: ");
	scanf("%d:%d:%d", &h, &min, &sec);

	if (h < 0) {
		time.hour = h;
		return time;
	}

	if (min >= 60) {
		printf("Il valore dei minuti e' maggiore di 60, riprova: ");
		scanf("%d", &min);
	}

	if (sec >= 60) {
		printf("Il valore dei secondi e' maggiore di 60, riprova: ");
		scanf("%d", &sec);
	}

	time.hour = h;
	time.minute = min;
	time.second = sec;

	return time;

}

int leggiMoreTimes(Time v[], int dim) {
	int len = 0;
	Time temp;
	do {
		temp = leggiTime();
		if (temp.hour >= 0 && len < dim) {
			v[len] = temp;
			len++;
		}
	} while (temp.hour >= 0 && len < dim);

	return len;

}

Time subtract(Time t1, Time t2) {
	int sec1, sec2, secRes;
	Time tRes;

	sec1 = (t1.hour * 3600) + (t1.minute * 60) + t1.second;
	sec2 = (t2.hour * 3600) + (t2.minute * 60) + t2.second;

	secRes = sec1 - sec2;

	tRes.second = secRes % 60;
	tRes.minute = secRes / 60;
	tRes.hour = secRes / 3600;

	return tRes;
}