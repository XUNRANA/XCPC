#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define int long long
int n,a[N],odd[N],ol,even[N],el,ans[N];
map<int,int>cnt[2],tmp[2];
signed main()
{
	cin>>n;	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt[a[i]&1][a[i]]++;
		if(a[i]%2==0) odd[++ol]=a[i];
		else even[++el]=a[i];
	}
	sort(even+1,even+el+1,greater<int>());
	sort(odd+1,odd+ol+1);
	for(int i=el,j=ol;i>=1;i++)
	{
		
		
	}
}  
