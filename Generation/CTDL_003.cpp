/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS() ios::sync_with_stdio(false);
#define tie() cin.tie(NULL); cout.tie(NULL);
/*Compact*/
#define pb push_back
#define pob pop_back
#define mp make_pair
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
typedef vector <int> vi;
struct item{
    int fi;
    int se;
    int th;
};
/*Initialize*/
bool MultiTest = false;
int test = 1;
int n, M;
item a[105];
int Fopt;
vector <item> Xopt;
/*Function*/
double score(item x){
	return (db)x.fi/x.se;
}
bool cmp(item x, item y){
	db X = score(x);
	db Y = score(y);
	if(X == Y)	return x.fi < y.fi;
	return X > Y;
}
//fi = value, se = weight;
void init(){
	Fopt = -1;
	cin >> n >> M;
	Fu(i, 0, n, 1)	cin >> a[i].fi;
    Fu(i, 0, n, 1)  cin >> a[i].se;
    Fu(i, 0, n, 1)  a[i].th = i;
	sort(a, a+n, cmp);
}

void BaB(int i, int weight, int value, vector <item> tmp){
	int X = ((M - weight) < a[i].se)?0:1;
	Fd(j, X, -1, 1){
        int V = j * a[i].fi;
        int W = j * a[i].se;
        if(j) tmp.pb(a[i]);
		if(i < n-1){
			db UB = (db)(value + V)+ (db)(M - weight - W)*score(a[i+1]);
			if(UB >= Fopt)
                BaB(i+1, weight + W, value + V, tmp);
		}
		else if(value + V > Fopt){
            Fopt = value + V;
            Xopt = tmp;
        }
		if(j)   tmp.pob();
	}
}
bool cmp2(item x, item y){
    return x.th < y.th;
}
void solve(){
    vector <item> tmp;
    BaB(0, 0, 0, tmp);
    cout << Fopt << endl;
    bool check[105] = {0};
    Fu(i, 0, Xopt.size(), 1)    
        check[Xopt[i].th] = true;
    Fu(i, 0, n, 1)
        if(check[i])    cout << "1 ";
        else cout << "0 ";
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