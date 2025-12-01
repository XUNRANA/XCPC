#include <bits/stdc++.h>
using namespace std;
long long t,n,q,l,r;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<long long>a(n+1),pre(n+1),post(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		pre[2]=post[n-1]=1;
		for(int i=3;i<=n;i++) 
		if(a[i]-a[i-1]<a[i-1]-a[i-2]) pre[i]=1;
		else pre[i]=a[i]-a[i-1];
		for(int i=n-2;i>=1;i--)
		if(a[i+1]-a[i]<a[i+2]-a[i+1]) post[i]=1;
		else post[i]=a[i+1]-a[i];
		
		for(int i=3;i<=n;i++) pre[i]+=pre[i-1];
		for(int i=n-2;i>=1;i--) post[i]+=post[i+1];
		
		cin>>q;
		while(q--)
		{
			cin>>l>>r;
			if(l<r) cout<<pre[r]-pre[l]<<"\n";
			else cout<<post[r]-post[l]<<"\n";
		}
	}	
}
