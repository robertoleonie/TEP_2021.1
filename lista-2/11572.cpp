#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int TAM = 1000000;
int vetor[TAM];
 
int main(void) {
  int K, numFlocos;
  set<int> conjunto;
  int esq = 0, dir = 0, result = 0;
  
  scanf("%d", &K);
 
  while(K--) {
    scanf("%d", &numFlocos);
    for(int i = 0; i < numFlocos; i++) 
    	scanf("%d", &vetor[i]);

    while(dir < numFlocos) {
      while(dir < numFlocos && !conjunto.count(vetor[dir])) 
          conjunto.insert(vetor[dir++]);
          
      result = max(result, dir - esq);
      conjunto.erase(vetor[esq++]);
    }
    printf("%d\n", result);
  }
  return 0;
}
