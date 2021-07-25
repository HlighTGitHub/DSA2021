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
int n;

/*Function*/
void init(){
    cin >> n;
}

void solve(){
    queue <int> q;
    map <int, int> seen;
    q.push(n);
    seen[n] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == 1){
            cout << seen[1] - 1;
            return;
        }
        if(!seen[cur-1]){
            q.push(cur-1);
            seen[cur-1] = seen[cur] + 1;
        }
        int lim = sqrt(cur);
        Fu(i, 2, lim+1, 1)
            if(cur%i == 0)
                if(!seen[cur/i]){
                    q.push(cur/i);
                    seen[cur/i] = seen[cur] + 1;
                }
    }
}
void solve2(){
    queue <pii> q;
    set <int> seen;
    q.push(mp(n, 0));
    seen.insert(n);
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        if(cur.fi == 1){
            cout << cur.se;
            return;
        }
        if(seen.find(cur.fi-1) == seen.end()){
            q.push(mp(cur.fi-1, cur.se+1));
            seen.insert(cur.fi-1);
        }
        int lim = sqrt(cur.fi);
        Fu(i, 2, lim+1, 1)
            if(cur.fi%i == 0)
                if(seen.find(cur.fi/i) == seen.end()){
                    q.push(mp(cur.fi/i, cur.se+1));
                    seen.insert(cur.fi/i);
                }
    }
}
/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    while(test--){
        init();
        solve2();
        cout << endl;
    }
    return 0;
}