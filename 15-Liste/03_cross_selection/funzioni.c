#include "funzioni.h"

int select(list l, int pos) {
	if (empty(l)) return -1;
	if (pos == 1) return head(l);
	return select(tail(l), pos - 1);
}

list crossSelection(list l1, list l2) {
	if (empty(l1)) {
		return emptyList();
	}
	else {
		return cons(select(l2, head(l1)), crossSelection(tail(l1), l2));
	}
}