#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k,cnt;
	cin>>n>>k;
	if(k==0) cout<<"0\n";
	else if(k<=n) cout<<"1\n";
	else
	{
		cnt=1;
		k-=n;	
		for(int i=n-1;i>=1;i--)
		{
			cnt++;
			k-=i;
			if(k<=0) break;
			cnt++;
			k-=i;
			if(k<=0) break;
 		}
 		cout<<cnt<<"\n";
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
