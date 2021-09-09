#include <iostream>

using namespace std;

int main (void){
    int s, d;
    int surplus, deficit;
    int total;
    int mesAtual, mesesDisponiveis;

    while(cin>>s>>d){
        surplus = 5*d/(s+d);

        if(surplus < 1) {
            cout<<"Deficit\n";
            continue;
        }

        deficit = 5 - surplus;
        total = 0;
        mesAtual = 0;

        while(mesAtual < 12) {  // enquanto mes atual < dezembro
            mesesDisponiveis = min(surplus, 12-mesAtual);
            total += s * mesesDisponiveis;
            mesAtual += mesesDisponiveis;

            mesesDisponiveis = min(deficit, 12-mesAtual);
            total -= d * mesesDisponiveis;
            mesAtual += mesesDisponiveis;
        }

        if(total < 0){
            cout<<"Deficit\n";
        } else {
            cout<<total<<"\n";
        }

    }
    return 0;
}