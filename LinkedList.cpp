#include <iostream>
using namespace std;

struct Node
{
    string elem;
    Node *next;
};

class LinkedList
{

  public:
    LinkedList() {head = NULL;}
    //simply an accessor, doesn't alter anything
    bool isEmpty()const {return head == NULL;}  
    //passing in memory adress of element(reference--> but cannot be altered)
    void insertFront(const string &element);
    void removeFront();
    void insertBack(const string &element);
    void removeBack();
    string getFront()const;
    string getBack()const;
    ~LinkedList();

  private:

  Node *head;

};

void LinkedList::insertFront(const string &element){

    Node* temp = new Node;
    temp->elem = element;
    temp->next = NULL;
    
    if(isEmpty()){
        head = temp;
    }

    else{
        temp->next = head;
        head = temp;
    }
}

void LinkedList::removeFront(){

    if(isEmpty()){cout<< "Error!! REmoving from an empty list!" << endl;}

    else{
        Node* temp = head;
        head = temp->next;
        delete temp;
        temp = NULL;

    }

}

void LinkedList::insertBack(const string &element){

    Node* temp1 = new Node;
    temp1->elem = element;
    temp1->next = NULL;

    if(isEmpty()){
        head = temp1;
    }
    else{
        Node* temp2 = head;

        while(temp2->next != NULL){
            
            temp2 = temp2->next;

        }

        temp2->next = temp1;
    }

}

void LinkedList::removeBack(){

      if(isEmpty()){cout << "Error!! Trying to delete from an empty list!" << endl;}

      else{
          Node* temp1 = head;
          Node* temp2 = temp1;

          while(temp1->next != NULL){
              temp2 = temp1;
              temp1 = temp1->next;
          }
          if(temp1 == head){
              head = NULL;
              delete temp1;
          }
          else{
            temp2->next = NULL;
            delete temp1;
            temp1 = NULL;
          }
      }
}

string LinkedList::getFront()const{

    if(isEmpty()){return "List is empty!!";}

    else{
        return head->elem;
    }

}

string LinkedList::getBack()const{

    if(isEmpty()){return "List is Empty!";}

    else{
        Node* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        return temp->elem;
    }

}

LinkedList::~LinkedList(){

    while(!isEmpty()){
       removeFront();
    }
    
}

int main()
{

    auto list = new LinkedList();
    cout << list->getFront() << endl;
    cout <<list->getBack() << endl;

    list->insertFront("Boikanyo");
    cout << list->getFront()<< endl;
    list->insertBack("Elias");
    cout <<list->getBack() << endl;

    list->insertFront("Tshwanelo");
    list->insertFront("Lesedi");
    list->insertBack("Kgoadira");
    cout << list->getFront()<< endl;
    cout << list->getBack()<< endl;

    list->removeBack();
    cout << list->getBack()<< endl;

    list->removeFront();
    cout << list->getFront()<< endl;

    cout << " " << endl;

    list->removeBack();
    cout << list->getBack()<< endl;
    list->removeBack();
    cout << list->getBack()<< endl;

    list->removeBack();
    cout << list->getBack()<< endl;
 
    list->removeBack();
    cout << list->getBack()<< endl;

    return 0;
}