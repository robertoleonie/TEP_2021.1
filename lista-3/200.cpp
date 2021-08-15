#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> str;

bool g[26][26];
bool f[26];

void constroi(int a, int b, int k)
{
    for (; a <= b && k >= str[a].size(); a++);
    if (a >= b) return;
    int i = a;
    int j = a;
    for (; j<=b; j++)
    {
        if (str[i][k] != str[j][k])
        {
            g[str[i][k]-'A'][str[j][k]-'A'] = true;
            f[str[i][k]-'A'] = true;
            f[str[j][k]-'A'] = true;
            constroi(i, j-1, k+1);
            i = j;
        }
    }
    constroi(i, j-1, k+1);
}

int main(void)
{
    string width;
    
    while (cin >> width, width != "#")
        str.push_back(width);
    
    constroi(0, str.size() - 1, 0);
    
    int cont = count(f, f+26, true);
    
    stack<char> resposta;
    while (cont) {
        for (int i=0; i<26; i++) {
            if ( f[i] && count( g[i], g[i]+26, true ) == 0 ) {
                resposta.push( 'A' + i );
                f[i] = false;
                cont--;
                for (int j=0; j<26; j++) 
                    g[j][i] = false;
            }
        }
    }

    while (!resposta.empty()) {
        printf("%c",resposta.top());
        resposta.pop();
    }

    puts("");
    return 0;
}
