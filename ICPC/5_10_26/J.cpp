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

const int N = 205;

int n, a[N];

void inp()
{
    cin >> n; FOR(i, 1, n) cin >> a[i];
}

namespace sub1
{
    int dp[N][N], trace[N][N];

    bool keep[N];

    void trace_path(int l, int r) 
    {
        if(l >= r) return;
        if(dp[l][r] == 0) return;

        if(trace[l][r] == -1) {
            keep[l] = keep[r] = 1;
            trace_path(l + 1, r - 1);
        }
        else {
            int k = trace[l][r];
            trace_path(l, k); trace_path(k + 1, r);
        }
    }

    void slv() 
    {
        FOR(i, 1, n - 1) {
            if(a[i] % a[i + 1] == 0 || a[i + 1] % a[i] == 0) dp[i][i + 1] = 1, trace[i][i + 1] = -1;
            else dp[i][i + 1] = 0;
        }
        FOR(len, 3, n) {
            FOR(i, 1, n - len + 1) {
                int j = i + len - 1;
                FOR(k, i, j - 1) {
                    if(maxi(dp[i][j], dp[i][k] + dp[k + 1][j])) {
                        trace[i][j] = k;
                    }
                }
                if(a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                    if(maxi(dp[i][j], dp[i + 1][j - 1] + 1)) {
                        trace[i][j] = -1;
                    }
                }
            }
        }
        trace_path(1, n);
        vector<int> ans;
        FOR(i, 1, n) if(!keep[i]) ans.push_back(i);
        cout << ans.size() << el;
        for(int x : ans) cout << x << " " ;
    }
}

namespace sub2 
{
    int trace[N][N], dp[N][N];
    int calc(int l, int r)
    {
        if(l >= r) return 0;
        if(l + 1 == r) {
            if(a[l] % a[r] == 0 || a[r] % a[l] == 0) dp[l][r] = 1, trace[l][r] = -1;
            else dp[l][r] = 0;
            return dp[l][r];
        }
        if(dp[l][r] != -1) return dp[l][r];
        FOR(k, l, r - 1) if(maxi(dp[l][r], calc(l, k) + calc(k + 1, r))) {
            trace[l][r] = k;
        }
        if((a[l] % a[r] == 0 || a[r] % a[l] == 0) && maxi(dp[l][r], calc(l + 1, r - 1) + 1)) trace[l][r] = -1;

        return dp[l][r];

    }
    bool keep[N];

    void trace_path(int l, int r) 
    {
        if(l >= r) return;
        if(dp[l][r] == 0) return;

        if(trace[l][r] == -1) {
            keep[l] = keep[r] = 1;
            trace_path(l + 1, r - 1);
        }
        else {
            int k = trace[l][r];
            trace_path(l, k); trace_path(k + 1, r);
        }
    }
    void slv() 
    {
        memset(dp, -1, sizeof dp);
        calc(1, n);

        trace_path(1, n);
        vector<int> ans;
        FOR(i, 1, n) if(!keep[i]) ans.push_back(i);
        cout << ans.size() << el;
        for(int x : ans) cout << x << " " ;
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
        sub2 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}