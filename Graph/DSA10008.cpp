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
int test, n, V, E, u;
typedef pair <int, int> pii;

/*Function*/
void init(){
    cin >> V >> E >> u;
}
void Dijkstra(vector <pii> *a){
    priority_queue < pii, vector <pii>, greater <pii> > q;
    int d[V+1];
    Fu(i, 1, V+1, 1)    d[i] = im;
    d[u] = 0;
    q.push(mp(u, 0));
    while(!q.empty()){
        int x = q.top().fi;
        int dx = q.top().se;
        q.pop();
        if(d[x] == dx){
            Fu(i, 0, a[x].size(), 1){
                int y = a[x][i].fi;
                int ey = a[x][i].se;
                if(d[y] > dx + ey){
                    d[y] = dx + ey;
                    q.push(mp(y, d[y]));
                }
            }
        }
    }
    Fu(i, 1, V+1, 1)    cout << d[i] << ' ';
}
void solve(){
    vector <pii> a[V+1];
    int x, y, z;
    Fu(i, 0, E, 1){
        cin >> x >> y >> z;
        a[x].pb(mp(y, z));
        a[y].pb(mp(x, z));
    }
    Dijkstra(a);
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