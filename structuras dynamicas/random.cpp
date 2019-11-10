#include <iostream>

using namespace std;


struct node{
 int valor;
 struct node *sig;
};

struct node *crear(int item){
    struct node *temp = new node;
    temp->valor = item;
    temp->sig=NULL;
    return temp;

}

void insert(struct node *root,int valor){
    if(root!=NULL){
     root->sig=crear(valor);
    }
}
 void print(struct node *root){
    if(root){
        cout<<root->valor;
        print(root->sig);}
}
 int main(){
    struct node *root = NULL;
    insert(root,4);
     insert(root,3);
     insert(root,2);
     insert(root,1);
     print(root);
    return 0;
}