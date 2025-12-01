#include <bits/stdc++.h>
using namespace std;
int main()
{
	int l,r,t,c=0;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		t=i;
		while(t)
		{
			if(t%10==2) c++;
			t/=10;
		}
	}
	cout<<c;
}
