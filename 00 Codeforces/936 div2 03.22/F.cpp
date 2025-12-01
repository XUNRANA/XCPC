#include <bits/stdc++.h>
using namespace std;
int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0};
vector<vector<int> >ans;
vector<int>path;
int v[20];
void dfs(int l)
{
	if(l==14)
	{
		ans.push_back(path);
		return ;
	}
	
	for(int i=1;i<=14;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			path.push_back(i);
			dfs(l+1);
			v[i]=0;
			path.pop_back();
		}
	}
}
int main()
{
	dfs(0);
	cout<<ans.size()<<"\n";
	/*
	for(auto i:ans)
	{
		for(auto j:i) cout<<j<<" ";
		cout<<"\n";
	}
	*/
}
