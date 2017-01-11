#include<iostream>
using namespace std;

void selectionSort(int *array, int size){
	for(int i=0;i<size-1;i++){
		int swap = i;
		for(int j=i+1;j<size;j++){
			if(array[j] < array[swap])
				swap = j;
		}
		int temp = array[i];
		array[i] = array[swap];
		array[swap] = temp;
	}
}

void insertionSort(int *array, int size){
		for(int j=1;j<size;j++){
			
		}
}

int main(){
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	selectionSort(array,10);
	for(int i=0;i<10;i++){
		cout << array[i] << " ";
	cout << endl;
	}
	return 0;
}
