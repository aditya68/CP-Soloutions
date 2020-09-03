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
const int Max=1e18;
int tst=1;
int a[12],b[12];
int dp[12][12];
string s[12][12];
string f(int i,int j)
{
    if(dp[i][j]!=-1)return s[i][j];
    if(i==j)
    {
        char ch;
        if(i!=9)ch=i+'1';
        else ch='1';
        dp[i][j]=0;
        s[i][j]="A";
        s[i][j]+=ch;
        if(i==9)s[i][j]+="0";
     return s[i][j];
    }
    int cnt=Max;
    for(int k=i;k<j;k++)
    {
        int op=a[i]*b[k]*b[j];
        string s1=f(i,k);
        string s2=f(k+1,j);
        op+=dp[i][k]+dp[k+1][j];
        if(op<cnt)
        {
            s[i][j]="("+s1+" x "+s2+")";
            cnt=op;
        }
    }
  dp[i][j]=cnt;
return s[i][j];
}
void solve()
{
    while(1)
    {
        int n; cin>>n;
        if(!n)break;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        string ans=f(0,n-1);
        cout<<"Case "<<tst++<<": ";
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
