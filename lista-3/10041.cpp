#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int casosDeTeste;
    int numFamiliares;
    int familia[numFamiliares];
    int index;
    int soma = 0;

    scanf("%d", &casosDeTeste);

    while(casosDeTeste--){
        scanf("%d",&numFamiliares);

        for(int i=0; i < numFamiliares; i++){
            scanf("%d", &familia[i]);
        }

        sort(familia, familia+numFamiliares);
        index =familia[numFamiliares/2];
        
        for(int i = 0; i < numFamiliares; i++){
            soma += abs(familia[i]-index);
        }

        printf("%d\n", soma);
    }
    return 0;
}