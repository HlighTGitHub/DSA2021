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
bool MultiTest = true;
int test = 1;
int n, k;
int a[ArrLim];
/*Function*/
void init(){
    cin >> n >> k;
}

void solve(){
    int res = 0;
    cinArr(a, n);
    sort(a, a+n);
    Fu(i, 1, n, 1){
        int x = upper_bound(a, a+i, a[i] - k) - a;
        res += i-x;
    }
    cout << res;
}

/*Main program*/
int main(){
    IOS()
    if(MultiTest)	cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
 		cin>>n>>k;
 		int a[n+5];
// 		int check[100005] = {0};
 		for(int i = 0 ;i <n;i++){
 			cin>>a[i];
		}
		long long int dem=0;
		sort(a,a+n);
		for(int i=0;i<n-1;i++){
			int m=a[i]+k;
			int m2=lower_bound(a,a+n,m)-a;
			int dem0=m2-i-1;
			if(dem0>0) dem=dem+dem0;
		}
		cout<<dem<<endl;
	}
	return 0;
}
