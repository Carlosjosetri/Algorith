#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct node{
    char key;
    struct node *left,*rigth;
};

struct node *NewNode(char key){
    struct node *temp = new node;
    temp->key=key;
    temp->left=temp->rigth=NULL;
    return temp;
}
void preorder2(struct node *root){
    if (root != NULL){
        //preorder(root);
        cout<<root->key<<" ";
        preorder2(root->left);
        preorder2(root->rigth);
    }
}
struct node* insert(struct node *root,char item){
    if(root==NULL)return NewNode(item);
    if(item>root->key)root->rigth= insert(root->rigth,item);
    if(item<root->key)root->left = insert(root->left,item);
    return root;

}
bool find(struct node *root,char item){
    if(root==NULL)return false;
    if(root->key==item)return true;
    if(item>root->key)return insert(root->rigth,item);
    if(item<root->key)return insert(root->left,item);


}

int main() {

    struct node *root = NULL;
    root = insert(root, 'g');
    root = insert(root, 'b');
    root = insert(root, 'z');
    root = insert(root, 'b');
    root = insert(root, 'p');
    root = insert(root, 'o');
    root = insert(root, 'e');

    cout<<find(root,'z');

}