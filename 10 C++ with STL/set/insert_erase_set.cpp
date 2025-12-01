#include <iostream>
#include <set>
using namespace std;
void print(set<int>&s)
{
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	cout<<*it<<" ";
	cout<<endl;
}
void test()
{
	set<int>s;
	s.insert(10);
	s.insert(200);
	s.insert(30);
	s.insert(4);
	print(s);
	
	s.erase(s.begin());
	print(s);
	
	s.erase(200);
	print(s);	
	
	s.clear();  //Çå¿Õ µÈÓÚs.erase(s.begin(),s.end()); 
	print(s);
}
int main()
{
	test();
}
