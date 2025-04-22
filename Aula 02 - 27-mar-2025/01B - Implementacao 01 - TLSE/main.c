#include "TLSE.h"

int main() {
    TLSE *l = TLSE_ini();
    int x;

    do {
        scanf("%d", &x);

        if (x < 0) {
            break;
        }
        if (x % 2 == 0) {
            l = TLSE_ins(l, x);
        }else {
            TLSE_ins_void(&l, x);
        }
    }while (1);

    TLSE_imp(l);

    TLSE_lib(l);
    return 0;
}
