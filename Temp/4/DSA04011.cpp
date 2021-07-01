#include<bits/stdc++.h>
using namespace std;
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
string a,b;
/*
    n = 0
    0110
    1*2^1 + 1*2^2
*/
ll cv(string s){
    ll sum = 0 ;
    for(int i = 0 ; i < s.length() ; i++){
        sum *= 2;
        sum += (s[i] == '1');
    }
    return sum;
}
void Input(){
    cin >> a >> b;
}   
void Solve(){
    cout << cv(a)*cv(b) << '\n';
}
int main(){
    setIO();
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}
