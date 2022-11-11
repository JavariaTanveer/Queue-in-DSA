#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:
    T *q;
    int front;
    int rear;
    int size;
public:
    Queue()
    {
        size = 5;
        front = rear = -1;
        q = new T[size];
    }
    bool isFull()
    {
        if(rear == size-1)
        {
            return true;
        }
        return false;
    }

    void enqueue(T data)
    {
        if(!isFull())
        {
            if(front==-1)
            {
                front++;
            }
            rear++;
            q[rear] = data;
        }
        else
        {
            //cerr<<"Queue is full"<<endl;
            T *temp = new T[size*2];
            for(int i=front; i<=rear; i++)
            {
                temp[i] = q[i];
            }

            delete []q;
            q = temp;
            size*=2;

            enqueue(data);

        }
    }

    bool isEmpty()
    {
        if(front==-1 && rear==-1)
            return true;
        return false;
    }

    void display()
    {

        if(!isEmpty())
        {
            for(int i=front; i<=rear; i++)
            {
                cout<<q[i]<<" <- ";
            }
        }
        else
        {
            cerr<<"Queue is empty"<<endl;
        }
    }

    T dequeue()
    {
        if(!isEmpty())
        {
            T temp = q[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                for(int i=front; i<rear; i++)
                {
                    q[i] = q[i+1];
                }
                rear--;
            }
            return temp;
        }
        else
        {
            return -1;
        }
    }
};


int main()
{
    Queue<int> que;
    que.enqueue(5);
    que.enqueue(50);
    que.enqueue(51);
    que.enqueue(55);
    que.enqueue(501);
    que.enqueue(5055);
    que.enqueue(511);
    int d = que.dequeue();
    d--;
    que.enqueue(d);
    d = que.dequeue();
    d--;
     que.enqueue(d);
    d =que.dequeue();
    d--;
    que.enqueue(d);

    que.display();





    return 0;
}
