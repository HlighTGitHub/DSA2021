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
#define lim 1000005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n1, n2, n3;
ll a[lim], b[lim], c[lim];
/*Function*/
void init(){
    cin >> n1 >> n2 >> n3;
}
void solve(){
    cinArr(a, n1);
    cinArr(b, n2);
    cinArr(c, n3);
    int x = 0, y = 0, z = 0;
    bool haveAns = false;
    while(x < n1 && y < n2 && z < n3){
        if(a[x] == b[y] && b[y] == c[z]){
            cout << a[x] << " ";
            haveAns = true;
            x++;
            y++;
            z++;
        }
        else if(a[x] < b[y]) x++;
        else if(b[y] < c[z]) y++;
        else z++;
    }
    if(!haveAns)    cout << -1;
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
