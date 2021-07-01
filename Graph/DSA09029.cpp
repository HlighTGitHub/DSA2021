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
int test;
int V, E;
bool U[1005];
class Graph{
    public:
        vector <int> a[1005];
        void addEdge(int x, int y);
        bool DFS(int visited, int v);
};
void Graph::addEdge(int x, int y){
    a[x].pb(y);
    a[y].pb(x);
}
bool Graph::DFS(int visited, int v){
    if(visited == V)
        return true;
    U[v] = true;
    Fu(i, 0, a[v].size(), 1)
        if(!U[a[v][i]] && DFS(visited + 1, a[v][i]))
            return true;
    U[v] = false;
    return false;
}
/*Function*/

void init(){
    cin >> V >> E;
}
void solve(){
    int x, y;
    Graph g;
    Fu(i, 0, E, 1){
        cin >> x >> y;
        g.addEdge(x, y);
    }
    bool haveHamilton = false;
    Fu(i, 1, V+1, 1){
        Re0(U);
        if(g.DFS(1, i)){
            haveHamilton = true;
            break;
        }
    }
    cout << (haveHamilton?1:0);
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