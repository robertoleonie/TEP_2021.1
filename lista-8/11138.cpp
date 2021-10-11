#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define TAM 1000

int g[TAM][TAM], gt[TAM];
int mx[TAM], my[TAM], usado[TAM];

int dfs(int now){
    int X;

    for(int i = 0; i < gt[now]; i++){
        X = g[now][i];
        if(!usado[X]) {
            usado[X] = 1;

            if(my[X] == 0 || dfs(my[X])) {
                mx[now] = X;
                my[X] = now;
                return 1;
            }
        }
    }
    return 0;
}

int main(void){
    int M, N, X;
    int T, casos = 0;
    int resp;

    cin >> T;
    while(T--){
        scanf("%d %d", &N, &M);
        memset(gt, 0, sizeof(gt));

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                scanf("%d", &X);

                if(X) g[i][gt[i]++] = j+N;
            }
        }

        memset(mx, 0, sizeof(mx));
        memset(my, 0, sizeof(my));

        resp = 0;
        
        for(int i = 1; i <= N; i++){
            if(!mx[i]){
                memset(usado, 0, sizeof(usado));
                if(dfs(i)) resp++;
            }
        }

        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", ++casos, resp);
    }
    return 0;
}