#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        int data;
        Node *next;

    public:
        Node(int data1, Node *next1)
        {
            data = data1;
            next = next1;
        }

    public: 
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* arr2LL(vector <int>& v){
    if(v.size()==0){
        return NULL;
    }
    Node *Head = new Node(v[0]);
    Node *tail = Head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        tail->next = temp;
        tail = temp;
    }
    return (Head);
}
void print(Node* Head){
    while(Head){
        cout << Head->data << " ";
        Head = Head->next;
    }
    cout << endl;
}
Node* deleteHead(Node* Head){
    if(Head==NULL)
        return Head;
    Node *temp = Head;
    Head = Head->next;
    delete(temp);
    return Head;
}
void deleteTail(Node* Head){
    if(Head==NULL||Head->next==NULL)
        return;
    Node *temp = Head;
    while(temp->next->next){
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = nullptr;
}
int lengthofLL(Node* Head){
    Node *temp = Head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool ifPresent(Node*Head,int val){
    Node *temp = Head;
    while(temp){
        if(temp->data==val){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
Node* deleteK(Node*Head,int k){
    if(Head==NULL)return Head;
    else if(k==1){
        Node *temp = Head;
        Head = Head->next;
        delete (temp);
        return Head;
    }
    Node *temp = Head;
    Node *prev;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = temp->next;
            delete (temp);
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return Head;
}
Node* deleteEl(Node*Head,int k){
    if(Head==NULL)return Head;
    else if(Head->data==k){
        Node *temp = Head;
        Head = Head->next;
        delete (temp);
        return Head;
    }
    Node *temp = Head;
    Node *prev;
    while (temp)
    {
        if (temp->data==k)
        {
            prev->next = temp->next;
            delete (temp);
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }
    return Head;
}
Node* insertHead(Node* Head,int k){
    return new Node(k, Head);
}
Node* insertTail(Node* Head,int k){
    if(Head==NULL){
        return new Node(k);
    }
    Node* temp = Head;
    while(temp){
        if(temp->next==NULL){
            Node *element = new Node(k);
            temp->next = element;
            break;
        }
        else{
            temp = temp->next;
        }
    }
    return Head;
}
Node* insertAtK(Node* Head,int k,int val){
    if(k>lengthofLL(Head)+1||k<1){
        cout << "err: position can't be accessed" << endl;
        return Head;
    }
    int cnt = 0;
    Node *temp = Head;
    if(k==1){
        return new Node(val, Head);
    }
    Node *element = new Node(val);
    while(temp){
        cnt++;
        if (cnt == k - 1)
        {
            element->next = temp->next;
            temp->next = element;
        }
        temp = temp->next;
    }
    return Head;
}
Node* insertBeforeK(Node* Head,int k,int val){
    if(Head==NULL){
        return Head;
    }
    Node *temp = Head;
    if(Head->data==k){
        return new Node(val, Head);
    }
    Node *element = new Node(val);
    while (temp->next)
    {
        if (temp->next->data==k)
        {
            element->next = temp->next;
            temp->next = element;
            break;
        }
        temp = temp->next;
    }
    return Head;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    Node *Head = arr2LL(v);
    Head = insertBeforeK(Head, 5,10);
    print(Head);
}