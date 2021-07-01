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
#define cinArr(Array, N)	for(int tmp=0; tmp<N; ++tmp)    cin >> Array[tmp];
#define coutArr(Array, N)	for(int tmp=0; tmp<N; ++tmp)	cout << Array[tmp] << ' ';
#define Re0(Object) memset(Object, 0, sizeof(Object))
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n, k;
int a[20];
vector <int> res;
vector < vector <int> > ans2;
int ans1;

/*Function*/
void init(){
    cin >> n >> k;
    cinArr(a, n);
    sort(a, a+n);
    ans1 = 0;
}

void Display(){
    if(ans1){
        cout << ans1 << ' ';
        Fu(i, 0, ans2.size(), 1){
            cout << '{';
            coutArr(ans2[i], ans2[i].size() - 1);
            cout << ans2[i][ans2[i].size() - 1] << "} ";
        }
        res.clear();
        ans2.clear();
    }
    else cout << -1;
}

void Try(int sum, int start) {
    Fu(i, start, n, 1){
        if(sum + a[i] <= k){
            sum += a[i];
            res.pb(a[i]);
            if(sum == k){
                ans2.pb(res);
                ++ans1;
            }
            else    Try(sum, i);
            sum -= a[i];
            res.pob();
        }
        else break;
    }
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while (test--) {
        init();
        Try(0, 0);
        Display();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/