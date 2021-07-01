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
int test, k;
string a;
/*Function*/
void init(){
    cin >> k;
    cin >> a;
}
void solve(){
    int n = a.size();
    bool isMax[n];
    Re0(isMax);
    Fu(i, 0, n, 1){
        int iMax = 0;
        while(iMax < n && isMax[iMax]) ++iMax;
        int jMin = iMax;
        int Count = 0;
        Fu(j, iMax, n, 1)
            if(!isMax[j]){
                if(a[j] > a[iMax]){ 
                    iMax = j;
                    Count = 1;
                }
                else if(a[j] == a[iMax] && Count > 0){
                    ++Count;
                    iMax = j;
                }
            }
        if(Count){
            int j = jMin;
            int tmp = 0;
            while(j < n && tmp < min(Count, k)){
                if(a[j] < a[jMin])
                    jMin = j;
                ++j;
                if(a[j] < a[iMax])  ++tmp;
            }
            swap(a[jMin], a[iMax]);
            --k;
        }
        isMax[jMin] = true;
        if(k == 0)  break;
    }
    cout << a << endl;
}

/*Main program*/
int main(){
    cin >> test;
    while(test--){
        init();
        solve();
    }
    return 0;
}

/*Source: From H.LighT*/