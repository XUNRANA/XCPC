#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	char c;
	string s[2005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++)
    {
        cin>>c;
        if(i==1) s[j]=s[j-1]+c;
        else if(j==1) s[j]=s[j]+c;
        else s[j]=min(s[j],s[j-1])+c;
    }
	cout<<s[m];
}