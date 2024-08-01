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
    void FindMinimum() {
        if (CurrentLocation == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node *tempNode = CurrentLocation;
        int minValue = tempNode->GetData();
        while (tempNode != NULL) {
            if (tempNode->GetData() < minValue) {
                minValue = tempNode->GetData();
            }
            tempNode = tempNode->GetNext();
        }
        cout << "Minimum value in the list: " << minValue << endl;
    }


};

int main(){
	List L1;
	L1.Insert(2);
	L1.Insert(10);
	L1.Insert(3);
	L1.Print();
	L1.FindMinimum();
}


