#include <bits/stdc++.h>
using namespace std;

int n;
int c[5];
int t[7];
bool ck(int x)
{
	int s=0;
	for(int i=0;i<4;i++)
	{
		if(!(x>>i&1)) s+=c[i+1]; 
	}
	
	int w=t[5]+t[6];
	
	for(int i=0;i<4;i++)
	{
		if(x>>i&1)
		{
			int need=5-c[i+1];
			
			if(t[i+1])
			{
				int c=min({need,3,s});
				need-=c;
				s-=c;
			}
			
			if(need)
			{
				int c=min({w,s,need});
				need-=c;
				w-=c;
				s-=c;
			}
			if(need) return 0;
		}
	}
	
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=4;i++) c[i]=0;
	
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s[1]=='D') c[1]++;
		else if(s[1]=='C') c[2]++;
		else if(s[1]=='H') c[3]++;
		else c[4]++;
	}
	
	for(int i=1;i<=6;i++) cin>>t[i];
	
	int ans=0;
	for(int i=1;i<=4;i++) ans+=c[i]/5,c[i]%=5;
	
//	cout<<ans<<"\n";
	int res=0;
	for(int i=1;i<(1<<4);i++)
	{
		if(ck(i))
		{
			int cnt=0;
			for(int j=0;j<4;j++)
			{
				if(i>>j&1) cnt++;
			}
			res=max(res,cnt);
		}
	}
	cout<<ans+res<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
