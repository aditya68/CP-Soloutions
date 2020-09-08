#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
using namespace std;
void solve()
{
    int n,m;
    while(cin>>n>>m)
    {
      int a[m];
      for(int i=0;i<m;i++)cin>>a[i];
      int ans=0;
      for(int mask=1;mask<pow(2,m);mask++)
     {
        int s=0,num=1; bool p=1;
        for(int i=0;i<m;i++)
        {
            if(mask&(1<<i))
            {
                s++;
                num=num*a[i]/__gcd(num,a[i]);
                if(num>n)
                {
                    p=0;
                    break;
                }
            }
        }
        if(!p)continue;
        int q=n/num;
        if(s%2)ans+=q;
        else ans-=q;
    }
    ans=n-ans;
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
