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
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n, V, E;
bool U[1005];

/*Function*/
void init(){
    cin >> V >> E;
}
bool DFS(vector <int> *a, int u){
    Re0(U);
    stack <int> s;
    U[u] = true;
    s.push(u);
    while(!s.empty()){
        int v = s.top();
        s.pop();
        Fu(i, 0, a[v].size(), 1)
            if(!U[a[v][i]]){
                U[a[v][i]] = true;
                s.push(v);
                s.push(a[v][i]);
            }
            else if(a[v][i] == u)   return true;
    }
    return false;
}
bool FasterWay(vector <int> *a, int u){
    U[u] = true;
    Fu(i, 0, a[u].size(), 1){
        if(U[a[u][i]]) return true;
        else if(FasterWay(a, a[u][i]))   return true;
    }
    U[u] = false;
    return false;
}
void solve(){
    int x, y;
    string res = "NO";
    vector <int> a[V+5];
    Re0(U);
    Fu(i, 0, E, 1){
        cin >> x >> y;
        a[x].pb(y);
    }
    Fu(i, 1, V+1, 1)
        if(FasterWay(a, i)){
            res = "YES";
            break;
        }
    cout << res;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/