#include<iostream>
using namespace std;

class Node{ 
private: 
    int data; 
    Node* next; 
public: 
    Node() : data(0), next(NULL) {
    }

    int GetData(){
        return data;
    }

    Node* GetNext(){
        return next;
    } 

    void SetData(int data){
        this->data = data;
    } 

    void SetNext(Node* next){
        this->next = next;
    }
};

class List { 
private: 
    Node *CurrentLocation; 
public: 
    List(){
        CurrentLocation = NULL;
    } 

    void Print(){
        Node *TempNode = CurrentLocation;
        if(TempNode == NULL){
            cout << "List is empty" << endl;
            return;
        }
        while(TempNode != NULL){
            cout << TempNode->GetData() << "-->";
            TempNode = TempNode->GetNext();
        }
        cout << "NULL" << endl;
    } 

    void Insert(int data){
        Node* newNode = new Node();
        newNode->SetData(data);
        newNode->SetNext(NULL);

        if (CurrentLocation == NULL) {
            CurrentLocation = newNode;
        } else {
            Node *tempNode = CurrentLocation;
            while (tempNode->GetNext() != NULL) {
                tempNode = tempNode->GetNext();
            }
            tempNode->SetNext(newNode);
        }
    } 

    void InsertAt(int position, int data){
        Node* newNode = new Node();
        newNode->SetData(data);
        if (position == 1){
            newNode->SetNext(CurrentLocation);
            CurrentLocation = newNode;
        } else {
            Node* tempNode = CurrentLocation;
            for(int i = 1; tempNode != NULL && i < position - 1; i++) {
                tempNode = tempNode->GetNext();
            }
            if (tempNode != NULL){
                newNode->SetNext(tempNode->GetNext());
                tempNode->SetNext(newNode);
            } else {
                cout << "error" << endl;
            }
        }
    }
};

int main(){
    List L1;
    L1.Insert(2);
    L1.Insert(10);
    L1.Insert(3);
    cout << "Initial List:" << endl;
    L1.Print();
    
    int position, data;
    cout << "Enter the position and data to insert: ";
    cin >> position >> data;
    
    L1.InsertAt(position, data);
    cout << "\nList after insertion:" << endl;
    L1.Print();
}

