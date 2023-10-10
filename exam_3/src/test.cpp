#include "../include/head.h"

int main() {
    LinkList A = InitList();
    LinkList B = InitList();
    LinkList C=InitList();
    LinkList D=InitList();
    LinkList E=InitList();

    printf("Set A:\n");
    InputElement(A);

    printf("Set B:\n");
    InputElement(B);

    C=overlap(A,B);
    printf("\nAB:\n");
    ListTraverse(C);
    DestroyList(C); 

    D=Union(A, B); 
    printf("\nA+B:\n");
    ListTraverse(D);
    DestroyList(D);

    printf("\nA-B:\n");
    E=SetDifference(A, B);
    ListTraverse(E);
    DestroyList(E);

    DestroyList(A);
    DestroyList(B);

    return 0;
}

