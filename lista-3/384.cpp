#include <iostream>
#include <string>

using namespace std;

int leSlump(int inicio, string &s);

int leSlimp(int inicio, string &s) {
    int i = inicio;

    if (i == s.size())
        return -1;

    if (s[i] == 'A')
        i++;
    else
        return -1;

    if (i == s.size())
        return -1;

    if (s[i] == 'H')
        return i + 1;

    if (s[i] == 'B') {
        i = leSlimp(i+1, s);
    } else {
        i = leSlump(i, s);
    }

    if (i == -1 || i == s.size())
        return -1;

    if (s[i] == 'C')
        return i + 1;

    return -1;
}

int leSlump(int inicio, string &s) {
    int i = inicio;

    if (i == s.size())
        return -1;

    if (s[i] == 'D' || s[i] == 'E')
        i++;
    else
        return -1;

    if (i == s.size())
        return -1;

    if (s[i] != 'F')
        return -1;

    for ( ; s[i] == 'F' && i < s.size(); i++);

    if (i == s.size())
        return -1;

    if (s[i] == 'G')
        return i + 1;

    i = leSlump(i, s);

    if (i == -1) 
        return -1;

    return i;
}

bool ehSlurpy(string &s) {
    int final = leSlimp(0, s);

    if (final == -1)
        return false;

    final = leSlump(final, s);

    return final == s.size();
}

int main(void) {
    int N;
    string input;

    cin >> N;
    getline(cin, input);

    cout << "SLURPYS OUTPUT" << endl;

    while (N--) {
        getline(cin, input);
        cout << (ehSlurpy(input) ? "YES" : "NO") << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}