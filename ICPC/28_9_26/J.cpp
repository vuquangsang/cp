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

const int N = 20;

int n;
string str[N];
void inp()
{   
    cin >> n;
    FOR(i, 1, n) cin >> str[i];
}

namespace sub1
{
    int dp[N][(1 << 16) + 2];

    int size(string T)
    {
        return T.size();
    }

    vector<pair<string, int>> vec[N];
    int preMax[(1 << 16) + 2];
    void slv()
    {
        memset(dp, -0x3f, sizeof dp);

        FOR(i, 1, n) {
            int sz = size(str[i]);
            FOR(msk, 1, (1 << sz) - 1) {
                string T = "";
                FOR(j, 0, sz - 1) if(msk >> j & 1) {
                    T += str[i][j];
                }
                vec[i].push_back({T, msk});
            }
        }

        FOR(i, 1, n) sort(all(vec[i]));

        int maxSize = 0;
        FOR(i, 1, n) maxi(maxSize, (int)str[i].size()); 
        FOR(i, 1, n) {
            int sz = str[i].size();
            
            int j = -1, maxAns = -1e9;
            for(pair<string, int> x : vec[i]) {
                string S = x.first; int msk = x.second;
                int number = __builtin_popcount(msk);
                
                if(i == 1) dp[i][msk] = number;
                else {
                    while(j + 1 < vec[i - 1].size() && vec[i - 1][j + 1].first < S) {
                        j++;
                        int subMsk = vec[i - 1][j].second;
                        maxi(maxAns, dp[i - 1][subMsk]);
                    }
                }
                if(j != -1) maxi(dp[i][msk], maxAns + number);
            }
        }
        int res = 0;
        FOR(msk, 1, (1 << size(str[n])) - 1) {
            maxi(res, dp[n][msk]);
        }
        cout << (!res ? -1 : res);
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