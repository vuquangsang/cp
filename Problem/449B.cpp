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

const int N = 3e5 + 2;
const long long inf = 1e18 + 2;

int n, m, k;
struct Line
{
    int x, y, w;
} E[N];
pair<int, int> trains[N];
vector<pair<int, int>> adj[N];
void inp()
{
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        E[i] = {x, y, w};
    }
    FOR(i, 1, k) {
        int x, y; cin >> x >> y;
        trains[i] = {x, y};
    }
}


namespace sub1
{
    long long dist[N];

    struct eg
    {
        int u;
        ll val;
        bool operator<(const eg&other) const
        {
            return val > other.val;
        }
    };
    void slv()
    {
        FOR(i, 1, n) dist[i] = inf;
        dist[1] = 0;
        priority_queue<eg> pq;
        pq.push({1, 0});
        while(!pq.empty()) {
            int u = pq.top().u;
            ll val = pq.top().val;
            pq.pop();
            if(val > dist[u]) continue;
            for(pair<int, int> x : adj[u]) {
                int v = x.first, w = x.second;
                if(mini(dist[v], dist[u] + w)) {
                    pq.push({v, dist[v]});
                }
            }
        }
        FOR(i, 1, n) cout << dist[i] << " ";
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

