#include <iostream>
#include <cstring>

static char s[128];
static char t[128];

static char saida[128];

int main(void){
    while(scanf("%s", s) && scanf("%s", t)){
        if(strcmp(s,t) == 0 && s[0] == '0')
            break;

        int tamS = strlen(s);
        int tamT = strlen(t);

        if(tamS > tamT){
            int padding = tamS - tamT;

            for(int i = tamT - 1; i >= 0; --i)
                t[i + padding] = t[i];
            for(int i = 0; i < padding; ++i)
                t[i] = '0';
        } else if (tamS < tamT) {
            int padding = tamT - tamS;

            for(int i = tamS - 1; i >= 0; --i)
                s[i + padding] = s[i];
            for(int i = 0; i < padding; ++i)
                s[i] = '0';
        }

        int tamMax;
        (tamS > tamT) ? tamMax = tamS : tamMax = tamT;
        
        int vaiUm = 0;
        int c = 0;
        int soma = 0;

        for(int i = tamMax - 1; i >= 0; --i){
            soma += s[i] - '0' + t[i] - '0';
            soma += vaiUm;
            vaiUm = soma / 10;
            if(vaiUm) ++c;
            soma = 0;
        }

        if(!c)
            printf("No carry operation.\n");
        else if(c > 1)
            printf("%d carry operations.\n", c);
        else
            printf("%d carry operation.\n", c);
    }
    return 0;
}