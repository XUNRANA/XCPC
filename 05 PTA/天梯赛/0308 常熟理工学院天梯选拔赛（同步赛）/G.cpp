#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	if(count(s.begin(),s.end(),'8')==0||count(s.begin(),s.end(),'3')==0) 
	{
		cout<<"0\n";
		return ;
	}
	
	
	//888888888888888888888888888888888888888883
	int l=s.find('3');
	int r=s.rfind('3');
	
	int ans=0;
	if(l!=r) ans=s.size()-1-l;
	else ans=s.size()-1-(l+1);
	ans=max(ans,0);
	cout<<ans<<"\n";
//	cout<<l<<" "<<r<<"\n";
//	88883..........388888888888
//	[3,8]
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

