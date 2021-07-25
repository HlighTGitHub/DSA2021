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
vector <int> edge[1005];
/*Function*/
void init();
int BFS_Coloring();
void solve();
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

void init(){
    cin >> V >> E;
    Fu(i, 0, 1005, 1) edge[i].clear();
    int x, y;
    Fu(i, 0, E, 1){
        cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

int BFS_Coloring(){
    int color[V+1] = {0};
    bool seen[V+1] = {0};
    Fu(i, 1, V+1, 1) color[i]=1;
    Fu(i, 1, V+1, 1) sort(all(edge[i]));
    Fu(start, 1, V+1, 1){
        if(seen[start]) continue;
        queue <int> q;
        q.push(start);
        seen[start] = true;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            Fu(i, 0, sz(edge[v]), 1){
                int w = edge[v][i];
                if(color[w] == color[v])
                    ++color[w];
                if(!seen[w]){
                    seen[w] = true;
                    q.push(w);
                }
            }
        }
    }
    return *max_element(color+1, color+V+1);
}

void solve(){
    cout << (BFS_Coloring() == 2?"YES":"NO");
}