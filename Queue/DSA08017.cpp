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
int test, n;

/*Function*/
void init(){
    cin >> n;
}
void solve(){
    queue <ll> q;
    vector <ll> res;
    q.push(6);
    q.push(8);
    Fu(i, 0, n, 1)
        Fu(j, 0, pow(2, (float)(i+1)), 1){
            ll tmp = q.front();
            q.pop();
            res.pb(tmp);
            q.push(tmp*10 + 6);
            q.push(tmp*10 + 8);
        }
    Fd(i, res.size()-1, 0, 1)
        cout << res[i] << ' ';
}
void solve2(){
    queue <ll> q;
    vector <ll> res;
    q.push(6);
    res.pb(6);
    q.push(8);
    res.pb(8);
    Fu(i, 0, n-1, 1)
        Fu(j, 0, pow(2, (float)(i+1)), 1){
            ll tmp = q.front();
            q.pop();
            q.push(tmp*10 + 6);
            res.pb(tmp*10 + 6);
            q.push(tmp*10 + 8);
            res.pb(tmp*10 + 8);
        }
    Fd(i, res.size()-1, 0, 1)
        cout << res[i] << ' ';
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve2();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/