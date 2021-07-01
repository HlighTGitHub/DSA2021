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
int test, n, res;
vector <int> tmp;

/*Function*/
void init(){
    cin >> n;
    res = 0;
    tmp.clear();
}
bool isDead(int x, int y){
    Fu(i, 0, tmp.size(), 1){
        if(tmp[i] == y) return true;
        if(x - y == i - tmp[i]) return true;
        if(x + y == i + tmp[i]) return true;
    }
    return false;
}
void Try(int x){
    Fu(y, 0, n, 1){
        if(!isDead(x, y)){
            tmp.pb(y);
            if(x == n-1)    ++res;
            else    Try(x+1);
            tmp.pob();   
        }
    }
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        Try(0);
        cout << res;
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/