#include <bits/stdc++.h> 
using namespace std;
#define int long long
int n,ans,a[100010],b[100010],l,r,c,lf,ri,m;
int ck(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++) 
	if(b[i]<=x)
	{
		if(b[i]<=l)
		{		
			cnt+=max(x/a[i]-l/a[i]-1,0ll);
			if(x/a[i]==l/a[i])
			{
				if(l%a[i]<=b[i]%a[i]&&x%a[i]>=b[i]%a[i]) cnt++;
			}
			else 
			{			
				if(l%a[i]<=b[i]%a[i]) cnt++;
				if(x%a[i]>=b[i]%a[i]) cnt++;
			}
		}
		else cnt+=(x-b[i])/a[i]+1;
		
		if(cnt>=c) return 1;
	}
	return 0;
}
signed main( )
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];//周期 
	for(int i=1;i<=n;i++) cin>>b[i];//开始 
	cin>>l>>r>>c;
	lf=l,ri=2e18;
	while(lf<=ri)
	{
		m=lf+ri>>1;
		if(ck(m)) ri=m-1;
		else lf=m+1;
	}
	if(lf<=r) cout<<lf<<"\n";
	else cout<<"-1\n";
}
