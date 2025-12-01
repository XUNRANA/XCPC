//N本书,第i本厚度Ai,分成M组，使最大一组的厚度最小
#include <bits/stdc++.h>
using namespace std; 
int n,m;
bool valid(int size,int *a)
{
	int group=1,rest=size;
	for(int i=1;i<=n;i++)
	{
		if(rest>=a[i]) rest-=a[i];
		else
		{
			group++;
			rest=size-a[i];
		}
	}
	return group<=m; 
}
int main()
{
	int sum=0;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n); 
	int l=0,mid,r=sum;
	while(l<r)
	{
		mid=l+(r-l)/2;
		if(valid(mid,a)) r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}
