#include <iostream>
#include <string>
using namespace std;
void insert_erase()
{
	string str="hello";
	cout<<str<<endl;
	str.insert(1,"111");
	cout<<str<<endl;
	str.erase(1,3);
	cout<<str<<endl;
}
int main()
{
	insert_erase();
}
