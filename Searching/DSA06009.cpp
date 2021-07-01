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
int test, n, k;

/*Function*/
void init(){
    cin >> n >> k;
}
void solve(){
    int tmp, res = 0;
    map <int, int> nb;
    Fu(i, 0, n, 1){
        cin >> tmp;
        ++nb[tmp];
    }
    for(map <int, int>::iterator i=nb.begin(); i->fi <= k/2 && i!=nb.end(); ++i){
        tmp = i->fi;
        int tmp2 = i->se;
        if(tmp == k-tmp) res += tmp2*(tmp2-1)/2;
        else if(nb[k-tmp] > 0)   res += tmp2*nb[k-tmp];
    }
    cout << res;
}
void solve2(){
    ll res = 0 ;
    vector <int> a(n);
    cinArr(a, n);
    sort(all(a));
    Fu(i, 0, n, 1){
        int l = lower_bound(a.begin()+ i + 1,a.end(), k-a[i]) - a.begin();
        int r = upper_bound(a.begin()+ l,a.end(), k-a[i]) - a.begin();
        res += 1LL*(r - l);
    }
    cout << res << endl;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve2();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/