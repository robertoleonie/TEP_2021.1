#include <iostream>
#include <string.h>
#include <algorithm>

#define TAM 100

using namespace std;

int main (void) {
  int T, N, M, S;
  int pre, area;

  long long K;
  long long linhas[TAM][TAM];
  long long somaCol[TAM];
  long long soma, P;

  cin >> T;

  for (int i = 0; i < T; i++) {

    S = 0;
    P = 1e9;

    cin >> N >> M >> K;

    for (int j = 0; j < N; j++){
      for (int k = 0; k < M; k++){
        scanf("%lld", &linhas[j][k]);
      }
    }

    for (int j = 0; j < N; j++) {
      memset(somaCol, 0, sizeof(somaCol));
      for (int k = j; k < N; k++) {
        for (int l = 0; l < M; l++) {
          somaCol[l] += linhas[k][l];
        }

        pre = 0;
        soma = 0;

        for (int l = 0; l < M; l++) {
          soma += somaCol[l];

          while (soma > K)
            soma -= somaCol[pre++];

          area = (k-j+1) * (l-pre+1);

          if (area > S) {
            S = area;
            P = soma;
          } else if (area == S) {
            P = min(soma, P);
          }
        }
      }
    }
    printf("Case #%d: %d %lld\n", i+1, S, P);
  }
  return 0;
}