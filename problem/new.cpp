#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
const int N = 1e5 + 2;
const long long inf = 1e18 + 2;


int n, a[N], b[N];
void inp()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
}


bool check(long long maxSum)
{
    int l = 1, r = n;
    FOR(i, 1, n) {
        while(abs(a[i] + b[l]) > maxSum) l++;
        while(abs(a[i] + b[r]) > maxSum) r--;
        if(l <= r) return 1;
    }
    return 0;
}
void solve()
{
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    long long l = 0, r = inf, mid, ans = 0;
    while(l <= r) {
        mid = (r + l) >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);

    #define __Azul__ "qs"
    if(fopen(__Azul__".inp", "r")) {
        freopen(__Azul__".inp", "r", stdin);
        freopen(__Azul__".out", "w", stdout);
    }

    inp();
    solve();
}
