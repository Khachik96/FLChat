#include"List_.h"

int main()
{
	List_<int> ob(5,2);
	ob.push_back_(4);
	ob.push_back_(-7);
	ob.push_front_(-36);
	ob.print_();
	std::cout << "########\n";
	//ob.del(0, 6);
	List_<int> p;
	p=ob.reverse();
	p.print_();
	system("pause");
}