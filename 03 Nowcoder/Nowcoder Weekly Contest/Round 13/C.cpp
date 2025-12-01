#include <bits/stdc++.h>
using namespace std;
int c,c0,ca,cA,ans;
string s;
void solve()
{
	ans=c=c0=cA=ca=0;
	cin>>s;
	for(auto i:s)
	if(isdigit(i)) c0++;
	else if(isupper(i)) cA++;
	else if(islower(i)) ca++;
	else c++;
    
	for(auto i:s)
	{
		if(isdigit(i)) 
		{
			if(c0==1) ans+=9;
			else ans+=65;
		}
		else if(isupper(i))
		{
			if(cA==1) ans+=25;
			else ans+=65;
		}
		else if(islower(i)) 
		{
			if(ca==1) ans+=25;
			else ans+=65;
		}
		else 
		{
			if(c==1) ans+=3;
			else ans+=65;
		}
	}
	cout<<ans<<"\n";
//	cout<<c<<" "<<c0<<" "<<ca<<" "<<cA<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
