#include <bits/stdc++.h>
long long t,n,m,cnt,a[200010],b[200010];
using namespace std;
int main()
{
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		/*
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<"\n";
		for(int i=1;i<=m;i++) cout<<b[i]<<" ";
		cout<<"\n";
		*/
		int l=1,r=n,i=1,j=m;
		while(l<=r)
		{
			if(abs(a[l]-b[j])>abs(a[r]-b[i])) cnt+=abs(a[l]-b[j]),l++,j--;
			else cnt+=abs(a[r]-b[i]),r--,i++;
			//cout<<cnt<<"\n";
		}
		cout<<cnt<<"\n";
	}
}
