#ifndef LINKLIST
#define LINKLIST

template<class T>
class LinkList{
	struct node{
		T* data;
		node *next;
		node(T *mdata, node *mnext) :data(mdata), next(mnext){}
		~node(){ delete data;
		cout << "Memory freed" << endl;
		}
	};
	
	node *head;//This is the head of the LinkList
	node* find_key(T*, int);

public:
	LinkList(){
		head = NULL;
	}
	LinkList(LinkList&);//Copy Constructor for the LinkList, does deep copy
	void printLinkList();
	void deletekey(T*);
	void push_back(T*);
	void push_front(T*);
	bool find_key(T*);
	void removeDuplicates();
	~LinkList();

};
#endif

/*Implementation of Copy Constructor*/
template<class T>
LinkList<T>::LinkList(LinkList& l){
	node *lhead = l.head;
	node *temp = this->head;

	while (lhead){
		T* data = new T[*(lhead->data)];
		
		if (!this->head){
			this->head = new node(data, NULL);
			temp = this->head;
		}
		else{
			temp->next = new node(data, NULL);
		}
		lhead = lhead->next;
	}
}

/*This method prints the LinkList*/
template<class T>
void LinkList<T>::printLinkList(){
	node * temp = head;
	while (temp){
		cout << *(temp->data) << endl;
		temp = temp->next;
	}
}

/*This method pushes back the value*/
template<class T>
void LinkList<T>::push_back(T* mdata){

	if (!head){
		head = new node(mdata, head);
	}
	else{
		node *temp = head;

		while (temp->next){
			temp = temp->next;
		}

		temp->next = new node(mdata, NULL);
	}
}

/*This method pushes the node at the front of the LinkList*/
template<class T>
void LinkList<T>::push_front(T* mdata){
	head = new node(mdata, head);
}

/*This method searches for the data in the list; found returns that node else return NULL*/
template<typename T>
typename LinkList<T>::node* LinkList<T>::find_key(T* data,int){
	node *temp = head;

	while (temp){
		if (*(temp->data) == *data)
			return temp;
	}

	return NULL;
}

/*This method returns true if key is found else return false*/
template<class T>
bool LinkList<T>::find_key(T* data){
	node * temp;

	temp = find_key(T*data,1);

	if (temp)return true;
	else return false;
}

/*This method frees the memory occupied by the linklist*/
template<class T>
LinkList<T>::~LinkList(){
	node* temp;
	while (head){
		temp = head;
		head = head->next;
		delete temp;
	}
}

/*Thie method removes duplicate elements from the LinkList using additional datastrucutres*/
template<class T>
void LinkList<T>::removeDuplicates(){
	map<T, int> tdata;
	node * temp = head;

	if (head){
		tdata[*(temp->data)] = 1;

		while (temp->next){

			if (tdata.count(*(temp->next->data)) > 0){
				node *temp1 = temp->next;
				temp->next = temp1->next;
				delete temp1;
			}
			else{
				temp = temp->next;
				tdata[*(temp->data)] = 1;
			}
		}
	}
}