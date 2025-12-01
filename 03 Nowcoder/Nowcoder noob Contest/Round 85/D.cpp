#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[100005],i,n,m,t,jj=0;
	long long sum=0,b[100005];
	cin>>n>>m;
	t=m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=n;i>=1;i--) b[i]=b[i+1]+a[i];
	for(i=1;i<=n;i++)
    {
		m-=a[i];
		if(m<=0)
        {
            cout<<"NO";
            return 0;
		}
		if(a[i]==0)
        {
			if(m<=b[i+1])
            {
				sum+=t-m;
				m=t;
			}
		}
	}
	cout<<n-1+sum;
}