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
int test;
string a, b;
int F[1000][1000];

/*Function*/
void init(){
    cin >> a >> b;
    Fu(i, 0, a.size(), 1)
        F[i][0] = 0;
    Fu(i, 0, b.size(), 1)
        F[0][i] = 0;
}
void dp(){
    Fu(i, 0, a.size(), 1)
        Fu(j, 0, b.size(), 1)
            if(a[i] != b[j])
                F[i+1][j+1] = max(F[i+1][j], F[i][j+1]);
            else
                F[i+1][j+1] = F[i][j] + 1;
    cout << F[a.size()][b.size()];
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        dp();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/