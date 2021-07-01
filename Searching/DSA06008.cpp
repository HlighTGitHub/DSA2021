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
int test, n, m;
int a[lim];
int b[lim];
int numOfb[5];
/*Function*/
void init(){
    cin >> n >> m;
    cinArr(a, n);
    cinArr(b, m);
    Re0(numOfb);
}
int Count(int x){
    if(x == 0)  return 0;
    if(x == 1)  return numOfb[0];
    int res = (b + m) - upper_bound(b, b + m, x);
    res += numOfb[0] + numOfb[1];
    if(x == 2)  return res - numOfb[3] - numOfb[4];
    if(x == 3)  return res + numOfb[2];
    return res;
}
void solve(){
    sort(b, b+m);
    for(int i=0; i<m && b[i]<5; ++i)
        numOfb[b[i]]++;
    int res = 0;
    Fu(i, 0, n, 1)
        res += Count(a[i]);
    cout << res;
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