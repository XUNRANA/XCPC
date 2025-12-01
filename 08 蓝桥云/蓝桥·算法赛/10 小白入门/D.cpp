#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
char a[2010][2010];
int f(int x,int y)
{
  int l=1;
  while(x-l>=1&&y-l>=1&&y+l<=m&&a[x-l][y-l]==a[x-l][y+l]&&a[x-l][y-l]=='*')
  {
    l++;
  }
  return l-1;
}
int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      cin>>a[i][j];
      if(a[i][j]=='*')
      {
        ans=max(ans,f(i,j));
      }
    }
  }
  cout<<ans<<"\n";
}
