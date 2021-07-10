#include<bits/stdc++.h>
using namespace std;
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define matrix vector<vector<ll>>
#define Modd (ll)(1e9 + 7)
 
using namespace std;
 
bool Multitests = 1;
ll test = 1, n, m, k, l, r, x, y;
string f;
 
ll CAL(ll d)
{
    ll ans = 0;
    for (int i = 0; i < f.size(); i++)
        if (f[i] != '0' && d >= (1LL << i))
            ans += (d - (1LL << i)) / (2LL << i) + 1;
    return ans;
}
 
void Solve()
{
    cin >> n >> l >> r;
    f = bitset<50>(n).to_string();
    while (f.size() > 1 && f[0] == '0')
        f.erase(f.begin());
    cout << CAL(r) - CAL(l - 1) << endl;
}
 
int main()
{
    setIO();
 
    if (Multitests)
        (cin >> test).ignore();
    while (test--)
        Solve();
    return 0;
}
