#include <iostream>

using namespace std;

long long X, Y, D;

void euclid(long long A, long long B){
    if(B == 0){
        X = 1;
        Y = 0;
        D = A;
        return;
    }
    euclid(B, A % B);
    long long x1, y1;

    x1 = Y;
    y1 = X - A/B * Y;
    X = x1;
    Y = y1;
}

int main(void){
    long long A, B;

    while(scanf("%lld %lld", &A, &B) == 2){
        if(A == 0) swap(A, B);
        euclid(A, B);
        printf("%lld %lld %lld\n", X, Y, D);
    }
    return 0;
}