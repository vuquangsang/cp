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

const int N = 1e5 + 2;

int n, k;
struct Const {
    int l, r, val;
} ps[N];
int a[N];
void inp()
{
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, k) {
        int l, r, val; cin >> l >> r >> val;
        ps[i] = {l, r, val};
    }
}

namespace sub1
{
    int D[N];

    bool isValid()
    {
        vector<int> pre(n + 1);
        FOR(i, 1, n) pre[i] = pre[i - 1] + (a[i] == -1);
        FOR(i, 1, k) if(pre[ps[i].r] - pre[ps[i].l - 1] > D[i]) return 1;
        FOR(i, 1, k) D[i] -= pre[ps[i].r] - pre[ps[i].l - 1];
        return 0;
    }

    struct Node {
        int val, r;
        bool operator<(const Node&other) const {
            return val > other.val;
        }
    };

    vector<int> vec[N];
    int temp[N];
    void slv()
    {
        FOR(i, 1, k) {
            D[i] = (ps[i].r - ps[i].l + 1 - ps[i].val) / 2;
            if(ps[i].r - ps[i].l + 1 - ps[i].val < 0) {
                cout << "Impossible";
                return;
            }
        }

        if(isValid()) {
            cout << "Impossible";
            return;
        }

        FOR(i, 1, k) {
            vec[ps[i].l].push_back(i);
        }

        priority_queue<Node> pq;

        int offset = 0;
        FOR(i, 1, n) {
            for(int id : vec[i]) pq.push({D[id] + offset, ps[id].r});

           while(!pq.empty() && pq.top().r < i) pq.pop();

            if(a[i] != 0) continue;

            bool ok = 1;
            if(!pq.empty()) {
                int val = pq.top().val;
                if(val - offset < 1) ok = 0;
            }
            if(ok) a[i] = -1, offset++;
            else a[i] = 1;
        }

        FOR(i, 1, n) cout << a[i] << " ";
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
