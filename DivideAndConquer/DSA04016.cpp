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
int test, m, n, K;

/*Function*/
void init(){
    cin >> m >> n >> K;
}
int KthElement(int a[], int m, int b[], int n, int k){
    if(m == 0)  return a[k-1];
    if(n == 0)  return b[k-1];
    if(k == 1)  return min(a[0], b[0]);
    int tmp = k/2;
    int i = min(m, tmp);
    int j = min(n, tmp);
    if(a[i-1] > b[j-1])
        return KthElement(a, m, b+j, n-j, k-j);
    return KthElement(a+i, m-i, b, n, k-i);
}
void solve(){
    int a[m];
    int b[n];
    cinArr(a, m);
    cinArr(b, n);
    cout << KthElement(a, m, b, n, K);
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