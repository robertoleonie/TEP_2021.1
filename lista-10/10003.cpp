#include <iostream>
#include <bits/stdc++.h>

#define TAM 100

using namespace std;

int L, N;
int corte[TAM], memo[TAM][TAM];

int minCost(int l, int r){
    if(l+1 == r)
        return 0;
    if(memo[l][r] != -1)
        return memo[l][r];

    int resp = 1e8;

    for(int i = l+1; i < r; i++){
        resp = min(resp, minCost(l, i)+minCost(i, r)+(corte[r]-corte[l]));
    }

    return memo[l][r] = resp;
}

int main(void){
    while(scanf("%d", &L), L){
        corte[0] = 0;
        cin >> N;

        for(int i = 1; i <= N; i++){
            scanf("%d", corte+i);
        }

        corte[N+1] = L;
        memset(memo, -1, sizeof(memo));

        printf("The minimum cutting is %d.\n", minCost(0, N+1));
    }
    return 0;
}
