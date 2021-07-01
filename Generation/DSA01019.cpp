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
bool a[20];
bool H_ed;
/*Function*/
void init(){
    cin >> n;
    Re0(a);
    a[0] = true;
    H_ed = true;
}
void Display(){
    Fu(i, 0, n, 1)
        cout << (a[i]?'H':'A');
    cout << endl;
}
void Try(int i){
    bool tmp = H_ed;
    Fu(j, 0, (H_ed?1:2), 1){
        a[i] = j;
        H_ed = (j?1:0);
        if(i == n-2)
            Display();
        else Try(i+1);
        H_ed = tmp; 
    }
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        if(n == 2)  cout << "HA\n";
        else    Try(1);
    }
    return 0;
}

/*Source: From HlighT*/