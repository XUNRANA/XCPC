#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string,int>&a,pair<string,int>&b)
{
	return a.second<b.second;
}
void solve()
{
	int n; 
	cin>>n;
	unordered_map<string,int> ump;
	while(n--)
	{
		string h; 
		int x; 
		cin>>h>>x;
		ump[h]+=x;
	}	
	for(auto &i:ump) i.second+=1000;
	vector<pair<string,int>>vmp(ump.begin(),ump.end()); 
	sort(vmp.begin(),vmp.end(),cmp);	
	cout<<vmp[0].first<<"\n"<<vmp[0].second;
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

