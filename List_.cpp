#include<iostream>
#include"List_.h"

List_::List_()
{

}
List_::List_(const List_ &other)
{

}

void List_::print_(node* begin)
{
	node* temp = begin;
	if (temp != NULL)
	{
		temp = temp->next;
		while (temp)
		{
			std::cout << "List:" << temp->m_a << "  -->" << temp->next << "\n";
			temp = temp->next;
		}
	}
	else
	{
		std::cout << "List is Empty:\n";
	}
}

void List_::init(node* &begin, const int num, const int n)
{
	begin = new node;
	node* temp = begin;
	for (size_t i = 0; i < n; i++)
	{
		temp->next = new node;
		temp = temp->next;
		temp->m_a = num;
		temp->next = NULL;
	}
}

void List_::push_back_(node* &begin, const int num)
{
	node* temp = begin;
	node* m_new = new node;
	while (temp)
	{
		if(temp->next==NULL)
		{
			temp->next = m_new;
			m_new->m_a = num;
			m_new->next = NULL;
		}
		temp = temp->next;
	}

}

void List_::push_front_(node* &begin, const int num)
{
	node* temp = begin;
	node* m_new = new node;
	m_new->next = temp->next;
	temp->next = m_new;
	m_new->m_a = num;
}

void List_::insert_(node* &begin,const int num, const int n)
{
	int i = 0;
	node* temp = begin;
	node* temp1 = temp->next;
	node* m_new = new node;
	if (n == 0)
	{
		push_front_(begin, num);
		if (n == length(temp))
		{
			push_back_(begin, num);
		}
	}
	else
	{
		while (temp)
		{
			if (i == n)
			{
				m_new->next = temp->next;
				temp->next = m_new;
				m_new->m_a = num;
				break;
			}
			++i;
			temp1 = temp1->next;
			temp = temp->next;
		}
	}
}

void List_::pop_back(node* &begin)
{
	node* temp = begin;
	node* temp1 = temp->next;

	while (temp)
	{
		if(temp1->next==NULL)
		{
			delete temp1;
			temp->next = NULL;
			break;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}

}

void List_::pop_front(node* &begin)
{
	node* temp = begin;
	node* temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;
}

void List_::delete_(node* &begin,const int n)
{
	int i = 0;
	node* temp = begin;
	node* temp1 = temp->next;
	while (temp)
	{
		if(i==n)
		{
			temp->next = temp1->next;
			delete temp1;
			break;
		}
		i++;
		temp1 = temp1->next;
		temp = temp->next;
	}
}

void List_::del(node* &begin, const int n, const int count)
{
	int i = 0;
	int end_count = (count + n) + 1;
	node* temp = begin;
	node* end = begin;
	node* beg = begin;
	if (end_count > length(temp))
	{
		pop_back(begin);

		if (n == 0)
		{
			pop_front(begin);
		}
	}
	else
	{
		while (temp)
		{
			if (i == n)
				beg = temp;
			if (i == end_count)
				end = temp;
			++i;
			temp = temp->next;
		}
		temp = beg;
		beg->next = end;
		while (temp->next!=end)
		{
			node* temp1 = temp->next;
			temp->next = temp->next;
			delete temp1;
		}
	}
}

unsigned int List_::size_(node* begin)
{
	int n = 0;
	node* temp = begin->next;
	while (temp)
	{
		n += sizeof(temp->m_a);
		temp = temp->next;
	}
	return n;
}

unsigned int List_::length(node* begin)
{
	int n = 0;
	node* temp = begin;
	temp = temp->next;
	while (temp)
	{
		n++;
		temp = temp->next;
	}
	return n;
}
