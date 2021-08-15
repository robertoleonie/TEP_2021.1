#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string a, b;
    int contA[26];
    int contB[26];
    int lenA, lenB;

    while(getline(cin, a) && getline(cin, b)){
        lenA = a.size();
        lenB = b.size();

        memset(contA, 0, sizeof(contA));
        memset(contB, 0, sizeof(contB));

        for(int i = 0; i < lenA; ++i){
            ++contA[a[i] - 'a'];
        }
        for(int i = 0; i < lenB; ++i){
            ++contB[b[i] - 'a'];
        }

        for(int i = 0; i < 26; ++i){
            for(int j = min(contA[i], contB[i])-1; j >= 0; --j){
                putchar('a' + i);
            }
        }

        putchar('\n');
    }

    return 0;
}