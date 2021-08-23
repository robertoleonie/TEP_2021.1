#include <iostream>
#include <vector>

using namespace std;

bool ehPrimo(int N) {
    if (N == 2) return true;
    if (N % 2 == 0) return false;

    for (int i = 3; i*i <= N; i += 2)
        if (N % i == 0) return false;

    return true;
}

unsigned fermat(unsigned a, int K, int N) {
    if (K == 1) return a;
    
    if (K % 2 == 0)
        return fermat((a * a) % N, K / 2, N);
    else
        return (a * fermat((a * a) % N, K / 2, N)) % N;
}

int main(void) {
    int N; 
    vector<int> carmichael;

    for (int i = 2; i < 65000; i++) {
        if (ehPrimo(i)) continue;

        unsigned j;
        for (j = 2; j < i; j++) {
            if (fermat(j, i, i) != j) break;
        }

        if (j == i) carmichael.push_back(i);
    }

    while (cin >> N) {
        if (N == 0) break;

        bool encontrado = false;
        for (int i = 0; i < carmichael.size(); i++) {
            if (carmichael[i] == N) {
                encontrado = true;
                break;
            }
        }

        if (encontrado) {
            cout << "The number " << N << " is a Carmichael number." << endl;
        } else {
            cout << N << " is normal." << endl;
        }
    }
    return 0;
}