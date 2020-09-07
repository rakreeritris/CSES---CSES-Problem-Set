#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 2e5 + 5;
const int MAX_L = 30; // ~ Log(1e9)
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

int n, q, dp[MAX_N][MAX_L];

int ancestor(int u, int k) {
    for (int i = 0; i < MAX_L; i++)
        if (k & (1 << i))
            u = dp[u][i];
    return u;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> dp[i][0];
    for (int i = 1; i < MAX_L; i++)
        for (int u = 1; u <= n; u++)
            dp[u][i] = dp[dp[u][i - 1]][i - 1];
    while (q--) {
        int x, k; cin >> x >> k;
        cout << ancestor(x, k) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
