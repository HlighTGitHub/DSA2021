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
int test, n;
#define pi pair<int, int>
/*Function*/
void init(){
    cin >> n;
}
bool cmp(pi a, pi b){
    if(a.se == b.se)    return a.fi > b.fi;
    return a.se > b.se;
}
void solve(){
    map < int, vector <int> > jobs;
    int deadline, profit;
    Fu(i, 0, n, 1){
        cin >> profit >> deadline >> profit;
        jobs[deadline].pb(profit);
    }
    int canDo = 0, res = 0;
    int time = 0;
    for(map < int, vector <int> > :: iterator it = jobs.begin(); it != jobs.end(); ++it)
        if(!jobs[it -> fi].empty()){
            sort(all(jobs[it -> fi]));
            canDo++;
        }
    Fu(i, 0, jobs.size(), 1){
        cout << jobs[i].fi << ' ' << jobs[i].se << endl;
        if(jobs[i].fi > time){
            ++canDo;
            res += jobs[i].se;
            ++time;
        }
    }
    cout << canDo << ' ' << res;
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