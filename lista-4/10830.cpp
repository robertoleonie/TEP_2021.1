#include <iostream>

long long SOD(long long N, long long M, long long K){
    long long i, j;
    if(N > M) return 0;
    i = ((N+M) * (M-N+1))/2;
    j = i + (M-N+1)*K;
    return j;
}

long long CSOD(long long N){
    long long soma = 0;
    for(long long i = 2; i*i <= N; i++){
        soma += SOD(i+1, N/i, i);
        soma += i;
    }
    return soma;
}

int main(void){
    long long N, k=1;

    while(scanf("%lld", &N) && N){
        printf("Case %lld: %lld\n", k++, CSOD(N));
    }
    return 0;
}