#include<initializer_list>

template <typename T , size_t _size>
class array{

	private:
	T arr[_size];

	void allocate()
	{
	
	} 

	public:

	// default constructor
	// array<int ,10> arr;
	array()
	{
	};

	// constructor with initializer list
	// array <int , 10> arr = {0,1,2,3,4,5,6,7,8,9};
	// array <int , 10> arr ({0,1,2,3,4,5,6,7,8,9});
	// 
	array(std::initializer_list<T> arrList)
	{

		size_t i = 0;
		for(typename std::initializer_list<T>::iterator it = arrList.begin();it!=arrList.end();it++)
		{
			arr[i]=*it;
			
			if(i == _size-1)
				break;

			i++;
		}
	};

	// destructor
	~array()
	{

	};

	// returns size of the array
	// size_t a = arr.size();
	// for(size_t i = 0;i<arr.size();i++)
	size_t size() const
	{
		return _size;
	}

	// subsript operator - both read and write
	// arr[1] = 10;
	// std::cout<<arr[1]<<std::endl;
	T& operator[](size_t index)
	{
		return arr[index];
	}
	
	// const subsript operator - only read and no write
	// arr[1] = 10; -invalid
	// std::cout<<arr[1]<<std::endl; - valid
	const T& operator[](size_t index) const
	{
		return arr[index];
	}


};
