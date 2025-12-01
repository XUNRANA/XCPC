#include <bits/stdc++.h>
using namespace std;
int main ()
{
	for(int k1=1;k1<=4;k1++)
	{
	cout<<k1<<"::\n";
	int n=k1,mi,mx;
	map<int,int>m;
    int a[]={0,1,2,3,4,5,6,7,8,9,10,11};
    do
    {
    	
    	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    	cout<<"\n";
    	
    	
    	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j+i-1<=n)
				{
					mx=1,mi=4;
					for(int k=i;k<=j+i-1;k++)
					{
						mx=max(mx,a[k]);
						mi=min(mi,a[k]);
					}
					if(mx-mi-j>=0) m[mx-mi-j]++;
				}
			}
		}
	}while(next_permutation(a+1,a+n+1));
	for(auto i:m) cout<<i.first<<" "<<i.second<<"\n";
	cout<<"\n\n\n";
	}
}
