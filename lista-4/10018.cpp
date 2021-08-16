#include <iostream>

using namespace std;

long revPal(long num){
    long numPal = 0;

    while(num){
        numPal *= 10;
        numPal += num % 10;
        num /= 10;
    }

    return numPal;
}

int main(void){
    long num, numPal;
    int N, j;

    cin >> N;

    for(int i = 0; i < N; i++){
        num = 0;
        numPal = 0;
        j = 0;

        cin >> num;

        numPal = revPal(num);

        if(num == numPal){
            cout << "0 " << num << endl;
        } else {
            while(num != numPal){
                j++;
                num += numPal;
                numPal = revPal(num);
            }
            cout << j << " " << num << endl;
        }
    }
    return 0;
}
