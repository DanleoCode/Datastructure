#include<iostream>
using namespace std;

struct queue{
	int front;
	int rear;
	int size;
	int capacity;
	int *array;
};

class Queue{
	public:
		static queue* createQueue(int capacity){
			queue *q = new queue;
			q -> capacity = capacity;
			q -> size = 0;
			q -> front = 0;
			q -> rear = capacity - 1;
			q -> array = new int[capacity];
			return q;
		}

		static bool isFull(queue *q){
			if(q -> size == q -> capacity){
				return true;
			}
			return false;
		}

		static bool isEmpty(queue *q){
			if(q -> size == 0){
				return true;
			}
			return false;
		}

		static bool enqueue(queue *q, int item){
			if(!isFull(q)){
				q -> rear = (q -> rear + 1) % q -> capacity;
				q -> size += 1;
				q -> array[q -> rear] = item;
				return true;
			}
			return false;
		}

		static int dequeue(queue *q){
			int item;
			if(!isEmpty(q)){
				item = q -> array[q -> front];
				q -> front = (q -> front + 1) % q -> capacity;
				q -> size --; 
				return item;
			}
			return item;
		}

		static int length(queue *q){
			return q -> size;
		}
};

int main(){

	queue *q = Queue :: createQueue(5);

	Queue :: enqueue(q, 2) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 1) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 3) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 4) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 5) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 6) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 1) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 1) ? cout << "done\n" : cout << "FULL\n";
	Queue :: enqueue(q, 1) ? cout << "done\n" : cout << "FULL\n";
	cout << "size is " << Queue :: length(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	Queue :: enqueue(q, 1) ? cout << "done\n" : cout << "FULL\n";
	cout << Queue :: dequeue(q) << endl;
	cout << "size is " << Queue :: length(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	cout << "size is " << Queue :: length(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	cout << Queue :: dequeue(q) << endl;
	cout << "size is " << Queue :: length(q) << endl;
	return 0;
}