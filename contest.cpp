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
bool p[10000007];
void solve()
{
    for(int i=2;i*i<=1e7;i++)
    {
        if(!p[i])
        {
            for(int j=2*i;j<=1e7;j+=i)
                p[j]=1;
        }
    }
    int n;
    while(cin>>n)
    {
        if(n<8)
        {
            cout<<"Impossible."<<endl;
            continue;
        }
        if(n%2)
        {
            cout<<2<<" "<<3<<" ";
            n-=5;
        }
        else
        {
            cout<<2<<" "<<2<<" ";
            n-=4;
        }
        for(int i=2;i<=n/2;i++)
        {
            if(!p[i]&&!p[n-i])
            {
                cout<<i<<" "<<n-i<<endl;
                break;
            }
        }
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
