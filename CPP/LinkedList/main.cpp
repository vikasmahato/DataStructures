#include "LinkedList.h"
#include "linkedList.cpp"

using namespace vikas;

int main(){

	LinkedList<int> ilist;
	ilist.pushFront(4);
	ilist.pushFront(9);

	std::cout << "Size of int list is: " << ilist.size() << std::endl;

	ilist.printDebug();
	
	return 0;
}