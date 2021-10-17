#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

#define TAM 13

using namespace std;

int T, N, M, A, B, P;
double custo;
int memo[1<<TAM][TAM]; // tsp state
int dist[51][51]; // shortest path
int armazena[TAM]; // map pos i to actual store index
int poupanca[TAM]; // poupanca from pos i

int tsp(int pos, int bitmask){
    if(bitmask == ((1<<P)-1)) 
        return -dist[0][armazena[pos]];
    if(memo[bitmask][pos] != -1e7) 
        return memo[bitmask][pos];

    int maxima = -dist[0][armazena[pos]];

    for(int i = 0; i < P; i++){
        if(!(bitmask &(1<<i))){
            maxima = max(maxima, tsp(i,bitmask|(1<<i)) + poupanca[i] - dist[armazena[pos]][armazena[i]]);
        }
    }

    return memo[bitmask][pos] = maxima;
}

int main(void) {
    cin >> T;

    while(T--){
        cin >> N >> M;

        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                dist[i][j] = 1e8;
            }
        }
        for(int i = 0; i < M; i++){
            cin >> A >> B >> custo;
            dist[B][A] = dist[A][B] = min(dist[A][B], (int)round(custo*100));
        }

        for(int k = 0; k <= N; k++){
            for(int i = 0;i <= N; i++){
                for(int j = 0; j <= N; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        cin >> P;
        memset(poupanca, 0, sizeof poupanca);

        for(int i = 0; i < (1<<P); i++){
            for(int j=0;j<=P;j++){
                memo[i][j] = -1e7;
            }
        }
        for(int i=0;i<P;i++){
            cin >> armazena[i] >> custo;
            poupanca[i] += round(custo*100);
        }

        int resp = 0;

        for(int i = 0; i < P; i++){
            resp = max(tsp(i,1<<i)-dist[armazena[i]][0]+poupanca[i], resp);
        }

        if(resp == 0)
			puts("Don't leave the house");
		else
			printf("Daniel can save $%.2f\n", resp/100.0);
    }
    return 0;
}