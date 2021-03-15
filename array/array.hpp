template <typename T , size_t _size>
class array{

	private:
	int m_size;

	void allocate()
	{
		T arr[m_size];
	
	} 

	public:

	array():m_size(_size)
	{
		allocate();
	};


	~array()
	{

	};

	size_t size()
	{
		return m_size;
	}


};
