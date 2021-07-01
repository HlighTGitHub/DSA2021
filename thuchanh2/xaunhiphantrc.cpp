#include<bits/stdc++.h>
#include<string>
using namespace std;
void solve(){
	string s;
	cin>>s;
	int n = s.length() - 1;
	for(int i = n; i >= 0; i--) 
        if(s[i] == '0')
            s[i] = '1';
        else {
            s[i] = '0';
            break;
        }
	cout<<s;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}
}