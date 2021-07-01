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
int N, K;
int a[1005];
/*Function*/
void init(){
    cin >> N >> K;
    cinArr(a, N);
}
void DP(){
    vector <int> dp[K];
    Fu(i, 0, K, 1)  dp[i].resize(N);
    dp[a[0]%K][0] = 1;
    Fu(n, 1, N, 1)
        Fu(k, 0, K, 1){
            int tmp = (a[n] + k)%K;
            dp[tmp][n] = dp[tmp][n-1];
            if(dp[k][n-1] && dp[k][n-1]+1 > dp[tmp][n])
                dp[tmp][n] = dp[k][n-1]+1;
        }
    cout << dp[0][N-1];
}
void solve(){
    DP();
}

/*Main program*/
int main(){
    IOS()
    if(MultiTest)	cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}