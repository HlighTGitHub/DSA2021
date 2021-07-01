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
int test, N;
ll K, u[100];
/*Function*/
void init(){
    u[0] = 1;
    Fu(i, 1, 51, 1)
        u[i] = 2*u[i-1] + 1;
}
int findNth(int n, ll k){
    if(n == 0)  return 1; 
    if(k == u[n-1])  return n+1;
    if(k < u[n-1])   return findNth(n-1, k);
    return findNth(n-1, k - (ll)u[n-1] - 1);
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    init();
    while(test--){
        cin >> N >> K;
        cout << findNth(N-1, K-1);
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/