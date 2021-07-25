/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL)
/*Compact*/
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(Object) Object.size()
#define all(Object) Object.begin(), Object.end()
#define Re0(Object) memset(Object, 0, sizeof(Object))
#define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
#define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
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
int dp[1001];
int a[1001];
/*Function*/
void init(){
    cin >> n;
    cinArr(a, n);
}

void solve(){
    int res = 0;
    Re0(dp);
    dp[0] = 1;
    Fu(i, 1, n, 1){
        dp[i] = 1;
        Fu(j, 0, i, 1){
            if(a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
            // else
            //     dp[i]
        }
        res = max(dp[i], res);
    }
    cout << res;
}

/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    Fu(i, 0, test, 1){
        init();
        cout << "Test " << i+1 << ": ";
        solve();
        cout << endl;
    }
    return 0;
}