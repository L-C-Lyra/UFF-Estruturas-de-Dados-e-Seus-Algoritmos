#include "TP_VD.h"

struct pilha_vet_din {
    int topo;
    int info;
    int *vetr;
};

TP_VD *TP_VD_ini() {
    TP_VD *p = (TP_VD *)malloc(sizeof(TP_VD));

    p -> topo = 0;
    p -> info = 1;
    p -> vetr = (int *)malloc(sizeof(int) * (p -> info));

    return p;
}

void TP_VD_push(TP_VD *p, int elem) {
    if (p -> topo == p -> info) {
        p -> info *= 2;
        p -> vetr = (int *)realloc(p -> vetr, sizeof(int) * (p -> info));
    }
    p -> vetr[p -> topo++] = elem;
}

void TP_VD_imp(TP_VD *p) {
    int i;

    for (i = (p -> topo - 1); i >= 0; i--) {
        printf("%d -> %d\n", (p -> topo - i), p -> vetr[i]);
    }
}

void TP_VD_lib(TP_VD *p) {
    free(p -> vetr);
    free(p);
}

int TP_VD_pop(TP_VD *p) {
    if (TP_VD_vaz(p)) {
        exit(1);
    }

    int resp = p->vetr[--p -> topo];

    if ((p -> info / 4) >= p -> info) {
        p -> info /= 2;
        p -> vetr = (int *)realloc(p -> vetr, sizeof(int) * (p -> info));
    }

    return resp;
}

int TP_VD_vaz(TP_VD *p) {
    return (p -> topo == 0);
}
