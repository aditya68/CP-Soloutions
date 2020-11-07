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
int tst=1;
void solve()
{
    int n,m,stt,ed; cin>>n>>m>>stt>>ed;
    vii v[n];
    for(int i=0;i<m;i++)
    {
        int a,b,wt; cin>>a>>b>>wt;
        v[a].pb({b,wt});
        v[b].pb({a,wt});
    }
    int d[n];
    for(int i=0;i<n;i++)d[i]=inf;
    set <pii> st;
    st.insert({0,stt});
    d[stt]=0;
    while(!st.empty())
    {
        pii p=*st.begin();
        st.erase(st.begin());
        int t=p.Y;
        if(t==ed)
        {
            cout<<"Case #"<<tst++<<": "<<d[t]<<endl;
            return;
        }
        for(int i=0;i<v[t].size();i++)
        {
            int ch=v[t][i].X,wt=v[t][i].Y;
            if(d[ch]>d[t]+wt)
            {
                st.erase({d[ch],ch});
                d[ch]=d[t]+wt;
                st.insert({d[ch],ch});
            }
        }
    }
    cout<<"Case #"<<tst++<<": unreachable"<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--)solve();
    return 0;
}
