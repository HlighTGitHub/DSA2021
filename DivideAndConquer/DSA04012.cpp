/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL)
/*Compact*/
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
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
vector <int> a,b;
int n,m;
/*Function*/
void init(){
    cin >> n >> m;
    a.resize(n) ; b.resize(m);
    for(int i = 0; i < n; i++ ) cin >> a[i];
    for(int i = 0; i < m; i++ ) cin >> b[i];
}   
void solve(){
    int cnt[1000] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int  j = 0 ; j < m ; j++){
            cnt[i+j] += a[i]*b[j];
        }
    }
    for(int i = 0; i <= n + m - 2; i++){
        cout << cnt[i] << ' ';
    }
    cout << '\n';
}
/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}