#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define lg(x) __lg(x)
#define alla(a,n) a+1,a+n+1
#define ll long long

template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = 1e4 + 2;
const long long INF = 1e16 + 2;

int n, m, a[N], b[N];

void inp()
{
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
}

namespace sub12
{
    const int MAX = 55;
    ll dp[MAX][MAX][MAX], sa[N], sb[N];
    void slv()
    {
        FOR(i, 1, n) sa[i] = sa[i - 1] + a[i];
        FOR(i, 1, m) sb[i] = sb[i - 1] + b[i];

        memset(dp, 0x3f, sizeof dp);

        dp[0][0][0] = 0;
        FOR(k, 1, min(n, m)) {
            dp[k][k][k] = dp[k - 1][k - 1][k - 1] + 1LL * (a[k] - 1) * (b[k] - 1);
            FOR(i, k, n) FOR(j, k, m) {
                FOR(u, 1, i) FOR(v, 1, j) {
                    mini(dp[k][i][j], dp[k - 1][u - 1][v - 1] + 1LL * (sa[i] - sa[u - 1] - (i - u + 1)) * (sb[j] - sb[v - 1] - (j - v + 1)));
                }
            }
        }
        ll ans = INF;

        FOR(k, 1, min(n, m)) mini(ans, dp[k][n][m]);

        cout << ans;
    }
}

namespace sub3
{
    const int MAX = 505;

    ll sa[N], sb[N], dp[MAX][MAX];
    void slv() 
    {
        FOR(i, 1, n) {
            a[i]--;
            sa[i] = sa[i - 1] + a[i];
        }
        FOR(i, 1, m) {
            b[i]--;
            sb[i] = sb[i - 1] + b[i];
        }
        
        memset(dp, 0x3f, sizeof dp);

        dp[0][0] = 0;
        FOR(i, 1, n) FOR(j, 1, m) {
            FOR(u, 1, i) mini(dp[i][j], dp[u - 1][j - 1] + 1LL * (sa[i] - sa[u - 1]) * b[j]);
            FOR(v, 1, j) mini(dp[i][j], dp[i - 1][v - 1] + 1LL * a[i] * (sb[j] - sb[v - 1]));
        }
        cout << dp[n][m];
    }
}
namespace sub4 
{
    ll dp[2][N], sa[N], sb[N];
    void slv() 
    {
         FOR(i, 1, n) {
            a[i]--;
            sa[i] = sa[i - 1] + a[i];
        }
        FOR(i, 1, m) {
            b[i]--;
            sb[i] = sb[i - 1] + b[i];
        }
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = 0;
        FOR(i, 1, n) {
            
            FOR(j, 1, m) {

            }
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "qs"
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }

    bool qs = 0;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub3 :: slv(); return 0;
        if(n <= 50) sub12 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}