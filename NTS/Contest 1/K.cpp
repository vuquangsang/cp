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

const int N = 5005;

int n, a[N], b[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
}

namespace sub1
{   
    ll dp[N][N];
    void slv()
    {
        memset(dp, -0x3f, sizeof dp);
        dp[0][0] = 0;
        FOR(i, 1, n) FOR(j, 1, n) {
            dp[i][j] = 1LL * a[i] * b[j];
            maxi(dp[i][j], dp[i - 1][j - 1] + 1LL * a[i] * b[j]);
        }
        ll res = -1e18;
        FOR(i, 1, n) FOR(j, 1, n) maxi(res, dp[i][j]);
        cout << res;
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

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}