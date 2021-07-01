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
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i];
#define Re0(Object) memset(Object, 0, sizeof(Object))
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;
bool a[20];
vector <int> res;
/*Function*/
void init(){
    cin >> n;
    Re0(a);
    res.clear();
}
bool check(int i, int j){
    if(res.empty())  return true;
    if(abs(res[i-1] - j) == 1)
        return false;
    return true;
}
void solve(int i){
    Fu(j, 1, n+1, 1){
        if(!a[j] && check(i, j)){
            a[j] = true;
            res.pb(j);
            if(i == n-1){
                coutArr(res, n);
                cout << endl;
            }
            else solve(i+1);
            a[j] = false;
            res.pob();
        }
    }
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve(0);
    }
    return 0;
}

/*Source: From HlighT*/