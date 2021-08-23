#include <iostream>

using namespace std;

int main(void) {
    long long N, largest, i;
    int cont;

    while (cin>>N && N != 0){
        if (N < 0)
            N *= -1;

        largest = -1;
        cont = 0;

        for (i = 2; i*i <= N && N != 1; i++) {
            while (N%i == 0){
                N /= i;
                largest = i;
            }
            if (largest == i)
                cont++;
        }

        if (N != 1 && largest!=-1)
            largest = N;
        else if(cont == 1)
            largest = -1;

        cout<<largest<<endl;
     }

    return 0;
}
