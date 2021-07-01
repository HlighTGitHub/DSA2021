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
int test, n, choice;
#define qi queue<int>
/*Function*/
void init(){
    cin >> n;
}
void Key1(qi q){
    cout << q.size() << endl;
}
void Key2(qi q){
    cout << (q.empty()?"YES":"NO") << endl;
}
void Key3(qi *q){
    int tmp;
    cin >> tmp;
    q->push(tmp);
}
void Key4(qi *q){
    if(!q->empty())
        q->pop();
}
void Key5(qi q){
    cout << (q.empty()?(-1):q.front()) << endl;
}
void Key6(qi q){
    cout << (q.empty()?(-1):q.back()) << endl;
}
void solve(){
    qi q;
    while(n--){
    	cin >> choice;
    	switch (choice){
	        case 1: Key1(q); break;
	        case 2: Key2(q); break;
	        case 3: Key3(&q); break;
	        case 4: Key4(&q); break;
	        case 5: Key5(q); break;
	        case 6: Key6(q); break;
    	}
    }
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve();
    }
    return 0;
}

/*Source: From HlighT*/