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
	set<int>s1;
	s1.insert(1);
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	print(s1);     //set默认升序 
	
	s1.insert(4);  //set对于重复元素只储存一个 
	print(s1);
	
	set<int>s2(s1);
    print(s2);
    
    set<int>s3;
    s3=s2;
    print(s3);
}
int main()
{
	test();
}
