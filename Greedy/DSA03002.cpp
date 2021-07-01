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
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n, m;
int Max, Min;

/*Function*/
void init(){
    cin >> n >> m;
}
void Add(int *a, int i){
    if(*a){
        int tmp = *a%10;
        Min += ((tmp^6)?tmp:5) * pow(10, i);
        Max += ((tmp^5)?tmp:6) * pow(10, i);
        *a /= 10;
    }
}
void solve(){
    int  i = 0;
    while(m || n){
        Add(&m, i);
        Add(&n, i);
        ++i;
    }
    cout << Min << ' ' << Max;
}

/*Main program*/
int main(){
    IOS()
    init();
    solve();
    return 0;
}

/*Source: From HlighT*/