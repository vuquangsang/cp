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

const int N = 2e3 + 2;
const int MAX = 1e4 + 2;

int n, m, q;
vector<pair<int, int>> adj[N];
struct Road
{
    int x, y, w;
} E[MAX];
void inp()
{
    cin >> n >> m >> q;
    FOR(i, 1, m) {
        int x, y, w; cin >> x >> y >> w;
        E[i] = {x, y, w};
        adj[x].push_back({y, w});
    }
}


namespace sub1
{
    struct eg
    {
        int u;
        ll val;
        bool operator<(const eg&other) const
        {
            return val > other.val;
        }
    };
    long long dist[N][N];

    void dij(int s)
    {
        FOR(i, 1, n) dist[s][i] = 1e18;
        dist[s][s] = 0;
        priority_queue<eg> pq;
        pq.push({s, 0});

        while(!pq.empty()) {
            int u = pq.top().u;
            ll val = pq.top().val;
            pq.pop();
            if(val > dist[s][u]) continue;
            for(pair<int, int> x : adj[u]) {
                int v = x.first, w = x.second;
                if(mini(dist[s][v], dist[s][u] + w)) {
                    pq.push({v, dist[s][v]});
                }
            }
        }
    }

    long long ans[N];
    void slv()
    {

        FOR(i, 1, n) dij(i);

        FOR(i, 1, n) ans[i] = 1e18;
        FOR(s, 1, n) {
            FOR(i, 1, m) {
                int x = E[i].x, y = E[i].y;
                mini(ans[s], dist[1][x] + dist[y][s]);
            }
        }

        while(q--) {
            int x, val; cin >> x >> val;
            cout << min(dist[1][x], ans[x] + val) << el;
        }
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #define __Azul__ "olp_ct22_roadimpro"
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

