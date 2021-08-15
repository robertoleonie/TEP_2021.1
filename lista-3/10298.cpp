#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void) {
    char s[1000000+5];
    bool got;
    int i, tam;

    while(scanf("%s", &s) && s[0]!='.'){
        tam = strlen(s);
        got = true;

        for(i = 1; i<tam-1; i++){
            if(tam % i != 0)
                continue;
            for(int j = i; j<tam; j++)
                if(s[j] != s[j%i]){
                    got = false;
                    break;
                }
        if(got) 
            break;
        got = true;
        }
        if(got)
            printf("%d\n", tam/i);
        else 
            printf("%d\n", tam);
    }
    return 0;
}