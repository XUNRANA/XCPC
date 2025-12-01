#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int w,h,s;
	cin>>w>>h;
	s=w*h;	
	map<int,int>mw,mh;
	for(int i=2;i*i<=w;i++)
	{
		while(w%i==0)
		{
			mw[i]++;
			w/=i;
		}
	}
	if(w!=1) mw[w]++;
	
	for(int i=2;i*i<=h;i++)
	{
		while(h%i==0)
		{
			mh[i]++;
			h/=i;
		}
	}
	if(h!=1) mh[h]++;
	int ans=0;
	for(auto i:mw)
	{
		if(mh.count(i.first))
		{
			ans=s/(i.first*i.first);
			break;
		} 
	}
	cout<<ans<<'\n';
}
