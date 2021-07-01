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
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n, k, start;
int a[20];
vector <int> res;
bool done;

/*Function*/
void init(){
    cin >> n >> k;
    cinArr(a, n);
    sort(a, a+n);
    res.clear();
    start = 0;
    done = false;
}
 
void Display(){
    cout << '[';
    coutArr(res, res.size() - 1);
    cout << res[res.size() - 1] << "] ";
}

void Try(int sum) {
    Fu(i, start, n, 1){
        if(sum + a[i] <= k){
            res.pb(a[i]);
            start = i+1;
            if(sum + a[i] == k){
                Display();
                done = true;
            }
            else    Try(sum + a[i]);
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
        Try(0);
        if(!done)    cout << -1;
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/