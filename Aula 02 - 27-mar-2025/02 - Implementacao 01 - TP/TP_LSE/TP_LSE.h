#include <stdio.h>
#include <stdlib.h>

typedef struct pilha_lse TP_LSE;

TP_LSE *TP_LSE_ini();

void TP_LSE_push(TP_LSE *p, int elem);

void TP_LSE_imp(TP_LSE *p);

void TP_LSE_lib(TP_LSE *p);

int TP_LSE_pop(TP_LSE *p);

int TP_LSE_vaz(TP_LSE *p);
