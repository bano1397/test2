#include <iostream>
using namespace std;

class Node
{
  private:
    int Data;
    Node* Next;
  public:
    int GetData(){
    return Data;
  }
    Node* GetNext(){
    return Next;
  }
    void SetData(int n){
    Data = n;
  }
    void SetNext(Node* nex){
    Next = nex;   
  }
};
 
int main(){
    Node* n1 = new Node();
    Node* n2 = new Node();
    n1->SetData(13);
    n1->SetNext(n2);

    n2->SetData(15);
    n2->SetNext(NULL);

    cout<<n1->GetNext()<<endl;
    cout<<n2<<endl;
    return 0;
}


