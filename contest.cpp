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
int ca,cb,n;
pii f(pii p1,int st)
{
    if(st==0)return {ca,p1.Y};
    else if(st==1)return {p1.X,cb};
    else if(st==2)return {0,p1.Y};
    else if(st==3)return {p1.X,0};
    else if(st==4)
    {
        if(p1.X<=cb-p1.Y)return {0,p1.X+p1.Y};
        else return {p1.X+p1.Y-cb,cb};
    }
    else
    {
        if(p1.Y<=ca-p1.X)return {p1.X+p1.Y,0};
        else return {ca,p1.X+p1.Y-ca};
    }
}
void solve()
{
    while(cin>>ca>>cb>>n)
    {
        map <pii,pii> pr;
        map <pii,bool> vis;
        queue <pii> q;
        q.push({0,0});
        vis[{0,0}]=1;
        pr[{0,0}]={-1,-1};
        pii p;
        while(!q.empty())
        {
            pii p1=q.front();
            q.pop();
            if(p1.Y==n)
            {
                p=p1;
                break;
            }
            for(int i=0;i<6;i++)
            {
                pii p2=f(p1,i);
                if(vis[p2])continue;
                q.push(p2);
                pr[p2]=p1;
                vis[p2]=1;
            }
        }
        vii ans;
        while(p.X!=-1)
        {
            ans.pb(p);
            p=pr[p];
        }
        reverse(all(ans));
        pii pre=make_pair(0,0);
        for(int i=1;i<ans.size();i++)
        {
            pii cur=ans[i]; int pos;
            for(int j=0;j<6;j++)if(cur==f(pre,j))pos=j;
            if(pos==0)cout<<"fill A";
            else if(pos==1)cout<<"fill B";
            else if(pos==2)cout<<"empty A";
            else if(pos==3)cout<<"empty B";
            else if(pos==4)cout<<"pour A B";
            else cout<<"pour B A";
            cout<<endl;
            pre=cur;
        }
        cout<<"success"<<endl;
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    setpr(3);
    int t; t=1;
    while(t--)solve();
    return 0;
}
