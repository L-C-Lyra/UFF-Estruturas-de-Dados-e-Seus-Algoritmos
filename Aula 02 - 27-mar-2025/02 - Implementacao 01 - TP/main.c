#include "TP_LSE/TP_LSE.h"

void TP_LSE_ord(TP_LSE *p) {
    TP_LSE *p_aux_a = TP_LSE_ini(), *p_aux_b = TP_LSE_ini();

    while (!TP_LSE_vaz(p)) {
        TP_LSE_push(p_aux_a, TP_LSE_pop(p));
    }

    while (!TP_LSE_vaz(p_aux_a)) {
        int m = TP_LSE_pop(p_aux_a);

        while (!TP_LSE_vaz(p_aux_a)) {
            int x = TP_LSE_pop(p_aux_a);

            if (x <= m) {
                TP_LSE_push(p_aux_b, x);
            } else {
                TP_LSE_push(p_aux_b, m);

                m = x;
            }
        }
        TP_LSE_push(p, m);

        while (!TP_LSE_vaz(p_aux_b)) {
            TP_LSE_push(p_aux_a, TP_LSE_pop(p_aux_b));
        }
    }

    TP_LSE_lib(p_aux_a);
    TP_LSE_lib(p_aux_b);
}

int main() {
    TP_LSE *p = TP_LSE_ini();

    printf("Insira Elementos MAIORES ou IGUAIS a 0 para Inclusao na Pilha: \n");
    do {
        int n;

        scanf("%d", &n);
        if (n < 0) {
            break;
        }

        TP_LSE_push(p, n);
    }while (1);

    printf("Antes de Ordenar: \n");
    TP_LSE_imp(p);

    TP_LSE_ord(p);
    printf("Depois de Ordenar: \n");
    TP_LSE_imp(p);

    TP_LSE_lib(p);
    return 0;
}