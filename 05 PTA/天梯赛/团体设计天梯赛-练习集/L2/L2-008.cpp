#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s,p;
int fx(int i,int j)
{
	int z=n-j+1;
	for(int k=i;k<=j;k++)
	{
		if(s[k]!=p[z]) return 0;
		z++;
	}
	return 1;
}
void solve()
{
	getline(cin,s);
	p=s;
	reverse(s.begin(),s.end());
	n=s.size();
	s=" "+s;
	p=" "+p;
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(fx(i,j))
			{
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
#define P1 131
int h1[1010];
int h2[1010];
int p1[1010];
int g1(int i,int j)
{
	return (h1[j]-h1[i]*p1[j-i]%P+P)%P;
}
int g2(int i,int j)
{
	return (h2[j]-h2[i]*p1[j-i]%P+P)%P;
}
void solve()
{
	string s,p;
	getline(cin,s);
	p=s;
	reverse(s.begin(),s.end());
	int n=s.size();
	s=" "+s;
	p=" "+p;
	h1[0]=h2[0]=p1[0]=1;
	for(int i=1;i<=n;i++)
	{
		p1[i]=p1[i-1]*P1%P;
		h1[i]=(h1[i-1]*P1%P+s[i])%P;
		h2[i]=(h2[i-1]*P1%P+p[i])%P;
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(g1(i,j)==g2(n-j+1,n-i+1))
			{
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
*/



