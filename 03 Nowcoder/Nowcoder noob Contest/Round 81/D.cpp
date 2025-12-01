#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int m,a,cnt=0;
		double ans=0;
		cin>>m>>a;
		for(int i=1;i<=m-a;i++)
        if(i%a==0||a%i==0) ans+=i,cnt++;
		if(ans/cnt>a) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
