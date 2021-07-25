/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL); cout.tie(NULL);
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
typedef pair<string, int> psi;
/*Function*/
void findChild(map < string, vector<psi> > tree, vector <psi> &res, psi dad){
    Fu(i, 0, sz(tree[dad.fi]), 1){
        string name = tree[dad.fi][i].fi;
        int age = dad.se - tree[dad.fi][i].se;
        psi per = mp(name, age);
        res.pb(per);
        findChild(tree, res, per);
    }
}
bool cmp(psi a, psi b){
    if(a.se == b.se) return a.fi < b.fi;
    return a.se > b.se;
}
void solve(){
    cin >> n;
    string dad, name;
    int born_when_dad_is;
    map < string, vector<psi> > tree;
    vector <psi> res;
    Fu(i, 0, n, 1){
        cin >> dad >> name >> born_when_dad_is;
        tree[dad].pb(mp(name, born_when_dad_is));
    }
    findChild(tree, res, mp("Ted", 100));
    sort(all(res), cmp);
    Fu(i, 0, sz(res), 1)
        cout << res[i].fi << ' ' << res[i].se << endl;
}

/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    Fu(t, 0, test, 1){
        cout << "DATASET " << t+1 << endl;
        solve();
    }
    return 0;
}