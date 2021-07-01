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
int test, n1, n2, n3;

/*Function*/
void init(){
    cin >> n1 >> n2 >> n3;
}
bool isValid(int i, int j, int k){
    return (i < n1) && (j < n2) && (k < n3);
}
bool isEnd(int i, int j, int k){
    return (i >= n1) || (j >= n2) || (k >= n3);
}
void solve(){
    ll a[n1];
    ll b[n2];
    ll c[n3];
    cinArr(a, n1);
    cinArr(b, n2);
    cinArr(c, n3);
    int i = 0, j = 0, k = 0;
    bool haveAns = false;
    int limit = min(a[n1-1], min(b[n2-1], c[n3-1]));
    while(!isEnd(i, j, k)){
        while(isValid(i, j, k) && a[i] != b[j])
            if(a[i] < b[j]) ++i;
            else            ++j;
        if(isValid(i, j, k)){
            k = lower_bound(c+k, c+n3, a[i]) - c;
            if(a[i] == b[j] && a[i] == c[k]){
                cout << a[i] << ' ';
                ++k;
                haveAns = true;
            }
            if(a[i] > limit || b[j] > limit || (k < n3 && c[k] > limit))
                break;
        }
        ++i;
        ++j;
    }
    if(!haveAns)    cout << "NO";
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