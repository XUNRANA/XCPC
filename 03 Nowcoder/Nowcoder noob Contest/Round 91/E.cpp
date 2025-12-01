#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,r1,r2,nxt[200010][26],ans;
string s;
int fd(int l,string t)
{
    char p;
	for(auto i:t) 
    {
        if(p==i)
        {
            l=nxt[l+1][i-'A'];
            continue;
        }
        l=nxt[l][i-'A'];
        p=i;
    }
	return l;
}
signed main()
{
	cin>>n>>k>>s;
	s="&"+s;
	for(int i=n+1;i>=1;i--)
	{
		for(int j=0;j<26;j++)
		{
			if(i==n+1) nxt[i][j]=n+1;
			else nxt[i][j]=nxt[i+1][j];
		}
		if(i!=n+1) nxt[i][s[i]-'A']=i;
	}
	for(int i=1;i<=n;i++)
	{
		r1=fd(i,"ACCEPT");
		r2=fd(i,"WA");
		if(r1==n+1||r1==0) continue;
		ans+=max(0ll,r2-max(r1,i+k-1));
	}
    cout<<ans;
}