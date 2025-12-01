#include <bits/stdc++.h>
using namespace std;
int t,n;
string s; 
int main()
{
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int sum[35]={0};
    cin>>n>>s;
    for(int j=0;j<n-1;j++)
    {  
      int x,y;
      cin>>x>>y;
      if(s[x-1]==s[y-1]) {sum[x]++;sum[y]++;}
    }
    int flag=0;
    for(int i=1;i<=n;i++) if(sum[i]>=2) flag=1;
    if(flag==1) cout<<"NO\n";
    else cout<<"YES\n";
  }
}
