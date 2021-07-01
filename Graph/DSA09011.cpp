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
int test, n, N, M;
pair <int, int> direct[9];

/*Function*/
void init(){
    cin >> N >> M;
}
bool isValid(int x, int y){
    return x >= 0 && y >=0 && x < N && y < M; 
}

void BFS(bool Map[][500], bool visited[][500], int x, int y){
    queue < pair <int, int> > q;
    visited[x][y] = true;
    q.push(mp(x, y));
    while(!q.empty()){
        int X = q.front().fi;
        int Y = q.front().se;
        q.pop();
        Fu(i, 0, 9, 1){
            x = direct[i].fi;
            y = direct[i].se;
            if(isValid(X + x, Y + y) 
                && Map[X + x][Y + y] 
                && !visited[X + x][Y + y]){
                visited[X + x][Y + y] = true;
                q.push(mp(X + x, Y + y));
            }
        }
    }
}
void solve(){
    bool Map[N][500];
    bool visited[N][500];
    int res = 0;
    Fu(i, 0, N, 1)
        Fu(j, 0, M, 1)
            cin >> Map[i][j];
    Re0(visited);
    Fu(i, 0, N, 1)
        Fu(j, 0, M, 1)
            if(Map[i][j] && !visited[i][j]){
                BFS(Map, visited, i, j);
                ++res;
            }
    cout << res;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    Fu(x, -1, 2, 1)
        Fu(y, -1, 2, 1)
            direct[3*x + y + 4] = mp(x, y);
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/