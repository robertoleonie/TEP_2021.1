#include <bits/stdc++.h>

using namespace std;

int contCor1 = 0;
int contCor2 = 0;

vector<int> cor;

unordered_map<int, unordered_set<int>> grafo;

bool dfs(int N, int color){
    if(cor[N] != 0) return cor[N] == color;
    cor[N] = color;

    if(color == 1) contCor1++;
    else contCor2++;

    for(auto& viz : grafo[N]){
        if(!dfs(viz, -color)) return false;
    }
    return true;
}

int main(void){
    int teste, N, M, A, B, ans;
    bool bipartido;

    cin >> teste;
    while(teste--){

        cin >> N >> M;
        cor.assign(N, 0);
        grafo.clear();

        for(int i = 0; i < M; i++){
            cin >> A >> B;
            grafo[A].insert(B);
            grafo[B].insert(A);
        }

        bipartido = true;
        ans = 0;

        for(int i = 0; i < N && bipartido; i++){
            if(cor[i] == 0){
                contCor2 = 0;
                contCor1 = contCor2;
                
                bipartido = dfs(i, 1);
                
                ans += max(1, min(contCor1, contCor2));
            }
        }

        if(bipartido) printf("%d\n", ans);
        else printf("%d\n", -1);

    }

    return 0;
}