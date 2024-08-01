#include<iostream>
using namespace std;
class Node{ 
    private: 
       int data; 
       Node* next; 
    public: 
       Node(){
       }
       int GetData(){
       	   return data;
       }
       Node* GetNext(){
       	   return next;
       } 
       void SetData(int data){
       	   this->data=data;
       } 
       void SetNext(Node* next){
       	   this->next=next;
       }
};
class List { 
    private: 
       Node *CurrentLocation; 
    public: 
       List(){
	CurrentLocation=NULL;
} 
       void Print(){
	Node *TempNode=CurrentLocation;
	if(TempNode==NULL){
		cout<<"List is empty"<<endl;
	}
	if(TempNode->GetNext()==NULL){
		cout<<TempNode->GetData();
		cout<<"-->"<<" NULL "<<endl;
	}
	else{
		do{
			cout<<TempNode->GetData();
			cout<<"-->";
			TempNode=TempNode->GetNext();
		}
		while(TempNode!=NULL);
	}
	cout<<"NULL"<<endl;
} 
       void Insert(int data){
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);
    Node *tempNode = CurrentLocation;
    if ( tempNode != NULL ) {
       while ( tempNode->GetNext() != NULL ) {
           tempNode = tempNode->GetNext();
       }
       tempNode->SetNext(newNode);
    }
    else {
       CurrentLocation = newNode;
    }
} 

    void addbetween(int x, int newData) {
    Node* newNode = new Node();
    newNode->SetData(newData);
    //newNode->SetNext(NULL);

    Node* tempNode = CurrentLocation;

    while (tempNode != NULL && tempNode->GetData() != x) {
        tempNode = tempNode->GetNext();
    }

     if (tempNode != NULL) {
            newNode->SetNext(tempNode->GetNext());
            tempNode->SetNext(newNode);
        }
    }
    
    void Delete(int data) {
    Node* tempNode = CurrentLocation;
    Node* previous = NULL;

    if (tempNode == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    if (tempNode->GetData() == data) {
        CurrentLocation = tempNode->GetNext();
        delete tempNode;
        return;
    }

    while (tempNode != NULL && tempNode->GetData() != data) {
        previous = tempNode;
        tempNode = tempNode->GetNext();
    }

    if (tempNode != NULL) {
        previous->SetNext(tempNode->GetNext());
        delete tempNode;
    } 
}

};

int main(){
	List L1;
	L1.Insert(2);
	L1.Insert(10);
	L1.Insert(3);
	L1.Print();
	L1.addbetween(10,5);
    cout << "\nUpdated List:" << endl;
    L1.Print();
    L1.Delete(2);
    cout << "\nAfter deleted Updated List:" << endl;
    L1.Print();
}


