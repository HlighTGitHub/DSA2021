#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
int V, E, a[100][100];
bool visited[1005];    //khai báo mảng toàn cục kiểm tra các đỉnh đã thăm.
vector < pair <int, int> > display;
//khai báo 1 vector lưu cặp đỉnh (cha, con) để thực hiện in cây khung.

void DFS(int u){
    stack <int> s; 
    visited[u] = -1;    
    s.push(u);
    while(!s.empty()){
        int v = s.top();    s.pop();
        for(int i=1; i<=V; i++){
            if(visited[i] == 0 && a[v][i] != 0){
                s.push(v);
                s.push(i);
                visited[i] = true;
                display.push_back(make_pair(v, i));
                break;
            }
        }
    }
}


void T_DFS(){
    int CayKhung = 0;
    for(int i=1; i<=V; i++){    
        //vòng lặp để duyệt BFS từ tất cả các điểm, tìm tất cả các cây khung.
        memset(visited, 0, sizeof(visited));
        display.clear();
        DFS(i);
        if(display.size() == V-1){     
            //số lượng phần tử trong display = V-1 <=> cây khung.
            for(int j=0; j < display.size(); j++){
                cout << '(' << display[j].first << ", " 
                            << display[j].second << ") ";
            }
            cout << endl;
            CayKhung++;
        }
    }
    if(CayKhung == 0)   cout << "Khong co cay khung.";
}

int main(){
    // cin >> V >> E;
    // for(int i=0; i<E; i++){
    //     int x, y;
    //     cin >> x >> y;
    //     a[x][y]=1;
    //     a[y][x]=1;
    // }
    // T_DFS();
    if(int x = 1)   cout << 1;
}



// int n, s, a[100][100], d[100], e[100], vs[100];
// void Dijkstra(int s){
//     int u, v;
//     for (v=1; v<= n; v++){
//         d[v]= a[s][v]; 
//         e[v]=s;
//     }
//     d[s]= 0; 
//     e[s] = 0;
//     vs[s]= 1;
//     while (1){
//         int u= 0, min= 32767;
//         for (v=1; v<= n; v++) 
//             if (vs[v]==0 && d[v]< min){
//                 u= v; 
//                 min= d[v];
//             }
//         if (u== 0) return; 
//         vs[u]= 1;
//         for (v=1; v<=n; v++)
//             if (vs[v]== 0 && d[v]> d[u]+a[u][v]){
//                 d[v]= d[u] + a[u][v]; 
//                 e[v] = u;
//             }
//     }
// }



// int a[100][100], n, u;
// int vs[100], e[100], s[10000], ce[10000];
// int kt(int a[][], int n) { //hàm kiểm tra điều kiện của đồ thị G.
//     int v;
//     for (v= 1; v<= n; v++){ 
//         vs[v]= 0; 
//         e[v]= 0;
//     } 
//     DfsDequy(1);       
//     int ok = 1;
//     for (v = 1; v <= n; v++)
//         if (vs[v] == 0){ 
//             ok = 0;
//             break;
//         }
//     if (ok == 0) return(0);
//     int bl= 0;
//     for(v = 1; v <= n; v++){
//         int deg= 0;
//         for(int i = 1; i<= n; i++)  
//             if(a[v][i] == 1) deg++;
//         if (deg%2 == 1){
//             bl++; 
//             if (bl > 2) return(0);
//             if (bl == 1){
//                 u = v; 
//                 ok = 2;
//             }
//         }
//     }   
//     return(ok);           
// }
// void EULER(int a[][]){
//     int top=0, v;
//     top++; 
//     s[top] = u; 
//     int k = 0;
//     while(top > 0){
//         int v = s[top]; 
//         int ok = 1;
//         for (int x = 1; x <= n; x++)
//             if (a[v][x] ==1){
//                 top++; 
//                 s[top]= x; 
//                 ok= 0; 
//                 a[v][x]= 0; 
//                 a[x][v]= 0; 
//                 break;
//             }
//         if (ok== 1){
//             k++;
//             ce[k]= v;
//             top--;
//         }
//     }
//     for (v = k; v > 0; v--)  cout << ce[v] << “ “;
// }
// int n, a[100][100];
// int d[100][100], e[100][100];
// void Floyd(){
//     int i, j, k;
//     for (i = 1; i <= n; i++)
//         for (j = 1; j <= n; j++){
//             d[i][j]= a[i][j];
//             e[i][j]= i;
//         }
//     for (k = 1; k <= n; k++)
//         for (i = 1; i <= n; i++)
//             for (j = 1; j <= n; j++)
//                 if (d[i][j] > d[i][k] + d[k][j]){
//                     d[i][j] > d[i][k] + d[k][j];
//                     e[i][j] = k;
//                 }
// }

// int n, m, d[10000], c[10000], ts[10000];
// int vs[100], t[100];
// void Kruskal() { 
//     for (int i = 1; i <= m-1, i++) 
//         for (int j = i+1; j <= m, j++)
//             if (ts[i] > ts[j]) {
//                 swap(ts[i], ts[j]);
//                 swap(d[i], d[j]);
//                 swap(c[i], c[j]);
//             }  
//     int wt = 0, k = 0;     
//     memset(vs, 0, sizeof(vs));
//     for (i = 1; i <= m; i++) 
//         if (!(vs[d[i]] !=0 && vs[d[i]] == vs[c[i]])){
//             k++;  
//             t[k]= i; 
//             wt = wt + ts[i];
//             if (k == n-1) { 
//                 cout <<  wt << endl; 
//                 cout << d[t[i]] << ' ' << c[t[i]] << endl;
//                 return; 
//             }
//         }   
//         int u = d[i], v = c[i]; 
//         if (vs[u] == 0 && vs[v] == 0){
//             vs[u] = k; 
//             vs[v] = k;
//         }  
//         else if (vs[u] == 0 && vs[v] != 0) vs[u] = vs[v]; 
//         else if (vs[u] != 0 && vs[v] == 0) vs[v] = vs[u];
//         else if (vs[u] < vs[v])
//             for (j = 1; j <= n; j++)
//                 if (vs[j] == vs[v]) 
//                     vs[j] = vs[u]; 
//         else if (vs[v] < vs[u])
//             for (j= 1; j<= n; j++)
//                 if (vs[j] == vs[u]) 
//                     vs[j]= vs[v];   
// } 


// int Stop = 0; int q[100]; int d[100]; int vs[100]; int e[100]; int fl[100][100];
// void  FindPath(){ 
//     int cq, dq, u, v;  
//         for (u = 1; u <= n; u++) 
//             vs[u] = 0;   
//     cq = 1;
//     dq = 1; 
//     q[cq] = s; 
//     vs[s] = 1;   
//     e[s] = 0; 
//     d[s] = 10000;
//     while (dq <= cq){  
//         u = q[dq];  
//         dq++;
//         for  (v = 1; v <= n; v++)  
//             if (vs[v]== 0) {
//                 if (c[u][v] > 0 && fl[u][v] < c[u][v]) { 
//                     e[v] = u;   
//                     d[v] = (d[u]< c[u][v] - fl[u][v])?d[u]: c[u][v] - fl[u][v];  
//                     cq++; 
//                     q[cq] = v; 
//                     vs[v] = 1;   
//                     if (v == t) return;   
//                 }	
//                 if (c[v][u] > 0 && fl[v][u] > 0) {  
//                     e[v] = -u;  
//                     d[v] = (d[u]< fl[v][u])?d[u]: fl[v][u];  
//                     cq++; 
//                     q[cq] = v; 
//                     vs[v] = 1;   
//                     if (v == t) return; 
//                 }
//             }           
//     }
//     Stop = 1;
// }




// int n, a[100][100];
// int vs[100], d[100], e[100];
// void Prim(int s) {
//     for (int v = 1; v <= n, v++){
//         vs[v] = 0; 
//         d[v] = a[s][v]; 
//         e[v] = s
//     }
//     d[s] = 0; 
//     vs[s] = 1;
//     p[s] = 0; 
//     int wt = 0, dem = 1; 
//     while (dem < n){ 
//         int u = 0;    
//         int min = 30000;
//         for (v = 1; v <= n; v++)
//             if (vs[v] == 0 && d[v] < min){
//                 min = d[v]; 
//                 u = v;
//             }
//         if (u == 0){
//             cout << "Khong co cay khung."; 
//             return;
//         }
//         vs[u] = 1; 
//         wt = wt + a[u][e[u]];
//         for (v = 1; v <= n; v++)
//             if (vs[v] == 0 && d[v] > a[u][v]){
//                 d[v] = a[u][v]; 
//                 e[v] = u; 
//             }
//     } 
//     cout << wt << endl;
//     for (v = 1; v <= n; v++)
//         if (p[v] != 0) 
//             cout << v << ' ' << e[v] << endl;
//     return; 
// }


// int n, m, d[10000], c[10000], ts[10000];
// int vs[100], t[100];
// void Kruskal() { 
//     for (int i= 1; i<= m-1, i++) 
//         for (int j= i+1;j<= m, j++)
//             if (ts[i] > ts[j]) {
//         int tg = ts[i]; ts[i]= ts[j]; ts[j]= tg;
//         tg = d[i]; d[i]= d[j]; d[j]= tg;
//         tg = c[i]; c[i]= c[j]; c[j]= tg; };  
//         int wt= 0, k= 0;     
//         for (i= 1; i<= n; i++) vs[i]= 0;
//         for (i= 1; i<= m; i++) 
//     if (!(vs[d[i]] !=0 && vs[d[i]] == vs[c[i]])){
//         k++;  t[k]= i; wt= wt + ts[i];
//         if (k == n-1) { cout << wt << endl; 
//     cout << d[t[i]] << “ “ <<c[t[i]] << endl;
//         return; }   
//     int u= d[i], v= c[i]; 
//             if (vs[u] == 0 && vs[v] == 0){
//                 vs[u]= k; vs[v]= k;}  
//                 else 
//     if (vs[u]==0 && vs[v]!=0) vs[u]=  vs[v]; 
//                 else 
//     if (vs[u]!=0 && vs[v]==0) vs[v]=  vs[u];
//                 else 
//         if (vs[u] < vs[v]) {
//                 tg= vs[v];
//         for (j= 1; j<= n; j++)
//         if (vs[j] == tg) vs[j]= vs[u]; 
//         }
//     else if (vs[v] < vs[u]) {tg= vs[u];
//     for (j= 1; j<= n; j++)
//         if (vs[j] == tg) vs[j]= vs[v];   }
//       } 
