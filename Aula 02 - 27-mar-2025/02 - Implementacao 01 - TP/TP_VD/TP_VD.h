#include <stdio.h>
#include <stdlib.h>

typedef struct pilha_vet_din TP_VD;

TP_VD *TP_VD_ini();

void TP_VD_push(TP_VD *p, int elem);

void TP_VD_imp(TP_VD *p);

void TP_VD_lib(TP_VD *p);

int TP_VD_pop(TP_VD *p);

int TP_VD_vaz(TP_VD *p);
