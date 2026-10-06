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

const int N = 5e4 + 2;

int n, a[N];

void inp()
{
    cin >> n; FOR(i, 1, n) cin >> a[i];
}

namespace sub1
{
    void compress() 
    {
        vector<int> V;
        FOR(i, 1, n) V.push_back(a[i]);
        sort(all(V)); 
        V.resize(unique(all(V)) - V.begin());

        FOR(i, 1, n) {
            a[i] = lower_bound(all(V), a[i]) - V.begin() + 1;
        }
    }

    int dp[N][2];

    struct SegmentTree 
    {
        pair<int, int> st[4 * N];

        pair<int, int> Merge(pair<int, int> a, pair<int, int> b) 
        {
            if(a.fi >= b.fi) return a;
            return b;
        }
        void upd(int id, int l, int r, int i, int val, int pos) 
        {
            if(i > r || i < l) return;
            if(l == r) {
                if(val > st[id].fi) st[id] = {val, pos};
                return;
            }
            int mid = (r + l) >> 1;
            upd(id << 1, l, mid, i, val, pos);
            upd(id << 1 | 1, mid + 1, r, i, val, pos);
            st[id] = Merge(st[id << 1], st[id << 1 | 1]);
        }
        pair<int, int> get(int id, int l, int r, int u, int v) 
        {
            if(r < u || v < l) return {0, 0};
            if(u <= l && r <= v) return st[id];
            int mid = (r + l) >> 1;
            return Merge(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
        }
    } myIt0, myIt1;

    int par[N][2];
    void slv()
    {
        compress();
        
        FOR(i, 1, n) {
            pair<int, int> ans1 = myIt1.get(1, 1, n, a[i] + 1, n);
            pair<int, int> ans0 = myIt0.get(1, 1, n, 1, a[i] - 1);
            dp[i][0] = ans1.fi + 1;
            dp[i][1] = ans0.fi + 1;
            
            par[i][0] = ans1.se;
            par[i][1] = ans0.se;

            myIt0.upd(1, 1, n, a[i], dp[i][0], i);
            myIt1.upd(1, 1, n, a[i], dp[i][1], i);
        }

        int ans = 0, u, v;
        FOR(i, 1, n) {
            if(maxi(ans, dp[i][0])) u = i, v = 0;
            if(maxi(ans, dp[i][1])) u = i, v = 1;
        }
        if(ans < 3) {
            cout << 0; return;
        }

        cout << ans << el;

        vector<int> vec;
        while(u) {
            vec.push_back(u);
            u = par[u][v];
            v ^= 1;
        }
        reverse(all(vec));

        for(int x : vec) cout << x - 1 << " ";
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