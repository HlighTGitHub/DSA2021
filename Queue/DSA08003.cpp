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
int test, n;
deque <string> res;
string choice;
/*Function*/
void Key1(){
    string tmp;
    cin >> tmp;
    res.push_front(tmp);
}
void Key2(){
    cout << (res.empty()?"NONE":res.front()) << endl;
}
void Key3(){
    if(!res.empty())
        res.pop_front();
}
void Key4(){
    string tmp;
    cin >> tmp;
    res.push_back(tmp);
}
void Key5(){
    cout << (res.empty()?"NONE":res.back()) << endl;
}
void Key6(){
    if(!res.empty())
        res.pop_back();
}
void solve(){
    cin >> choice;
    if(choice == "PUSHFRONT")       Key1();
    else if(choice == "PRINTFRONT") Key2();
    else if(choice == "POPFRONT")   Key3();
    else if(choice == "PUSHBACK")   Key4();
    else if(choice == "PRINTBACK")  Key5();
    else if(choice == "POPBACK")    Key6();
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}

/*Source: From HlighT*/