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
#define oo INT_MAX
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test;

/*Function*/
int C(int K, int N){
    K = min(K, N-K);
    ll C[K+1];
    Re0(C);
    C[0] = 1;
    Fu(n, 1, N+1, 1)
        Fd(k, min(K, n), 1, 1){
            C[k] = C[k] + C[k-1];
            C[k] %= Mod;
        }
    return C[K];
}
void solve(){
    int n, k;
    cin >> n >> k;
    cout << C(k, n);
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/