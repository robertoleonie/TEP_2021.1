#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int soma;
bool somaEhIgual;
char c;

bool leArvore(long long valor) {
   bool filhoEsq = false, filhoDir = false;
   int valorAtual = 0, sinal = 1;
   
   while (scanf("%c", &c)!=EOF) {
      if (c=='(') break;
      if (c==')') return false;
      if (c==' ' || c=='\n') continue;
      if (c=='-') sinal = -1;
      if (isdigit(c)) valorAtual = valorAtual*10 + (c-48);
   }
   
   valorAtual *= sinal;
   valor += (long long)valorAtual;
   filhoEsq = leArvore(valor);
   
   while (scanf("%c", &c)!=EOF && c!='(');
   
   filhoDir = leArvore(valor);
   
   if (!filhoEsq && !filhoDir && valor==soma) somaEhIgual = true;
   
   while (scanf("%c", &c)!=EOF && c!=')');
   return true;
}

int main (void){
   char c;
   while (scanf("%d ", &soma)!=EOF) {
      somaEhIgual = false;
      while (scanf("%c", &c)!=EOF && c!='(');
      leArvore(0);
      
      if (somaEhIgual) puts("yes");
      else puts("no");
   }
   return 0;
}
