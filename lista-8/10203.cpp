#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    double soma;
    string s;

    int T, x, hrs, mns;
    cin >> T;

    while(T--){
        soma = 0;

        cin >> x >> x;
        ws(cin);
        getline(cin, s);

        while(s.size() > 0){
            stringstream ss(s);
            double x1, y1, x2, y2;
            ss >> x1 >> y1 >> x2 >> y2;

            soma += sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
            
            if(cin.eof()) break;

            getline(cin, s);
        }
        soma *= 6;
        soma /= 1000;

        hrs = round(soma)/60;
        mns = int(round(soma)) % 60;

        cout << hrs << ":";
        if(mns < 10)
            cout << 0;
        cout << mns << endl;

        if(T) 
            cout << endl;
        else 
            return 0;
    }
}
