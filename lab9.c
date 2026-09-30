#include<stdio.h>
#include<stdlib.h>
typedef struct Treenode{
 int data,ht;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
}NODE;
 NODE *Root;

NODE* createNode(int data){
    NODE *new_node;
    new_node= (NODE*) malloc(sizeof(NODE));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}
void inorder(NODE* r) {
    if (r != NULL) {
        inorder(r->leftChild);
        printf("%d(BF=%d) ", r->data, BalanceFactor(r));
        inorder(r->rightChild);
    }
}
int height(NODE* n){
    if(n == NULL)
        return 0;

    int leftHt = height(n->leftChild);
    int rightHt = height(n->rightChild);

    return (leftHt > rightHt ? leftHt : rightHt) + 1;
}
int BalanceFactor(NODE* n) {
    if (n == NULL)
        return 0;
    return height(n->leftChild) - height(n->rightChild);
}
void Tree_insert(int data) {
    NODE *y = NULL;
    NODE *t = Root;
    NODE *x = createNode(data);
    while (t != NULL) {
        y = t;
        if (x->data < t->data) {
            t = t->leftChild;
        } else {
            t = t->rightChild;
        }
    }

    x->mother = y;

    if (y == NULL) {
        Root = x;
    } else if (x->data < y->data) {
        y->leftChild = x;
    } else {
        y->rightChild = x;
    }
}
int main() {
    int a[] = {17, 3, 19, 1, 6, 18, 22, 4, 25};
    int i, size;
    size = sizeof(a) / sizeof(a[0]);

    for (i = 0; i < size; i++) {
        Tree_insert(a[i]);
    }

    inorder(Root);
    printf("\n");
return 0;
}
