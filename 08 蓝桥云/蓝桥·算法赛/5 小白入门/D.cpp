#include <iostream>
using namespace std;
int c1,c2,t,n;
int main()
{
  cin>>n;
  for(int i=1;i<=2*n;i++) 
  {
    cin>>t;
    if(i&1)
    {
      if(t!=1) c1++;
      if(t!=0) c2++;
    }
    else
    {
      if(t!=0) c1++;
      if(t!=1) c2++;
    }
  }
  cout<<min(c1,c2)/2;
}
