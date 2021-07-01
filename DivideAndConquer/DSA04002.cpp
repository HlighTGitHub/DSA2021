/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS() ios::sync_with_stdio(false);
#define tie() cin.tie(NULL); cout.tie(NULL);
/*Compact*/
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define all(Object) Object.begin(), Object.end()
#define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
#define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
#define Re0(Object) memset(Object, 0, sizeof(Object))
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test;
ll n;
string s;
/*Function*/
void init(){
    cin >> n;
    // cin >> s;
}
ll powmod(ll a, ll b){
    if(b == 1)  return a%Mod;
    ll tmp = powmod(a, b/2);
    if(b&1) return tmp*tmp%Mod*a%Mod;
    return tmp*tmp%Mod;
}
void solve2(){
    ll a=0, b=0;
    Fu(i, 0, s.size(), 1){
        a = a*10 + (s[i] - '0');
        b += (s[i] - '0')*powmod(10, i);
    }
    cout << powmod(a, b);
}
void solve(){
    ll rev = 0, tmp = n;
    while(tmp){
        rev = rev*10 + tmp%10;
        tmp /= 10;
    }
    cout << powmod(n, rev);
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/