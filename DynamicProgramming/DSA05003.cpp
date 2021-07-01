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
int N, M, K;
string a, b, c;
int dp[105][105][105];
/*Function*/
void init(){
    cin >> N >> M >> K;
    cin >> a >> b >> c;
}
void DP(){
    a = " " + a;
    b = " " + b;
    c = " " + c;
    Fu(n, 1, N+1, 1)
        Fu(m, 1, M+1, 1)
            Fu(k, 1, K+1, 1)
                if(a[n] == b[m] && b[m] == c[k])
                    dp[n][m][k] = dp[n-1][m-1][k-1] + 1;
                else
                    dp[n][m][k] = max(dp[n-1][m][k], max(dp[n][m-1][k], dp[n][m][k-1]));
}
void solve(){
    DP();
    cout << dp[N][M][K];
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