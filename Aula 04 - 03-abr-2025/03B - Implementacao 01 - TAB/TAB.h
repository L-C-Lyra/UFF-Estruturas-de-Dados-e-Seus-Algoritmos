#include <stdio.h>
#include <stdlib.h>

typedef struct arv_bin {
    int info_no;
    struct arv_bin *esq, *dir;
}TAB;

TAB *TAB_ini();

TAB *TAB_cri(int raiz, TAB *esq, TAB *dir);

void TAB_imp_pre(TAB *ab);
void TAB_imp_pos(TAB *ab);
void TAB_imp_sim(TAB *ab);
void TAB_imp_idt(TAB *ab);

void TAB_lib(TAB *ab);

TAB *TAB_bus(TAB *ab, int elem);
