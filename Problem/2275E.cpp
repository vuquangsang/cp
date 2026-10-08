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

const int N = 5e5 + 2;

int n, a[N], b[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
}

namespace sub1
{
    ll cost[N];
    int calc(int x, int y) 
    {
        return (x == y ? 2 : 1);
    }
    ll dp[N];
    void slv()
    {
        FOR(i, 1, n + 1) cost[i] = dp[i] = 0;

        cost[n] = (a[n] == b[n] ? 2 : 1);
        if(n >= 2) {
            cost[n - 1] = calc(a[n - 1], b[n]) + calc(b[n], a[n]) + calc(a[n], b[n - 1]);
        }

        dp[n] = cost[n];
        FORD(i, n - 1, 1) {
            if(i <= n - 2) cost[i] = cost[i + 2] + calc(a[i], b[i + 1]) + calc(b[i + 1], a[i + 2]) + calc(b[i + 2], a[i + 1]) + calc(a[i + 1], b[i]);
            dp[i] = max(cost[i], calc(a[i], b[i]) + calc(b[i], a[i + 1])  + dp[i + 1]);
        }
        cout << dp[1] << el;
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

    bool qs = 1;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub1 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}