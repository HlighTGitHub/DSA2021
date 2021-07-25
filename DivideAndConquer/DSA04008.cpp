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
    ll a[2][2];
    void Create();
};
void Matrix::Create(){
    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
}
Matrix mul(Matrix x, Matrix y){
    Matrix res;
    Fu(i, 0, 2, 1)
        Fu(j, 0, 2, 1){
            res.a[i][j] = 0;
            Fu(k, 0, 2, 1){
                res.a[i][j] += x.a[i][k]*y.a[k][j];
                res.a[i][j] %= Mod;
            }
        }
    return res;
}
Matrix powmod(Matrix x, int n){
    if(n == 1)  return x;
    Matrix tmp = powmod(x, n>>1);
    tmp = mul(tmp, tmp);
    if(n&1) return mul(tmp, x);
    return tmp;
}
/*Initialize*/
bool MultiTest = true;
int test = 1;
int n;

/*Function*/
void init(){
    cin >> n;
}

void solve(){
    Matrix res;
    res.Create();
    res = powmod(res, n-1);
    cout << res.a[1][1];
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