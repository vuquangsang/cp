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

const int N = 2002;

int n, a[N][N];

void inp()
{
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];   
}

namespace sub1
{

    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

    bool vis[N][N], isValid[2 * N + 2];

    void dfs(int x, int y) 
    {
        vis[x][y] = 1;
        if(y == 1 || x == n) isValid[a[x][y]] = 1;
        for(int i = 0; i < 8; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if(!vis[nx][ny] && a[nx][ny] == a[x][y]) dfs(nx, ny);
            }
        }
    }
    void slv()
    {
        FOR(i, 1, n) FOR(j, 1, n) vis[i][j] = 0;
        FOR(i, 1, n * n + 1) isValid[i] = 0;

        FOR(i, 1, n) {
            if(!vis[1][i]) dfs(1, i);
            if(!vis[i][n]) dfs(i, n);
        }
        FOR(i, 1, 2 * n + 1) if(!isValid[i]) {
            cout << i << el; return;
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

    bool qs = 1;

    int T = 1;
    if(qs) cin >> T;
    while(T--) {
        inp();
        sub1 :: slv();
    }

    cerr << "\nTime " << 0.001 * clock() << "s "; return 0;
}