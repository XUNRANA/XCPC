#include <iostream>
#include <map>
using namespace std;
void print(map<int,int>&m)
{
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++)
	cout<<"Key = "<<(*it).first<<", value = "<<it->second<<endl;
	cout<<endl;
}
void test()
{
	// key value
	map<int,int>m;    //插入对组 
	m.insert(pair<int,int>(1,10));//insert按key升序 
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int,int>(4,40));
	m.insert(pair<int,int>(2,20));
	print(m);
	
	map<int,int>m1(m);
	print(m1);
	
	map<int,int>m2;
	m2=m;
	print(m2);
	
	for(auto i:m) cout<<i.first<<" "<<i.second<<endl;
}
int main()
{
	test();
}
