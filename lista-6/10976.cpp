#include <iostream>

using namespace std;

int main(void) {
    int k;
    int cont;

    while(cin>>k) {
        int solucao[1000][2]= {0};
        cont = 0;

        for(int y = k+1; y <= 2*k; y++){
            double x = ((double)k * (double)y)/((double)y - (double)k);
            if(x==(int)x) {
                solucao[cont][0] = (int)x;
                solucao[cont][1] = y;
                cont++;
            }
        }

        cout<<cont<<endl;

        for(int i = 0; i < cont; i++) {
            cout<<"1/"<<k<<" = 1/"<<solucao[i][0]<<" + 1/"<<solucao[i][1]<<endl;
        }
    }

    return 0;
}