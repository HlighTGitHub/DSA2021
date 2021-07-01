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
#define oo INT_MAX
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value = v;
        left = right = NULL;
    }
};
void makeNode(Node* root, int x, int y, char side){
    switch(side){
        case 'L':   root->left = new Node(y);
                    break;
        case 'R':   root->right = new Node(y);
                    break;       
    }
}
void Insert(Node* root, int x, int y, char side){
    if(root == NULL)    return;
    if(root->value == x)  makeNode(root, x, y, side);
    else{
        Insert(root->left, x, y, side);
        Insert(root->right, x, y, side);
    }
}
bool BFS(Node* root){
    queue < Node* > q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node->left != NULL){
            if(node->right == NULL) return false;
            else{
                q.push(node->left);
                q.push(node->right);
            }
        }
        else if(node->right != NULL)    return false;
    }
    return true;
}
/*Initialize*/
int test, n;

/*Function*/
void init(){
    cin >> n;
}
void solve(){
    Node* root = NULL;
    int x, y;
    char side;
    while(n--){
        cin >> x >> y >> side;
        if(root == NULL){
            root = new Node(x);
            makeNode(root, x, y, side);
        }
        else Insert(root, x, y, side);
    }
    cout << (BFS(root)?"1":"0");
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/