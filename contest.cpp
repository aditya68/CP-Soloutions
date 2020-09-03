#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
using namespace std;
const int Max=2e5+5;
int dp[505];
int p[105],f[105];
void solve()
{
    int n,m;
    while(cin>>n>>m)
    {
       int ans=0;
       for(int i=0;i<m;i++)cin>>p[i]>>f[i];
       for(int i=1;i<505;i++)dp[i]=Max;
       for(int i=0;i<m;i++)
       {
         for(int j=500;j>=0;j--)
         {
            if(j-f[i]<0)break;
            dp[j]=min(dp[j],dp[j-f[i]]+p[i]);
            if((dp[j]>2000&&dp[j]-200<=n)||dp[j]<n)ans=max(ans,j);
         }
      }
      cout<<ans<<endl;
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
