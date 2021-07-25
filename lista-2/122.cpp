#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define TAM 100000

int valores[TAM], var, i;
bool pertence[TAM], compara;

bool validacao() {
   if (!pertence[1]) 
   	return false;
   	
   for(i=2; i<=var; i+=2){
      bool isFilho = pertence[i] || pertence[i+1];
      if (isFilho && !pertence[i/2]) 
      	return false;
   }
   return true;
}

int main(void) {
   int tamanho, aux, aux2 = 1;
   char palavra[300], caminho[300];
   
   while (scanf("%s", &palavra) != EOF) {
      var = 1; 
      compara = true;
      memset(pertence, false, TAM);
      
      while (1) {
         if (strcmp(palavra, "()")==0) 
         	break;
         	
         sscanf(palavra, "(%d,%s)", &aux, &caminho);
         tamanho = strlen(caminho);

         for(i = 0; i < tamanho-2; i++) {
            aux2 *= 2;
            if (caminho[i]=='R') aux2 += 1;
         }
         
         if(pertence[aux2]) compara = false;
         pertence[aux2] = true;
         valores[aux2] = aux;
         var = max(aux2, var);
         
         scanf("%s", &palavra);
      }
      
      if (!compara || !validacao()) 
		puts("not complete");
      else {
         printf("%d", valores[1]);
         for(i = 2; i < var; i++) {
            if (pertence[i]) printf(" %d", valores[i]);
         }
         printf("\n");
      }
   }
   return 0;
}
