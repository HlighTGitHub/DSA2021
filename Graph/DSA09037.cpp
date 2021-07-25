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
bool MultiTest = false;
int test = 1;
int K, N, M;

/*Function*/
void init(){
    cin >> K >> N >> M;
}
void BFS(vector <int> edge[], int u, vector <bool> &res){
    bool seen[N+1] = {0};
    queue <int> q;
    q.push(u);
    seen[u] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        Fu(i, 0, sz(edge[v]), 1){
            int w = edge[v][i];
            if(!seen[w]){
                seen[w] = true;
                q.push(w);
            }
        }
    }
    Fu(i, 1, N+1, 1)
        res[i] = res[i] & seen[i];
}
void solve(){
    int pos[K];
    cinArr(pos, K);
    vector <int> edge[N+1];
    vector <bool> res(N+1, 1);
    int ans = 0;
    int x, y;
    Fu(i, 0, M, 1){
        cin >> x >> y;
        edge[x].pb(y);
    }
    Fu(i, 0, K, 1)
        BFS(edge, pos[i], res);
    Fu(i, 1, N+1, 1)
        if(res[i])  ++ans;
    cout << ans;
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