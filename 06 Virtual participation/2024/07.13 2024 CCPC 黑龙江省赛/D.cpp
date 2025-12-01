#include <bits/stdc++.h>
using namespace std;
int n,t,ha,hb,ca,cb;
void solve()
{
	cin>>n>>ha>>hb;
	vector<int>a,b;
	ca=cb=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		if(t==-1) ca++;
		else a.push_back(t);
 	}
 	
 	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		if(t==-1) cb++;
		else b.push_back(t);
 	}
 	sort(a.begin(),a.end());
 	for(int i=0;i<a.size()/2;i++) swap(a[i],a[a.size()-1-i]);
 	sort(b.begin(),b.end());
 	
 	
 	for(int i=0;i<min(a.size(),b.size());i++)
 	{
 		hb-=a[i];
 		ha-=b[i];
 		if(ha<=0||hb<=0) break; 
	}
	if(ha>0&&hb<=0) cout<<"yes\n";
	else cout<<"no\n";
	
	 /*
 	for(auto i:a) cout<<i<<" ";
 	cout<<"\n";
 	
 	for(auto i:b) cout<<i<<" ";
 	cout<<"\n";
 	*/
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
} 
