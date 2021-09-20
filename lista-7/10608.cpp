#include <bits/stdc++.h>

using namespace std;

int tamanhoDoGrupo[30000];
int maiorGrupo;

int udfsFind(int* udfs, int n){
    return udfs[n] == n ? n : udfsFind(udfs, udfs[n]);
}

void udfsJoin(int *udfs, int a, int b){
    if(udfsFind(udfs, a) == udfsFind(udfs, b)) return;
    int novoTam = tamanhoDoGrupo[udfsFind(udfs,a)] += tamanhoDoGrupo[udfsFind(udfs,b)];
    maiorGrupo = max(novoTam, maiorGrupo);
    udfs[udfsFind(udfs, b)] = udfsFind(udfs, a);
}

int main(void) {
    int test, N, M, A, B;

    cin >> test;

    while(test--){
        cin >> N >> M;

        maiorGrupo = 1;
        int udfs[N];
        for(int i = 0; i < N; i++){
            tamanhoDoGrupo[i] = 1;
            udfs[i] = i;
        }

        for(int i = 0; i < M; i++){
            cin >> A >> B;
            udfsJoin(udfs, A-1, B-1);
        }
        cout << maiorGrupo << endl;
    }

    return 0;
}
