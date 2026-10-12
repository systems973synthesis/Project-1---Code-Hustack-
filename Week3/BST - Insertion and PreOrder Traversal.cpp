#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BST {
    int key;
    struct BST* left;
    struct BST* right;
    struct BST* parent;
} BST;
struct BST* CreateNode(int target) {
    struct BST* new_node = (struct BST*)malloc(sizeof(struct BST));
    new_node->key = target;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
}
struct BST* Search(struct BST* Node, int target) {
    if (Node == NULL) return NULL;
    if (target < Node->key) return Search(Node->left, target);
    if (target > Node->key) return Search(Node->right, target);
    return Node;
}
struct BST* Min(struct BST* Node) {
    if (Node == NULL) return NULL;
    while (Node->left != NULL) {
        Node = Node->left;
    }
    return Node;
}
struct BST* Max(struct BST* Node) {
    if (Node == NULL) return NULL;
    while (Node->right != NULL) {
        Node = Node->right;
    }
    return Node;
}
struct BST* Predecessor(struct BST* Node) {
    if (Node == NULL) return NULL;
    if (Node->left != NULL) return Max(Node->left);
    else {
        struct BST* p = Node->parent;
        while (p != NULL && Node == p->left) {
            Node = p;
            p = p->parent; 
        }
        return p;
    }
}
struct BST* Successor(struct BST* Node) {
    if (Node == NULL) return NULL;
    if (Node->right != NULL) return Min(Node->right); 
    else {
        struct BST* p = Node->parent;
        while (p != NULL && Node == p->right) {
            Node = p;
            p = p->parent;
        }
        return p;
    }
}
struct BST* Insert(struct BST* Node, int target) {
    if (Node == NULL) return CreateNode(target); 
    if (target < Node->key) {
        struct BST* LeftChild = Insert(Node->left, target);
        Node->left = LeftChild;
        LeftChild->parent = Node;
    }
    else if (target > Node->key) {
        struct BST* RightChild = Insert(Node->right, target);
        Node->right = RightChild;
        RightChild->parent = Node;
    }
    return Node;
} 
void PreOrder(struct BST* Node) {
    if (Node == NULL) return;
    printf("%d ", Node->key);
    PreOrder(Node->left);
    PreOrder(Node->right);
}
int main() {
    struct BST* Tree = NULL;
    char ss[100];
    int t;
    while (1) {
        scanf("%s", ss);
        if (strcmp(ss, "#") == 0) break;
        if (strcmp(ss, "insert") == 0 || strcmp(ss, "add") == 0) {
            scanf("%d", &t);
            Tree = Insert(Tree, t);
        } else {
            t = atoi(ss);
            if (t != 0 || strcmp(ss, "0") == 0) {
                Tree = Insert(Tree, t);
            }
        }
    }
    PreOrder(Tree);
    return 0;
}

