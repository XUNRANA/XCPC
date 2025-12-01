#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,a,b,c,d;
	vector<pair<int,int>>A,B;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b>>c>>d;
		if(c==d)
		{
			if(a<b) A.push_back({a,i});
			else B.push_back({b,i});
		}
		else if(c) A.push_back({a,i});
		else B.push_back({b,i});
	}
	


//8
// 9 11 0 1
// 1 8 0 1
// 15 7 1 0
// 3 13 1 1
// 6 12 0 1
// 16 5 1 0
// 4 2 1 0
// 10 14 1 0
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	cout<<A.size()<<" ";
	for(auto i:A) cout<<i.second<<" ";
	cout<<"\n";
	cout<<B.size()<<" ";
	for(auto i:B) cout<<i.second<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
