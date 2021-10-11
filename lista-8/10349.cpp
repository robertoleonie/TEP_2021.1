#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int T, R, C, PT;

#define TAM 400

vector<vector<int>> A, B;
vector<int> emparelha;
bitset<TAM> vis;

int aug(int U){
    int V;

    if(vis[U]) return 0;

    vis[U] = 1;
    for(int i = 0; i < B[U].size(); i++){
        V = B[U][i];
        if(!emparelha[V] || aug(emparelha[V])){
            emparelha[U] = V;
            emparelha[V] = U;
            return 1;
        }
    }

    return 0;
}

int main(void){
    int resp;

    cin >> T;
    while(T--){
        cin >> R >> C;
        A.assign(R, vector<int>(C));
        PT = 1;

        for(int i = 0; i < R; i++){
            ws(cin);
            for(int j = 0; j < C; j++){
                char C;
                cin >> C;
                if(C=='*')
                    A[i][j] = PT++;
            }
        }

        B.assign(PT, vector<int>());
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(A[i][j]){
                    if(i > 0 && A[i-1][j]) {
                        B[A[i][j]].push_back(A[i-1][j]);
                        B[A[i-1][j]].push_back(A[i][j]);
                    }
                    if(j > 0 && A[i][j-1]) {
                        B[A[i][j]].push_back(A[i][j-1]);
                        B[A[i][j-1]].push_back(A[i][j]);
                    }
                    if(i < R-1 && A[i+1][j]) {
                        B[A[i][j]].push_back(A[i+1][j]);
                        B[A[i+1][j]].push_back(A[i][j]);
                    }
                    if(j < C-1 && A[i][j+1]) {
                        B[A[i][j]].push_back(A[i][j+1]);
                        B[A[i][j+1]].push_back(A[i][j]);
                    }
                }
            }
        }
        resp = 0;
        emparelha.assign(PT, 0);

        for(int i = 1; i < PT; i++){
            if(emparelha[i])
                continue;
            vis.reset();

            resp += aug(i);
        }

        cout << PT-resp-1 << endl;
    }
}