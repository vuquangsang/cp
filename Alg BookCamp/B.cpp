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

const int N = 505;
const long long inf = 1e18 + 2;


int n, k;
int a[N];
long long dist[N][N];
void inp()
{
    cin >> n >> k;
    FOR(i, 1, n) FOR(j, 1, n) cin >> dist[i][j];
    a[1] = 1;
    k++;
    FOR(i, 2, k) cin >> a[i];
}


namespace sub1
{
    ll dp[(1 << 21) + 2][23];
    void slv()
    {
        FOR(k, 1, n) FOR(x, 1, n) FOR(y, 1, n) mini(dist[x][y], dist[x][k] + dist[k][y]);
        memset(dp, 0x3f, sizeof dp);
        dp[1][1] = 0;
        FOR(msk, 0, (1 << k) - 1) {
            FOR(i, 0, k - 1) if(msk >> i & 1){
                if(dp[msk][i + 1] > inf) continue;
                FOR(j, 0, k - 1) if(!(msk >> j & 1)) {
                    int nw_msk = msk | (1 << j);
                    mini(dp[nw_msk][j + 1], dp[msk][i + 1] + dist[a[i + 1]][a[j + 1]]);
                }
            }
        }
        ll ans = inf;
        FOR(i, 2, k) mini(ans, dp[(1 << k) - 1][i] + dist[a[i]][1]);
        cout << ans;
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
        sub1 :: slv();
    }

    cerr << "\nTime" << 0.001 * clock() << "s "; return 0;


}
