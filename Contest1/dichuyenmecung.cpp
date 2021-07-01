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
int t, n, kt = 0;
int	a[100][100],test[100][100];
char x[10000];
vector <string> X;
int l1[10],l2[10];

/*Function*/
void init(){
    cin >> n;
    Fu(i, 1, n+1, 1)
        Fu(j, 1, n+1, 1)
            cin >> a[i][j];
    X.clear();
}
void solve(int i, int j, int all) {
    if (i == n && j == n ) {
        kt = 1;
        string tmp = "";
        for (int k = 1; k <= all-1; k++) tmp += x[k];
        X.pb(tmp);
    }
    else {
        int i1,j1;
        for (int r = 1; r <= 4; r++) { 
            i1 = i + l1[r];
            j1 = j + l2[r];
            if (1 <= i1 && i1 <= n && 1 <= j1 && j1 <= n &&  a[i1][j1] == 1 && test[i1][j1] != 1) {
                if (r == 1) x[all] = 'D';
                else if(r == 2) x[all] = 'L';
                else if(r==3) x[all] = 'R';
                else x[all] = 'U';
                test[i1][j1] = 1;
                solve(i1,j1,all+1);
                test[i1][j1] = 0;
            }
        }
    }
}


/*Main program*/
int main(){
    IOS()
    l1[1] = 1; l1[2] = 0; l1[3] = 0; l1[4] = -1;
    l2[1] = 0; l2[2] = -1; l2[3] = 1; l2[4] = 0;
    cin >> t;
    while(t--){
        init();
        if(a[1][1] == 0) cout << -1 << endl;
        else{
            test[1][1] = 1;
            solve(1, 1, 1);
            if(kt == 0) cout << -1 << endl;
            else{
                cout << X.size() << ' ';
                coutArr(X, X.size());
                cout << endl;
            }
            kt = 0;
        }
    }
    return 0;
}

/*Source: From HlighT*/