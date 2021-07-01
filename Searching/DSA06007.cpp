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

/*Function*/
void init(){
    cin >> n;
}
void solve(){
    int a[n], b[n], l = 0, r = n-1;
    cinArr(a, n);
    Fu(i, 0, n, 1)  b[i] = a[i];
    sort(b, b+n);
    while(a[l] == b[l]) ++l;
    while(a[r] == b[r]) --r;
    // int l = 0, r, Max = a[0], Min = a[0];
    // bool Found = false;
    // Fu(i, 1, n, 1){
    //     if(a[i] >= Max)
    //         Max = a[i];
    //     else{
    //         if(Found){
    //             if(a[i] < Min){
    //                 Min = a[i];
    //                 //swap(a[i], a[l]);
    //             }
    //         }
    //         else Min = a[i];
    //         Found = true;
    //         while(a[l] <= Min) ++l;
    //         r = i;
    //     }
    // }
    cout << l+1 << ' ' << r+1;
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