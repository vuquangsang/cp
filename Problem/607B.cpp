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

const int N = 505;

int n, a[N];

void inp()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

namespace sub1
{
    int dp[N][N];
    int calc(int l, int r) 
    {
        if(l > r) return 2e9;
        if(l == r) return 1;
        if(l + 1 == r) {
            if(a[l] == a[r]) return 1;
            return 2;
        }
        int &res = dp[l][r];
        if(res != -1) return res;
        res = 2e9;
        if(a[l] == a[r]) res = min(res, calc(l + 1, r - 1));
        for(int k = l; k < r; k++) {
            mini(res, calc(l, k) + calc(k + 1, r));
        }
        dp[l][r] = res;
        return res;
    }
    void slv()
    {
        memset(dp, -1, sizeof dp);
        cout << calc(1, n);
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