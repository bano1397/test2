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

    void SwapByData(int data1, int data2){
    if (data1 == data2) return; // No operation needed if the data is the same

    Node *node1 = CurrentLocation, *node2 = CurrentLocation;
    bool found1 = false, found2 = false;

    // Find nodes containing data1 and data2
    while (node1 != NULL && !found1) {
        if (node1->GetData() == data1) found1 = true;
        else node1 = node1->GetNext();
    }

    while (node2 != NULL && !found2) {
        if (node2->GetData() == data2) found2 = true;
        else node2 = node2->GetNext();
    }

    // If both elements are found, swap their data
    if (found1 && found2) {
        int temp = node1->GetData();
        node1->SetData(node2->GetData());
        node2->SetData(temp);
    } else {
        cout << "One or both elements not found. No swap performed." << endl;
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
    
    int data1, data2;
    cout << "Enter the data of the two nodes you wish to swap: ";
    cin >> data1 >> data2;
    
    L1.SwapByData(data1, data2);
    cout << "\nList after swapping:" << endl;
    L1.Print();
}

