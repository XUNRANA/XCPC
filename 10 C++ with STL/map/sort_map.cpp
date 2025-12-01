#include <iostream>
#include <map>
using namespace std;
class cmp
{
	public:
		bool operator()(int v1,int v2)
		{
			return v1>v2;
		}
		
};
void test()
{
	map<int,int,cmp>m;
	
	m.insert(make_pair(2,20));
	m.insert(make_pair(1,10));
	m.insert(make_pair(2,30));
	m.insert(make_pair(3,30));
	
	for(map<int,int,cmp>::iterator it=m.begin();it!=m.end();it++)
	cout<<"Key = "<<it->first<<" Value = "<<it->second<<endl;
}
int main()
{
	test();
} 
