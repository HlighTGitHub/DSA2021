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
#define lim 200005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;
vector <int> a[lim];
int dep[lim];
ll dp[lim];
ll sub[lim];
/*Function*/

void init(){
    cin >> n;
}

void DFS(int i){
    dp[i] = dep[i];
	sub[i] = 1;
	Fu(j, 0, a[i].size(), 1){
		DFS(a[i][j]);
		dp[i] += dp[a[i][j]];
		sub[i] += sub[a[i][j]];
	}
}
void solve(){
    int tmp;
    Fu(i, 2, n+1, 1){
        cin >> tmp;
		a[tmp].pb(i);
		dep[i] = dep[tmp] + 1;
	}
	DFS(1);
	Fu(i, 1, n+1, 1)
		cout << dp[i] - sub[i] * ((ll)dep[i]-1) << ' ';
}
/*Main program*/
int main(){
    IOS()
    // cin >> test;
    // while(test--){
        init();
        solve();
    //     cout << endl;
    // }
    return 0;
}

/*Source: From Nguyen Manh Son*/