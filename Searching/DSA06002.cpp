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
int test, n, k;
#define pi pair <int, int>
/*Function*/
void init(){
    cin >> n >> k;
}
bool cmp(pi a, pi b){
    if(abs(a.se - k) == abs(b.se - k))
        return a.fi < b.fi;
    return abs(a.se - k) < abs(b.se - k);
}
void solve(){
    vector <pi> a;
    int tmp;
    Fu(i, 0, n, 1){
        cin >> tmp;
        a.pb(mp(i, tmp));
    }
    sort(all(a), cmp);
    Fu(i, 0, n, 1)
        cout << a[i].se << ' ';
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