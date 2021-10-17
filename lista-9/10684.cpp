#include <iostream>

using namespace std;

int main(void) {
    int N, v;
    int atual, maxima;

    while(scanf("%d", &N), N){
        atual = 0;
        maxima = 0;

        for(int i = 0; i < N; i++){
            cin >> v;
            atual = max(0, atual+v);
            maxima = max(maxima, atual);
        }
        if(maxima){
            printf("The maximum winning streak is %d.\n", maxima);
        } else { 
            printf("Losing streak.\n");
        }
    }
    return 0;
}
