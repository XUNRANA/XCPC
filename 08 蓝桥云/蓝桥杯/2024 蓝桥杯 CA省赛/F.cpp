#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int i1=1;i1<=n;i1++)
			{
				if(i1==i||i1==j) continue;
				if(a[i]%a[i1]==0||a[i1]%a[i]==0)
				{
					for(int j1=1;j1<=n;j1++)
					{
						if(j1==i||j1==j||j1==i1) continue;
						if(a[j]%a[j1]==0||a[j1]%a[j]==0) ans++;
					}
				} 
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5 
3 6 2 2 7

*/
