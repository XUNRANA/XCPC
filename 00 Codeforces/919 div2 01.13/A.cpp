#include <bits/stdc++.h>
using namespace std;
long long t,n,i,mx,mi,f,t1,a[110],ans;
int main()
{
    cin>>t;
	while(t--)
	{
		cin>>n>>a;
		i=1,mx=1,mi=1e9;
		while(n--)
		{
			cin>>f>>t1;
			if(f==1) mx=max(mx,t1);
			else if(f==2) mi=min(mi,t1);
			else a[i++]=t1;
		}
		ans=mi-mx+1;
		for(int j=1;j<i;j++) if(a[j]>=mx&&a[j]<=mi) ans--;
		cout<<max(ans,0ll)<<"\n";
	} 
	
}
