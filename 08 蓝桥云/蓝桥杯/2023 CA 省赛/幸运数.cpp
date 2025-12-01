#include <bits/stdc++.h>
using namespace std;
int is(int x,int p)
{
	int res=0,cnt=0,c1=0;
	while(x)
	{
		res+=x%10;
		x/=10;
		cnt++;
		if(cnt==p) c1=res;
	}
	if(c1*2==res) return 1;
	return 0;
}
int main()
{
	//2 4 6 8
	//9 
	int ans=9;
	for(int i=1000;i<10000;i++)
	{
		if(is(i,2)) ans++;
	}
	for(int i=100000;i<1000000;i++)
	{
		if(is(i,3)) ans++;
	}
	for(int i=10000000;i<100000000;i++)
	{
		if(is(i,4)) ans++;
	}
	cout<<ans;
}
