#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

#define MAX 10

using namespace std;

int main(void){
    int N;
    cin>>N;
    char aux;

    for(int i = 0; i < N; i++){
        char palavra[MAX] = {'\0'};
        cin>>palavra;

        for(int j = 0; j < strlen(palavra); j++){
            for(int k = j+1; k < strlen(palavra); k++){
                if(palavra[j] > palavra[k]){
                    // se o caractere for maior, eu realizo a troca (ordem alfabetica)
                    aux = palavra[j];
                    palavra[j] = palavra[k];
                    palavra[k] = aux;
                }
            }
        }

        do {
            for(int j = 0; j < strlen(palavra); j++){
                cout<<palavra[j];
            }
            cout<<endl;
        } while (next_permutation(palavra, palavra+strlen(palavra)));
        cout<<endl;
    }
    return 0;
}
