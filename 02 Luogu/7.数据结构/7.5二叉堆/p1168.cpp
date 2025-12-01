#include <bits/stdc++.h>
using namespace std;
int n,t;
int ans[100010],j;
int main()
{
	cin>>n;
	vector<int>a;//vector
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		a.insert(lower_bound(a.begin(),a.end(),t),t);
		if(i%2==1) ans[j++]=a[(i-1)/2];
	}
	for(int i=0;i<j;i++) cout<<ans[i]<<" ";
}
