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
#define lim 1000005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;
bool isntP[lim];
vector <int> Prime;
/*Function*/
void init(){
    isntP[0] = true;
    isntP[1] = true;
    Fu(i, 2, 1000, 1)
        if(!isntP[i])
            Fu(j, 2*i, lim - 4, i)
                isntP[j] = true;
}
bool isPrime(int a){
    if(a == 2 || a == 3)    return true;
    if(a < 2 || a%2 == 0 || a%3 == 0)   return false;
    Fu(i, 5, ceil(sqrt(a))+1, 6)
        if(a%i == 0 || a%(i+2) == 0)    return false;
    return true;
}
void solve(){
    Fu(i, 2, sqrt(n)+1, 1)
        if(!isntP[i] && !isntP[n-i]){
            cout << i << ' ' << n-i;
            return;
        }
    cout << -1;
}
void solve2(){
    Fu(i, 2, sqrt(n)+1, 1)
        if(isPrime(i) && isPrime(n-i)){
            cout << i << ' ' << n-i;
            return;
        }
    cout << -1;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    // init();
    while(test--){
        cin >> n;
        solve2();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/