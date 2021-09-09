#include <iostream>

int resp[92][9], at = -1;
int y[9], visitado[9] = {};

int valida(int indice, int k) {
    for(int i = 1; i < indice; i++) {
        if(abs(i-indice) == abs(y[i]-k))
            return 0;
    }
    return 1;
}

void dfs(int indice) {
    if(indice == 9) {
        ++at;
        for(int i = 1; i <= 8; i++) {
            resp[at][i] = y[i];
        }
        return ;
    }
    for(int i = 1; i <= 8; i++) {
        if(!visitado[i] && valida(indice, i)) {
            visitado[i] = 1;
            y[indice] = i;
            dfs(indice+1);
            visitado[i] = 0;
        }
    }
}

int main(void) {
    dfs(1);
    int teste = 0, a[9];
    while(scanf("%d", &a[1]) == 1) {
        for(int i = 2; i <= 8; i++)
            scanf("%d", &a[i]);

        int movs = 0xfffff;
        for(int i = 0; i <= at; i++) {
            int aux = 0;
            for(int j = 1; j <= 8; j++)
                if(resp[i][j] != a[j])
                    aux++;
            if(aux < movs) movs = aux;
        }
        printf("Case %d: %d\n", ++teste, movs);
    }
    return 0;
}