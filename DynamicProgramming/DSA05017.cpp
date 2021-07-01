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
int a[100005];
int up[100005];
int down[100005];
/*Function*/
void init(){
    cin >> n;
    cinArr(a, n);
}
void DP(){
    Fu(i, 0, n, 1){
        up[i] = a[i];
        Fu(j, 0, i, 1)
            if(a[i] > a[j])
                up[i] = max(up[i], up[j] + a[i]);
    }
    Fd(i, n-1, 0, 1){
        down[i] = a[i];
        Fd(j, n-1, i+1, 1)
            if(a[i] > a[j])
                down[i] = max(down[i], down[j] + a[i]);
    }
}
void solve(){
    DP();
    int Max = -1;
    Fu(i, 0, n, 1)
        Max = max(Max, up[i] + down[i] - a[i]);
    cout << Max;
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