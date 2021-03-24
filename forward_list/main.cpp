#include "forward_list.hpp"
#include<forward_list>





int main()
{
	forward_list<int> listA;

	listA.push_front(1);
	listA.push_front(2);
	listA.push_front(3);
	listA.push_front(4);
	listA.push_front(5);
	listA.push_front(6);
	listA.push_front(7);
	listA.push_front(8);


	forward_list<int> listB(listA);

	forward_list<int> listC = listA;
	forward_list<int> listD(10);
	forward_list<int> listE(10,1);

	forward_list<int>::iterator itA = listA.begin();
	forward_list<int>::iterator itB = itA;
	++itB;
	++itB;
	++itB;
	++itB;
	++itB;
	++itB;

	forward_list<int> listF(itA,itB);
	forward_list<int> listG({1,2,3,4,5,6});
	forward_list<int> listH = {1,2,3,4,5,6};
 	

	listF.printList();


	return 0;
}
