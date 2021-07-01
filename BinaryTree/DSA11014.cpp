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
void makeNode(Node* root, int y, char side, map < int, Node* > *m){
    switch(side){
        case 'L':   root->left = new Node(y);
                    (*m)[y] = root->left;
                    break;
        case 'R':   root->right = new Node(y);
                    (*m)[y] = root->right;
                    break;
    }
}
void makeNodeTest(Node* root, int y, char side, map < int, Node* > *m){
    bool alreadyHave = ((*m)[y] != NULL);
    switch(side){
        case 'L':   if(alreadyHave) root->left = (*m)[y];
                    else{
                        root->left = new Node(y);
                        (*m)[y] = root->left;
                    }
                    break;
        case 'R':   if(alreadyHave) root->right = (*m)[y];
                    else{
                        root->right = new Node(y);
                        (*m)[y] = root->right;
                    }
                    break;
    }
}

/*Initialize*/
int test, n;

/*Function*/
int BFS(Node* root){
    queue < Node* > q;
    q.push(root);
    int sum = 0;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL){
            if(node->right->left == NULL && node->right->right == NULL)
                sum += node->right->value;
            else
                q.push(node->right);
        }
    }
    return sum;
}

void rightLeafSum(Node* root, int *sum){
    if(!root)   return;
    if(root->right)
        if(!root->right->left && !root->right->right)
            *sum += root->right->value;
    rightLeafSum(root->left, sum);
    rightLeafSum(root->right, sum);
}

void solve(){
    cin >> n;
    Node* root = NULL;
    int x, y;
    char side;
    map < int, Node* > m;
    while(n--){
        cin >> x >> y >> side;
        if(m[x] == NULL){
            m[x] = new Node(x);
            if(root == NULL)
                root = m[x];
        }
        makeNodeTest(m[x], y, side, &m);
    }
    cout << BFS(root);
    /*Another way:
        int sum = 0;
        rightLeafSum(root, &sum);
        cout << sum;
    */
}

/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        solve();
        cout << endl;
    }
    return 0;
}