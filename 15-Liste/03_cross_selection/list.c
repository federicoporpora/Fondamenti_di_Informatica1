#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* ---- PRIMITIVE ---- */
list emptyList(void) { return NULL; }

boolean empty(list l) {
	if (l == NULL) return true; else return false;
}

element head(list l) {
	if (empty(l)) exit(1);
	else return l->value;
}

list tail(list l) {
	if (empty(l)) exit(1);
	else return l->next;
}

list cons(element e, list l) {
	list t;
	t = (list)malloc(sizeof(item));
	t->value = e; t->next = l; return t;
}

/* ---- NON PRIMITIVE ---- */
void showList(list l) {
	printf("[");
	while (!empty(l)) {
		printf("%d", head(l));
		l = tail(l);
		if (!empty(l)) printf(", ");
	} printf("]\n");
}

boolean member(element el, list l) {
	if (empty(l)) return false;
	else if (el == head(l)) return true;
	else return member(el, tail(l));
}

int length(list l) {
	if (empty(l)) return 0;
	else return 1 + length(tail(l));
}

list append(list l1, list l2) {
	if (empty(l1)) return l2;
	else return cons(head(l1), append(tail(l1), l2));
}

list reverse(list l) {
	if (empty(l)) return emptyList();
	else return append(reverse(tail(l)),
		cons(head(l), emptyList()));
}

list copy(list l) {
	if (empty(l)) return l;
	else return cons(head(l), copy(tail(l)));
}

list delete(element el, list l) {
	if (empty(l)) return emptyList();
	else if (el == head(l)) return tail(l);
	else return cons(head(l), delete(el, tail(l)));
}

void freelist(list l) {
	if (empty(l)) return;
	else
	{
		freelist(tail(l));
		free(l);
	}
	return;
}

list insord(element el, list l) {
	if (empty(l)) return cons(el, l);
	else if (el <= head(l)) return cons(el, l);
	else return cons(head(l), insord(el, tail(l)));
}

list inputordlist(int n) {
	element e;
	if (n < 0) exit(1);
	else if (n == 0) return emptyList();
	else {
		scanf("%d", &e);
		return insord(e, inputordlist(n - 1));
	}
}