#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ONLY_CPP ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

typedef double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> II;

const ld pi=2*acos(0);
const int im = INT_MAX;
const int in = INT_MIN;
const int limit = 1e5+5;
const ll M = 1e9+7;

int main ()
{
    ONLY_CPP
    int T;
    cin >> T;
    while(T--){
        int hang,cot, tmp;
        cin>>hang>>cot;
        vector<vi > b;
        for(int i = 1; i <= hang; i++){
            vi temp;
            temp.clear();
            for(int j = 1; j <= cot; j++){
                cin>>tmp;
                temp.pb(tmp);
            }
            b.pb(temp);
        }
        int ngay = 0;
        while(true){
            int kt = 0;
            vector<vi > a;
            a.clear();
            a=b;
            for(int i = 0; i <= hang-1; i++){
                for(int j = 0; j <= cot-1; j++){
                    if(b[i][j] == 2){
                        kt = 1;
                        a[i][j] = 0;
                        if(i >= 1){
                            if(a[i-1][j] == 1) a[i-1][j]++;
                        }
                        if(j >= 1){
                            if(a[i][j-1] == 1) a[i][j-1]++;
                        }
                        if(i <= hang-2){
                            if(a[i+1][j] == 1) a[i+1][j]++;
                        }
                        if(j <= cot-2){
                            if(a[i][j+1] == 1) a[i][j+1]++;
                        }
                    }
                }
            }
            b.clear();
            b=a;
            if(!kt){
                ngay--;
                break;
            }
            ngay++;
        }
        int check = 0;
        for(int i = 0; i <= hang-1; i++){
            for(int j = 0; j <= cot-1; j++){
                if(b[i][j] == 1){
                    check = 1;
                    break;
                }
            }
            if(check == 1) break;
        }
        if(check == 1) cout<<-1;
        else cout<<ngay;
        cout << endl;
   }
    return 0;
}

// #include <bits/stdc++.h>

// #define pb push_back
// #define mp make_pair
// #define fi first
// #define se second
// #define ONLY_CPP ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// using namespace std;

// typedef double ld;
// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<int,int> II;

// const ld pi=2*acos(0);
// const int im = INT_MAX;
// const int in = INT_MIN;
// const int limit = 1e5+5;
// const ll M = 1e9+7;

// int h,c;

// bool check(int i, int j) 
// { 
// 	return (i >= 0 && j >= 0 && i < h && j < c); 
// } 

// bool kc(II temp) 
// { 
// 	return (temp.fi == -1 && temp.se == -1); 
// } 

// bool checkall(int a[][500]) 
// { 
// 	for (int i=0; i<h; i++) 
// 	for (int j=0; j<c; j++) 
// 		if (a[i][j] == 1) 
// 			return true; 
// 	return false; 
// } 

// int sol(int a[][500]) 
// { 
// 	queue<II> q; 
// 	II temp; 
// 	int ans = 0; 

// 	for (int i=0; i<h; i++) 
// 	{ 
// 	for (int j=0; j<c; j++) 
// 	{ 
// 			if (a[i][j] == 2) 
// 			{ 
// 				temp.fi = i; 
// 				temp.se = j; 
// 				q.push(temp); 
// 			} 
// 		} 
// 	} 

// 	temp.fi = -1; 
// 	temp.se = -1; 
// 	q.push(temp); 

// 	while (!q.empty()) 
// 	{ 

// 		bool dpTLE = false; 

// 		while (!kc(q.front())) 
// 		{ 
// 			temp = q.front(); 

// 			if (check(temp.fi+1, temp.se) && a[temp.fi+1][temp.se] == 1) 
// 			{ 

// 				if (!dpTLE) ans++, dpTLE = true; 

// 				a[temp.fi+1][temp.se] = 2; 

// 				temp.fi++; 
// 				q.push(temp); 

// 				temp.fi--; 
// 			} 

// 			if (check(temp.fi-1, temp.se) && a[temp.fi-1][temp.se] == 1) { 
// 				if (!dpTLE) ans++, dpTLE = true; 
// 				a[temp.fi-1][temp.se] = 2; 
// 				temp.fi--; 
// 				q.push(temp); 
// 				temp.fi++; 
// 			} 

// 			if (check(temp.fi, temp.se+1) && a[temp.fi][temp.se+1] == 1) { 
// 				if (!dpTLE) ans++, dpTLE = true; 
// 				a[temp.fi][temp.se+1] = 2; 
// 				temp.se++; 
// 				q.push(temp);
// 				temp.se--; 
// 			} 

// 			if (check(temp.fi, temp.se-1) && a[temp.fi][temp.se-1] == 1) { 
// 				if (!dpTLE) ans++, dpTLE = true; 
// 				a[temp.fi][temp.se-1] = 2; 
// 				temp.se--; 
// 				q.push(temp);
// 			} 

// 			q.pop(); 
// 		} 

// 		q.pop(); 

// 		if (!q.empty()) { 
// 			temp.fi = -1; 
// 			temp.se = -1; 
// 			q.push(temp); 
// 		} 
 
// 	} 

// 	return (checkall(a))? -1: ans; 
// } 

// int main ()
// {
//     ONLY_CPP
//     int T;
//     cin >> T;
//     while(T--){
//         cin>>h>>c;
//         int a[500][500];
//         for(int i = 0; i < h; i++){
//             for(int j = 0; j < c; j++){
//                 cin>>a[i][j];
//             }
//         }
//         cout<<sol(a)<<endl;
//     }
//     return 0;
// }