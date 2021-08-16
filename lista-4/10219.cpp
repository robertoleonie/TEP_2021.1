#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    long long N, K;
    double digito;

    while(cin >> N >> K){
        digito = 0;

        if(K > N - K){
            for(long long i = K+1; i <= N; i++){
                digito += (log10(i) - log10(N - i + 1));
            }
        } else {
            for(long long i = N-K+1; i <= N; i++){
                digito += (log10(i) - log10(N - i + 1));
            }
        }
        digito = floor(digito) + 1;
        printf("%0.lf\n", digito);
    }
    return 0;
}