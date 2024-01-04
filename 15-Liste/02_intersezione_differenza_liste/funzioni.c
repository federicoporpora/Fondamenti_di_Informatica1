#include "funzioni.h"

list intersect(list l1, list l2) {
	list lRes = emptyList();
	lRes = append(l1, l2);
	return lRes;
}

boolean isPresent(element el, list l) {
	boolean found = false;
	while (!empty(l) && !found) {
		if (head(l) == el) {
			found = true;
		}
		else {
			found = isPresent(el, tail(l));
		}
	}
	return found;
}

list diff(list l1, list l2) {
	list lRes = emptyList();
	while (!empty(l1)) {
		if (!isPresent(head(l1), l2)) {
			lRes = cons(head(l1), lRes);
		}
		l1 = tail(l1);
	}
	return lRes;
}