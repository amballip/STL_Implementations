#include<memory>
#include<iostream>
#include<initializer_list>
#include<algorithm>

template<typename T>
struct node
{
    T m_value;
    std::shared_ptr<node<T>> m_next;

	node():m_value(T()),m_next(nullptr)
	{
	}

	~node()
	{
	}

};

template<typename T>
class forward_list
{
	private:
	// head node. singly linked list starts with head
	std::shared_ptr<node<T>> head;
	
	public:

	//iterator declaration
	struct iterator
	{
		private:
		std::shared_ptr<node<T>> m_data;


		public:

		//no default constructor. iterator must be initialized.
		iterator(std::shared_ptr<node<T>> current):m_data(current)
		{
		}

		//++ overload for incrementing in for loops
		iterator operator++()
		{
			 this->m_data = this->m_data->m_next;
			 return *this;
		}

		T& operator*()
		{
			return (this->m_data->m_value);
		}

		bool operator!=(iterator rhs)
		{
			return !(this->m_data == rhs.m_data);
		}

		iterator& operator = (iterator& lhs)
		{
			this->m_data=lhs.m_data;
			return *this;
		}

		std::shared_ptr<node<T>> get()
		{
			return m_data;
		}

	};

	// default constructor
	// forward_list<int> listA;
	forward_list():head(nullptr)
	{

	}


	forward_list(forward_list& forwList)
	{
		*this = forwList;

	}

	forward_list(size_t count,T elem = T())
	{
		head = std::make_shared<node<T>>();
		head->m_value = elem;
		iterator it = begin();
		--count;
		while(count--)
		{
			insert_after(it,elem);
			++it;
		}

	}


	forward_list(std::initializer_list<T> initList)
	{
		head = std::make_shared<node<T>>();
		typename std::initializer_list<T>::iterator it= initList.begin();
		head->m_value = *it;
		++it;
		iterator thisIt = iterator(head);

		while(it!=initList.end())
		{
			insert_after(thisIt,*it);
			++it;
			++thisIt;
		}


	}

	forward_list(iterator& itA,iterator& itB)
	{
		head = std::make_shared<node<T>>();
		head->m_value = *itA;

		iterator itRhs(this->head);
		iterator itLhs = itA.get()->m_next;
		
		while(itLhs!=itB)
		{
			this->insert_after(itRhs,itLhs.get()->m_value);
			++itRhs;
			++itLhs;
		}
	}


	
	~forward_list()
	{

	}


	void printList()
	{
		std::shared_ptr<node<T>> temp = head;

		while(temp->m_next!=nullptr)
		{
			std::cout<<temp->m_value<<"->";
			temp=temp->m_next;
		}

		std::cout<<temp->m_value;

		std::cout<<std::endl;

	}

	void push_front(T value)
	{
		if(head==nullptr)
		{
			head = std::make_shared<node<T>>();
			head->m_value = value;
		}
		else
		{
			std::shared_ptr<node<T>> temp = std::make_shared<node<T>>();
			temp -> m_value = value;

			temp->m_next = head;
			head = temp;
		}

	}

	void insert_after(iterator& it,T elem)
	{
		std::shared_ptr<node<T>> temp = std::make_shared<node<T>>();
		temp->m_value = elem;

		it.get()->m_next = temp;
	}

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{

		return iterator(nullptr);
	}

	forward_list& operator=(forward_list& rhs)
	{
		this->head = std::make_shared<node<T>>();
		this->head->m_value = rhs.head->m_value;

		iterator lhsIt(this->head);
		iterator rhsIt(rhs.head->m_next);

		while(rhsIt!=rhs.end())
		{
			this->insert_after(lhsIt,rhsIt.get()->m_value);
			++lhsIt;
			++rhsIt;
		}

		return *this;

	}



};
