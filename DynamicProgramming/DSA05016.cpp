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
vector <ll> ugly;
pair <int, int> mark[3] = {{2, 61}, {3, 39}, {5,26}};
/*Function*/
void init(){
    cin >> n;
}
void Gen(int step, ll tmp){
    Fu(i, 0, mark[step].se, 1){
        ll num = tmp * pow(mark[step].fi, i);
        if(step == 2){
            if(num > 0 && num <= LONG_LONG_MAX)
                ugly.pb(num);
        }
        else if(num < tmp)  return;
        else Gen(step+1, num);
    }
}
void sieve(){
    Gen(0, 1);
    sort(ugly.begin(), ugly.end());
}
void solve(){
    cout << ugly[n-1];
}

/*Main program*/
int main(){
    IOS()
    if(MultiTest)	cin >> test;
    sieve();
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}