#include <bits/stdc++.h>
using namespace std;
int n,t,ans;
//裴蜀定理：ax+by=m，其有解的充要条件为gcd（a，b）|m 
//逆定理：a,b是不全为0的整数，若d>0为a，b的公因数，且存在整数x，y使得ax+by=d,则d=gcd（a，b） 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t<0) t=-t;
		ans=__gcd(ans,t);
	}
	cout<<ans<<"\n";
}
