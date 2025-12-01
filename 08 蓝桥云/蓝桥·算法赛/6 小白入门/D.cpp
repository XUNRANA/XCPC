#include <iostream>
using namespace std;
long long t,x;
int main()
{
  cin>>t;
  while(t--)
  {
    cin>>x;
    if(x%4==0&&x/4%2==0&&x>4)
    {
      cout<<"Yes\n";
      cout<<x/4-1<<" "<<x/4+1<<"\n";
    }
    else cout<<"No\n";
  }
}
