#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 1000
#define TAMM 1000000

typedef struct {
    int i, j, v;
} E;

E D[TAMM];
int R[TAM], P[TAM];

int cmp(const void *i, const void *j) {
    static E *a, *b;
    a = (E *)i, b = (E *)j;

    return a->v - b->v;
}

void inicializa(int N) {
    for(int i = 0; i < N; i++){
        R[i] = 1;
        P[i] = i;
    }
}

int encontraP(int x) {
    return P[x] == x ? x : P[x]=encontraP(P[x]);
}

int joint(int x, int y) {
    x = encontraP(x);
    y = encontraP(y);

    if(x != y) {
        if(R[x] > R[y]){
            R[x] += R[y];
            P[y] = x;
        } else {
            R[y] += R[x];
            P[x] = y;
        }

        return 1;
    }

    return 0;
}

int main(void) {
    int T, N, M, R, casos = 0;
    int x[TAM], y[TAM];
    int ac, estado;
    double rodovia, ferrovia;
    int j;

    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &R);

        for(int i = 0; i < N; i++)
            scanf("%d %d", &x[i], &y[i]);

        inicializa(N);
        M = 0;

        for(int i = 0; i < N; i++) {
            for(j = i+1; j < N; j++) {
                D[M].i = i;
                D[M].j = j;
                D[M].v = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                M++;
            }
        }

        qsort(D, M, sizeof(E), cmp);

        ac = 0;
        estado = 1;

        rodovia = 0;
        ferrovia = 0;

        R = R*R;

        for(int i = 0; i < M; i++) {
            if(joint(D[i].i, D[i].j)) {
                if(D[i].v > R) {
                    ferrovia += sqrt(D[i].v);
                    estado ++;
                } else {
                    rodovia += sqrt(D[i].v);
                }
                ac++;
                if(ac == N-1) break;
            }
        }

        printf("Case #%d: %d %.lf %.lf\n", ++casos, estado, rodovia, ferrovia);
    }

    return 0;
}