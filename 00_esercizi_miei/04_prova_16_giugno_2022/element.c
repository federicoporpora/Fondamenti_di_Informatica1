#define _CRT_SECURE_NO_DEPRECATE
#include "element.h"
#include <stdio.h>

//boolean isEqual(element e1, element e2) {
//	return (e1 == e2); //non restituisce esattam. true/false
//}
//
//boolean isLess(element e1, element e2) {
//	return (e1 < e2); // come sopra
//}
//
//element getElement() {
//	element el;
//	scanf("%d", &el);
//	return el;
//}
//
void printElement(element el) {
	printf("Cliente: %d\tTitolo: %s\n", el.cliente, el.titolo);
}