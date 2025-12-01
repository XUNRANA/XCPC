#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	string sn=to_string(n);
	int len=sn.size(); 
	vector<pair<int,int>>ans;
	for(int a=1;a<=10000;a++)
	{
		int mib=max(1,len*a-5);
		int mxb=len*a;
//		cout<<a<<" "<<mib<<" "<<mxb<<"\n";
		for(int b=mib;b<mxb;b++)
		{
			int x=n*a-b;
			int y=0;
			for(int i=0;i<len*a-b;i++)
			y=y*10+(sn[i%len]-'0');
			if(x==y) ans.push_back({a,b});
		}
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
}

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
