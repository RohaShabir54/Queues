#include<iostream>
using namespace std;
template<typename T> 
class Queue {
	
	int array_capacity;
	int queue_size;
    int ifront;
	int iback;
	T* array;
public:
	Queue(int val){
		
		if (val <= 0) {
			throw invalid_argument("Capacity must be positive.");
		}
		array_capacity = val;
		queue_size = 0;
		ifront = 0;
		iback = -1;
		array = new T[array_capacity];
	}
public:
	~Queue()
	{
		delete[] array;
	}
public:
	bool empty()
	{
		return queue_size == 0;
	}
public:
	T front()
	{
		if (empty())
		{
			throw runtime_error("Queue is empty");
		}
		else
		{
			return array[ifront];
			
		}
	}
public:
	T pop()
	{
		if (empty())
		{
			throw runtime_error("Queue is empty");
		}
	else
	{
			ifront = (ifront + 1) % array_capacity;
			--queue_size;
		   return array[ifront - 1];
		  
	}
	}
public:
	void push(T val)
	{
		if (queue_size == array_capacity)
		{
			throw runtime_error("Queue is full no more elements can be pushed ");
		}
		else {
			iback=(iback+1)%array_capacity;
			array[iback] = val;
			++queue_size;
		}
	}
public:
	void print()
	{
		int current_index = ifront;
		for (int i=0;i < queue_size;i++)
		{
			cout << array[current_index] << " ";
			current_index = (current_index+1)%array_capacity;
		}
		cout << endl;

	}
	

};
int main()
{
	try {
		Queue<int>q(6);
		q.push(10);
		q.push(20);
		q.push(30);
		cout << "Elements of queue are :";
		q.print();
		q.pop();
		q.pop();
		cout << "Elements of queue after popping are:";
		q.print();
		cout << "Front of queue is :" << q.front();
	}

	catch (const runtime_error& e) {
		cerr << "Runtime Error: " << e.what() << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
		return 0;
	

}