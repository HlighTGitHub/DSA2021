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
typedef long long int ll;
typedef double db;

/*Initialize*/
int test, n;
int a[20];
int b[20];
bool done1, done2;
/*Function*/
void init(){
    cin >> n;
    done1 = false;
    done2 = false;
    Fu(i, 0, n, 1)  a[i] = i+1;
}
void Display(){
    Fu(i, 0, n, 1)
        cout << (char)(a[i] + 'A' -1);
    Fu(i, 0, n, 1)
        cout << b[i];
    cout << endl;
}
void Try(int index);
void Generate1(){
    int i = n-1;
    while(a[i-1] > a[i])  --i;
    if(i){
        int k = n-1;
        while(a[k] < a[i-1])  --k;
        swap(a[i-1], a[k]);
        int l = i, r = n-1; 
        while(l < r){
            swap(a[l], a[r]);
            ++l;
            --r;
        }
        Try(0);
    }
    else    done1 = true;
    
}
void Try(int index){
    Fu(i, 1, n+1, 1){
        b[index] = i;
        if(index == n-1)    Display();
        else Try(index +1);
    }
}

/*Main program*/
int main(){
    IOS()
    //cin >> test;
    //while(test--){
        init();
        //Display();
        Try(0);
        while(!done1)
            Generate1();
    //     }
    // }
    return 0;
}

/*Source: From HlighT*/