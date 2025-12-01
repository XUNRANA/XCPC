#include <bits/stdc++.h> 
using namespace std;
int n,a[1001],ans,res,cnt,p;
int main()
{
	cin>>n;
	set<int>st;
	for(int i=1;i<=n;i++) cin>>a[i],st.insert(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==p) cnt++;
		else cnt=1;
		p=a[i];
		res=max(res,cnt);
	}
	for(auto i:st)
	{
		p=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i) continue;
			if(a[j]==p) cnt++;
			else cnt=1;
			p=a[j];
			ans=max(ans,cnt);
		}
	}
	cout<<ans-res<<"\n";
}
