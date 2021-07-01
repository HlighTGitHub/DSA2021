#include <bits/stdc++.h>
using namespace std;

string binary;
string binaryToGray(){
    string gray = "";
    gray += binary[0];
    for (int i = 1; i < binary.length(); i++) {
        gray += (binary[i - 1] == binary[i])?'0':'1';
    } 
    return gray;
}
int main()
{
    int test;
    cin >> test;
	while(test--){
		cin >> binary;  
	    cout << binaryToGray();
		cout << endl;
	}
    return 0;
}