#include<iostream>
using namespace std;

struct Node{
	int item;
	struct Node *next;
	struct Node *prev;
};

struct DList{
	int item;
	struct DList *next;
	struct DList *prev;
	struct DList *head;
};

class DoubleList{
	public:
		static DList* createList(int item){
			DList *list = new DList();
			list -> next = NULL;
			list -> prev = NULL;
			
		}
};

class DList{
	private:
		Node *head;

	public:
		void setHead(Node *node){
			this->head = node;
		}

		Node* getHead(){
			return this->head;
		}

		Node* createNode(int item){
			Node* node = new Node;
			node->item = item;
			node->next = NULL;
			node->prev = NULL;
			return node;
		}

		bool AddAtLast(int item){
			if(getHead() == NULL){
				setHead(createNode(item));
				return true;
			} else{
				Node* temp = getHead();
				while(temp -> next != NULL)
					temp = temp -> next;
				Node *newNode = createNode(item);
				newNode->prev = temp;
				temp -> next = newNode;
				return true;
			}
			return false;
		}

		bool AddAtFirst(int item){
			if(getHead() == NULL){
				setHead(createNode(item));
				return true;
			}
			else{
				Node *temp = getHead();
				Node *newNode = createNode(item);
				newNode -> next = temp;
				temp -> prev = newNode;
				setHead(newNode);
				return true;
			}
		}

		void reverse(){
			Node *temp = getHead();

			Node *current = temp;
			Node *prev = NULL;
			
			while(current){
				current -> prev = current -> next;
				current -> next = prev;

				prev = current;
				current = current -> prev;

			}
			cout << "Done \n";
			setHead(prev);
		}

		void traverse(){
			traverse(getHead());
		}

		void traverse(Node *head){
			cout << "List is \n";
			Node *temp = head;
			while(temp != NULL){
				cout << temp -> item << " ";
				temp = temp -> next;
			}
			cout << "\n***********\n";
		}
};

int main(){

	DList* list = new DList();
	int item;
	cin >> item;
	while(item > 0){
		list -> AddAtLast(item);
		cin >> item;
	}
	list -> traverse();
	list -> reverse();
	list -> traverse();
	return 0;
}