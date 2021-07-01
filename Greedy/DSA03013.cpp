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
// int test, D;
// string a;
// int Char[26];

// /*Function*/
// void init(){
//     cin >> D >> a;
//     Re0(Char);
// }
// bool check(int start, int N, bool index[]){
//     return (!index[start] && start + D*(N-1) < a.size());
// }
// void solve(){
//     int len = a.size();
//     Fu(i, 0, len, 1)
//         Char[a[i] - 'A']++;
//     priority_queue <int> q;
//     bool index[len] = {0};
//     int firstEmpty = 0;
//     Fu(i, 0, 26, 1)
//         if(Char[i])  q.push(Char[i]);
//     while(!q.empty()){
//         if(check(firstEmpty, q.top(), index)){
//             Fu(i, firstEmpty, len, D)
//                 index[i] = true;
//             firstEmpty++;
//             q.pop();
//         }
//         else{
//             cout << -1;
//             return;
//         }
//     }
//     cout << 1;
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

int main(){
	int t;
	cin >> t;
	while (t--){
		string s;
		int d;
		cin >> d >> s;
		
		int a[10005] = {0},dem=0;
		for (int i = 0 ; i < s.size() ; i++){
			a[s[i]]++;
			if (dem < a[s[i]]) dem = a[s[i]];
		}
		if (dem * (d-1) < s.size()) cout <<"1";
		else cout <<"-1";
		cout <<endl;
	}


	return 0;
}