#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int i, teste, j, len;
        char expressao[150];
        scanf("%d\n", &teste);
        
        for (i=1; i<=teste; i++) {
            stack<char> pilha;
            cin.getline(expressao,150);
            
            len=strlen(expressao);
            
            if(len==0) {
                printf("Yes\n");
                continue;
            }
            
            for(j=0; j<len; j++) {
                if(expressao[j]=='(' || expressao[j]=='[')
                    pilha.push(expressao[j]);
                else if (!pilha.empty() && ((pilha.top()=='(') &&(expressao[j]==')' ) || (pilha.top()=='[') && expressao[j]==']' ))
                        pilha.pop();
                else if(expressao[j]==' ')
                    continue;
                else
                    break;
 
            }
 
            if(pilha.empty() && len==j)
                printf("Yes\n");
            else
                printf("No\n");
        }
    return 0;
}
