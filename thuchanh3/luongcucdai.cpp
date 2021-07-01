#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;


/* Yêu cầu:
 - Nhập ma trận trọng số biểu diễn G từ tệp DT.INP; với s = 1; t = n;
 - Tìm luồng cực đại f.
 - Xuất kết quả ra tệp DT.OUT:
     + Dòng đầu ghi Val(f).
     + N dòng sau ghi f[i][j].
*/

int n;
int a[1005][1005];

void Input(){
    ifstream fin("DT.INP");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            fin >> a[i][j];
    fin.close();
}

void Output(int result){
    ofstream fout("DT.OUT");
    fout << result << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            fout << ((j > i)? a[j][i]:0) << ' '; //in luồng trên cung (i, j).
        fout << endl;
    }
    fout.close();
}

bool FindPathfromStoT(int *res){        //Loang bằng BFS.
    int parent[n+1];
    memset(parent, 0, sizeof(parent));

    queue <int> q;
    int path_flow = INT_MAX;

    parent[1] = 1;
    q.push(1);

    while(!q.empty()){
        int u = q.front();  q.pop();
        for(int v = 2; v <= n; v++){
            if(!parent[v] && a[u][v]){
                path_flow = min(path_flow, a[u][v]);
                parent[v] = u;
                if(v == n){
                    //Khi đã loang tới đỉnh n, cập nhật luồng cực đại và mạng.
                    while(v != parent[v]){
                        a[v][parent[v]] += path_flow;
                        a[parent[v]][v] -= path_flow;
                        v = parent[v];
                    }
                    *res += path_flow;
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}

int Ford_Fulkerson(){
    int res = 0;
    while(FindPathfromStoT(&res));
    return res;
}

/*Main program*/
int main(){
    Input();
    Output(Ford_Fulkerson());
    return 0;
}
