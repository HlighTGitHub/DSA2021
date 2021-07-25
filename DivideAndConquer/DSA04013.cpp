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
int n;
int a[ArrLim];

/*Function*/
void init(){
    cin >> n;
    cinArr(a, n);
    sort(a, a+n);
}
bool found(int th, int value, bool seen[]){
    int index = lower_bound(a+n/2+th, a+n, value) - a;
    if(index == n)  return false;
    while(index < n && seen[index] == true)  ++index;
    if(index == n)  return false;
    seen[index] = true;
    return true;
}
void solve(){
    bool seen[n+1] = {0};
    int i = 0;
    int ans = n;
    while(i < n/2 && found(i, 2*a[i], seen))
        --ans, ++i;
    cout << ans;
}

void solve2(){
    int res = n , mid = n/2;
    for(int i = 0; i < n/2 && mid < n; i++ )
        while(mid < n)
            if(2*a[i] <= a[mid]){
                res--;
                mid++;
                break;
            }
            else mid++;
    cout<< res << '\n';
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