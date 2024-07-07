#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
    public:
        Node(int data1)
        {
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* arrayToDoublyLinkedList(vector <int> &v){
    if(v.size()<1)
        return NULL;
    Node *Head = new Node(v[0]);
    Node *tail = Head;
    for (int i = 1; i < v.size(); i++){
        Node *temp = new Node(v[i]);
        temp->back = tail;
        tail->next = temp;
        tail = temp;
    }
    return Head;
}

Node* deleteHead(Node* Head){
    if(Head==NULL){
        return Head;
    }
    if(Head->next==NULL){
        delete (Head);
        return NULL;
    }
    Node *temp = Head;
    Head = Head->next;
    Head->back = NULL;
    delete (temp);
    return Head;
}

Node* deleteTail(Node* Head){
    if(Head==NULL){
        return Head;
    }
    if(Head->next==NULL){
        return Head;
    }
    Node *temp = Head;
    while(temp->next->next){
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
    return Head;
}


void print(Node* Head){
    Node *temp = Head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    vector <int> v={1,2};
    Node* Head=arrayToDoublyLinkedList(v);
    print(Head);
    Head=deleteHead(Head);
    print(Head);
    Head=deleteTail(Head);
    print(Head);
}
