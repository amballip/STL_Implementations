#include "forward_list.hpp"
#include<forward_list>
#include<string>
#include<iostream>
#include<string>


void print(std::forward_list<int>& list)
{
	for(std::forward_list<int>::iterator it = list.begin(); it!=list.end(); ++it)
	{
		std::cout<<*it<<std::endl;
	}

	std::cout<<std::endl;

}
void print(std::string message)
{
	std::cout<<message<<std::endl;
}

int main()
{
#if 0
	forward_list<int> listA;
	forward_list<int> listB({1,2,3,4,5});
	forward_list<int> listC= {6,7,8,9,10};
	forward_list<int> listD(listC);
	forward_list<int> listE(10);
	forward_list<int> listF(10,9);
	

	forward_list<int>::iterator start = listB.begin(),end = listB.begin();
	++end;
	++end;
	++end;

	forward_list<int> listG(start,end);
	forward_list<int> listH = listG;

	listA.printList();
	listB.printList();
	listC.printList();
	listD.printList();
	listE.printList();
	listF.printList();
	listG.printList();
	listH.printList();

	std::cout<<listA.empty()<<std::endl;
	std::cout<<listB.empty()<<std::endl;
	std::cout<<(listC==listD)<<std::endl;
	std::cout<<(listC!=listD)<<std::endl;
	std::cout<<(listE==listD)<<std::endl;
	std::cout<<(listE!=listD)<<std::endl;

	forward_list<int> listI;
	listI = listC;
	
	listI.printList();

	forward_list<int> listJ;
	listJ= {1,3,3,4,5};
	listJ.printList();

	forward_list<int> listK;
	forward_list<int> listL;
	listL.assign(10,9);
	listL.printList();
	listK.assign({1,3,3,3});
	listK.printList();

	forward_list<int> listM;
	listM.assign(start,end);
	listM.printList();

	listL.swap(listK);
	listL.printList();
	listK.printList();

	std::cout<<listB.front()<<std::endl;

	for(forward_list<int>::iterator it = listB.begin(); it!=listB.end(); ++it)
	{
		std::cout<<*it<<std::endl;
	}

	listB.insert_after(listB.before_begin(),10);
	listB.printList();
	listB.push_front(3);
	listB.printList();
	listB.pop_front();
	listB.printList();

	listF.insert_after(listF.begin(),start,end);
	listF.printList();

	forward_list<int> listN = {34,4,345,5,5,3,4,5,56,6,6};
	listN.printList();

	for(int i = 0;i<4;++i)
	{
		listN.erase_after(listN.before_begin());
	}


	listN.printList();
	listN.clear();
	listN.printList();

	std::forward_list<int> list = {1,2,3,4,5,6};
	std::forward_list<int> list1 = {7,8,9};

	list1.splice_after(list1.before_begin(),list);

	print(list);
	print(list1);
	
	forward_list<int> listA = {1,2,3,4,5,6};
	forward_list<int> listA1 = {7,8,9};

	listA1.splice_after(listA1.before_begin(),listA);

	listA.printList();
	listA1.printList();

	
#endif


	forward_list<int> listA;
	forward_list<int> listB({2,4,7,8,9});
	print("lists created");

	listA = listB;

	listB.printList();


	
	return 0;
}
