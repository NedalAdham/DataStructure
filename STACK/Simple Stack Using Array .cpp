#include <iostream>
using namespace std ;

class stack {
    int *arr;
    int nextindex;
    int capacity ;

public:
    stack()
    {
        capacity=4;
        arr = new int [capacity];
        nextindex = 0 ;
    }

    /*/
    stack(int cap)
    {
        capacity= cap;
        arr = new int [cap];
        nextindex = 0 ;
    }
     /*/


    //return no of element
    int size ()
    {
        return nextindex;
    }

    bool isempty()
    {
        return nextindex == 0;
    }


     void push (int ele)
     {

        if (nextindex == capacity)
        {
           int *newarr = new int [2*capacity];
            for (int i = 0; i < capacity ; ++i)
            {
             newarr[i] = arr[i] ;
            }
            delete [] arr ;
            arr = newarr;
            capacity = 2*capacity ;
        }
        arr[nextindex] = ele ;
        nextindex++;
     }

     void pop ()
     {
        if (isempty())
        {
            cout <<"stack empty"<<endl ;
            return;
        }
        nextindex--;
     }

     int top ()
     {
         if (isempty())
         {
             cout <<"stack empty"<<endl ;
             return -1 ;
         }
         return arr[nextindex-1];
     }


};

int main() {
 
}