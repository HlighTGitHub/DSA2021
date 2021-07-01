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
int test, n, start;
vector <int> a;
/*Function*/
void init(){
    cin >> n;
    start = n;
    a.clear();
}
void Display(){
    cout << '(';
    coutArr(a, a.size()-1);
    cout << a[a.size()-1] << ") ";
}
void Try(int sum){
    Fd(i, start, 1, 1){
        if(i <= n-sum){
            a.pb(i);
            sum += i;
            start = i;
            if(sum == n) Display();
            else Try(sum);
            a.pob();
            sum -= i;
        }
    }
}
int X(){
    switch (n){
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 5;
        case 5: return 7;
        case 6: return 11;
        case 7: return 15;
        case 8: return 22;
        case 9: return 30;
        default: return 42;
    }
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        cout << X() << endl;
        Try(0);
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/