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
string a;
/*Function*/
void init(){
    cin >> n;
}
void init2(){
    cin >> a;
}
void solve(){
    ll res = 0;
    queue <ll> q;
    q.push(1);
    while(true){
        ll tmp = q.front();        
        if(tmp > n) break;
        q.pop();
        ++res; 
        q.push(tmp*10);
        q.push(tmp*10 + 1);
    }
    cout << res;
}
void solve2(){
    ll res = 0;
    bool is0[a.size()];
    Re0(is0);
    Fu(i, 0, a.size(), 1){
        if(a[i] == '0') is0[i] = true;
        else if(a[i] > '1') break;
    }
    Fu(i, 0, a.size(), 1)
        res += (1 - is0[i])*pow(2, (float)(a.size() - 1 - i));
    cout << res;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init2();
        solve2();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/