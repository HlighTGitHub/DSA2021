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
string a;

/*Function*/
void init(){
    getline(cin, a);
}
bool isOpt(char x){
    char check[] = {'+', '-', '*', '/'};
    Fu(j, 0, 4, 1)
        if(x == check[j])
            return true;
    return false;
}
void solve(){
    stack <char> s;
    bool valid = false;
    Fu(i, 0, a.size(), 1){
        if(a[i] == ')'){
            while(s.top() != '('){
                if(isOpt(s.top())) valid = true;
                s.pop();
            }
            if(!valid){
                cout << "Yes";
                return;
            }
            valid = false;
            s.pop();
        }
        else s.push(a[i]);
    }
    while (!s.empty()){
        if(s.top() == '('){
            valid = true;
            break;
        }
        s.pop();
    }
    cout << (!valid?"No":"Yes");
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    cin.ignore();
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/