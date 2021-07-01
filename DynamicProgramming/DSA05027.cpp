/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*Compact*/
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define all(a)	a.begin(), a.end()
#define Fu(i,a,b,jump)	for(int i=a; i<b; i+=jump)
#define Fd(i,a,b,jump)	for(int i=a; i>b; i-=jump)
#define cinArr(a, n)	for(int i=0; i<n; ++i){ll tmp; cin >> tmp; a[i] = tmp;}
#define coutArr(a, n)	for(int i=0; i<n; ++i)	cout << a[i] << ' ';
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> II;
struct item{
	int W;
	int V;
};

/*Initialize*/
int n, M;
item a[1001];

/*Function*/
//Branch and Bound Method:
int Fopt, Wnow, Vnow;
double score(item x){
	return (db)x.V/x.W;
}
bool cmp(item x, item y){
	db X = score(x);
	db Y = score(y);
	if(X == Y)	return x.V > y.V;
	return X > Y;
}
void init(){
	Fopt = in;
	Wnow = 0;	Vnow = 0;
	cin >> n >> M;
	Fu(i, 0, n, 1)	cin >> a[i].W;
    Fu(i, 0, n, 1)  cin >> a[i].V;
	sort(a, a+n, cmp);
}
void BaB(int i){
	int X = ((M - Wnow) < a[i].W)?0:1;
	Fd(j, X, -1, 1){
		Wnow += j*a[i].W;
		Vnow += j*a[i].V;
		if(i < n-1){
			db UB = (db)Vnow + (db)(M - Wnow)*score(a[i+1]);	//Upper Bound.
			if(UB >= Fopt) BaB(i+1);
		}
		else if(Vnow > Fopt)	Fopt = Vnow;
		Wnow -= a[i].W*j;
		Vnow -= a[i].V*j;
	}
}
//Dynamic programming Method:
int F[1001][1001];
void init2(){
	cin >> n >> M;
	Fu(i, 1, n+1, 1)	cin >> a[i].W;
    Fu(i, 1, n+1, 1)    cin >> a[i].V;
}
int DP(){
	Fu(i, 1, n+1, 1)
		Fu(j, 1, M+1, 1)
			if(a[i].W <= j)	
				F[i][j] = max(F[i-1][j], F[i-1][j-a[i].W] + a[i].V);
			else F[i][j] = F[i-1][j];
	return F[n][M];
}
/*Main program*/ 
int main(){
    IOS();
    int test;
    cin >> test;
    while(test--){
        init();
		BaB(0);
        cout << Fopt << endl;
    }
    return 0;
}

/*Source: From H.LighT*/
