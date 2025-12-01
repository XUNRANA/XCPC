#include <bits/stdc++.h>
using namespace std;
int n,f,a[1010],ans;
int main()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	if(!a[i]) ans^=i;
	else
	{
		set<int>s;
		f=0;
		for(int j=i;a[j];j=a[j])
		{
			if(s.count(j)) 
			{
				f=1;
				break;
			}
			else s.insert(j);
		}
		if(f==0) ans^=i;
	}
	cout<<ans<<'\n';
} 
