#include <iostream>
#include <stdlib.h> // rand()
using namespace std;
//Sudo code obtained from page 171 and 179 of textbook.
//Partition(A,p,r) fucntion
int partition(int *data, int start, int size){
	//Set up pivit point element to compare
	int pivotElement = data[size];
	//We begin by setting a marker for comparing elements from the begining of the array.
	int index = start - 1;
	//We compare elements to the pivot point and move them if needed.
	for(int i = start;i < size; i++){
		if(data[i] <= pivotElement){
			//index is incremented if swap is performed
			index++;
			//Swap
			int temp = data[index];
			data[index] = data[i];
			data[i] = temp;
		}
	}
	//We place our pivot element in its coressponding indez
	int temp = data[index + 1];
	data[index + 1] = data[size];
	data[size] = temp;
	return index + 1;
}
//Randomized-Patition(A,p,r) fuction
int randomizedPartition(int *data, int start, int size){
	int randomIndex = start + rand() % (start - size); // [start...(size - 1)] 
	//In order to compare elements to the randomly selected element, we swap it with the last element of the array.
	int temp = data[size];
	data[size] = data[randomIndex];
	data[randomIndex] = temp;
	//Now we begin the comparing.
	return partition(data, start, size);
}
//Randomized-Quicksort(A,p,r) fucntion
void randomizedQuickSort(int *data,int start, int size){
	//This will stop once the elements are in arrays with 1 element. Divide and conquer.
	if(start < size){
		int pivot = randomizedPartition(data, start, size);
		//Left side
		randomizedQuickSort(data, start, pivot - 1);
		//right side
		randomizedQuickSort(data, pivot + 1, size);
	}
}
//Simple print fuction itteratea through array.
void print(int *data, int size){
	for(int i = 0; i < size;i++)
		cout << data[i] << ";";
}
//Main
int main(int argc, char **argv){
	//initialize variables.
	int size;
	cin >> size;
	int *data = new int[size];
	//Collect data.
	for(int i = 0; i < size; i++)
		cin >> data[i];
	//print sorted array.
	randomizedQuickSort(data, 0, size - 1);
	print(data, size);
	//delete the array from memory.
	delete[] data;
	return 0;
}	