#include <bits/stdc++.h>
using namespace std;
int a[]={13,1,2,3,5,4,4,2,2,2};
int b[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int f(int y,int m,int d)
{
	int res=0;
	res+=a[y%10];
	y/=10;
	res+=a[y%10];
	y/=10;
	res+=a[y%10];
	y/=10;
	res+=a[y%10];
	y/=10;
	
	res+=a[m%10];
	m/=10;
	res+=a[m%10];
	m/=10;
	
	res+=a[d%10];
	d/=10;
	res+=a[d%10];
	d/=10;
	return res;
}
int main()
{
	int ans=0,s=0;
	for(int i=2000;i<=2023;i++)
	{
		for(int j=1;j<=12;j++)
		{
			for(int d=1;d<=b[j];d++)
			{
				s++;
				
				if(f(i,j,d)>50) ans++;//cout<<i<<" "<<j<<" "<<d<<"\n";
			}
			if(j==2&&(i==2000||i==2004||i==2008||i==2012||i==2016||i==2020||i==2024))
			{
				s++;
				if(f(i,j,29)>50) ans++;//cout<<i<<" "<<j<<" "<<29<<"\n";
			}
		}
	}
	
	int i=2024;
	for(int j=1;j<=3;j++)
	{
		
		for(int d=1;d<=b[j];d++)
		{
			s++;
		//	cout<<i<<" "<<j<<" "<<d<<"\n";
			if(f(i,j,d)>50) ans++;//cout<<i<<" "<<j<<" "<<d<<"\n";
		}
		if(j==2&&(i==2000||i==2004||i==2008||i==2012||i==2016||i==2020||i==2024))
		{
			s++;
		//	cout<<i<<" "<<j<<" "<<29<<"\n";
			if(f(i,j,29)>50) ans++;//cout<<i<<" "<<j<<" "<<29<<"\n";
		}
	}
	 
	 
	i=2024;
	int j=4;
	for(int d=1;d<=13;d++)
	{
		s++;
		if(f(i,j,d)>50) ans++;
	//	else cout<<f(i,j,d)<<" "<<i<<" "<<j<<" "<<d<<"\n";
	}
	cout<<ans<<"\n";
//	cout<<s<<"\n";
	
}
