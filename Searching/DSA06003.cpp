// /*Cre: HlighT*/
// #include <bits/stdc++.h>
// #define IOS() ios::sync_with_stdio(false);
// #define tie() cin.tie(NULL); cout.tie(NULL);
// /*Compact*/
// #define pb push_back
// #define pob pop_back
// #define mp make_pair
// #define fi first
// #define se second
// #define all(Object) Object.begin(), Object.end()
// #define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
// #define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
// #define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
// #define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
// #define Re0(Object) memset(Object, 0, sizeof(Object))
// /*Constant*/
// #define Pi atan(1)*4
// #define lim 100005
// #define im INT_MAX
// #define in INT_MIN
// const int Mod = 1e9+7;
// /*Declare*/
// using namespace std;
// typedef long long ll;
// typedef double db;

// /*Initialize*/
// int test, n;
// #define pi pair <int, int>
// /*Function*/
// void init(){
//     cin >> n;
// }
// void solve(){
//     vector <pi> a(n);
//     Fu(i, 0, n, 1){
//         cin >> a[i].fi;
//         a[i].se = i;
//     }
//     sort(all(a));
//     bool visited[n] = {0};
//     int res = 0;
//     Fu(i, 0, n, 1){
//         if(!visited[i] && a[i].se != i){
//             int j = i;
//             int tmp = 0;
//             while(!visited[j]){
//                 visited[j] = true;
//                 j = a[j].se;
//                 ++tmp;
//             }
//             res += tmp - 1;
//         }
//     }
//     cout << res;
// }

// /*Main program*/
// int main(){
//     IOS()
//     cin >> test;
//     while(test--){
//         init();
//         solve();
//         cout << endl;
//     }
//     return 0;
// }

// /*Source: From HlighT*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod = 1e9+7;

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 0; i < n - 1; i++){
		int x = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[x]) x = j;
		}
		if(x != i){
			swap(a[x],a[i]);
			ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	int test = 1;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}