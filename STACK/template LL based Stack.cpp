template <typename t>
class node{
public:
    t data ;
    node<t> *next;

    node (t data)
    {
       this ->data =data;
       next=NULL;
    }
};
template <typename t>

class stack{
    node<t> *head;
    int size ;
public:
    stack()
    {
        head = NULL ;
        size = 0 ;
    }

    int getsize()
    {
        return size;
    }

    bool iiempty()
    {
        return size==0;
    }

    void push(t ele)
    {
        node<t> *n  = new node<t>(ele);
        n -> next = head ;
        head = n ;
        size ++ ;

    }

    void pop()
    {
        if (iiempty())
        {
            cout <<"empty stack"<<endl;
            return;
        }
        node<t> *temp = head;
        head = head -> next ;
        temp ->next = NULL;
        delete  temp;
        size--;
    }

    t top ()
    {
        if (iiempty())
        {
            cout <<"empty stack"<<endl;
            return 0;
        }
        return head -> data ;
    }
};
int main()
{
    stack <int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout <<s.top()<<endl;
    s.pop();
    cout <<s.top()<<endl;
    s.pop();
    cout <<s.top()<<endl;
    s.pop();

    cout<<s.getsize()<<endl;
    cout<<s.iiempty()<<endl;
}