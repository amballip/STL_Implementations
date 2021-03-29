This is a simpler implementation of standard STL container `std::forward_list`

### Constructors

1. `forward_list();`
    * Parameters: None
    * Return value: None
    * Complexity: Constant
    * Note: Default constructor
    * examples

	  ```c++
      forward_list<int> intList;
	  ```	
  
2. `forward_list(const forward_list& forwList);`
    * Parameters: forwList - already created forward_list
    * Return value: None
    * Complexity: Linear - based on the size of the forwList
    * Note: copy constructor - copies all the elements from forwList into new list
    * examples

	  ```c++
      forward_list<int> intList(otherList);	
      forward_list<int> intList = otherList;
	  ```


3. `forward_list(size_t count,const T& value);`
    * Parameters: count- no of copies to be created, value - value of the copies
    * Return value: None
    * Complexity: linear - based on the count
    * Note: creates count copies of value elements
    * examples

		```c++
		forward_list<int> intList(5,3);	
		intList has {3,3,3,3,3}
		```

4. `explicit forward_list(size_t count);`
    * Parameters: unsigned integer count - no of copies to be created
    * Return value: None
    * Complexity: linear based on count
    * Note: creates count copies with default value T()
    * examples

		```c++
		forward_list<int> intList(5);
		//intList has {0,0,0,0,0}
		forwardList<std::string> strList(5);
		//intList has {"","","","",""}
		```

5. `forward_list(const std::initializer_list<T>& initList)
    * Parameters: initializer list containing elements of type T
    * Return value: None
    * Complexity: linear based on the size of initializer list
    * Note: creates a forward_list from elements of initializer list
    * examples
	
		```c++
		forward_list<int> intList({1,2,3,4,5});
		forward_list<int> intList = {1,2,3,4,5};
		```

6. `forward_list(const iterator& start,const iterator& end)`
    * Parameters: iterators start and end
    * Return value: None
    * Complexity: linear based on the distance between start and end
    * Note: creates a forward_list from range [start,end)
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,4,5,6};
		forward_list<int>::iterator start = intList.begin(),end = intList.begin();
		++end;
		++end;
		++end; // end is pointing to element with value 4
		forward_list<int> intListOther(start,end);
		//intListOther has {1,2,3};
		```






