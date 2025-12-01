#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
#define P 1000000007
#define p 1331
int n,m,ans;
int dp[N],l[N],r[N];
string s,t;
void f1(int l,int r)
{
	dp[l]=1;
	map<char,int>mp;
	for(int i=l+1;i<r;i++)
	{
		dp[i]=2*dp[i-1]%P;
		if(mp.count(s[i])) dp[i]=(dp[i]-dp[mp[s[i]]-1]+P)%P;
		mp[s[i]]=i;
	}
	ans=dp[r-1];
}
void solve()
{
	cin>>n>>m>>s>>t;
	s="$"+s;
	t="$"+t;
    if(n<m)
    {
        cout<<"0\n";
        return ;
    }
    for(int i=1,j=1;i<=n;i++)
    {
        if(s[i]==t[j]) 
        {
            l[j]=i;
            j++;
        }
        if(j==m+1) break;
    }
    if(!l[m])
    {
        cout<<"0\n";
        return ;
    }
    for(int i=n,j=1;i>=1;i--)
    {
        if(s[i]==t[j]) 
        {
            r[j]=i;
            j++;
        }
        if(j==m+1) break;
    } 
    if(!r[m])
    {
        cout<<"0\n";
        return ;
    }
    if(l[m]<r[m]) f1(l[m],r[m]);
    int a=0,b=0,k=1;
    for(int i=1;i<=m;i++)
    {
        a=(a*p%P+(t[m+1-i]-'a'+1))%P;
        b=(b+k*(t[m+1-i]-'a'+1)%P)%P;
        k=k*p%P;
        //m+1-i----m
        if(a==b&&l[m+1-i-1]<r[m]) ans++;
    }
    cout<<ans%P<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
