#include<iostream>
template<class T1>
struct node
{
	T1 m_a;
	node<T1> *next;
};
template<class T1>
class List_
{
private:
	node<T1> *element;
public:
	void init(const T1, const int);
	void print_()const;

	void push_back_(const T1);
	void push_front_(const T1);
	void insert_(const T1, const int);

	void pop_back();
	void pop_front();
	void delete_(const int);
	void del(const int, const int);
	void clear();

	node<T1>* reverse();
	void Make_Zero();
	unsigned int size_()const;
	unsigned int length_()const;



	int &operator[](int);
	node<T1>* &operator=(node<T1>*);
	List_();
	List_(const List_&);
	List_(const T1);
	List_(const T1, const int);
};


template<class T1>
List_<T1>::List_()
{
	element= NULL;
	element= 0;
}
template<class T1>
List_<T1>::List_(const T1 num)
{
	init(num, 1);
}
template<class T1>
List_<T1>::List_(const T1 num, const int n)
{
	init(num, n);
}
template<class T1>
List_<T1>::List_(const List_ &other)
{
	element = other.element;
}

template<class T1>
void List_<T1>::print_() const
{
	int i = 0;
	node<T1>* temp = element;
	if (temp != NULL && length_()!=0)
	{
		temp = temp->next;
		while (temp)
		{
			std::cout << "List[" << i << "] :" << temp->m_a << "  -->" << temp->next << "\n";
			temp = temp->next;
			++i;
		}
	}
	else
	{
		std::cout << "List is Empty:\n";
	}
}

template<class T1>
void List_<T1>::init(const T1 num, const int n)
{
	element = new node<T1>;
	node<T1> *temp = element;
	for (size_t i = 0; i < n; i++)
	{
		temp->next = new node<T1>;
		temp = temp->next;
		temp->m_a = num;
		temp->next = NULL;
	}
}

template<class T1>
void List_<T1>::push_back_(const T1 num)
{
	node<T1>* temp = element;
	node<T1>* m_new = new node<T1>;
	while (temp)
	{
		if (temp->next == NULL)
		{
			temp->next = m_new;
			m_new->m_a = num;
			m_new->next = NULL;
		}
		temp = temp->next;
	}
}

template<class T1>
void List_<T1>::push_front_(const T1 num)
{
	node<T1>* temp = element;
	node<T1>* m_new = new node<T1>;
	m_new->next = temp->next;
	temp->next = m_new;
	m_new->m_a = num;
}

template<class T1>
void List_<T1>::insert_(const T1 num, const int n)
{
	int i = 0;
	node<T1>* temp = element;
	node<T1>* temp1 = temp->next;
	node<T1>* m_new = new node<T1>;
	if (n == 0)
	{
		push_front_(num);
		if (n == length_())
		{
			push_back_(num);
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

template<class T1>
void List_<T1>::pop_back()
{
	node<T1>* temp = element;
	node<T1>* temp1 = temp->next;

	while (temp)
	{
		if (temp1->next == NULL)
		{
			delete temp1;
			temp->next = NULL;
			break;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}

}

template<class T1>
void List_<T1>::pop_front()
{
	node<T1>* temp = element;
	node<T1>* temp1 = temp->next;
	temp->next = temp1->next;
	delete temp1;
}

template<class T1>
void List_<T1>::delete_(const int n)
{
	int i = 0;
	node<T1>* temp = element;
	node<T1>* temp1 = temp->next;
	while (temp)
	{
		if (i == n)
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

template<class T1>
void List_<T1>::del(const int n, const int count)
{
	int i = 0;
	int end_count = (count + n)+1;

	node<T1>* temp = element;
	if (temp != NULL)
	{
		node<T1>* end = element;
		node<T1>* beg = element;
		if (end_count > length_())
		{
			pop_back();

			if (n == 0)
			{
				pop_front();
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
			while (temp->next != end)
			{
				node<T1>* temp1 = temp->next;
				temp->next = temp->next;
				delete temp1;
			}
			pop_back();
		}
	}
}

template<class T1>
void List_<T1>::clear()
{
	const int _size = length_()-1;
	del(0, _size);
}

template<class T1>
unsigned int List_<T1>::size_()const
{
	int n = 0;
	node<T1>* temp = element->next;
	while (temp)
	{
		n += sizeof(temp->m_a);
		temp = temp->next;
	}
	return n;
}

template<class T1>
unsigned int List_<T1>::length_()const
{
	int n = 0;
	node<T1>* temp = element;
	if (temp == NULL)
		return 0;
	temp = temp->next;
	while (temp)
	{
		n++;
		temp = temp->next;
	}
	return n;
}
template<class T1>
int& List_<T1>::operator[](int j)
{
	int i = 0;
	node<T1>* temp = element->next;
	if (j < length())
	{
		while (temp)
		{
			if (i == j)
			{
				return temp->m_a;
			}
			++i;
			temp = temp->next;
		}
	}
	else
	{
		std::cout << "error index:" << j << "\n";
	}

}

template<class T1>
node<T1>* &List_<T1>::operator=(node<T1>* el)
{
	return el;
}

template<class T1>
void List_<T1>::Make_Zero()
{
	node<T1>* temp = element;
	while (temp)
	{
		temp->m_a = 0;
		temp = temp->next;
	}
}
