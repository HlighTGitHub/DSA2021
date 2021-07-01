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
#define oo INT_MAX
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;

/*Function*/
void init(){
    cin >> n;
}
int StI(string a){
    int res = 0;
    Fu(i, 0, a.size(), 1)
        res = res*10 + (a[i] - '0');
    return res;
}
int Cal(int a, string op, int b){
    switch (op[0]){
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
}
void solve(){
    string tmp;
    queue <int> q;
    string a[n];
    cinArr(a, n);
    Fd(i, n-1, 0, 1){
        if(a[i] == "+" || a[i] == "-" || a[i] == "*" || a[i] == "/"){
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            q.push(Cal(y, a[i], x));
        }
        else q.push(StI(a[i]));
    }
    cout << q.front();
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