#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<char, char> reverse;
    reverse['A'] = 'A'; reverse['E'] = '3'; reverse['H'] = 'H'; reverse['I'] = 'I'; reverse['J'] = 'L';
    reverse['L'] = 'J'; reverse['M'] = 'M'; reverse['O'] = 'O'; reverse['S'] = '2'; reverse['T'] = 'T';
    reverse['U'] = 'U'; reverse['V'] = 'V'; reverse['W'] = 'W'; reverse['X'] = 'X'; reverse['Y'] = 'Y';
    reverse['Z'] = '5'; reverse['1'] = '1'; reverse['2'] = 'S'; reverse['3'] = 'E'; reverse['5'] = 'Z';
    reverse['8'] = '8';
    
    string palavra;
    
    while(cin >> palavra) {
        bool palindromo(true), espelhado(true);
        
        for (string::iterator inicio = palavra.begin(), 
            final = palavra.end() - 1; 
            inicio <= final; 
            ++inicio, --final) {
                
            if(*inicio != *final) palindromo = false;
            
            if(reverse.find(*inicio) == reverse.end() || reverse[*inicio] != *final)
                espelhado = false;
        }
        
        cout << palavra << " -- is ";
        
        if(palindromo && espelhado) cout << "a mirrored palindrome.";
        else if(palindromo) cout << "a regular palindrome.";
        else if(espelhado) cout << "a mirrored string.";
        else cout << "not a palindrome.";
        
        cout << "\n\n";
    }
    return 0;
}
