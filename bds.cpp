#include<iostream>
using namespace std;

class Stack{
	private:
		int top;
		int *stackArray;
		int size;
		
	public:
		Stack(int size){
			top = -1;
			this -> size = size;
			setArray(size);
		}

		void setArray(int size){
			this -> stackArray = new int[size];
		}

		int* getArray(){
			return this -> stackArray;
		}

		int getTop(){
			return this -> top;
		}

		int getSize(){
			return this -> size;
		}

		void increaseTop(){
			this -> top = getTop() + 1;
		}
		
		void decreseTop(){
			this -> top = getTop() -1;
		}

		bool push(int item){
			if(getTop() >= (getSize()-1)){
				return false;
			}
			else{
				increaseTop();
				stackArray[getTop()] = item;
				return true;
			}
		}

		bool pop(){
			if(getTop() <= -1){
				return false;
			}
			else{
				decreseTop();
				return true; 
			}
		}

		void traverse(){
			for(int i=0;i<=this -> getTop();i++)
				cout << stackArray[i] << " ";
			cout << endl;
		}
};

int main(){
	Stack *stack = new Stack(5);
	stack -> push(3);
	stack -> push(1);
	stack -> push(4);
	stack -> push(6);
	stack -> push(9);	
	if(!stack -> push(12))
		cout << "OVERFLOW\n" ;
	stack -> traverse();
	stack -> pop();
	stack -> pop();
	stack -> traverse();
	stack -> pop();
	stack -> pop();
	stack -> pop();
	stack -> pop();
	stack -> pop();
	stack -> pop();
	stack -> pop();

	if(!stack -> pop())
		cout << "underflow\n" ;
	stack -> pop();

		stack -> traverse();
	return 0;
}