#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        for (int i = n.length()-1; i >= 0; i--){
            if (n[i] == '1'){
                n[i] = '0';
                for (int j = i+1; j <= n.length()-1 ; j++){
                    n[j] = '1'; 
                }
                break;
            }
            if(i == 0){
                for(int j = 0; j < n.length(); j++)
                    n[j] = '1';
            }
        } 
        cout << n;
        cout << endl;
    }
}