#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,x;
	cin>>n>>x;
	int i=0;
	vector<int>a;
	while(i<n)
	{
		int f=0;
		for(int j=29;j>=0;j--) if(!(x>>j&1)&&(i>>j&1)) f=1;
		if(f) break;
		a.push_back(i);
		i++;
	}
	while(a.size()<n) a.push_back(x);
	int res=0;
	for(auto i:a) res|=i;
	if(res!=x)
	{
		a.pop_back();
		a.push_back(x);
	}
	for(auto i:a) cout<<i<<" ";
	cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
