#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,b,ans,res,sum,p[1010],s[1010];
struct node
{
	int sum,sub;
}a[1010];
bool cmp(node a1,node a2)
{
	if(a1.sum==a2.sum) return a1.sub>a2.sub;
	return a1.sum<a2.sum;
}
signed main()
{
	cin>>n>>b;
	ans=n;
	for(int i=1;i<=n;i++) cin>>p[i]>>s[i],a[i].sum=p[i]+s[i],a[i].sub=p[i]/2+s[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) 
	{
		if(sum+a[i].sum>b) 
		{
			ans=i-1;
			break;
		}
		res=max(a[i].sum-a[i].sub,res);
		sum+=a[i].sum;
	}
	if(ans==n)
	{
		cout<<n<<"\n";
		return 0;
	}
	int k=b-sum;
	for(int i=ans+1;i<=n;i++) 
	if(k>=a[i].sub)
	{
		ans++;
		break;
	}
	else if(k+res>=a[i].sum)
	{
		ans++;
		k=k+res-a[i].sum;
		for(int j=ans+1;j<=n;j++)
		{
			if(j==i) continue;
			if(k>=a[j].sum)
			{
				k-=a[j].sum;
				ans++;
			}
			else break;
		}
	}
	cout<<ans<<'\n';
}
/*
5 45
6 3
2 8
10 2
1 2
12 5
*/
