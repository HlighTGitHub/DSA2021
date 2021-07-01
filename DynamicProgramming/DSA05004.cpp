#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	int f[n+1];
	for(int i=0; i<n; i++)	cin >> a[i];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int res = 1;
	for(int i=1; i<n; i++){
		f[i] = 1;
		for(int j = 0; j<i; j++)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j]+1);
		res = max(f[i], res);
	}
	cout << res;
	return 0;
}