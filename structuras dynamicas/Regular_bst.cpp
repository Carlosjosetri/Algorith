#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

struct node{
    int key;
    struct node *left, *right;
};

// Estructura para crear nodos de un arbol.
struct node *nuevoNodo(int item){
    struct node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Funcion para imprimir datos del arbol, en orden(izquierdo,root,derecho).
void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}
//Funcion para imprimir datos del arbol, en preorder(root,izquierdo,derecho)
void preorder(struct node *root){
    if (root != NULL){
        //preorder(root);
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//Funcion para imprimir datos del arbol, en postorder(izquierdo,derecho,root)

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
}

/* Funcion para insertar un nuevo nodo al BST, dada una llave*/
struct node* insert(struct node* node, int key){
    /* Si el arbol esta vacio, retorna un nuevo nodo*/
    if (node == NULL) return nuevoNodo(key);

    /* De lo contrario, se recorre el arbol*/
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* retorna el puntero del nodo (sin cambio)*/
    return node;
}



int ancestro(struct node *root,int a,int b){

    if(root->key < a && root->key < b){
        return ancestro(root->right,a,b);
    }
    if(root->key > a && root->key > b){
        return ancestro(root->left,a,b);
    }
    if(root->key > a && root->key < b){
        return root->key;
    }

}

int suma(struct node *root,int n){

    if(root!=nullptr){
        if(n < root->key ){
            return 1+suma(root->left,n);
        }
        else if( n > root->key ){
            return 1+suma(root->right,n);
        }
        if(root->key == n)
            return 1;
    }
    return 0;
}


int aux (struct node *root,int a,int b){
    if(root!=NULL){
        if(root->key < a && root->key < b){
            return aux(root->right,a,b);
        }
        if(root->key > a && root->key > b){
            return aux(root->left,a,b);
        }
        if(root->key > a && root->key < b){
            return suma(root->left,a)+ suma(root->right,b);
        }
    }else{
        return -1;
    }
}

/* Dado un arbol no vacio, retorna el nodo con el valor de llave minimo encontrado en ese arbol.
El arbol entero no necesita ser recorrido */
struct node * minValueNode(struct node* node){
    struct node* current = node;

    /* Recorre el arbol hasta encontrar la hoja mas a la izquierda */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Dado un BST y una llave, elimina la llave y retorna el nuevo root  */
struct node* deleteNode(struct node* root, int key){// base case
    if (root == NULL) return root;// If the key to be deleted is smaller than the root's key,// then it lies in left subtree
    if (key < root->key)root->left = deleteNode(root->left, key);// If the key to be deleted is greater than the root's key,// then it lies in right subtree
    else if (key > root->key)root->right = deleteNode(root->right, key);// if key is same as root's key, then This is the node// to be deleted
    else{// node with only one child or no child
        if (root->left == NULL){struct node *temp = root->right;free(root);return temp;}
        else if (root->right == NULL){struct node *temp = root->left;free(root);return temp;}// node with two children: Get the inorder successor (smallest// in the right subtree)
        struct node* temp = minValueNode(root->right);
// Copy the inorder successor's content to this node
        root->key = temp->key;// Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);}return root;}


int mainr(){
    /* Creamos el siguiente arbol
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    //root=insert (root,100);
    //root =insert (root,1);

    cout<<aux(root,20,40)<<endl;
    return 0;
}