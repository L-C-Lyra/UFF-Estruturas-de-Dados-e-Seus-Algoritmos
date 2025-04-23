#include <string.h>
#include "TAB.h"

TAB *TAB_suc_aux(TAB *ab, int elem, TAB *ab_aux){
    if (!ab) {
        return ab_aux;
    }

    TAB *ab_esq = TAB_suc_aux(ab -> esq, elem, ab_aux);
    if (ab_esq) {
        if ((!ab_aux) && (ab_esq -> info_no > elem)) {
            ab_aux = ab_esq;
        } else if ((ab_aux) && (ab_esq -> info_no < ab_aux -> info_no)) {
            ab_aux = ab_esq;
        }
    }

    TAB *ab_dir = TAB_suc_aux(ab -> dir, elem, ab_aux);
    if (ab_dir) {
        if ((!ab_aux) && (ab_dir -> info_no > elem)) {
            ab_aux = ab_dir;
        } else if ((ab_aux) && (ab_dir -> info_no < ab_aux -> info_no)) {
            ab_aux = ab_dir;
        }
    }

    if (ab -> info_no > elem) {
        if (ab -> info_no > elem) {
            if ((!ab_aux) || (ab -> info_no < ab_aux -> info_no)) {
                ab_aux = ab;
            }
        }

    }
    return ab_aux;
}

TAB *TAB_suc(TAB *ab, int elem) {
    if (!ab) {
        return ab;
    }

    if (ab -> info_no == elem) {
        return TAB_suc_aux(ab, elem, NULL);
    }
    return TAB_suc_aux(ab, elem, ab);
}

int main() {
    int no, no_pai;

    printf("Digite a RAIZ da Arvore: ");
    scanf("%d", &no);

    TAB *ab = TAB_cri(no, NULL, NULL), *ab_suc;

    do {
        char lado[2];

        char opc[3];
        printf("Quer continuar inserindo NOS na Arvore? (Digite 'N' ou 'n' para Parar.) ");
        fgets(opc, 3, stdin);

        if ((opc[0] == 'N') || (opc[0] == 'n')) {
            break;
        }

        printf("Digite o PAI (Que DEVE Existir.), o FILHO a ser Inserido na Arvore e a Posicao 'E' para ESQ ou 'D' para DIR: ");
        scanf("%d%d%s", &no_pai, &no, lado);

        ab_suc = TAB_bus(ab, no_pai);
        if (!ab_suc) {
            TAB_lib(ab);
            return 0;
        }

        if (strcmp(lado, "E") == 0) {
            ab_suc -> esq = TAB_cri(no, NULL, NULL);
        } else if (strcmp(lado, "D") == 0) {
            ab_suc->dir = TAB_cri(no, NULL, NULL);
        } else {
            printf("Lado invalido! Use apenas 'E' ou 'D'.\n");
        }
    }while (1);

    int n;

    printf("n: ");
    scanf("%d", &n);
    ab_suc = TAB_suc(ab, n);
    if (ab_suc) {
        printf("suc(ab, %d) = %d\n", n, ab_suc -> info_no);
    } else {
        printf("NAO EXISTE suc(ab, %d).\n");
    }

    TAB_lib(ab);
    return 0;
}