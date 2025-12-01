#include <bits/stdc++.h>
using namespace std;
int a[6];
void solve()
{
	for(int i=1;i<=5;i++) cin>>a[i];
	int ans=0;
	
	ans+=a[3]/2;
	a[3]%=2;

	int t=min(a[2],a[4]);
	ans+=t;
	a[2]-=t;
	a[4]-=t;

	int l=1;
	while(a[5]&&l<=5)
	{
		if(l!=5)
		{
			t=min(a[5],a[l]);
			a[5]-=t;
			a[l]-=t;
			ans+=t;
		}
		else
		{
			t=a[5]/2;
			a[5]-=t;
			ans+=t;
		}
		l++;
	}


	// 2 2 2

	ans+=a[2]/3;
	a[2]%=3;
	
	//3最多1个 、2最多2个
	if(a[3]&&a[2])
	{
		if(a[1])//1 2 3
		{
			a[3]--;
			a[2]--;
			a[1]--;
			ans++;
		}
		else
		{
			if(a[2]>1)// 2(1) 2 3
			{
				a[3]--;
				a[2]-=2;
				ans++;
			}
		}
	}

	l=1;
	while(a[4]&&l<=4)
	{
		if(l==4)
		{
			ans+=a[4]/3;
		}
		else
		{
			t=min(a[4],a[l]/2);
			a[4]-=t;
			a[l]-=2*t;
			ans+=t;
			if(a[l]==1)
			{
				a[l+1]++;
				a[l]=0;
			}
		}
		l++;
	}

	ans+=(a[1]+a[2]*2+a[3]*3)/6;
	cout<<ans<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
