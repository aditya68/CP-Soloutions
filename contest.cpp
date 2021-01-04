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
#define endl '\n'
const int inf=2e9;
const int N=1e5+5;
int tre[N][10];
bool isnum[N];
int cnt=1;
bool Insert(string s)
{
    int t=0; bool is=1;
    for(int i=0;i<s.size();i++)
    {
        if(!tre[t][s[i]-'0'])tre[t][s[i]-'0']=cnt++;
        t=tre[t][s[i]-'0'];
        if(isnum[t])is=0;
    }
    isnum[t]=1;
    if(is)
    {
        for(int i=0;i<10;i++)
        {
            if(!tre[t][i])continue;
            is=0;
        }
    }
    return is;
}
void solve()
{
    int n; cin>>n;
    bool is=1;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        if(Insert(s))continue;
        is=0;
    }
    if(is)cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    memset(tre,0,sizeof(tre));
    memset(isnum,0,sizeof(isnum));
    cnt=1;
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
