#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll Y[100],n,queen=0;
void init(){
	cin >> n;
	for(ll i=1;i<=n;i++){
		Y[i]=0;
	}
}
void display(){
    for(ll i=1;i<=n;i++) cout << Y[i] << ' ';
    cout << endl;
}
bool inval(ll x,ll y){
	for(ll i=1;i<=queen;i++){
		if(y==Y[i] || x-y==i-Y[i] || x+y==i+Y[i]) return false;
	}
	return true;
}
bool NotExist=true;
void Try(ll i){
	for(ll j=1;j<=n;j++){
		if(inval(i,j)){
			Y[i]=j;
			queen++;
			if(i==n){
				display();
				NotExist=false;
			}
			else Try(i+1);
			queen--;
		}
	}
	cout << '(' << i << ')' << ' ';
}
main(){
    init();
    Try(1);
    if(NotExist) cout << "Just one, or more Queen, please!";
}