#include <cstdio>
#include <algorithm>

using namespace std;

int resolver(int N, int M){
    if (N > M) swap(N, M);
    if (N == 1) return M;
    if (N == 2) return M / 4 * 4 + (M % 4 == 1 ? 2 : (M % 4 >= 2 ? 4 : 0));
    
    return (N*M + 1) / 2;
}

int main(){
    int M, N;
    
    while(1){
        scanf("%d %d", &N, &M);
        if(N == 0) break;
        
        printf("%d knights may be placed on a %d row %d column board.\n", resolver(N,M), N, M);
    }
    return 0;
}
