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
const int Max=2e9;
int n,pt[52];
int dp[52][52];
int f(int i,int j)
{
  if(j-i==1)
  {
      dp[i][j]=0;
      return 0;
  }
  if(dp[i][j]=!-1)return dp[i][j];
    int cnt=Max;
    for(int t=i+1;t<j;t++)
        cnt=min(cnt,f(i,t)+f(t,j));
    if(cnt==Max)cnt=0;
    else cnt+=pt[j]-pt[i];
    dp[i][j]=cnt;
 return dp[i][j];
}
void solve()
{
    while(1)
    {
        memset(dp,-1,sizeof(dp));
        int l; cin>>l;
        if(!l)break;
        cin>>n; pt[0]=0; pt[n+1]=l;
        for(int i=1;i<=n;i++)cin>>pt[i];
        int ans=f(0,n+1);
        cout<<"The minimum cutting is "<<ans<<"."<<endl;
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
