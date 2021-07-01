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
string a;

/*Function*/
void init(){
    cin >> a;
}
int CtI(char x){
    return x - '0';
}
int Cal(int a, char op, int b){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        default : return a%b;
    }
}
void solve1(){ //don't know where is wrong...
    stack <int> n;
    stack <char> op;
    Fu(i, 0, a.size(), 1)
        if(isdigit(a[i])){
            n.push(CtI(a[i]));
            if(isdigit(a[i-1])){
                n.pop();
                int tmp = Cal(n.top(), op.top(), CtI(a[i]));
                n.pop();
                op.pop();
                if(!n.empty()){
                    tmp = Cal(n.top(), op.top(), tmp);
                    n.pop();
                    op.pop();
                }
                n.push(tmp);
            }
        }
        else op.push(a[i]);
    cout << n.top();
}
int Pob(stack <int> *n){
    int tmp = n->top();
    n->pop();
    return tmp;
}
void solve2(){
    stack <int> n;
    Fd(i, a.size()-1, 0, 1)
        if(isdigit(a[i]))
            n.push(CtI(a[i]));
        else{
            int tmp = Pob(&n);
            n.push(Cal(tmp, a[i], Pob(&n)));
        }
    cout << n.top();
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve2();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/