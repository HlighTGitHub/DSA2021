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
typedef vector <int> vi;

/*Initialize*/
bool MultiTest = true;
int test = 1;
int n, sum;
int num[10];
/*Function*/
//Tham lam tối ưu hơn queue:
void init(){
    cin >> n;
    int tmp;
    Re0(num);
    sum = 0;
    Fu(i, 0, n, 1){
        cin >> tmp;
        ++num[tmp];
        sum += tmp;
    }
}
void Erase(int mod){
    if(mod == 0) return;
    int del = 2;
    Fu(i, mod, 10, 3)
        if(num[i]){
            --num[i];
            del = 0;
            break;
        }
    int i = 3 - mod;
    while(del && i<9){
        if(num[i])  --num[i];
        if(!num[i]) ++i;
    }
    if(del) cout << -1;
}
void solve(){
    Erase(sum%3);
    Fd(i, 9, 0, 1)
        while(num[i]--)
            cout << i;
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