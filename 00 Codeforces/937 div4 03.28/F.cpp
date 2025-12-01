#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a+1!=c) cout<<"-1\n";
	else if(a==0) cout<<b<<"\n";
	else 
	{
		int l=log2(a+1);
		int b1=0,d1=(1<<l);
		if(log2(a+1)!=(int)log2(a+1)) 
		{
			l++;
			b1=((1<<l)-1-a);
			d1=b1+((1<<(l-1))-b1)*2;
		}
		if(b1>=b) cout<<l<<"\n";
		else cout<<l+((b-b1)+d1-1)/d1<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
