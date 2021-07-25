/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS(false) ios::sync_with_stdio(false)
#define tie() cin.tie(NULL)
/*Compact*/
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(Object) Object.size()
#define all(Object) Object.begin(), Object.end()
#define Re0(Object) memset(Object, 0, sizeof(Object))
#define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
#define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
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
int s, t;

/*Function*/
void init(){
    cin >> s >> t;
}
int justQueue(/* will MLE */){
    if(s >= t)  return  t - s;
    queue <pii> q;
    q.push(mp(0, s));
    while(q.front().se != t){
        pii front = q.front();
        q.pop();
        q.push(mp(front.fi+1, front.se-1));
        q.push(mp(front.fi+1, front.se<<1));
    }
    return q.front().fi;
}
int QueueAndDP(){
    if(s >= t)  return  t - s;
    queue <int> q;
    int step[20001] = {0};
    q.push(s);
    while(!step[t]){
        int top = q.front();
        q.pop();
        if(top - 1 > 0 && !step[top - 1]){
            step[top - 1] = step[top] + 1;
            q.push(top - 1);
        }
        if(top << 1 < 20000 && !step[top*2]){
            step[top << 1] = step[top] + 1;
            q.push(top << 1);
        }
    }
    return step[t];
}
int BinaryChop(int S, int T){
    if(S >= T)  return S - T;
    if(T & 1)   return BinaryChop(S, T+1) + 1;
    return BinaryChop(S, T >> 1) + 1;
}
void solve(){
    // cout << justQueue();
    // cout << QueueAndDP();
    cout << BinaryChop(s, t);
}
/*Main program*/
int main(){
    IOS(false);
    tie();
    if(MultiTest)	cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}