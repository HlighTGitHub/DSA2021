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
int V, E, s, t;

/*Function*/
void init(){
    cin >> V >> E >> s >> t;
}
void BFS(vector <int> edge[], int u, int parent[]){
    queue <int> q;
    q.push(u);
    parent[u] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        Fu(i, 0, edge[v].size(), 1){
            int tmp = edge[v][i];
            if(!parent[tmp]){
                q.push(tmp);
                parent[tmp] = v;
            }
        }
    }
}
void solve(){
    int x, y;
    vector <int> edge[V+1];
    int parent[V+1] = {0};
    Fu(i, 0, E, 1){
        cin >> x >> y;
        edge[x].pb(y);
    }
    BFS(edge, s, parent);
    if(parent[t]){
        vector <int> res;
        while(t > 0){
            res.pb(t);
            t = parent[t];
        }
        Fd(i, res.size()-1, 0, 1)
            cout << res[i] << ' ';
    }
    else cout << -1;
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