#include <bits/stdc++.h>
using namespace std;

#define     el "\n"
#define     FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; i++)
#define     FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define     pb push_back
#define     fi first
#define     se second
#define     all(x) x.begin(),x.end()
#define     lg(x) __lg(x)
#define     alla(a,n) a+1,a+n+1
#define     ll long long


template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = 1e5 + 2;

int n, m, P, C, a[N], s[N];

void inp()
{
    cin >> n >> m >> P >> C;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 0, m - 1) cin >> s[i];
}


namespace sub1
{
    long long dp[N][70];
    long long sq(ll x)
    {
        return 1LL * x * x;
    }
    void slv()
    {
        sort(a + 1, a + n + 1);
        memset(dp, -0x3f, sizeof dp);

        dp[0][0] = 0;
        FOR(i, 1, n) {
            FOR(msk, 0, (1 << m) - 1) dp[i][msk] = dp[i - 1][msk];
            FOR(msk, 0, (1 << m) - 1) {
                FOR(j, 0, m - 1) if(i >= s[j]) {
                    int diff = a[i] - a[i - s[j] + 1];
                    if(msk >> j & 1) {
                        maxi(dp[i][msk], dp[i - s[j]][msk] + P - 1LL * sq(diff) * C);
                    }
                    else {
                        maxi(dp[i][msk | (1 << j)], dp[i - s[j]][msk] + P - 1LL * sq(diff) * C);
                    }
                }
            }
        }
        cout << dp[n][(1 << m) - 1];
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "whome"
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }

    bool qs = 0;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub1 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}

