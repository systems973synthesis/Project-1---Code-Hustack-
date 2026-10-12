#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SZ 1005
typedef struct Tree {
    char str[100];
    struct Tree *FirstChild;
    struct Tree *NextSibling;
} Tree;

Tree* Nodes[SZ];
int CntNode = 0;

struct Tree *CreateNode(char* ss) {
	Tree *newNode = (Tree *)malloc(sizeof(Tree));
	strcpy(newNode->str, ss);
	newNode->FirstChild = NULL;
    newNode->NextSibling = NULL;
	return newNode;
}

Tree* GetNode(char* ss) {
	for (int i = 0; i < CntNode; i++) {
		if (strcmp(Nodes[i]->str, ss) == 0) return Nodes[i];
	}
	Tree* newNode = CreateNode(ss);
	Nodes[CntNode++] = newNode;
	return newNode;
}

void AddChild(Tree* child, Tree* parent) {
	if (parent == NULL || child == NULL) return;
	if (parent->FirstChild == NULL) {
		parent->FirstChild = child;
	}
	else {
		Tree* temp = parent->FirstChild;
		while (temp->NextSibling) {
			temp = temp->NextSibling;
		}
		temp->NextSibling = child;
	}
}

int Height(Tree* node) {
    if (!node) return -1;
    int hMax = -1;
    for (Tree* c = node->FirstChild; c; c = c->NextSibling) {
        int h = Height(c);
        if (h > hMax) hMax = h;
    }
    return hMax + 1;
}

int Leaves(Tree* node) {
    if (!node) return 0;
    int cnt = 0;
    for (Tree* c = node->FirstChild; c; c = c->NextSibling) {
        cnt += 1 + Leaves(c); 
    }
    return cnt;
}

int main() {
    char Ss[100], s1[50], s2[50], Cmd[100], yc[50], s3[50];
	while (1) {
	    fgets(Ss, sizeof(Ss), stdin);
		Ss[strcspn(Ss, "\n")] = '\0';
		if (strcmp(Ss, "***") == 0) break;
		else {
			sscanf(Ss, "%s %s", s1, s2);
			Tree* ss2 = GetNode(s2);
            Tree* ss1 = GetNode(s1);
			AddChild(ss1, ss2);
		}
	}
	while (1) {
		fgets(Cmd, sizeof(Cmd), stdin);
		Cmd[strcspn(Cmd, "\n")] = '\0';
		if (strcmp(Cmd, "***") == 0) break;
		else {
			sscanf(Cmd, "%s %s", yc, s3);
			Tree* ss3 = GetNode(s3);
			if (strstr(Cmd, "descendants") != 0) printf("%d\n", Leaves(ss3));
			else printf("%d\n", Height(ss3));
		}
	}
	return 0;                          
}

