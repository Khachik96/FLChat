struct node
{
	int m_a;
	node* next;
};
class List_
{
public:
	void init(node* &, const int,const int);
	void print_(node*);

	void push_back_(node* &,const int);
	void push_front_(node* &,const int);
	void insert_(node* &,const int,const int);

	void pop_back(node* &);
	void pop_front(node* &);
	void delete_(node* &,const int);
	void del(node* &,const int,const int);

	unsigned int size_(node*);
	unsigned int length(node*);

	List_();
	List_(const List_&);
};