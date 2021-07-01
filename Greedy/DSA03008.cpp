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
#define pii pair<int, int>
/*Function*/
bool cmp(pii a, pii b){
    return  a.se < b.se;
}
void solve(pii a[]){
    sort(a, a+n, cmp);
    int res = 1;
    int tmp = a[0].se;
    Fu(i, 1, n, 1)
        if(a[i].fi >= tmp){
            res++;
            tmp = a[i].se;
        }
    cout << res;
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        cin >> n;
        pii a[n];
        Fu(i, 0, n, 1)  cin >> a[i].fi;
        Fu(i, 0, n, 1)  cin >> a[i].se;
        solve(a);
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/

