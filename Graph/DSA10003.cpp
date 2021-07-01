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
typedef pair <int, int> pii;
/*Initialize*/
int test, n, V, E;
int parent[1005];

/*Function*/
int Find(int a){
    if(a == parent[a])  return a;
    parent[a] = Find(parent[a]);
    return parent[a];
}
bool Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b)  return true;
    if(a < b)   parent[b] = a;
    else        parent[a] = b;
    return false;
}
void solve(){
    cin >> V >> E;
    vector <pii> edges;
    int x, y;
    string res = "NO";
    Fu(i, 0, E, 1){
        cin >> x >> y;
        edges.pb(mp(x, y));
    }
    Fu(i, 1, V+1, 1)    parent[i] = i;
    Fu(i, 0, E, 1){
        x = edges[i].fi;
        y = edges[i].se;
        if(Union(x, y)){
            res = "YES";
            break;
        }
    }
    cout << res;
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