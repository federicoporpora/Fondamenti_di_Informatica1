typedef struct time {
	int hour, minute, second;
} Time;
Time leggiTime();
int leggiMoreTimes(Time v[], int dim);
Time subtract(Time t1, Time t2);