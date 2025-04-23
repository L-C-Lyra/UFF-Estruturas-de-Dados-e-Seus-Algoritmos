#include <stdio.h>
#include <stdlib.h>

typedef struct lse {
    int info_no;
    struct lse *prox_no;
}TLSE;

TLSE *TLSE_ini();

TLSE *TLSE_ins(TLSE *l, int elem);
void TLSE_ins_void(TLSE **l, int elem);

void TLSE_imp(TLSE *l);
void TLSE_imp_rec(TLSE *l);
void TLSE_imp_rev_rec(TLSE *l);

void TLSE_lib(TLSE *l);
void TLSE_lib_rec(TLSE *l);

TLSE *TLSE_ret(TLSE *l, int elem);
TLSE *TLSE_ret_rec(TLSE *l, int elem);

TLSE *TLSE_bus(TLSE *l, int elem);
TLSE *TLSE_bus_rec(TLSE *l, int elem);
