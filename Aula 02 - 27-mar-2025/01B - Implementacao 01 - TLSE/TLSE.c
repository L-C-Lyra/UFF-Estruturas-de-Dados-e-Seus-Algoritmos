#include "TLSE.h"

TLSE *TLSE_ini() {
    return NULL;
}

TLSE *TLSE_ins(TLSE *l, int elem) {
    TLSE *novo_no = (TLSE *)malloc(sizeof(TLSE));

    novo_no -> prox_no = l;
    novo_no -> info_no = elem;

    return novo_no;
}

void TLSE_ins_void(TLSE **l, int elem) {
    TLSE *novo_no = (TLSE *)malloc(sizeof(TLSE));

    novo_no -> prox_no = *l;
    novo_no -> info_no = elem;
    *l = novo_no;
}

void TLSE_imp(TLSE *l) {
    TLSE *no = l;

    while (no) {
        printf("%d ", no -> info_no);
        no = no -> prox_no;
    }
}

void TLSE_imp_rec(TLSE *l) {
    if (l) {
        printf("%d ", l -> info_no);

        TLSE_imp_rec(l -> prox_no);
    }
}

void TLSE_imp_rev_rec(TLSE *l) {
    if (l) {
        TLSE_imp_rev_rec(l -> prox_no);

        printf("%d ", l -> info_no);
    }
}

void TLSE_lib(TLSE *l) {
    TLSE *no = l;

    while (no) {
        TLSE *no_aux = no;
        no = no -> prox_no;

        free(no_aux);
    }
}

void TLSE_lib_rec(TLSE *l) {
    if (l) {
        TLSE_lib_rec(l -> prox_no);

        free(l);
    }
}

TLSE *TLSE_ret(TLSE *l, int elem) {
    TLSE * no = l, *no_ant = NULL;

    while ((no) && (no -> info_no != elem)) {
        no_ant = no;
        no = no -> prox_no;
    }

    if (!no) {
        return l;
    }
    if (!no_ant) {
        l = l -> prox_no;
    } else {
        no_ant -> prox_no = no -> prox_no;
    }

    free(no);
    return l;
}

TLSE *TLSE_ret_rec(TLSE *l, int elem) {
    if (!l) {
        return l;
    }

    if (l -> info_no == elem) {
        TLSE *no = l;
        l = l -> prox_no;

        free(no);
    } else {
        l -> prox_no = TLSE_ret_rec(l -> prox_no, elem);
    }

    return l;
}

TLSE *TLSE_bus(TLSE *l, int elem) {
    TLSE *no = l;

    while ((no) && (no -> info_no != elem)) {
        no = no -> prox_no;
    }

    return no;
}

TLSE *TLSE_bus_rec(TLSE *l, int elem) {
    if ((!l)|| (l -> info_no == elem)) {
        return l;
    }
    return TLSE_bus_rec(l -> prox_no, elem);
}
