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
int test, x;

/*Function*/

int m[14] = {1200, 2400, 9600, 2400, 9600, 2400, 1200, 9600, 9600, 38400, 9600, 9600, 9600, 38400};
double p[14];
void init(){
    double sum = 0;
    for(int i=0; i<14; i++) sum += m[i];
    for(int i=0; i<14; i++)
        p[i] = m[i] / sum; // tự động ép kiểu vì sum là biến double.
}
double l[14] = {7, 6, 4, 6, 4, 6, 7, 4, 4, 2, 4, 4, 4, 2};
double L(){
    double res = 0;
    for(int i=0; i<14; i++)
        res += p[i] * l[i];
    return res;
}
double H(){
    double res = 0;
    for(int i=0; i<14; i++)
        res -= p[i] * log2(p[i]);
    return res;
}
/*Main program*/
int main(){
    IOS()
    init();
    cout << L() << ' ' << H();
    return 0;
}

/*Source: From HlighT*/