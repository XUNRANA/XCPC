#include <bits/stdc++.h>
using namespace std;
int c[1000010];
int main()
{
	int n,x,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		mx=max(mx,x);//最大能力值
		int m=sqrt(x);
		for(int i=1;i<=m;i++)
		if(x%i==0)
		{
			c[i]++;
			if(x!=i*i) c[x/i]++;
		}  
	}
	for(int i=0;i<=mx;i++) cout<<c[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		while(c[mx]<i) mx--;
		cout<<mx<<endl;
	}
}
