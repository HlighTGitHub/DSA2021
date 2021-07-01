#include <bits/stdc++.h>
using namespace std;

string gray;
string graytoBinary(){
    string binary = "";
    binary += gray[0];
    for (int i = 1; i < gray.length(); i++) {
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
            binary += (binary[i - 1] == '0')?'1':'0';
    }
    return binary;
}
int main()
{
    int test;
    cin >> test;
	while(test--){
		cin >> gray;  
	    cout << graytoBinary();
		cout << endl;
	}
    return 0;
}