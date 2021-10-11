#include <cstdio>

const int TAM = 200;

int f[TAM];
int d[TAM];

int find(int x){
    if(x != f[x])
        return f[x] = find(f[x]);
    return x;
}

int main(void){
    int N, R;
    bool ok;
    int resp;
    int A, B, raiz;
    
    while(scanf("%d %d", &N, &R) != EOF){
        ok = 1; resp = 0;

        for(int i = 0; i < N; i++){
            d[i] = 0; f[i] = i;
        }

        for(int i = 0; i < R; i++){
            scanf("%d %d", &A, &B);
            f[find(A)] = find(B);
            d[A]++; d[B]++;
        }

        if(R <= 1 || N == 0){
            ok = 0;
        }
        raiz = find(0);

        for(int i = 0; ok && i < N; i++){
            if(d[i] != 0){
                if(find(i) != raiz || d[i] % 2 != 0){
                    ok = 0;
                    break;
                }
            }
        }

        if(ok)
            printf("Possible\n");
        else
            printf("Not Possible\n");
    }
    return 0;
}