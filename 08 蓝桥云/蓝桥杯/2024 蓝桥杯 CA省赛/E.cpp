#include <bits/stdc++.h>
using namespace std;
double n,t,a[100010];
int k;
int main()
{
	cin>>n>>k>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+k+1);
	double p=0,res=0;
	for(int i=1;i<=k;i++) p+=a[i];
	for(int i=1;i<=k;i++) res+=(a[i]-p/k)*(a[i]-p/k);
	if(res<t*k) 
	{
		cout<<k<<"\n";
		return 0;
	}
	for(int i=k+1;i<=n;i++) 
	{
		sort(a+1,a+1+i);
		for(int j=1;j<=i-k+1;j++)
		{
			double p=0,res=0;
			for(int i1=j;i1<=j+k-1;i1++) p+=a[i1];
			for(int i1=j;i1<=j+k-1;i1++) res+=(p/k-a[i1])*(p/k-a[i1]);
			if(res<t*k) 
			{
				cout<<i<<"\n";
				return 0;
			}
		}
	}
	cout<<-1<<"\n";
	return 0;
}
