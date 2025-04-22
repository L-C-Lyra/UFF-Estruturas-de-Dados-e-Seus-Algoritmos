#include "TP_LSE.h"
#include "TLSE.h"

struct pilha_lse {
    TLSE *topo;
};

TP_LSE *TP_LSE_ini() {
    TP_LSE *p = (TP_LSE *)malloc(sizeof(TP_LSE));

    p -> topo = NULL;

    return p;
}

void TP_LSE_push(TP_LSE *p, int elem) {
    TLSE *novo_no = (TLSE *)malloc(sizeof(TLSE));

    novo_no -> info_no = elem;
    novo_no -> prox_no = p -> topo;
    p -> topo = novo_no;
}

void TP_LSE_imp(TP_LSE *p) {
    TP_LSE *p_aux = TP_LSE_ini();
    int i = 1;

    while (!TP_LSE_vaz(p)) {
        int x = TP_LSE_pop(p);

        printf("%d -> %d\n", i++, x);

        TP_LSE_push(p_aux, x);
    }

    while (!TP_LSE_vaz(p_aux)) {
        TP_LSE_push(p, TP_LSE_pop(p_aux));
    }

    TP_LSE_lib(p_aux);
}

void TP_LSE_lib(TP_LSE *p) {
    TLSE *no = p;

    while (no) {
        TLSE *no_aux = no;
        no = no -> prox_no;

        free(no_aux);
    }
}

int TP_LSE_pop(TP_LSE *p) {
    if (!TP_LSE_vaz(p)) {
        TLSE *no_aux = p -> topo;
        int x = no_aux -> info_no;

        p -> topo = no_aux -> prox_no;

        free(no_aux);

        return x;
    } else {
        exit(1);
    }
}

int TP_LSE_vaz(TP_LSE *p) {
    return (p -> topo == NULL);
}
