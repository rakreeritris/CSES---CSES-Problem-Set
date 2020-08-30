#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
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



void solve() {
    int n, m; cin >> n >> m;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    vvi dp(n, vi(m + 1, 0));
    for (int i = 1; i <= m; i++)
        dp[0][i] = (x[0] == 0 || x[0] == i);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == 0 || x[i] == j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) (dp[i][j] += dp[i - 1][j - 1]) %= MOD;
                if (j < m) (dp[i][j] += dp[i - 1][j + 1]) %= MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) 
        (ans += dp[n - 1][i]) %= MOD;
    cout << ans << "\n";
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
