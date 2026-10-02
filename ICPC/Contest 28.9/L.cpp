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

const int N = 65;

long long K;
string s;
int n;
void inp()
{
    cin >> K >> s;
    reverse(all(s));
    s = ' ' + s;
    n = s.size() - 1;
}

namespace sub1
{
    bool isDel[N];
    vector<int> pos;
    ll calc(string str)
    {
        int n = str.size() - 1;
        ll total = 0;
        FOR(i, 1, n) {
            if(str[i] == '1') total += (1LL << (i - 1));
        }
        return total;
    }
    void slv()
    {
        if(calc(s) < K) {
            cout << 0;
            return;
        }

        int ans = 0;
        FOR(i, 0, 61) {
            if((1LL << i) > K) {
                ans = i; break;
            }
        }
        ans = max(0, n - ans);
        FORD(i, n - 1, 1) {
            if(!ans) break;
            if(s[i] == '1') isDel[i] = 1, ans--;
        }
        int j = n - 1;
        while(ans) {
            if(!isDel[j]) isDel[j] = 1, ans--;
            j--;
            if(j < 0) break;
        }
        ans = 0;
        string str = " ";

        FOR(i, 1, n) {
            if(isDel[i]) ans++;
            else str += s[i];
        }


        if(calc(str) <= K) {
            cout << ans;
        }
        else {
            int sz = str.size() - 1;
            int j = sz - 1;
            string suf = "1";
            str.erase(sz, 1);

            while(1) {
                if(str[j] == '1') ans++;
                else suf = '0' + suf;
                str.pop_back();
                j--;
                if(calc(str + suf) <= K) {
                    cout << ans; return;
                }
                if(j < 1) break;
            }
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
