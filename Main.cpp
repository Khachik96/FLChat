#include "List_.h"
#include<iostream>
int main()
{
	int m = 0;
	int b = 0;
	List_ ob;
	node* el;
	ob.init(el, 2, 7);
	ob.print_(el);
	m = ob.length(el);
	b = ob.size_(el);
	std::cout << "\n\nm="<<m<<"\nb="<<b<<"\n";
	ob.push_back_(el, -58);
	ob.insert_(el, 11,5);
	ob.print_(el);
	m = ob.length(el);
	b = ob.size_(el);
	std::cout << "\n\nm="<<m<<"\nb="<<b<<"\n";

	system("pause");
}