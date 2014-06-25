#include<iostream>
#include<map>
using namespace std;
#include"linklist.h"


int main(){
	LinkList<int>l;
	l.push_back(new int(1));
	l.push_front(new int(2));
	l.push_front(new int(1));
	l.push_back(new int(2));
	l.push_back(new int(3));
	l.push_back(new int(4));
	l.push_front(new int(3));
	l.push_front(new int(2));
	l.push_front(new int(4));
	l.push_front(new int(7));

	l.removeDuplicates();

	l.printLinkList();

	return 0;
}