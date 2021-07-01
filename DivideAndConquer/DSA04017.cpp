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
int solve(ll a[], ll b[], int l, int r){
    if(l == r) return l;
    int m = (l+r)/2;
    if(a[m] == b[m])    return solve(a, b, m+1, r);
    return solve (a, b, l, m);
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        cin >> n;
        ll a[n];
        ll b[n];
        cinArr(a, n);
        cinArr(b, n-1);
        cout << solve(a, b, 0, n-1) + 1;
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/