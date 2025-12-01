#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s,x,ans,p,y,a[200010],index;
void solve()
{
	s=0;
	index=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<a[1]+k<<"\n";
		return ;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) 
	{
		if(a[i]*(i-1)-s==k)
		{
			int j=i;
			while(a[j]==a[i]&&j<=n) j++;
			cout<<(a[i])*n-(n-1)+n-j+1<<"\n";
			return ;
		}
		else if(a[i]*(i-1)-s>k) 
		{
			index=i-1;
			break;
		}
		s+=a[i];
	}
	if(index==-1)
	{
		ans=(((k+s)/n)*n-(n-1))+(k+s)%n;
	}
	else
	{
		p=(s+k)/index;
		y=(s+k)%index;
		int j=index;
		while(a[j]==a[index]&&j<=n) j++;
		ans=p*n-(n-1)+n-j+1+y;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
