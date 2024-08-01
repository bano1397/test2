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

    void InsertInSortedList(int data){
        Node* newNode = new Node();
        newNode->SetData(data);
        
        if (CurrentLocation == NULL || CurrentLocation->GetData() >= data) {
            newNode->SetNext(CurrentLocation);
            CurrentLocation = newNode;
        } else {
        	
            Node* current = CurrentLocation;
            while (current->GetNext() != NULL && current->GetNext()->GetData() < data) {
                current = current->GetNext();
            }
            newNode->SetNext(current->GetNext());
            current->SetNext(newNode);
        }
    }
};

int main(){
    List L1;
    L1.InsertInSortedList(5);
    L1.InsertInSortedList(1);
    L1.InsertInSortedList(3);
    L1.InsertInSortedList(2);
    L1.InsertInSortedList(4);
    cout << "Sorted List after Insertions:" << endl;
    L1.Print();
}

