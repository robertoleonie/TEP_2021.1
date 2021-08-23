#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    unsigned N, rt;

    while(cin >> N && N > 0){
        rt = sqrt(N);
        if(N == rt*rt) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}