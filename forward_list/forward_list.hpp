#include<memory>
#include<iostream>

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

//	bool operator==(std::shared_ptr<node<T>> lhs)
//	{
//		return this->m_value == lhs->m_value;
//	}

};

template<typename T>
class forward_list
{
	private:
	std::shared_ptr<node<T>> head;

	public:


	forward_list():head(nullptr)
	{

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

		bool operator!=(iterator rhs)
		{
			return !(this->m_data == rhs.m_data);
		}

		iterator& operator = (iterator& lhs)
		{
			this->m_data=lhs.m_data;
			return *this;
		}

	
	
	};


	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{

		return iterator(nullptr);
	}



			

};

