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
pii ST, EN;
vector <pii> mov;

/*Function*/
void init(){
    char col;
    int row;
    cin >> col >> row;
    ST = mp(col - 'a', row - 1);
    cin >> col >> row;
    EN = mp(col - 'a', row - 1);
    /*Giải theo ma trận: Tiện hơn trong việc truy cập, nhưng dài hơn.
    Giải theo mảng 1 chiều: Gọn và ngắn hơn, nhưng cần tính toán kỹ vị trí các ô.
    */
}
bool validPos(pii pos){
    if(pos.fi < 0 || pos.fi > 7)  return false;
    if(pos.se < 0 || pos.se > 7)  return false;
    return true;  
}
int BFS(){
    vector < vector <int> > step(8, vector <int> (8, -1));
    queue <pii> q;
    q.push(ST);
    step[ST.fi][ST.se] = 0;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(const auto &i:mov){
            pii pos = mp(cur.fi + i.fi, cur.se + i.se);
            if(validPos(pos) && step[pos.fi][pos.se] == -1){
                if(pos == EN)   return step[cur.fi][cur.se] + 1;
                step[pos.fi][pos.se] = step[cur.fi][cur.se] + 1;
                q.push(pos);
                //cerr << pos.fi << ' ' << pos.se << endl;
            }
        }
    }
    return 0;
}
void solve(){
    cout << BFS();
}

/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    Fu(i, -2, 3, 1)
        if(i)
            Fu(j, -2, 3, 1)
                if(j && abs(i)^abs(j))
                    mov.pb(mp(i, j));
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}