#include <bits/stdc++.h>
using namespace std;
int main()
{
	double n,ans=1e10,x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		ans=min(ans,(x+1)/i);
	}
    printf("%.10f",ans);
}