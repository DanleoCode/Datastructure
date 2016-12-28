#include<iostream>

using namespace std;
struct Node{
	int item;
	Node *nextNode;
};

class List{
	private:
		 Node* head;

	public:

		List(){
			this->head = NULL;
		}

		Node* getHead(){
			return this->head;
		}

		void setHead(Node* node){
			this->head = node;
		}

		Node* createNode(int item){
			Node* node = new Node;
			if(node != NULL){
				node->item = item;
				node->nextNode = NULL;
				return node;
			}
			return NULL;
		}

		bool addAtLast(int item){
			Node* newNode = createNode(item);
			if(getHead() == NULL)
				this->head = newNode;
			else{
				Node* temp = getHead();
				while(temp->nextNode != NULL)
					temp = temp->nextNode;
				temp->nextNode = newNode;
			}
			return true;
		}

		bool addAtFirst(int item){
			Node* newNode = createNode(item);
			try{
				if(getHead() == NULL)
					this->head = newNode;
				else{
					newNode->nextNode = getHead();
					setHead(newNode);
				}
				return true;
			}
			catch(...){
				cout << "Exception caught" << endl;
			}
			return false;
		}


		void traverse(){
			traverse(getHead());
		}

		static void traverse(Node* head){
			cout << "LIST as FOLLOWS : " << endl;
			Node* temp = head;
			while(temp != NULL){
				cout << temp->item << " ";
				temp = temp->nextNode;
			}
			cout << "\n**********\n";	
		}

		int size(){
			int size = 0;
			Node* node = getHead();
			while(node != NULL){
				size++;
				node = node->nextNode;
			}
			return size;
		}

		void reverse(){
			Node* prev = NULL;
			Node* current = getHead();
			Node* swap = NULL;
			while(current){
				swap = current -> nextNode;
				current -> nextNode = prev;
				prev = current;
				current = swap;
			}
			setHead(prev);
		}

		int removeNode(int item){
			if(getHead() == NULL)
				return -1;
			else if(getHead() -> item == item){
				setHead(getHead() -> nextNode);
			}
			else{
				Node *temp =  getHead()	-> nextNode;
				Node *prev = getHead();
				while(temp != NULL){
					if(temp -> item == item){ 
						prev -> nextNode = temp -> nextNode;
						break;
					}
					prev = temp;
					temp = temp -> nextNode;
				}
			}
		}

		bool insertAfter(int after, int item){
			Node *location = itemAfterExist(after);
			if(location != NULL){
				Node *newNode = createNode(item);
				newNode -> nextNode = location -> nextNode;
				location -> nextNode = newNode;
				return true;
			}
			return false;
		}

		Node* itemAfterExist(int item){
			Node *temp = getHead();
			while(temp != NULL){
				if(temp -> item == item)
					return temp;
				temp = temp -> nextNode;
			}
			return NULL;
		}

		bool insertBefore(int location, int item){
			if(getHead() -> item == location){
				addAtFirst(item);
			}
			else{
				Node *exist = itemBeforeExist(location);
				if(exist){
					Node *newNode = createNode(item);
					newNode -> nextNode = exist -> nextNode;
					exist -> nextNode = newNode;
					return true;
				}
			}
			return false;
		}

		Node* itemBeforeExist(int item){
			Node *temp = getHead();
			while(temp != NULL){
				if(temp -> nextNode != NULL)
					if(temp -> nextNode -> item == item)
						return temp;
					temp = temp -> nextNode;
			}
			return NULL;
		}

		Node* middleElement(){
			
		}
};


int main(){
	List* list = new List();

	int item;
	cin >> item;
	while(item > 0){
		//list->addAtLast(item);
		list->addAtLast(item);
	cin >> item;
	}
	list->traverse();

	cout << "enter number to insert : ";
	int term;
	cin >> term;
	cout << "before number : ";
	cin >> item;
	list -> insertBefore(item, term);
	//list -> insertAfter(item, term);
	//list -> removeNode(item);
	//list->reverse();
	
	list->traverse();
	return 0;
}
