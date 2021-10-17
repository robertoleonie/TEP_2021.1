#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX 1440

using namespace std;

int main (void) {
    int C, N, T, M, pos;
    int TT[MAX], resp;

    cin >> C;

    for(int i = 0; i < C; i++){
        cin >> N >> T >> M;

        for(int j = 0; j < M; j++){
            scanf("%d", &TT[j]);
        }

        sort(TT, TT+M);

        pos = 0;
        resp = pos;

        if(M % N == 0){
            resp = TT[N-1]+2*T;
            pos = N;
        } else {
            resp = TT[M%N-1]+2*T;
            pos = M%N;
        }

        for(; pos < M; pos += N){
            if(resp >= TT[pos+N-1]){
                resp = resp+2*T;
            } else {
                resp = TT[pos+N-1]+2*T;
            }
        }
        resp -= T;
        printf("%d %d\n", resp, (M+N-1)/N);
    }
    return 0;
}