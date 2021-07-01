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
void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r - m;
    vector <int> a;
    vector <int> b;
    Fu(i, 0, n1, 1)
        a.pb(arr[l+i]);
    Fu(i, 0, n2, 1)
        b.pb(arr[m+1+i]);
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            ++i;
        }
        else{
            arr[k] = b[j];
            ++j;
        }
        ++k;
    }
    while(i < n1){
        arr[k] = a[i];
        ++k;++i;
    }
    while(j < n2){
        arr[k] = b[j];
        ++k;++j;
    }
}
void mergeSort(int arr[], int l, int r){
    if(l >= r)  return;
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}
void solve(){
    int c[n];
    cinArr(c, n);
    mergeSort(c, 0, n-1);
    coutArr(c, n);
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