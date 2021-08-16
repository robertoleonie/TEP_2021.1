#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define COEF_MAX 105
#define K_MAX 51

unsigned long long C[K_MAX][K_MAX];

void coef() {
    C[0][0] = 1;
    for (int i = 1; i < K_MAX; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
}

int main(void) {
    coef();
    int coeff, K, n;
    string a, b;
    char s[COEF_MAX];

    scanf("%d", &coeff); 

    for (int i = 1; i <= coeff; i++) {
        cin >> s;
        n = strlen(s);
        a = b = "";

        int T = 1;
        while (s[T]!='+') a += s[T++];
        T++;
        while (s[T]!=')') b += s[T++];
        T += 2;

        sscanf(s+T, "%d", &K);
        printf("Case %d: ", i);
        cout << a;
        if (K > 1) printf("^%d", K);
        
        for (T = 1; T < K; T++) {
            printf("+%lld*", C[K][T]);
            cout << a;
            if (K-T>1) printf("^%d", K-T);
            cout << "*" << b;
            if (T > 1) printf("^%d", T);
        }
        
        printf("+");
        cout << b;
        if (K > 1) printf("^%d", K);
        printf("\n");
    }

    return 0;
}