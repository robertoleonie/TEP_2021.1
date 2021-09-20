#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct node {
    int M, N;
    string S;

    node (int MM, int NN, string SS){
        M = MM; N = NN; S = SS;
    }
};

map<string, vector<node>> mapa;
vector<node> v, v1, v2, v3, v4;

int mdc(int a, int b){
    if(a%b==0) return b;
    return mdc(b,a%b);
}

int main(void){
    int M, N, A, B, D;
    char ponto;
    string s1, s2;
    bool enc;

    while(true){
        cin >> ponto;
        if(ponto == '.') break;

        else if(ponto == '!'){
            cin >> M >> s1 >> ponto >> N >> s2;

            D = mdc(M, N);
            M /= D; N /= D;

            v1 = mapa[s1];
            v2 = mapa[s2];
            mapa[s1].push_back(node(M, N, s2));

            for(int i = 0; i < v1.size(); i++){
                A = v1[i].N*M;
                B = N*v1[i].M;

                D = mdc(A, B);

                A /= D;
                B /= D;

                mapa[v1[i].S].push_back(node(A, B, s2));
                mapa[s2].push_back(node(B, A, v1[i].S));
            }

            mapa[s2].push_back(node(N, M, s1));

            for(int i = 0; i < v2.size(); i++){
                A = v2[i].N*N;
                B = M*v2[i].M;
                
                D = mdc(A, B);

                A /= D;
                B /= D;

                mapa[v2[i].S].push_back(node(A, B, s1));
                mapa[s1].push_back(node(B, A, v2[i].S));
            }

            v1 = mapa[s1];

            for(int i = 0; i < v1.size(); i++){
                v3 = mapa[v1[i].S];
                for(int j = i+1; j < v1.size(); j++){
                    enc = false;

                    for(int k = 0; k < v3.size(); k++){
                        if(v3[k].S == v1[j].S){
                            enc = true;
                            break;
                        }
                    }

                    if(!enc){
                        A = v1[i].N*v1[j].M;
                        B = v1[j].N*v1[i].M;
                        D = mdc(A, B);

                        A /= D;
                        B /= D;

                        mapa[v1[i].S].push_back(node(A, B, v1[j].S));
                        mapa[v1[j].S].push_back(node(B, A, v1[i].S));
                    }
                }
            }
        } else {
            cin >> s1 >> ponto >> s2;
            v = mapa[s1];
            enc = false;

            for(int i = 0; i < v.size(); i++){
                if(v[i].S == s2){
                    enc = true;
                    cout << v[i].M << " " << s1 << " = " << v[i].N << " " << s2 << endl;
                }
            }

            if(!enc) cout << "? " << s1 << " = ? " << s2 << endl;
        }
    }

    return 0;
}