#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,a,b) for(int i = a;i <= b;i ++)
#define frd(i,a,b) for(int i = a;i >= b; i --)
#define pb push_back
#define fi first
#define se second
#define el '\n'
template <class X, class Y> bool minimize(X &x, const Y &y) {if (x > y) {x = y;return true;} else return false;}
template <class X, class Y> bool maximize(X &x, const Y &y) {if (x < y) {x = y;return true;} else return false;}
 
string s;
 
const int N = 2005;
// int dp[N][N];
 
// int min_change(string x,string y){
//     int _n = x.size();
//     int _m = y.size();
 
//     fr(i,0,_n) fr(j,0,_m) dp[i][j] = 1e9;
//     fr(i,0,_n) dp[i][0] = i;
//     fr(i,0,_m) dp[0][i] = i;
 
//     fr(i,1,_n){
//         fr(j,1,_m){
//             if(x[i - 1] == y[j - 1]) dp[i][j] = dp[i-1][j-1];
//             else{
//                 dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i - 1][j - 1]});
//             }
//         }
//     }
 
//     return dp[_n][_m];
// }
 
 
signed main(){
    ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #define TASK "qn"
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
 
    cin >> s;
 
    int cnt0 = 0;
    int n = s.size();
 
    fr(i,0,s.size() - 1) cnt0 += (s[i] == '0');
 
    if(cnt0 < n - cnt0){
        fr(i,0,s.size() - 1) cout << 0;
    }
    else if(cnt0 > n - cnt0){
        fr(i,0,s.size() - 1) cout << 1;
    }
    else{
        if(s[0] == '1'){
            cout << 0;
            fr(i,1,s.size() - 1) cout << 1;
        }
        else{
            cout << 1;
            fr(i,1,s.size() - 1) cout << 0;
        }
    }
    return 0;
}
