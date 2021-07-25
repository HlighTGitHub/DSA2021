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
string a;

/*Function*/
void init(){
    cin >> a;
}

void solve(){
    stack<int> stk;
    int res = 0;
    stk.push(-1);
    for(int i=0;i<a.length();i++){
        if (a[i] == '(') stk.push(i);
        else{
            stk.pop();
            if (!stk.empty()){
                res = max(res, i - stk.top());
            }
            else stk.push(i);
        }
    }
    cout << res;
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