#include <iostream>

using namespace std;

int main (void){
	int N;
    int vitoriasX, vitoriasO, x, o;
    bool flag;

	cin>>N;

	while(N--){
		string str[3];
		cin>>str[0]>>str[1]>>str[2];

		vitoriasX = 0;
        vitoriasO = 0;
		x = 0;
        o = 0;

		if(str[0][0]=='X' && str[1][1]=='X' && str[2][2]=='X') vitoriasX++;
		if(str[2][0]=='X' && str[1][1]=='X' && str[0][2]=='X') vitoriasX++;
		if(str[0][0]=='X' && str[1][0]=='X' && str[2][0]=='X') vitoriasX++;
		if(str[0][1]=='X' && str[1][1]=='X' && str[2][1]=='X') vitoriasX++;
		if(str[0][2]=='X' && str[1][2]=='X' && str[2][2]=='X') vitoriasX++;
		if(str[0][0]=='X' && str[0][1]=='X' && str[0][2]=='X') vitoriasX++;
		if(str[1][0]=='X' && str[1][1]=='X' && str[1][2]=='X') vitoriasX++;
		if(str[2][0]=='X' && str[2][1]=='X' && str[2][2]=='X') vitoriasX++;
		
		if(str[0][0]=='O' && str[1][1]=='O' && str[2][2]=='O') vitoriasO++;
		if(str[2][0]=='O' && str[1][1]=='O' && str[0][2]=='O') vitoriasO++;
		if(str[0][0]=='O' && str[1][0]=='O' && str[2][0]=='O') vitoriasO++;
		if(str[0][1]=='O' && str[1][1]=='O' && str[2][1]=='O') vitoriasO++;
		if(str[0][2]=='O' && str[1][2]=='O' && str[2][2]=='O') vitoriasO++;
		if(str[0][0]=='O' && str[0][1]=='O' && str[0][2]=='O') vitoriasO++;
		if(str[1][0]=='O' && str[1][1]=='O' && str[1][2]=='O') vitoriasO++;
		if(str[2][0]=='O' && str[2][1]=='O' && str[2][2]=='O') vitoriasO++;
		
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				if(str[i][j] == 'O') o++;
				if(str[i][j] == 'X') x++;
			}
		}

		flag = true;

        if((vitoriasX > 0 && vitoriasO > 0) || 
            (vitoriasX > 0 && (x != o+1)) || 
            (vitoriasO > 0 && (x != o))) {
            cout<<"no";
        }

        else if((vitoriasX > 0 && (x == o+1)) || 
            (vitoriasO > 0 && (x == o)) || 
            ((x == o) || (x == o+1))) {
            cout<<"yes\n";
        }

        else cout<<"no\n";

        cout<<endl;
	}
	return 0;
}