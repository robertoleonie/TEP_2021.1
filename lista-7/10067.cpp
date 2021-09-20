#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 10000

int alteracao[8][4] = {{1,0,0,0},{-1,0,0,0},{0,1,0,0},{0,-1,0,0},{0,0,1,0},{0,0,-1,0},{0,0,0,1},{0,0,0,-1}};

string inicio, fim;

map<string, int> indiceMap;

int bfs() {
   if (inicio==fim) return 0;
   if (indiceMap[fim]==-1) return -1;

   queue<string> fila;
   queue<int> filaIndice;

   fila.push(inicio); 
   filaIndice.push(1);

   while (!fila.empty()) {
      string U = fila.front(); fila.pop();
      int indiceU = filaIndice.front(); filaIndice.pop();
      for(int k = 0; k < 8; k++) {
         string V = U;
         for (int i = 0 ; i < 4; i++) {
            V[i] += alteracao[k][i];

            if (V[i]<'0') V[i] = '9';
            else if (V[i]>'9') V[i] = '0';
         }
         int index = indiceMap[V];

         if (index != 0) continue;
         if (V == fim) return indiceU;
         
         index = indiceMap[V] = indiceU + 1;
         fila.push(V); filaIndice.push(index);
      }
   }
   return -1;
}

int main(void) {
   int T, val, M;

   cin >> T;
   while (T--) {
    inicio = fim = ""; indiceMap.clear();
    for (int i = 1; i < 5; i++){
        cin >> val;
        inicio += val+48;
    }
    for (int i = 1; i < 5; i++){
        cin >> val;
        fim += val+48;
    }
    scanf("%d", &M);
    while (M--) {
        string tmp = "";
        for(int i = 1; i < 5; i++){
            scanf("%d", &val); tmp += val+48;
        }
        indiceMap[tmp] = -1;
    }
    indiceMap[inicio] = 1;
    printf("%d\n", bfs());
    }
    return 0;
}