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
const int N=5e5+5;
int tre[N][26];
bool isword[N];
int cnt=1;
vector <string> ans;
void Insert(string s)
{
    int t=0;
    for(int i=0;i<s.size();i++)
    {
       if(!tre[t][s[i]-'a'])tre[t][s[i]-'a']=cnt++;
       t=tre[t][s[i]-'a'];
    }
    isword[t]=1;
    return;
}
void dfs(int t,string s)
{
    if(isword[t])ans.pb(s);
    for(int i=0;i<26;i++)
    {
        int ch=tre[t][i];
        if(!ch)continue;
        char chh='a'+i;
        dfs(ch,s+chh);
    }
    return;
}
bool Find(string s)
{
    int t=0; bool is=1;
    for(int i=0;i<s.size();i++)
    {
        if(!tre[t][s[i]-'a'])
        {
            is=0;
            break;
        }
        t=tre[t][s[i]-'a'];
    }
    if(!is)return 0;
    for(int i=0;i<26;i++)
    {
        if(!tre[t][i])continue;
        char chh='a'+i;
        dfs(tre[t][i],s+chh);
    }
    if(ans.empty())return 0;
   return 1;
}
void solve()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        Insert(s);
    }
    int k,tst=1; cin>>k;
    while(k--)
    {
        string s; cin>>s;
        cout<<"Case #"<<tst++<<":"<<endl;
        if(!Find(s))
        {
            cout<<"No match."<<endl;
            continue;
        }
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
        ans.clear();
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
