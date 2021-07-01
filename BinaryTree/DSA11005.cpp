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
#define lim 100005
#define oo INT_MAX
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;

/*Function*/

void Postorder(int in[], int lv[], int l, int r, int dad, map <int, int> m, bool visited[]){
    if(l > r)   return;
    int DivI = m[lv[dad]];
    visited[dad] = true;
    int tmp = dad;
    while(tmp < n && (visited[tmp] || m[lv[tmp]] > DivI)) ++tmp;
    if(tmp != dad)  Postorder(in, lv, l, DivI - 1, tmp, m, visited);
    tmp = dad;
    while(tmp < n && (visited[tmp] || m[lv[tmp]] < DivI)) ++tmp;
    if(tmp != dad)  Postorder(in, lv, DivI+1, r, tmp, m, visited);
    cout << in[DivI] << ' ';
}
void solve(){
    cin >> n;
    int in[n];
    int lv[n];
    map <int, int> m;
    Fu(i, 0, n, 1){
        cin >> in[i];
        m[in[i]] = i;
    }
    cinArr(lv, n);
    int dad = 0;
    bool visited[n] = {0};
    Postorder(in, lv, 0, n-1, dad, m, visited);
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/