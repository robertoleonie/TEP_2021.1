#include<cstdio>
#include<stack>
 
using namespace std;
 
int carro, numCarros;
stack<int> pilhaDeCarros;
 
void ordenaCarros(void) {
	int i, j;
	
    while(1) {
        while(pilhaDeCarros.size() > 0) 
        	pilhaDeCarros.pop();
        i = 0;
        
        for(j = 0; j < numCarros; j++) {
            scanf("%d", &carro);
            if(carro == 0)
            	return;
 
            while(i < numCarros && i != carro) {
                if(pilhaDeCarros.size() > 0 && pilhaDeCarros.top() == carro) 
                	break;
                i++;
                pilhaDeCarros.push(i);
            }
            
            if(pilhaDeCarros.top() == carro) 
            	pilhaDeCarros.pop();
        }
        if(pilhaDeCarros.size() == 0) 
        	printf("Yes\n");
        else 
        	printf("No\n");
    }
}
 
int main() {
    while(1) {
        scanf("%d", &numCarros);
        if(numCarros == 0) 
        	break;
 
        ordenaCarros();
        printf("\n");
    }
    return 0;
}
