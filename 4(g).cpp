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
    List() : CurrentLocation(NULL) { } 

    void Print() {
        Node *TempNode = CurrentLocation;
        if(TempNode == NULL) {
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

    //Bubble sort
    void Sort() {
        if (CurrentLocation == NULL || CurrentLocation->GetNext() == NULL) {
            return; 
        }

        bool wasSwapped;
        do {
            wasSwapped = false;
            Node *current = CurrentLocation;
            while (current->GetNext() != NULL) {
                Node *next = current->GetNext();
                if (current->GetData() > next->GetData()) {
                    
                    int temp = current->GetData();
                    current->SetData(next->GetData());
                    next->SetData(temp);
                    wasSwapped = true;
                }
                current = next;
            }
        } while (wasSwapped);
    }
};

int main(){
    List myList;
    myList.Insert(4);
    myList.Insert(2);
    myList.Insert(5);
    myList.Insert(1);
    myList.Insert(3);

    cout << "Original List:" << endl;
    myList.Print();

    myList.Sort();

    cout << "Sorted List:" << endl;
    myList.Print();
}

