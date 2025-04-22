#include <stdio.h>

int main() {
    int *pa, a, b;
    char *pc, c, d;
    double *pd, e, f;

    printf("a = %d[%p]\tb = %d[%p]\tpa = %p[%p]\n", a, &a, b, &b, pa, &pa);
    printf("c = %c->%d[%p]\td = %c->%d[%p]\tpc = %p[%p]\n", c, c, &c, d, d, &d, pc, &pc);
    printf("e = %.5f[%p]\tf = %.5f[%p]\tpd = %p[%p]\n\n\n", e, &e, f, &f, pd, &pd);

    pa = &a;
    pc = &c;
    pd = &e;
    (*pa) = 5;
    a++;
    c = 'A';
    (*pc)++;
    e = 102.3456789;

    printf("a = %d[%p]\tb = %d[%p]\tpa = %p[%p]\n", a, &a, b, &b, pa, &pa);
    printf("c = %c->%d[%p]\td = %c->%d[%p]\tpc = %p[%p]\n", c, c, &c, d, d, &d, pc, &pc);
    printf("e = %.5f[%p]\tf = %.5f[%p]\tpd = %p[%p]\n\n\n", e, &e, f, &f, pd, &pd);

    pa++;
    pc++;
    pd++;

    printf("a = %d[%p]\tb = %d[%p]\tpa = %p[%p]\n", a, &a, b, &b, pa, &pa);
    printf("c = %c->%d[%p]\td = %c->%d[%p]\tpc = %p[%p]\n", c, c, &c, d, d, &d, pc, &pc);
    printf("e = %.5f[%p]\tf = %.5f[%p]\tpd = %p[%p]\n\n\n", e, &e, f, &f, pd, &pd);

    (*pa) = (int) e;
    (*pc) = 'b';
    (*pd) = 25.252525;
    pa++;
    pc++;
    pd++;

    printf("a = %d[%p]\tb = %d[%p]\tpa = %p[%p]\n", a, &a, b, &b, pa, &pa);
    printf("c = %c->%d[%p]\td = %c->%d[%p]\tpc = %p[%p]\n", c, c, &c, d, d, &d, pc, &pc);
    printf("e = %.5f[%p]\tf = %.5f[%p]\tpd = %p[%p]\n\n\n", e, &e, f, &f, pd, &pd);

    pa++;
    pc++;
    pd++;

    printf("a = %d[%p]\tb = %d[%p]\tpa = %p[%p]\n", a, &a, b, &b, pa, &pa);
    printf("c = %c->%d[%p]\td = %c->%d[%p]\tpc = %p[%p]\n", c, c, &c, d, d, &d, pc, &pc);
    printf("e = %.5f[%p]\tf = %.5f[%p]\tpd = %p[%p]\n\n\n", e, &e, f, &f, pd, &pd);

    pa++;
    //(*pa) = 300; // Falha de Segmentação!
    pc++;
    (*pc) = 2;
    pd++;
    (*pa) *= 5;

    printf("a = %d[%p]\tb = %d[%p]\tpa = %p[%p]\n", a, &a, b, &b, pa, &pa);
    printf("c = %c->%d[%p]\td = %c->%d[%p]\tpc = %p[%p]\n", c, c, &c, d, d, &d, pc, &pc);
    printf("e = %.5f[%p]\tf = %.5f[%p]\tpd = %p[%p]\n\n\n", e, &e, f, &f, pd, &pd);

    void *pv;

    pv = (int *) &b;
    ((int *) pv++);

    printf("p = %p[%p]\n", pv, &pv);

    return 0;
}