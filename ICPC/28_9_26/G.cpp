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

int n, m;
int deg[N];
bool isPath[N][N];
void inp()
{
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y; cin >> x >> y;
        deg[x]++; deg[y]++;
        isPath[x][y] = isPath[y][x] = 1;
    }
}

namespace sub1
{
    struct Node {
        int x, y;
    };

    bool isValid[N][N];
    int tempDeg[N];

    bool check(int k) 
    {
        FOR(x, 1, n) FOR(y, 1, n) isValid[x][y] = 0;

        FOR(x, 1, n) FOR(y, 1, n) isValid[x][y] = isPath[x][y];
        FOR(x, 1, n) tempDeg[x] = deg[x];


        deque<Node> dq;
        FOR(x, 1, n) FOR(y, x + 1, n) if(!isValid[x][y] && tempDeg[x] + tempDeg[y] >= k) {
            dq.push_back({x, y});
            isValid[x][y] = isValid[y][x] = 1;
        }

        while(!dq.empty()) {
            int x = dq.back().x, y = dq.back().y;
            dq.pop_back();

            tempDeg[x]++, tempDeg[y]++;

            FOR(c, 1, n) if(x != c && !isValid[x][c] && tempDeg[x] + tempDeg[c] >= k) {
                isValid[x][c] = isValid[c][x] = 1;
                dq.push_back({x, c});
            }
            FOR(c, 1, n) if(y != c && !isValid[y][c] && tempDeg[y] + tempDeg[c] >= k) {
                isValid[y][c] = isValid[c][y] = 1;
                dq.push_back({y, c});
            }
        }
        FOR(i, 1, n) if(tempDeg[i] != n - 1) return 0;
        return 1;
    }
    void slv()
    {
        int l = 0, r = 1e9, mid, ans = 0;
        while(l <= r) {
            mid = (r + l) >> 1;
            if(check(mid)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << ans;
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