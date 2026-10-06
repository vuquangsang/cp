#include <bits/stdc++.h>
#define ll long long
//#define int long long
#define pb push_back
#define fi first
#define se second
#define MASK(i) (1ll<<(i))
#define c_bit(i) __builtin_popcountll(i)
#define FOR(i, a, b)    for (int i = (int)(a), lim(b); i <= lim; i++)
#define FORD(i, a, b)   for (int i = (int)(a); i >= (int)(b); i--)
#define BIT(x,i) (((x) >> (i)) & 1)
#define set_on(x,i) ((x) | MASK(i))
#define set_off(x,i) ((x) & ~MASK(i))
#define TASK "deche"
using namespace std;
ll gcd(ll a,ll b){return __gcd(a,b);}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

bool minimize(int &x, const int &y)
{
    if (x > y)
    {
        x = y;
        return 1;
    }
    return 0;
}
bool maximize(int &x, const int &y)
{
    if (x < y)
    {
        x = y;
        return 1;
    }
    return 0;
}

const int N = 1e5 + 5, M = 5e5 + 5, sm = 1e9 + 3, base = 31;
void add(int &x, const int &y){x += y; if (x >= sm)    x-=sm;}
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, -1, 0, 1};

string s;

void doc()
{
    cin>>s;
}

namespace sub1
{
    void xuly()
    {
        bool dd = 0, ok = 0 ;
        int cnt = 0;
        string res = "";
        for (int i = 0; i < s.size(); i ++)
        {
            char c = s[i];
            if (c != '(' && c != ')')   ok = 1;
            if (c == '+' && dd == 0)    
            {
                res += '-';
                continue;
            }
            if (c == '-' && dd == 1)    
            {
                res += '+';
                continue;
            }
            if (c == '(' && ok)   
            {
                dd = 1;
                cnt ++;
            }
            if (c == ')')
            {
                if (cnt) cnt --;
                if (!cnt) dd = 0;
            }
            res += c;
        }
        cout<<res;
    }
}


signed main()
{
    if (fopen("INP.INP","r"))
    {
        freopen("INP.INP","r",stdin);
        freopen("INP.OUT","w",stdout);
    }
    if (fopen(TASK".INP","r"))
    {
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int mtt = 0, test=1;
    if (mtt)    cin>>test;
    while (test --)
    {
        doc();
        sub1::xuly();
    }


}