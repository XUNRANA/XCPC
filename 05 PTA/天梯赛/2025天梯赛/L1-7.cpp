#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int j,int i)
{
	int res=1;
	for(int c=1;c<=i;c++) res=res*j;
	return res;
}
vector<int>ans;
bool ck(int i,int n)
{
	int j=1;
	ans.clear();
	while(n>=fx(j,i))
	{
		ans.push_back(j);
		n-=fx(j,i);
		j++;
	}
	if(n==0) return 1;
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=30;i>=1;i--)
	{
		if(ck(i,n)) 
		{
			int f=0;
			for(auto j:ans)
			{
				if(f) cout<<"^"<<i<<"+";
				cout<<j;
				f=1;
			}
			cout<<"^"<<i;
			cout<<"\n";
			return ;
		}
	}
	cout<<"Impossible for "<<n<<".";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
