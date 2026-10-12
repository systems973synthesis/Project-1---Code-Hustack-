#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SZ 1005
typedef struct Tree {
	int id;
	struct Tree *children[SZ];
	int child_count;
} Tree;

Tree *nodes[SZ];
Tree *root = NULL;

struct Tree *createNode(int data) {
	Tree *newNode = (Tree *)malloc(sizeof(Tree));
	newNode->id = data;
	newNode->child_count = 0;
	return newNode;
}

void MakeRoot(int data) {
	if (root == NULL) {
		root = createNode(data);
		nodes[data] = root;
	}
}

void Insert(int u, int v) {
	if (nodes[u] || !nodes[v]) return;
	Tree *parent = nodes[v];
	Tree *newNode = createNode(u);
	nodes[u] = newNode;
	parent->children[parent->child_count++] = newNode;
}

void PreOrder(Tree *node) {
	if (!node) return;
    printf("%d ", node->id);
	for (int i = 0; i < node->child_count; i++) {
	    PreOrder(node->children[i]);
	}
}

void InOrder(Tree *node) {
    if (!node) return;
	if (node->child_count > 0) {
	    InOrder(node->children[0]);
	}
	printf("%d ", node->id);
	for (int i = 1; i < node->child_count; i++) {
	    InOrder(node->children[i]);
	}
}

void PostOrder(Tree *node) {
    if (!node) return;
	for (int i = 0; i < node->child_count; i++) {
	    PostOrder(node->children[i]);
	}
	printf("%d ", node->id);
}

int main() {
    char Ss[105], s[55];
    int u, v;
	while (1) {
	    fgets(Ss, sizeof(Ss), stdin);
		Ss[strcspn(Ss, "\n")] = '\0';
		if (strcmp(Ss, "*") == 0) break;
		else {
			if (strstr(Ss, "MakeRoot") != NULL) {
				sscanf(Ss, "%s %d", s, &u);
				MakeRoot(u);
			}
			else if (strstr(Ss, "Insert") != NULL) {
				sscanf(Ss, "%s %d %d", s, &u, &v);
				Insert(u, v);
			}
			else if (strstr(Ss, "PreOrder") != NULL) {
				PreOrder(root);
				printf("\n");
			}
			else if (strstr(Ss, "InOrder") != NULL) {
				InOrder(root);
				printf("\n");
			}
			else if (strstr(Ss, "PostOrder") != NULL) {
				PostOrder(root);
				printf("\n");
			}
		}
	}
}

