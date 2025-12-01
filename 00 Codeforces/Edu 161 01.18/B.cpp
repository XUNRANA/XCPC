#include <bits/stdc++.h>
using namespace std;
long long t,n,t1,ans,s;
long long f(long long m,long long n)
{
	long long res=1,fz=1;
	for(int i=1;i<=m;i++) fz*=i,res*=(n-i+1); 
	return res/fz;
}
int main()
{
	cin>>t;
	while(t--)
	{
		ans=s=0;
		cin>>n;
		map<int,int>m;
		for(int i=1;i<=n;i++)
		{
			cin>>t1;
			m[t1]++;
		} 
		for(auto i:m) 
		{
			if(i.second==2) ans+=s;
			if(i.second>=3) 
			{
				ans+=f(3,i.second);
				ans+=f(2,i.second)*s;
			}
			s+=i.second;
		}
		cout<<ans<<"\n";
	}
	/*1 2 4 8 16 32*/
} 
