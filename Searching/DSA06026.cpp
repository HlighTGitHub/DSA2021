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
#define Fu(I,L,R,Jump)	for(int I=L; I<R; I+=Jump)
#define Fd(I,R,L,Jump)	for(int I=R; I>=L; I-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
#define Re0(Object) memset(Object, 0, sizeof(Object))
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
/*Declare*/
using namespace std;
typedef long long int ll;
typedef double db;

/*Initialize*/
int test, n;
int a[100];
/*Function*/
void init(){
    cin >> n;
    cinArr(a, n)
}
void solve(){
    int step = 1;
    Fd(i, n-1, 1, 1){
        bool did = false;
        Fu(j, 0, i, 1)
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                did = true;
            }
        if(did){
            printf("Buoc %d: ", step++);
            coutArr(a, n);
            cout << endl;
        }
    }
}

/*Main program*/
int main(){
    init();
    solve();
    return 0;
}

/*Source: From H.LighT*/