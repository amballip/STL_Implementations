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

	protected:
	std::shared_ptr<node<T>> head;
	std::shared_ptr<node<T>> beforeHead;


	void createHead(const T& value)
	{
		createBeforeHead();
		head= std::make_shared<node<T>>();
		head->m_value = value;
		beforeHead->m_next = head;
	}
	void createBeforeHead()
	{
		beforeHead = std::make_shared<node<T>>();
	}
	
	public:

//******************************************** Iterators ****************************************************

	struct iterator
	{
		private:
		std::shared_ptr<node<T>> m_data;


		public:

		iterator(std::shared_ptr<node<T>> current):m_data(current)
		{
		}

		iterator operator++()
		{
			 this->m_data = this->m_data->m_next;
			 return *this;
		}

		T& operator*()
		{
			return (this->m_data->m_value);
		}

		const T& operator*() const
		{
			return (this->m_data->m_value); } 
		bool operator!=(const iterator rhs) const
		{
			return !(this->m_data == rhs.m_data);
		}

		bool operator==(const iterator rhs) const
		{
			return this->m_data == rhs.m_data;
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

	iterator before_begin()
	{
		return iterator(beforeHead);
	}



	struct const_iterator
	{
		private:
		std::shared_ptr<node<T>> m_data;


		public:

		const_iterator(std::shared_ptr<node<T>> current):m_data(current)
		{
		}

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

	const_iterator cbefore_begin()
	{
		return const_iterator(beforeHead);
	}
	
	
//******************************************** Constructors ****************************************************


	forward_list():head(nullptr)
	{
		createBeforeHead();

	}

	forward_list(const forward_list& forwList)
	{
		*this = forwList;

	}

	forward_list(size_t count,T elem = T())
	{
		createHead(elem);
		iterator it = begin();
		--count;
		while(count--)
		{
			insert_after(it,elem);
			++it;
		}

	}


	forward_list(const std::initializer_list<T>& initList)
	{
		typename std::initializer_list<T>::iterator it= initList.begin();
		createHead(*it);
		++it;
		iterator thisIt = iterator(head);

		while(it!=initList.end())
		{
			insert_after(thisIt,*it);
			++it;
			++thisIt;
		}


	}

	forward_list(const iterator& itA,const iterator& itB)
	{
		createHead(*itA);
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
		if(head==nullptr)
		{
			std::cout<<"list is empty"<<std::endl;
		}
		else
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

	}

	void push_front(T value)
	{
		if(head==nullptr)
		{
			createHead(value);
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
		if(it==iterator(beforeHead) && head==nullptr)
		{
			createHead(elem);
		}
		else if(it==iterator(beforeHead) && head!=nullptr)
		{
			std::shared_ptr<node<T>> temp = std::make_shared<node<T>>();
			temp->m_value = elem;

			temp->m_next = head;
			head = temp;
		}
		else
		{
			std::shared_ptr<node<T>> temp = std::make_shared<node<T>>();
			temp->m_value = elem;

			temp->m_next = it.get()->m_next;
			it.get()->m_next = temp;
		}
	}

	void insert_after(const iterator& it,size_t n,T elem)
	{
		forward_list<int>::iterator m_it = it;
		while(n--)
		{
			insert_after(it,elem);
			++m_it;
		}
	}

	void insert_after(const iterator& it, const iterator& start, const iterator& end)
	{
		iterator m_current = it;
		iterator m_start = start;
		iterator m_end = end;

		while(m_start!=m_end)
		{
			insert_after(m_current,m_start.get()->m_value);
			++m_start;
			++m_current;
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

	void splice_after(iterator current,
					  forward_list<T>& forwList,
					  iterator begin,
					  iterator end)
	{
		if(begin==end || begin.get()->m_next == end.get())
		{
			return;
		}
		else 
		{
			if(current==this->before_begin())
				this->head = begin.get()->m_next;
			if(begin==forwList.before_begin())
				forwList.head = end.get();
	
			iterator it =begin;

			while(it.get()->m_next!=end.get())
			{
				++it;
			}

			std::shared_ptr<node<T>> temp = current.get()->m_next;
			current.get()->m_next = begin.get()->m_next;
			begin.get()->m_next=end.get();
			it.get()->m_next = temp;
		}	
	}

	void splice_after(iterator current,forward_list<int>& forwList)
	{
		splice_after(current,forwList,forwList.before_begin(),forwList.end());
	}

	void splice_after(iterator current,forward_list<int>& forwList,iterator end)
	{
		iterator it = forwList.before_begin();
		iterator itNext = it.get()->m_next;

		if(it ==end || it==forwList.begin())
		{
			return;
		}
		else
		{
			while(itNext.get()->m_next!=end.get())
			{
				++it;
				++itNext;
			}

			this->splice_after(current,forwList,it,end);
		}

	}

	void merge(forward_list<T>& forwList)
	{
		iterator curr= this->begin();
		iterator prev= this->before_begin();

		while(curr!=this->end() && !forwList.empty())
		{
			if(*curr <= forwList.head->m_value)
			{
				splice_after(curr,forwList,forwList.head->m_next);
				++curr;
				if(curr.get()->m_next!=this->end().get())
				{
					++curr;
				}
				else
				{
					break;
				}
				prev.get()->m_next = curr.get();
				
			}
			else
			{
				splice_after(prev,forwList,forwList.head->m_next);
				if(curr.get()->m_next!=this->end().get())
				{
					++curr;
				}
				else
				{
					break;
				}
				prev.get()->m_next = curr.get();
			}
			
		}

		while(forwList.head!=nullptr)
		{
			splice_after(curr,forwList,forwList.head->m_next);
			++curr;
		}

	}

	void reverse()
	{
		std::shared_ptr<node<T>> prev = this->before_begin().get();
		std::shared_ptr<node<T>> current = prev->m_next;
		std::shared_ptr<node<T>> next  = current->m_next;

		while(next!=this->end().get())
		{
			current->m_next = next->m_next;
			next->m_next= prev->m_next;
			prev->m_next = next;

			next = current->m_next;
		}

		head = prev->m_next;
		current->m_next = nullptr;
		beforeHead->m_next = head;

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
		if(it==iterator(beforeHead))
		{
			head = head->m_next;
			beforeHead->m_next = head;

		}
		else
		{
			it.get()->m_next = it.get()->m_next->m_next;
		}
	}


//******************************************** Operator Overloads  ***********************************************

	forward_list& operator=(const forward_list& rhs)
	{
		this->createHead(rhs.head->m_value);

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

