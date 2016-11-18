#include <iostream>

//Nodes and lists use public data members for convenience
//This may make some software engineers froth at the mouth

class Node
{
public:
    int value; //This could really be any type
    Node* next;
    Node* prev;
    Node(int val){
        std::cout << "Node constructr!" << std::endl;
        this->value=val;
        this->next=(Node*)0;
        this->prev=(Node*)0;
    }
    ~Node(){
        std::cout << "Node destructor" << std::endl;
        std::cout << "I had the value "<<this->value << std::endl;
    }
};
class List
{

public:
    Node* head;
    Node* tail;

    List(){
        std::cout << "List Constructor!" << std::endl;
        this->head=0;
        this->tail=0;
    }
    ~List(){
        std::cout << "List destructor!" << std::endl;
    }
    void insert(Node* n, Node* x){
        //Not actually perfect: how do we prepend to an existing list?
        if (n!=0){
            x->next=n->next;
            n->next=x;
            x->prev=n;
            if (x->next!=0)
                x->next->prev=x;
        }
        if (this->head==0){
            this->head=x;
            this->tail=x;
            x->prev=0;
            x->next=0;
        }else if (this->tail=n){
            this->tail=x;
        }
    }
    void display(){
        Node* i=this->head;
        std::cout << "List: " ;
        while(i!=0){
            std::cout << i->value << ",";
            i=i->next;
        }
        std::cout << std::endl;
    }

    //Remove element in list
    void remove(Node *h, int *v)
    {
        Node *current = h;

        while(current != NULL)
        {
            if(current == v)
            {
                if(current.prev != NULL)
                {
                    current.prev.next = current.next;
                }
                else
                {
                    current = current.next;
                }
            }
            else
            {
                if(current.next != NULL)
                {
                    current.next.prev = current.prev;
                }
                else
                {
                    current = current.prev;
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    List* l=new List();
    l->insert(0,new Node(4));
    l->insert(l->head,new Node(6));
    l->insert(l->head,new Node(8));
    l->display();

    //Remove element
    int val;
    std::cout << "Enter a value to remove: ";
    std::cin >> val;
    l->remove(l->head, &val);
    l->display();

    delete l;
    return 0;
}
