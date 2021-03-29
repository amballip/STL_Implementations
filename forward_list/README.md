This is a simpler implementation of standard STL container `std::forward_list`

No support for 

1. Move constructors or move semantics
2. Allocators
3. Iterators currently cant work with std::algorithm

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
	  forward_list<int> otherList = {1,2,3,4,5};
      forward_list<int> intList(otherList);	
      forward_list<int> intList = otherList;
	  // can be called with empty lists
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

5. `forward_list(const std::initializer_list<T>& initList);`
    * Parameters: initializer list containing elements of type T
    * Return value: None
    * Complexity: linear based on the size of initializer list
    * Note: creates a forward_list from elements of initializer list
    * examples
	
		```c++
		forward_list<int> intList({1,2,3,4,5});
		forward_list<int> intList({}); // empty initializer list
		forward_list<int> intList = {1,2,3,4,5};
		forward_list<int> intList = {};
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

### Member functions

1. `void push_front(const T& value);`
    * Parameters: value of type T
    * Return value: None
    * Complexity: constant
    * Note: addes existing value to the start of the list. No new elements are created
    * examples

		```c++
		forward_list<int> intList;
		intList.push_front(10);
		intList.push_front(9);
		intList.push_front(8);
		// initList has now {8,9,10}
		```
2. `void pop_front();`
    * Parameters: None
    * Return value: None
    * Complexity: constant
    * Note: removes first element from forward_list
    * examples

		```c++
		forward_list<int> intList = {1,2,3};
		intList.pop_front();
		//intList has now {2,3}
		```

3. `void merge(forward_list<T>& forwList);`
    * Parameters: forward list to be merged
    * Return value: None
    * Complexity: linear
    * Note: merges two sorted list. parameter forwList will be empty after merge. only pointers are moved.
    * examples

		```c++
		forward_list<int> intList = {1,3,5,7,9};
		forward_list<int> other = {2,4,6,8};
		intList.merge(other);
		//intList has {1,2,3,4,5,6,7,8,9}
		// other.empty() returs true
		```
4. `void reverse()
    * Parameters: None
    * Return value: None
    * Complexity: linear
    * Note: reverses the forward_list. only pointers are changed. Actual data is untouched.
    * examples

		```c++
		forward_list<int> intList = {1,2,3,4,5};
		intList.reverse();
		//intList has now {5,4,3,2,1};

5. `bool empty() const`
    * Parameters: None
    * Return value: bool
    * Complexity: constant
    * Note: returns if the forward_list is empty
    * examples

		```c++
		forward_list<int> emptyList;
		emptyList.empty(); // returns true
		forward_list<int> intList = {1,2,3};
		intList.emtpty(); // return false;
		```

6. `T& front();`

	`const T& front() const;`
    * Parameters: None
    * Return value: value of the first element. 
    * Complexity: constant
    * Note: returns value of the first element. read and write.
    * examples

		```c++
		forward_list<int> intList= {1,2};
		int b = intList.front(); // read
		intList.front() = 3;
		// intList has now {3,2};
		```
7. `void swap(forward_list<T>& forwList);`
    * Parameters: forward_list which needs to be swaped with
    * Return value: None
    * Complexity: constant
    * Note: swaps current foward_list with forwList. just changing pointers so complexity is constant
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3};
		forward_list<int> other = {7,8,9};
		intList.swap(other);
		// intList has now {7,8,9};
		// other has now {1,2,3};
		```
	
8. `void insert_after(const iterator& pos,size_t n,const T& value)`
    * Parameters:iterator after which element needs to be added and value to add 
    * Return value: None
    * Complexity: constant
    * Note: adds the value element after the positiion the pos points to . copies the elment.
    * examples
		
		```c++
		forward_list<int> intList  = {1,2,3,4,5};
		forward_list<int>::iterator it = intList.begin();
		++it;
		++it;
		//it points to 3;
		intList.insert_after(it,8);
		//intList has now {1,2,3,8,4,5};
		```

9. `void insert_after(const iterator& pos, const iterator& start, const iterator& end)`
    * Parameters: pos- iterator after which elements will be added fron range [start,end)
    * Return value: None
    * Complexity: linear - based on the distance between start and end
    * Note: inserts elements between [start,end) after pos. copies the elements
    * examples
		
		```c++
		forward_list<int> intList  = {1,2,3,4,5};
		forward_list<int>::iterator pos = intList.begin();
		//pos points to element with value 1
		forward_list<int>::iterator start = intList.begin();
		++start;
		++start;
		//it points to 3;
		intList.insert_after(it,start,intList.end());
		//intList has now {1,3,4,5,2,3,4,5};
		```

10. `void insert_after(const iterator pos,std::initializer_list<T> initList)`
    * Parameters: intList - initializer list
    * Return value: None
    * Complexity: linear - based on the size of the initializer list
    * Note: creates new elements after pos based on the elements in initializer list
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3};
		intList.insert_after(intList.begin,{5,6,7});
		intList has now {1,5,6,7,2,3};
		```
11. `void assign(size_t count,const T& value)`
    * Parameters: count - no of elements to be added, value  - of what value
    * Return value: None
    * Complexity: linear  - based on the count
    * Note: replaces the current forward_list with count copeis of value
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,5};
		intList.assign(2,3);
		//intList has now {3,3};

		forward_list<int> intList;
		intList.assign(2,3);
		//intList has now {3,3};
		```

12. `void assign(iterator start, iterator end)`
    * Parameters: range  - iterators start and end
    * Return value: None
    * Complexity: linear - based on the distance between start and end
    * Note: replaces the current list with range [start,end)
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3};
		forward_list<int> other = {4,5,6};
		intList.assign(intList.begin(),intList.end());
		//intList has now {4,5,6};
		```

13. `void assign(std::initializer_list<T> initList)`
    * Parameters: intList - initializer list
    * Return value: None
    * Complexity: linear - based on the size of the initializer list
    * Note: creates new elements after pos based on the elements in initializer list
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3};
		intList.assign({4,5,6});
		//intList has now {4,5,6};
		```
14. `void splice_after(iterator pos,forward_list<T>& forwList,iterator start,iterator end)
    * Parameters: intList - pos - after which elements in range (start,end) will be added
    * Return value: None
    * Complexity: linear - based on distance between [start,end)
    * Note: elements within range (start,end) will be delinked from forwList and lined to calling forward_list after iterator pos
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,4,5};
		forward_list<int>::iterator start intList.begin(),end = intList.intList.begin();
		++end;
		++end;
		++end; // end will point to element with value 4

		forwardList<int> other;
		other.splice_after(other.before_begin, intList,start,end);
		// other has {2,3}
		// intList has {1,4,5}
		```
15. `void splice_after(iterator pos,forward_list<int>& forwList)`
    * Parameters: pos after which elements to be joined. forwList - from which elements will be removed
    * Return value: None
    * Complexity: linear - based on size of forwList
    * Note: relinks all the elements form forwList and joins the after pos in calling forward_list
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,4,5};
		forwardList<int> other;
		other.splice_after(other.before_begin, intList);
		// other has {1,2,3,4,5}
		// intList is empty list
		```
16. `void splice_after(iterator pos,forward_list<int>& forwList,iterator end)`

    * Parameters: intList - pos after which elements to be joined,forwList - forward_list from which element just before end will be removed
    * Return value: None
    * Complexity: linear - based on the size of forwList
    * Note: relinks the element just before end and joins it with calling forward_list after pos
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,4,5};
		forward_list<int>::iterator end = intList.intList.begin();
		++end;
		++end;
		++end; // end will point to element with value 4

		forwardList<int> other;
		other.splice_after(other.before_begin, intList,end);
		// other has {3}
		// intList has {1,2,4,5}
		```

17. `void clear()`
    * Parameters: None
    * Return value: None
    * Complexity: linear - linear  - memory of the all the elements should be freed.
    * Note: free the underlying memory
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,4,5};
		intList.clear();
		// intList is now empty
		```

18. `void erase_after(const iterator pos)`
    * Parameters: iterator pos
    * Return value: None
    * Complexity: constant
    * Note: removes element just after pos
    * examples
		
		```c++
		forward_list<int> intList = {1,2,3,4,5};
		intList.erase_after(intList.before_begin());
		// intList is now {2,3,4,5};
		```
