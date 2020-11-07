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
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n,m,ans;
char ch[30][30];
bool valid(int i,int j)
{
    if(i<0||i>=n||j<0||j>=m)return 0;
    if(ch[i][j]=='X'||ch[i][j]=='S')return 0;
    return 1;
}
void solve()
{
    while(1)
 {
    cin>>m>>n;
    if(!m)return;
    int rw,cl;
    map <pii,int> mp;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    {
        cin>>ch[i][j];
        if(ch[i][j]=='S')
        {
            rw=i;
            cl=j;
         }
         mp[{i,j}]=inf;
    }

    set <pi> st;
    st.insert({0,{rw,cl}});
    mp[{rw,cl}]=0;
    while(!st.empty())
    {
        pi p=*st.begin();
        st.erase(st.begin());
        int r1=p.Y.X,cl1=p.Y.Y,val=p.X;
        if(ch[r1][cl1]=='D')
        {
            ans=mp[{r1,cl1}];
            break;
        }
        for(int i=0;i<4;i++)
        {
            int r2=r1+dx[i];
            int cl2=cl1+dy[i];
            int wt;
            if(!valid(r2,cl2))continue;
            if(ch[r2][cl2]=='D')wt=0;
            else wt=ch[r2][cl2]-'0';
            if(mp[{r2,cl2}]>mp[{r1,cl1}]+wt)
            {
                  st.erase({mp[{r2,cl2}],{r2,cl2}});
                  mp[{r2,cl2}]=mp[{r1,cl1}]+wt;
                  st.insert({mp[{r2,cl2}],{r2,cl2}});
            }
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
