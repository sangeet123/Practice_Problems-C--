#include<iostream>
using namespace std;

class LinkList{
	struct node{
		int data;
		node *next;
		node(){}
		node(int mdata, node *mnext) :data(mdata), next(mnext){}
		static void print(node* temp){
			while (temp){
				cout << temp->data << endl;
				temp = temp->next;
			}
		}
	}*head;
	void breakDown(node**, node**, int, node*);
	void breakDown(node**,node**,node*);
	node* swapPairwise(node*, node*);
	bool hasSufficientNodes();
public:
	LinkList(){ head = 0; }
	void pairWiseSwap();
	void swapAdjacentPair();
	void insert(int);
	~LinkList();
};

/*swapping adjacant nodes of LinkList without using breaking down function */
void LinkList::swapAdjacentPair(){
	if (hasSufficientNodes()){
		node *zeroth = NULL;
		node *first = NULL;
		node *second = NULL;
		node *third = NULL;
		
		/*Initializing*/
		first = head;
		second = head->next;
		third = second->next;
		head = second;

		/*Performing first alternative swapping*/
		first->next = third;
		second->next = first;
		zeroth = first;
		first = third;
		if (first)
			second = third->next;
		else
			second = NULL;

		while (second){
			third = second->next;
			zeroth->next = second;
			second->next = first;
			first->next = third;
			zeroth = first;
			first = zeroth->next;
			if (first)
			second = first->next;
			else second = NULL;
		}
	}
	node::print(head);
}

/*Freeing memory consumed by all the nodes*/
LinkList::~LinkList(){
	while (head){
		node *temp = head;
		head = head->next;
		delete temp;
	}
}

/*checks if LinkList has at least two nodes*/
bool LinkList::hasSufficientNodes(){
	if (!head){
		cout << "LinkList is empty:Insert some items ane try using insert(int)" << endl;
		return false;
	}
	else if (!head->next){
		cout << "Only one item in LinkList: Nothing to swap" << endl;
		return false;
	}

	return true;
}

/*PairWiseSwapping the node of the LinkList*/
void LinkList::pairWiseSwap(){
	
	if (hasSufficientNodes()){
		node* first = NULL;
		node* second = NULL;

		//breakDown(&first, &second, 1, head);//This is iterative version of breakdown linklist
		breakDown(&first, &second, head);
		head = swapPairwise(first, second);
		node::print(head);
	}
}


/*Method that does Pairwise swapping of nodes*/
struct LinkList::node* LinkList::swapPairwise(node* first, node* second){
	node *temp1 = NULL;
	node *temp2 = NULL;
	node *last = NULL;
	node *head = second;
	while (second){
		temp1 = first->next;
		temp2 = second->next;

		second->next = first;
		first->next = temp2;

		last = first;
		first = temp1;
		second = temp2;
	}
	if (first)last->next = first;//Because of this condition we need to check if linklist has only one node

	return head;
}

/*Method for breaking down the linklist into even and odd nodes pair*/
void LinkList::breakDown(node **first, node **second, int no, node *head){
	if (!head)return;
	else breakDown(first, second, no + 1, head->next);

	if (no % 2){
		head->next = *first;
		*first = head;
	}
	else{
		head->next = *second;
		*second = head;
	}
}

/*Iterative way of breaking down the linklist into even and odd nodes pair*/
void LinkList::breakDown(node **first, node **second, node *head){
	
	*first = head;
	*second = head->next;

	node *first1; 
	node *second1;

	first1 = *first;
	second1 = *second;


	while (second1){
		first1->next = second1->next;
		if (second1->next){
			second1->next = second1->next->next;
		}
		else{
			second1->next = NULL;
		}
		first1 = first1->next;
		second1 = second1->next;
	}
	if (first1)first1->next = NULL;
}


/*Method for inserting into LinkList*/
void LinkList::insert(int data){
	head = new node(data, head);
}

int main(){
	LinkList ll;


	ll.insert(6);
	ll.insert(5);
	ll.insert(4);
	ll.insert(3);
	ll.insert(2);
	ll.insert(1);
	
	ll.swapAdjacentPair();
	cout << "_____________________________" << endl;
	ll.pairWiseSwap();

	return 0;
}