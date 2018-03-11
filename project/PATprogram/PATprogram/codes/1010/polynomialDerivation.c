#include "../projects.h"
#include <stdlib.h>
/*
多项式求导
1.构建结构体，以结构体链表存储多项式各项
2.求导，系数乘以幂次作为新的系数；幂次减一作为新的幂次；幂次为0的项舍去。
*/
typedef struct polynomialNode {
	int a;
	int n;
	struct polynomialNode *next;
}PolyNode;
typedef struct polynomial {
	int n;
	struct polynomialNode *next;
}PolyList;
PolyNode * createNode() {
	PolyNode *p = (PolyNode*)malloc(sizeof(PolyNode));
	scanf("%d %d", &p->a, &p->n);
	//scanf("%d", &p->a); 
	//scanf("%d", &p->n);
	p->next = NULL;
	return p;
}
PolyList * createPolynomial() {
	PolyList *plist;
	plist = (PolyList*)malloc(sizeof(PolyList));
	plist->next = createNode();
	plist->n = 1;
	PolyNode *p = plist->next;
	while (getchar() != '\n') {
		p->next = createNode();
		plist->n++;
		p = p->next;
	}
	return plist;
}
void polynomialPrint(PolyList *plist) {
	PolyNode *p;
	p = plist->next;
	if (p == NULL) {
		printf("0 0");
	}
	else {
		while (p != NULL) {
			printf("%d %d", p->a, p->n);
			if (p->n != 0 && p->next != NULL) {
				printf(" ");
			}
			p = p->next;
		}
	}


}
void polynomialFree(PolyList *plist) {
	PolyNode *p, *q;
	p = plist->next;
	if (p == NULL);
	else {
		q = p->next;
		while (q != NULL) {
			free(p);
			p = q;
			q = p->next;
		}
		free(p);
	}
}
void polynomialDerivation() {
	PolyList *plist = createPolynomial();
	PolyNode *p = plist->next;
	if (p == NULL);
	else if (p->next == NULL) {
		if (p->n == 0) {
			free(p);
			p = NULL;
			plist->next = NULL;
		}
		else {
			p->a = p->a*p->n;
			p->n = p->n - 1;
		}
	}
	else {
		while (p != NULL) {
			if (p->next == NULL) {
				p->a = p->a*p->n;
				p->n = p->n - 1;
				p = p->next;
			}
			else if (p->next->n == 0) {
				free(p->next);
				p->next = NULL;
				p->a = p->a*p->n;
				p->n = p->n - 1;
				p = p->next;
			}
			else {
				p->a = p->a*p->n;
				p->n = p->n - 1;
				p = p->next;
			}
		}





	}

	polynomialPrint(plist);
	polynomialFree(plist);
	free(plist);
}
