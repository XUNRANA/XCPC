#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,i;
}a[100010];
bool cmpx(node a1,node a2)
{
	if(a1.x==a2.x) return a1.i<a2.i;
	return a1.x>a2.x;
}
bool cmpi(node a1,node a2)
{
	return a1.i<a2.i;
}
int n,k,ans[100010],s;
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i].x,a[i].i=i;
	sort(a+1,a+1+n,cmpx);
	int j=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i].i-j>=0) s+=a[i].i-j;
		else 
		{
			for(int k=i+1;k<=n;k++)
			{
			
			}
		}
		if(s<=k) ans[j++]=a[i].x;
		else break;
	}
	for(int i=1;i<=n;i++) if(ans[i]) cout<<ans[i]<<" ";
	else cout<<-1<<" ";
	cout<<"\n";
	return 0;
}
/*
3 3
1 3 2
*/
