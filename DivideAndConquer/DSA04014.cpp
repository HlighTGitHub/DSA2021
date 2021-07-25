/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL)
/*Compact*/
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
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
const int ArrLim = 1e8+5;
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

/*Initialize*/
bool MultiTest = true;
int test = 1;
ll n, res;
ll arr[ArrLim];

/*Function*/
void init(){
    cin >> n;
    cinArr(arr, n);
    res = 0;
}
void merge(ll arr[], int l, int m, int r){
    vector <ll> a(arr+l, arr+m+1);
    vector <ll> b(arr+m+1, arr+r+1);
    int i = 0, j = 0, k = l;
    while(i < sz(a) && j < sz(b)){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            ++i;
        }
        else{
            arr[k] = b[j];
            ++j;
            res += sz(a) - i;
        }
        ++k;
    }
    while(i < sz(a)){
        arr[k] = a[i];
        ++k;
        ++i;
    }
    while(j < sz(b)){
        arr[k] = b[j];
        ++k;
        ++j;
    }
}
void mergeSort(ll arr[], int l, int r){
    if(l >= r)  return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}
void solve(){
    mergeSort(arr, 0, n-1);
    cout << res;
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