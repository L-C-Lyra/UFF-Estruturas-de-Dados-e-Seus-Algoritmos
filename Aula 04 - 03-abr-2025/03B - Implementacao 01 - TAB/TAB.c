#include "TAB.h"

TAB *TAB_ini() {
    return NULL;
}

TAB *TAB_cri(int raiz, TAB *esq, TAB *dir) {
    TAB *ab = (TAB *)malloc(sizeof(TAB));

    ab -> info_no = raiz;
    ab -> esq = esq;
    ab -> dir = dir;

    return ab;
}

void TAB_imp_pre(TAB *ab) {
    if (ab) {
        printf("%d ", ab -> info_no);

        TAB_imp_pre(ab -> esq);
        TAB_imp_pre(ab -> dir);
    }
}

void TAB_imp_pos(TAB *ab) {
    if (ab) {
        TAB_imp_pos(ab -> esq);
        TAB_imp_pos(ab -> dir);

        printf("%d ", ab -> info_no);
    }
}

void TAB_imp_sim(TAB *ab) {
    if (ab) {
        TAB_imp_sim(ab -> esq);

        printf("%d ", ab -> info_no);

        TAB_imp_sim(ab -> dir);
    }
}

void TAB_imp_aux(TAB *ab, int andr) {
    int i;

    if (ab) {
        for (i = 0; i <= andr; i++) {
            printf("\t");
        }
        printf("%d\n", ab -> info_no);

        TAB_imp_aux(ab -> esq, andr + 1);
    } else {
        for (i = 0; i <= andr; i++) {
            printf("\t");
        }
        printf("NULL\n");
    }
}

void TAB_imp_idt(TAB *ab) {
    TAB_imp_aux(ab, 0);
}

void TAB_lib(TAB *ab) {
    if (ab) {
        TAB_lib(ab -> esq);
        TAB_lib(ab -> dir);

        free(ab);
    }
}

TAB *TAB_bus(TAB *ab, int elem) {
    if ((!ab) || (ab -> info_no == elem)) {
        return ab;
    }

    TAB *no = TAB_bus(ab -> esq, elem);
    if (no) {
        return no;
    }
    return TAB_bus(ab -> dir, elem);
}
