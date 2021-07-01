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
string str;
bool a[50][50];
/*Function*/
void Analyze(int row){
    int tmp = 0;
    Fu(i, 0, str.size(), 1){
        while(str[i] == ' '){
            ++i;
            a[row][tmp-1] = true;
            tmp = 0;
        }
        if(i<str.size()) tmp = tmp*10 + (str[i] - '0');
    }
}
void init(){
    cin >> n;
    cin.ignore();
    Fu(i, 0, n, 1){
        getline(cin, str);
        str = str + " ";
        Analyze(i);
    }
}
void solve(){
    Fu(i, 0, n, 1)
        Fu(j, i, n, 1)
            if(a[i][j]) cout << i+1 << ' ' << j+1 << endl;
}

/*Main program*/
int main(){
    IOS()
        init();
        solve();
    return 0;
}

/*Source: From HlighT*/