#include <bits/stdc++.h>
using namespace std;
struct node
{
  int a,b;
}c[100010];
int main()
{
  int n,cnt=1;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>c[i].a>>c[i].b;
  for(int i=2;i<=n;i++)
  {
    if(c[i].a!=c[i-1].a||c[i].b!=c[i-1].b) cnt++;
  }
  cout<<cnt;
}
