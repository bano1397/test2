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
    Node* Search(int a) {
        Node* tempNode = CurrentLocation;
        while (tempNode != NULL) {
            if (tempNode->GetData() == a) {
            cout << a << " found in the list" << endl;
                return tempNode;  
            }
            tempNode = tempNode->GetNext();
        }
        cout << a << " not found in the list" << endl;
        return NULL;  
    }


};

int main(){
	List L1;
	L1.Insert(2);
	L1.Insert(10);
	L1.Insert(3);
	L1.Print();
	L1.Search(10);
	L1.Search(100);
}


