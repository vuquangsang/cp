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

const int N = 2e5 + 2;

struct Edge {
    int x, y;
    double l, c;
    int id;
} E[N];

int n, m;

void inp()
{
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        double l, c; 
        cin >> x >> y >> l >> c;
        E[i] = {x, y, l, c, i};
    }
}

namespace sub1
{
    vector<int> ans;
    
    struct Node {
        double val; 
        int id;
    } newPath[N];

    int lab[N];
    int root(int x) {return lab[x] < 0 ? x : lab[x] = root(lab[x]);}
    bool joint(int x, int y) 
    {
        x = root(x), y = root(y);
        if(x == y) return 0;
        if(lab[x] < lab[y]) swap(x, y);
        lab[x] += lab[y];
        lab[y] = x;
        return 1;
    }

    bool calc(double x) 
    {
        FOR(i, 1, n) lab[i] = -1;

        double total = 0;

        vector<int> path;
        FOR(i, 1, m) {
            double value = newPath[i].val;
            int id = newPath[i].id;
            if(joint(E[id].x, E[id].y)) {
                total += value;
                path.push_back(id);
            }
        }
        ans = path;
        return total <= 0;
    }
    bool check(double x)
    {
        FOR(i, 1, m) {
            newPath[i] = {(double)E[i].c - E[i].l * x, i};
        }
        sort(alla(newPath, m), [](Node a, Node b) {
            if(a.val == b.val) return a.id < b.id;
            return a.val < b.val;
        });
        return calc(x);
    }
    void slv()
    {
        double l = 0.0000, r = 1e18, mid, res;
        
        FOR(i, 1, 100) {
            mid = (r + l) / 2;
            if(check(mid)) res = mid, r = mid;
            else l = mid;
        }

        sort(all(ans));

        for(int x : ans) cout << x << " ";
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