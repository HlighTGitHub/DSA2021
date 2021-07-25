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
int V, E;

/*Function*/
void init(){
    cin >> V >> E;
}
bool DFS(vector <int> edge[], int u){
    bool seen[V+1] = {0};
    int visit = 1;
    stack <int> s;
    int start = (u == 1)?2:1;
    s.push(start);
    seen[start] = true;
    while(!s.empty()){
        int v = s.top();
        s.pop();
        Fu(i, 0, sz(edge[v]), 1)
            if(!seen[edge[v][i]] && edge[v][i] != u){
                s.push(v);
                s.push(edge[v][i]);
                seen[edge[v][i]] = true;
                ++visit;
            }
    }
    if(visit < V-1)   return true;
    return false;
}
void solve(){
    vector <int> edge[V+1];
    int x, y;
    Fu(i, 0, E, 1){
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    Fu(i, 1, V+1, 1)
        if(DFS(edge, i))
            cout << i << ' ';
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