//
//  main.cpp
//  Assignment_4
//
//  Created by Sai Uthej V on 10/2/14.
//  Copyright (c) 2014 University of Texas, Dallas. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <array>

using namespace std;

class heapsorts  {
    
public:
    
    int size;
    
    int numbers[13];
    
    heapsorts();
    
    void createarray();
    
    void heapify(int index);
    
    void percolatedown(int index, int maxindex);
    
    void heapsort();
    
    void displayheap();
    
    ~heapsorts();
    
};

heapsorts::heapsorts()  {
    
    size = 0;
    
    int i;
    
    for (i = 0; i<13; i++)
        
        numbers[i] = -1;              //initialize the array to a default value

}

void heapsorts::createarray()  {
    
    int i;
    
    cout << "Enter the elements you wish to sort:\n";
    
    for (i = 1; i<13; i++) {    //populating the array
        
        cin >> numbers[i];
        
        size=size+1;
    }
    
}

void heapsorts::heapify(int index)  {
    
    int temp = 0;                   //heapify = percolate up; fixing the heap property to create a max heap
    
    if (index > 0 and index < ((size/2)+1))  {
    
        if (numbers[(index*2)] > numbers[(index*2)+1] && numbers[index] < numbers[(index*2)])  {
        
            temp = numbers[(index*2)];
        
            numbers[(index*2)] = numbers[index];
        
            numbers[index] = temp;
            
            heapify((index*2));
        
            heapify(--index);
        
        }
    
        else if (numbers[(index*2)] < numbers[(index*2)+1] && numbers[index] < numbers[((index*2)+1)])  {
        
            temp = numbers[((index*2)+1)];
        
            numbers[((index*2)+1)] = numbers[index];
        
            numbers[index] = temp;
            
            heapify(((index*2)+1));
        
            heapify(--index);
        
        }
    
        else
        
            heapify(--index);
    }
    
}

void heapsorts::percolatedown(int index, int maxindex)  {
    
    int temp = 0;
    
    int swap = index;             //percolate down after swap to sort elements
    
    
    if ((index > 0) && ((2*index) <= maxindex) && (numbers[swap] < numbers[(index*2)]))
            
        swap = index*2;
    
    if ((index > 0) && (((2*index)+1) <= maxindex) && (numbers[swap] < numbers[((index*2)+1)]))
            
        swap = (2*index)+1;
    
    if (swap != index)  {
        
        temp = numbers[swap];
        
        numbers[swap] = numbers[index];
        
        numbers[index] = temp;
        
        percolatedown(swap, maxindex);
        
    }

}


void heapsorts::heapsort()  {
    
    int end = size;
    
    int temp;
    
    while (end > 1)  {              // swap to start sorting
        
        temp = numbers[1];
        
        numbers[1] = numbers[end];
        
        numbers[end] = temp;
        
        percolatedown(1, --end);
        
    }
    
}

void heapsorts::displayheap()  {
    
    for (int i=1; i<13; i++)        // displaying the heapsort
        
        cout << numbers[i]<< " ";
    
    cout << endl;
    
}

heapsorts::~heapsorts()  {
    
    int i;
    
    size = 0;
    
    for (i=0; i<13; i++)
        
        numbers[i] = -1;            // restoring the default values to the array
    
}

int main()  {
    
    heapsorts Heap;
    
    Heap.createarray();
    
    cout<<"Numbers before creating a heap"<<endl;
    
    Heap.displayheap();
    
    Heap.heapify(Heap.size/2);      // fixing the heap
    
    cout<<"Heap created"<<endl;
    
    Heap.displayheap();             // displaying the max heap
    
    Heap.heapsort();                // performing a heapsort
    
    cout << "Heap after sorting"<<endl;
    
    Heap.displayheap();             // display after the sorting

    return 0;
    
}