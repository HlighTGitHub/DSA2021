/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL)
/*Compact*/
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(Object) Object.size()
#define all(Object) Object.begin(), Object.end()
#define Re0(Object) memset(Object, 0, sizeof(Object))
#define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
#define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
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

/*Initialize*/
bool MultiTest = true;
int test = 1;
string a;

/*Function*/
void init(){
    cin >> a;
    a = '(' + a + ')';
}
void solve(){
    bool change = false;
    stack <bool> sign;
    sign.push(true);
    Fu(i, 1, sz(a)-1, 1){
        if(a[i] == '('){
            if(a[i-1] == '-'){
                change = !change;
                sign.push(false);
            }
            else sign.push(true);
        }
        else if(a[i] == ')'){
            if(!sign.top())
                change = !change;
            sign.pop();
        }
        else{
            if((a[i] != '+' && a[i] != '-') || !change)
                cout << a[i];
            else{
                if(a[i] == '+') cout << '-';
                else cout <<'+';
            }
            
        }
    }
}
void solve2(){
    stack <int> s;
    Fu(i, 1, sz(a)-1, 1)
        if(a[i] == '(')
            s.push(i);
        else if(a[i] == ')'){
            int pos = s.top();
            s.pop();
            if(a[pos-1] == '-')
                Fu(j, pos+1, i, 1){
                    if(a[j] == '+') a[j] = '-';
                    else if(a[j] == '-') a[j] = '+';
                }
        }
    Fu(i, 1, sz(a), 1)
        if(a[i] != '(' && a[i] != ')')
            cout << a[i];
}
/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}