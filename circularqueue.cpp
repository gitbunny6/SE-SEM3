//circular queue
#include<iostream>
#define N 5
using namespace std;
class CircularQueue{
    int queue[N];
    int front;
    int rear;

    public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    bool isFull();
    bool isEmpty();
    void enqueue(int x); //x is the item to be enqueued
    void dequeue();
    void display();
};

bool CircularQueue :: isFull(){
    return((rear+1)%N==front);
}

bool CircularQueue :: isEmpty(){
    return(front==-1 && rear==-1);
}

void CircularQueue :: enqueue(int x){
    //check if queue is full
    if(isFull()){
        cout<<"\nQueue is FULL, can't enqueue "<<x<<endl;
        return;
    }else if(isEmpty()){
        front=rear=0;
        queue[rear] = x;
    }else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void CircularQueue :: dequeue(){
    if(isEmpty()){
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }else if(front==rear){
        cout<<"Dequeued element : " << queue[front] <<endl;
        front=rear=-1;
    }else{
        cout<<"Dequeued element : " << queue[front] <<endl;
        front = (front+1)%N;
    }
}

void CircularQueue :: display(){
    int i = front;
    if(isEmpty()){
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }else{
        while(i!=rear){
            cout << queue[i] << " ";
            i = (i+1)%N;
        }
        cout << queue[rear] <<endl;
    }
}

int main(){
    CircularQueue q;
    int x, ch;
    do{
        cout<<"\n1. Enqueue element\n2. Dequeue element\n3. Display\n4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        cout << endl;
        switch(ch){
            case 1:
                cout<<"Enter element to enqueue: ";
                cin>>x;
                cout<<endl;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;    
            case 3:
                q.display();
                break;
        }
    }while(ch!=4);
    return 0;
}
