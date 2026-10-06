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
#define pii pair<int, int>
template <class T> bool maxi(T &x, T y) { if(x < y) { x = y ; return true ;} return false;}
template <class T> bool mini(T &x, T y) { if(x > y) { x = y ; return true ;} return false;}

const int N = 1e3 + 2;

int n, m;
char a[N][N];

void inp()
{
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
}

namespace sub1
{   
    int dx[8] = {0, 0, 1, -1, -1, 1, -1, 1};
    int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
    int dist[2][N][N];

    bool check(int x, int y) 
    {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    }
    void bfs(int u, int v, int k)
    {
        deque<pair<int, int>> dq;

        dq.push_back({u, v});
        while(!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();
            FOR(i, 0, 3) {
                int ua = dx[i] + x;
                int uv = dy[i] + y;
                if(check(ua, uv) && a[ua][uv] != 'X' && dist[k][ua][uv] == -1) {
                    dq.push_back({ua, uv});
                    dist[k][ua][uv] = dist[k][x][y] + 1;
                }
            }
         }
    }

    vector<pair<int, int>> imNode;

    vector<pair<int, int>> adj[N][N];
    bool isImpor[N][N];

    int color[N][N];

    void bfs_color() 
    {
        memset(color, 0, sizeof color);

        queue<pair<int, int>> q;

        FOR(y, 1, m) color[0][y] = 1, q.push({0, y});
        FOR(x, 1, n) color[x][m + 1] = 1, q.push({x, m + 1});

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            FOR(i, 0, 7) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(check(u, v) && a[u][v] == 'X' && color[u][v] == 0) {
                    color[u][v] = 1, q.push({u, v});
                }
            }
        }

        FOR(y, 1, m) color[n + 1][y] = 2, q.push({n + 1, y});
        FOR(x, 1, n) color[x][0] = 2, q.push({x, 0});

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            FOR(i, 0, 7) {
                int u = x + dx[i];
                int v = y + dy[i];
                if(check(u, v) && a[u][v] == 'X' && color[u][v] == 0) {
                    color[u][v] = 2, q.push({u, v});
                }
            }
        }
    }
    void slv()
    {
        memset(dist, -1, sizeof dist);
        dist[0][1][1] = dist[1][n][m] = 0;
        bfs(1, 1, 0);
        bfs(n, m, 1);
        
        int D = dist[0][n][m];
        // cout << D << el;
        FOR(x, 1, n) FOR(y, 1, m) if(a[x][y] != 'X') {
            if(dist[0][x][y] + dist[1][x][y] == D) imNode.push_back({x, y}), isImpor[x][y] = 1;
        }
        for(pair<int, int> t : imNode) {
            int x = t.first, y = t.second;
            FOR(i, 0, 3) {
                int u = dx[i] + x;
                int v = dy[i] + y;
                if(check(u, v) && isImpor[u][v]) adj[x][y].push_back({u, v});
            }
        }
        
        vector<int> cnt(D + 1, 0);
        for(pair<int, int> t : imNode) {
            cnt[dist[0][t.first][t.second]]++;
        }
        vector<pair<int, int>> trueImNode;

        for(pair<int, int> t : imNode) {
            int x = t.first, y = t.second;
            if(cnt[dist[0][x][y]] == 1) {
                if((x != 1 && y != 1) || (x != n && y != m)) trueImNode.push_back({x, y});
            }
        }

        bfs_color();
        
        for(pair<int, int> t : trueImNode) {
            int x = t.first, y = t.second;
            // cout << x << " " << y << el;
            bool touch1 = 0, touch2 = 0;

            FOR(i, 0, 7) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(color[nx][ny] == 1) touch1 = 1;
                if(color[nx][ny] == 2) touch2 = 1;
            }

            if(!(touch1 && touch2)) {
                a[x][y] = '*';
            }
        }
        FOR(i, 1, n) {
            FOR(j, 1, m) cout << a[i][j];
            cout << el;
        }
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