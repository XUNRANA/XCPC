#include <bits/stdc++.h>
using namespace std;
void divide(int n)
{
	int p[n],cnt[n]={0};
	int i,j=1;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			p[j++]=i;
			while(n%i==0)
			{
				cnt[j-1]++;
				n/=i;
			}
		}
	}
	if(n>0) p[j++]=n,cnt[j-1]=1;
	for(i=1;i<j-1;i++) cout<<"("<<p[i]<<"^"<<cnt[i]<<")*";
	cout<<"("<<p[i]<<"^"<<cnt[i]<<")\n";
}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++) cout<<i<<" ",divide(i);
}
