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
#define oo INT_MAX
const int ArrLim = 1e6+5;
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

/*Initialize*/
bool MultiTest = true;
int test = 1;
int n;
int dp[10][105];
/*Function*/
void init(){
    cin >> n;
}
void DP(){
    Fu(i, 0, 10, 1)
        dp[i][1] = 1;
    Fu(i, 0, 10, 1)
        Fu(j, 2, 101, 1)
            Fu(k, 0, i+1, 1){
                dp[i][j] += dp[k][j-1];
                dp[i][j] %= Mod;
            }
}
void solve(){
    ll ans = 0;
    Fu(i, 0, 10, 1)
        ans += dp[i][n];
    cout << ans%Mod;
}

/*Main program*/
int main(){
    IOS()
    if(MultiTest)	cin >> test;
    DP();
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}