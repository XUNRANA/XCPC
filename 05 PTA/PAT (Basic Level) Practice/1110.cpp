#include <bits/stdc++.h>
using namespace std;

int da[100000];
int ne[100000];
int h,n,k,a1,d1,n1;
void solve()
{
	cin>>h>>n>>k;
	while(n--)
	{
		cin>>a1>>d1>>n1;
		da[a1]=d1;
		ne[a1]=n1;
	}
	vector<int>a;
	while(h!=-1)
	{
		a.push_back(h);
		h=ne[h];
	}
	

	vector<int>ans,res;
	for(int j=0;j<a.size();j+=k) ans.push_back(j);
	reverse(ans.begin(),ans.end());
	
	for(auto i:ans)
	{
		for(int j=0;j<k;j++)
		{
			if(i+j<a.size()) res.push_back(a[i+j]);
		}
	}
//	for(auto i:res) cout<<i<<" ";
//	cout<<"\n";


	for(int i=0;i<res.size();i++)
	if(i!=res.size()-1) printf("%05d %d %05d\n",res[i],da[res[i]],res[i+1]);
	else printf("%05d %d %d\n",res[i],da[res[i]],-1);
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
