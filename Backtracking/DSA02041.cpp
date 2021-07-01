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
int dp[100005];
/*Function*/
void init(){
    cin >> n;
}
void DP(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    Fu(i, 4, 100005, 1){
        int div3 = dp[i/3] + 1;
        int div2 = dp[i/2] + 1;
        int sub  = dp[i-1] + 1;
        if(i%6 == 0)
            dp[i] = min(sub, min(div3, div2));
        else if(i%3 == 0)
            dp[i] = min(div3, sub);
        else if(i%2 == 0)
            dp[i] = min(div2, sub);
        else
            dp[i] = sub;
    }
}
void solve(){
    cout << dp[n];
}
int Min;
void Try(int i, int step){
    if(i == 1){
        Min = min(Min, step);
        return;
    }
    if(i%3 == 0)   Try(i/3, step + 1);
    if(i%2 == 0)   Try(i/2, step + 1);
    Try(i-1, step + 1);
}
void solve2(){
    Min = oo;
    Try(n, 0);
    cout << Min;
}
/*Main program*/
int main(){
    IOS()
    if(MultiTest)	cin >> test;
    // DP();
    while(test--){
        init();
        solve2();
        cout << endl;
    }
    return 0;
}