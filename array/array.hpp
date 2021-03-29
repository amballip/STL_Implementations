#include<initializer_list>
#include<cstddef>
template <typename T , size_t _size>
class array
{

	private:
	T arr[_size];

	public:

	// default constructor
	// array<int ,10> arr;
	array()
	{
	}

	// constructor with initializer list
	// array <int , 10> arr = {0,1,2,3,4,5,6,7,8,9};
	// array <int , 10> arr1 ({0,1,2,3,4,5,6,7,8,9});
	// array <int , 10> arr1 ({0,1,2,3,4});  - sets arr1[5] to arr1[9] = 0 or int()
	array(std::initializer_list<T> arrList)
	{

		if(arrList.size() == _size)
		{
			size_t i = 0;
			for(typename std::initializer_list<T>::iterator it = arrList.begin();it!=arrList.end();it++)
			{
				arr[i]=*it;
				i++;
			}
		}
		else if(arrList.size()<_size)
		{
			size_t tempIndex = 0;
			typename std::initializer_list<T>::iterator it = arrList.begin();

			while(tempIndex !=_size)
			{
				if(it!=arrList.end())
				{
					arr[tempIndex] = *it;
					tempIndex++;
					it++;
				}
				else
				{
					arr[tempIndex] = T();
					tempIndex++;
				}
			}
		}

		else
		{
			constexpr bool i = _size<arrList.size();
			static_assert(i,"too many arguments");
		}
	}

	// destructor
	~array()
	{

	}

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

	//iterator functions

	iterator begin()
	{
		return iterator(&arr[0]);
	}

	iterator end()
	{
		return iterator(&arr[_size]);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(arr[_size-1]);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(arr[-1]);

	}

	const_iterator cbegin()
	{
		return const_iterator(arr[0]);
	}

	const_iterator cend()
	{
		return const_iterator(arr[_size]);
	}

	const_reverse_iterator crbegin()
	{
		return const_reverse_iterator(arr[size-1]);
	}
	
	const_reverse_iterator crend()
	{
		return const_reverse_iterator(arr[-1]);
	}

	//iterator implementations

	struct iterator
	{

		iterator(T* ptr = nullptr):m_ptr(ptr)
		{

		}

		T& operator*() const
		{
			return *m_ptr;
		}

		T& operator->()
		{
			return  m_ptr;
		}

		iterator& operator++()
		{
			m_ptr++;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			++(*this);
			return temp;
		}

		iterator operator+(size_t offset)
		{
			return iterator(m_ptr+offset);
		}

		bool operator==(const iterator& a)
		{
			return this->m_ptr == a.m_ptr;
		}

		bool operator != (const iterator& a)
		{
			return this->m_ptr != a.m_ptr;
		}



		private:
			T* m_ptr;

	};

	struct const_iterator
	{

		iterator(T* ptr = nullptr):m_ptr(ptr)
		{

		}

		T& operator*() const
		{
			return *m_ptr;
		}

		T& operator->()
		{
			return  m_ptr;
		}

		iterator& operator++()
		{
			m_ptr++;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			++(*this);
			return temp;
		}

		iterator operator+(size_t offset)
		{
			return iterator(m_ptr+offset);
		}

		bool operator==(const iterator& a)
		{
			return this->m_ptr == a.m_ptr;
		}

		bool operator != (const iterator& a)
		{
			return this->m_ptr != a.m_ptr;
		}



		private:
			T* m_ptr;

	};
	struct reverse_iterator
	{

		iterator(T* ptr = nullptr):m_ptr(ptr)
		{

		}

		T& operator*() const
		{
			return *m_ptr;
		}

		T& operator->()
		{
			return  m_ptr;
		}

		iterator& operator++()
		{
			m_ptr++;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			++(*this);
			return temp;
		}

		iterator operator+(size_t offset)
		{
			return iterator(m_ptr+offset);
		}

		bool operator==(const iterator& a)
		{
			return this->m_ptr == a.m_ptr;
		}

		bool operator != (const iterator& a)
		{
			return this->m_ptr != a.m_ptr;
		}



		private:
			T* m_ptr;

	};

	struct const_reverse_iterator
	{

		iterator(T* ptr = nullptr):m_ptr(ptr)
		{

		}

		T& operator*() const
		{
			return *m_ptr;
		}

		T& operator->()
		{
			return  m_ptr;
		}

		iterator& operator++()
		{
			m_ptr++;
			return *this;
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			++(*this);
			return temp;
		}

		iterator operator+(size_t offset)
		{
			return iterator(m_ptr+offset);
		}

		bool operator==(const iterator& a)
		{
			return this->m_ptr == a.m_ptr;
		}

		bool operator != (const iterator& a)
		{
			return this->m_ptr != a.m_ptr;
		}



		private:
			T* m_ptr;

	};


};
