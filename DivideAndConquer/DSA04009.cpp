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
class Matrix{
    public:
    ll a[11][11];
    int deg;
};
Matrix mul(Matrix x, Matrix y){
    Matrix res;
    res.deg = x.deg;
    Fu(i, 0, res.deg, 1)
        Fu(j, 0, res.deg, 1){
            res.a[i][j] = 0;
            Fu(k, 0, res.deg, 1){
                res.a[i][j] += x.a[i][k]*y.a[k][j];
                res.a[i][j] %= Mod;
            }
        }
    return res;
}
Matrix powmod(Matrix x, int k){
    if(k == 1)  return x;
    Matrix tmp = powmod(x, k>>1);
    tmp = mul(tmp, tmp);
    if(k&1) return mul(tmp, x);
    return tmp;
}
/*Initialize*/
bool MultiTest = true;
int test = 1;
int N, K;

/*Function*/
void init(){
    cin >> N >> K;
}

void solve(){
    Matrix res;
    res.deg = N;
    Fu(i, 0, N, 1)
        Fu(j, 0, N, 1) 
            cin >> res.a[i][j];
    res = powmod(res, K);
    Fu(i, 0, N, 1){
        Fu(j, 0, N, 1) 
            cout << res.a[i][j] << ' ';
        cout << endl;
    }
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