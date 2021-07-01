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
int test, n, x;
string X;
string str;
/*Function*/
void init(){
    cin >> n >> x;
}
void solve(){
    list <int> a;
    int tmp;
    Fu(i, 0, n, 1){
        cin >> tmp;
        a.pb(tmp);
    }
    a.remove(x);
    cout << a.size() << endl;
    list <int> :: iterator it;
    for(it = a.begin(); it!= a.end(); ++it)
        cout << *it << ' ';
}
void init2(){
    // cin >> X;
    // cin.ignore();
    getline(cin, str);
    cin >> X;
}
void solve2(){
    string tmp = "";
    Fu(i, 0, str.size(), 1){
        while(i<str.size() && str[i] == ' ')    ++i;
        while(i<str.size() && str[i] != ' ')    tmp += str[i++];
        if(tmp != X) cout << tmp << ' ';
        tmp = "";
    }
}
/*Main program*/
int main(){
    IOS()
    // cin >> test;
    // while(test--){
        init2();
        solve2();
        // cout << endl;
    // }
    return 0;
}

/*Source: From HlighT*/