/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL)
/*Compact*/
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
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
int n;
string bin1, bin2;
/*Function*/
void init(){
    cin >> bin1 >> bin2;
}
int MakeEqualLength(string &a, string &b){
    if(sz(a) > sz(b)) swap(a, b);
    string head(sz(b)-sz(a), '0');
    a = head + a;
    return sz(a);
}
string addbin(string a, string b){
    bool carry = false;
    string res = "";
    char tmp;
    int len = MakeEqualLength(a, b);
    Fd(i, len-1, 0, 1){
        bool x = a[i] - '0';
        bool y = b[i] - '0';
        tmp = (x ^ y ^ carry) + '0';
        res = tmp + res;
        carry = (x & y) | (x & carry) | (y & carry);
    }
    if(carry)   res = '1' + res;
    return res;
}
ll mulKaratsuba(string X, string Y){
    int len = MakeEqualLength(X, Y);
    if(len == 0)    return 0;
    if(len == 1)    return (X[0] - '0')&(Y[0] - '0');
    int head = len/2;
    int tail = len - head;
    string a = X.substr(0, head);
    string b = X.substr(head, tail);
    string c = Y.substr(0, head);
    string d = Y.substr(head, tail);
    ll U = mulKaratsuba(a, c);
    ll V = mulKaratsuba(b, d);
    ll W = mulKaratsuba(addbin(a, b), addbin(c, d));
    return U*(1LL<<(2*tail)) + (W - U - V)*(1LL<<tail) + V;
}
ll Convert(string s){
    ll sum = 0 ;
    for(int i = 0 ; i < s.length() ; i++){
        sum *= 2;
        sum += (s[i] == '1');
    }
    return sum;
}
void solve(){
    srand(time(NULL));
    bool useKaratsuba = rand()&1;
    if(useKaratsuba)    cout << mulKaratsuba(bin1, bin2);
    else                cout << Convert(bin1) * Convert(bin2);
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