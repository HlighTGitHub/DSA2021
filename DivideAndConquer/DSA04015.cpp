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
#define lim 10000005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;
ll k;
/*Function*/
int seek(ll a[], int l, int r, ll x){
    if(x < a[0])    return (-2);
    while(l < r){
        int m = (l+r)/2;
        if(a[m] == x)   return m;
        if(a[m] < x)    l = m+1;
        else r = m-1;
    }
    return l;
}

void solve(ll a[]){
    int i = seek(a, 0, n-1, k);
    if(a[i] >= k && i>0)    --i;
    if(i+2 && a[i+1] == k) ++i;
    cout << i+1;
}
void solve2(ll a[]){
    int i = upper_bound(a, a+n, k) - a;
    cout << i - (!i);
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        cin >> n >> k;
        ll a[n];
        cinArr(a, n);
        solve2(a);
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/