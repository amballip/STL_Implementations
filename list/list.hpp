#include<memory>
#include<iostream>

template<typename T>
struct node
{
    T value;
    std::shared_ptr<node<T>> next;

	node():value(T()),next(nullptr)
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

		while(temp->next!=nullptr)
		{
			std::cout<<temp->value<<"->";
			temp=temp->next;
		}

		std::cout<<temp->value;

		std::cout<<std::endl;

	}



			

};

