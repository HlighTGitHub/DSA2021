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
#define oo INT_MAX
const int ArrLim = 1e6+5;
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;

/*Initialize*/
bool MultiTest = false;
int test = 1;
int n, k;
char a[20];
char c[20];
vector <string> res;
/*Function*/
void init(){
    cin >> n >> k;
    memset(a, 'A', sizeof(a));
    res.clear();
}
bool Gen(){
    int i = n-1;
    while(a[i] == 'B') --i;
    if(i<0) return false;
    else{
        a[i] = 'B';
        Fu(j, i+1, n, 1)  a[j] = 'A';
    }
    return true;
}
void check(){
    int str = 0;
    string cmp(c, c+k);
    Fu(i, 0, n-k+1, 1)
        if(*(new string(a+i, a+i+k)) == cmp)
            ++str;
    if(str == 1)
        res.pb(*(new string(a, a+n)));
}
void solve(){
    check();
    while(Gen())
        check();
    cout << res.size() << endl;
    Fu(i, 0, res.size(), 1)
        cout << res[i] << endl;
}

/*Main program*/
int main(){
    IOS()
    if(MultiTest)	cin >> test;
    memset(c, 'A', sizeof(c));
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

// #include<bits/stdc++.h>
// #define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// using namespace std;
// typedef long long i64;
// string a;
// int n,k;
// vector < string > res;
// void input(){
//     cin >> n >> k; a.resize(n);
// }

// void check(){
//     int ok = 0;
//     for(int i = 0 ; i < n - k + 1 ; i++){ // tach thanh cac xau co do dai la k, i : 1 -> 3
//         int cnt = 0;
//         for(int j = i; j < i + k; j++){ //
//             if( a[j] == 'A') cnt++;
//         }
//         if( cnt == k ) ok++;
//     }
//     if (ok == 1) res.push_back(a);
// }
// void Try(int i){
//     for(char j = 'A' ; j <= 'B' ; j++){
//         a[i] = j;
//         if ( i == n - 1 ) check();
//         else Try(i+1);
//     }
// }
// void solve(){
//     Try(0);
//     cout << res.size() << endl;
//     for(int i = 0 ; i < res.size() ; i++){
//         cout << res[i] << endl;
//     }
// }
// int main(){
//     //freopen("input.txt","r",stdin);
//     //freopen("output.txt","w",stdout);
//     faster();
//     int t=1;// cin>>t;
//     while(t--){ input();solve();}
//     cerr << "\nRunning is : " << 1.0*clock()/1000 ;
//     return 0;
// }