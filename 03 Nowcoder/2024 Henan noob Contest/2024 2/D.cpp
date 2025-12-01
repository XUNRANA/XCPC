#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string a,b,ans;
	cin>>a>>b;
	reverse(a.begin(),a.end());
	int cur=0,temp=0;
	for(int i=0;i<a.size()+b.size();i++)
	{
		if(i<a.size()) cur+=a[i]-'0';
		if(i>=b.size()) cur-=a[i-b.size()]-'0';
		temp+=cur*(b[0]-'0');
		ans.push_back(temp%10+'0');
		temp/=10;
	}
	while(ans.size()>1&&ans.back()=='0') ans.pop_back();
	reverse(begin(ans),end(ans));
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
