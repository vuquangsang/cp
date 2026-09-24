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

int n, a[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n - 1) cin >> a[i];
}


namespace sub1
{
    int rmq[N][21];
    long long dp[N];
    int calc(int x, int y)
    {
        return (a[x] > a[y] ? x : y);
    }
    void build_rmq()
    {
        FOR(i, 1, n) rmq[i][0] = i;
        for(int j = 1; (1 << j) - 1 <= n; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                rmq[i][j] = calc(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int get(int l, int r)
    {
        int j = __lg(r - l + 1);
        return calc(rmq[l][j], rmq[r - (1 << j) + 1][j]);
    }
    void slv()
    {
        build_rmq();

        dp[n] = 0;

        for(int i = n - 1; i >= 1; i--) {
            int pos = get(i + 1, a[i]);
            dp[i] = n - i + dp[pos] - a[i] + pos;
        }
        ll ans = 0;
        FOR(i, 1, n - 1) ans += dp[i];
        cout << ans;
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "675E"
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

