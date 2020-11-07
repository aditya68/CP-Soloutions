#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define setpr(x) cout<<fixed<<setprecision(x)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,pii>
const int inf=1e9+7;
void solve()
{
    int n,k;
    while(cin>>n>>k)
    {
        int t[n];
    for(int i=0;i<n;i++)cin>>t[i];
    vi el[n],fl[100];
    string str;
    getline(cin, str);
    for(int i=0;i<n;i++)
    {
        getline(cin, str);
        stringstream ss;
        ss << str;
        int f;
        while(ss >> f)
        {
            el[i].pb(f);
            fl[f].pb(i);
        }
    }
    int c=1; map <pii,int> mp;
    for(int i=0;i<100;i++)for(int j=0;j<n;j++)mp[{i,j}]=c++;
    vii v[c+1];
    for(int i=0;i<fl[0].size();i++)
    {
        int elv=fl[0][i];
        int p2=mp[{0,elv}];
        v[0].pb({p2,0});
    }
    for(int i=0;i<fl[k].size();i++)
    {
        int elv=fl[k][i];
        int p1=mp[{k,elv}];
        v[p1].pb({c,0});
    }
    for(int i=0;i<100;i++)for(int j=0;j<n;j++)
    {
        int p1=mp[{i,j}];
        for(int k=0;k<el[j].size();k++)
        {
            int f=el[j][k];
            if(f==i)continue;
            int p2=mp[{f,j}];
            int tme=t[j]*abs(f-i);
            v[p1].pb({p2,tme});
        }
        for(int k=0;k<fl[i].size();k++)
        {
            int elv=fl[i][k];
            if(elv==j)continue;
            int p2=mp[{i,elv}];
            v[p1].pb({p2,60});
        }
    }
    int d[c+1];
    for(int i=0;i<=c;i++)d[i]=inf;
    set <pii> st;
    st.insert({0,0});
    d[0]=0;
    int ans=-1;
    while(!st.empty())
    {
        pii p=*st.begin();
        st.erase(st.begin());
        int tt=p.Y;
        if(tt==c)
        {
            ans=d[tt];
            break;
        }
        for(int i=0;i<v[tt].size();i++)
        {
            int ch=v[tt][i].X,wt=v[tt][i].Y;
            if(d[ch]>d[tt]+wt)
            {
                st.erase({d[ch],ch});
                d[ch]=d[tt]+wt;
                st.insert({d[ch],ch});
            }
        }
    }
    if(ans!=-1)cout<<ans<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
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
