#include<cstdio>
#include<math.h>
#include<string.h>

#define TAM 10000000
bool p[10000001];

void primalidade(){
	memset(p, false, sizeof(p));
	for (int i = 2; i*i <= TAM; i++){
		if (!p[i]){
			for (int K = (TAM - 1) / i, j = i*K; K >= i; K--, j -= i)
				p[j] = true;
		}
	}
}

void conj(int N){
	for (int i = 2;; i++){
		if (!p[i] && !p[N - i]){
			printf("%d %d", i, N - i);
			return;
		}
	}
}

int main(void){
    int N;
	primalidade();

	while (scanf("%d", &N) == 1){
		if (N < 8)
			puts("Impossible.");
		else{
			if (N % 2 == 0)
				printf("%d %d ", 2, 2), N -= 4;
			else
				printf("%d %d ", 2, 3), N -= 5;
			conj(N);
			putchar('\n');
		}
	}
	return 0;
}