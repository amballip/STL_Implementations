#include<memory>
#include<iostream>
#include<initializer_list>

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

//********************************************Iterators****************************************************

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

		bool operator!=(const iterator rhs) const
		{
			return !(this->m_data == rhs.m_data);
		}

		iterator& operator = (const iterator& lhs)
		{
			this->m_data=lhs.m_data;
			return *this;
		}

		const std::shared_ptr<node<T>>& get() const
		{
			return m_data;
		}

	};

	iterator begin() const
	{
		return iterator(head);
	}

	iterator end() const
	{

		return iterator(nullptr);
	}



	struct const_iterator
	{
		private:
		std::shared_ptr<node<T>> m_data;


		public:

		//no default constructor. iterator must be initialized.
		const_iterator(std::shared_ptr<node<T>> current):m_data(current)
		{
		}

		//++ overload for incrementing in for loops
		const iterator& operator++() 
		{
			 this->m_data = this->m_data->m_next;
			 return *this;
		}

		const T& operator*() const
		{
			return (this->m_data->m_value);
		}

		bool operator!=(const iterator rhs) const
		{
			return !(this->m_data == rhs.m_data);
		}

		const iterator& operator = (const iterator& lhs)
		{
			this->m_data=lhs.m_data;
			return *this;
		}

		const std::shared_ptr<node<T>>& get() const
		{
			return m_data;
		}

	};

	const_iterator cbegin() const
	{
		return const_iterator(head);
	}

	const_iterator cend() const
	{
		return const_iterator(nullptr);
	}
	
	
//******************************************** Constructors ****************************************************

	// default constructor
	// forward_list<int> listA;

	forward_list():head(nullptr)
	{

	}

	forward_list(const forward_list& forwList)
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
//******************************************** Destructor  **********************************************


	~forward_list()
	{

	}

	
//******************************************** Member functions  *************************************************


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

	void insert_after(const iterator& it,T elem)
	{
		std::shared_ptr<node<T>> temp = std::make_shared<node<T>>();
		temp->m_value = elem;

		temp->m_next = it.get()->m_next;
		it.get()->m_next = temp;
	}

	void insert_after(const iterator& it,size_t n,T elem)
	{
		while(n--)
		{
			insert_after(it,elem);
			++it;
		}
	}

	void insert_after(const iterator& it, const iterator& start, const iterator& end)
	{
		iterator m_start = start;
		iterator m_end = end;

		while(m_start!=m_end)
		{
			insert_after(it,m_start.get()->m_value);
			++m_start;
		}
		
	}

	void assign(size_t count,T elem)
	{
		*this = forward_list(count,elem);
	}

	void assign(const iterator& begin,const iterator& end)
	{
		*this = forward_list(begin,end);
	}

	void assign(const std::initializer_list<T> initList)
	{
		*this  = forward_list(initList);
	}

	void swap(forward_list<T>& forwList)
	{
		std::shared_ptr<node<T>> temp = this->head;
		this->head = forwList.head;
		forwList.head = temp;
	}

	bool empty()
	{
		return head==nullptr;
	}

	T& front()
	{
		return this->head->m_value;
	}

	void pop_front()
	{
		head= head->m_next;
	}

	void clear()
	{
		head = nullptr;
	}

	void erase_after(const iterator it)
	{
		it.get()->m_next = it.get()->m_next->m_next;
	}


//******************************************** Operator Overloads  ***********************************************

	forward_list& operator=(const forward_list& rhs)
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

	forward_list& operator=(std::initializer_list<T> initList)
	{
		*this =  forward_list<T>(initList);
		return *this;
	}

	bool operator==(const forward_list& lhs)
	{
		bool equal = true;
		iterator rhsIt = this->head;
		iterator lhsIt = lhs.head;

		while(rhsIt!= this->end() && lhsIt!= lhs.end())
		{
			if(*rhsIt!=*lhsIt)
			{
				equal = false;
				break;
			}
				
			++rhsIt;
			++lhsIt;
		}

		if(rhsIt!= this->end() || lhsIt!= lhs.end())
			equal = false;

		return equal;

	}

	bool operator!=(const forward_list& lhs)
	{
		return !(*this==lhs);

	}



};

