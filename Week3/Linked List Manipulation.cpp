#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
} Node;

struct Node *createNode(int key) {
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = key;
	new_node->prev = NULL;
	new_node->next = NULL;
	return new_node;
}

struct Node* reverse(struct Node* head) {
    if (head == NULL) return NULL;
    struct Node* temp = NULL;
    struct Node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
}

struct Node* addfirst(struct Node* head, int key) {
	struct Node* new_node = createNode(key);
	new_node->next = head;
	if (head != NULL) {
		head->prev = new_node;
	}
	return new_node;	
}

struct Node* addlast(struct Node* head, int key) {
    struct Node* new_node = createNode(key);
    if (head == NULL) {
        return new_node;  
    }
    struct Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
    return head;  
}

int search(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 0;
    while (temp != NULL) {
    	pos++;
        if (temp->data == key) {
            return pos; 
        }
        temp = temp->next;
    }
    return -1; 
}

struct Node* addbefore(struct Node* head, int u, int v) {
    if (head == NULL) return head;
    struct Node* temp = head;
    while (temp != NULL && temp->data != u) {
        temp = temp->next;
    }
    if (temp == NULL) return head;  
    struct Node* new_node = createNode(v);
    new_node->next = temp;
    new_node->prev = temp->prev;
    if (temp->prev) {
        temp->prev->next = new_node;
    } 
    else {
        head = new_node; 
    }
    temp->prev = new_node;
    return head;
}

struct Node* addafter(struct Node* head, int u, int v) {
    if (head == NULL) return head;
    struct Node* temp = head;
    while (temp != NULL && temp->data != u) {
        temp = temp->next;
    }
    if (temp == NULL) return head; 
    struct Node *new_node = createNode(v);
    new_node->prev = temp;
    new_node->next = temp->next;
    if (temp->next) { 
        temp->next->prev = new_node;
    }
    temp->next = new_node;
    return head;
}

struct Node *delPos(struct Node *head, int pos) { 
    if (head == NULL || pos <= 0) {
        return head;
    }
    struct Node *curr = head;
    for (int i = 1; curr && i < pos; i++) {
        curr = curr->next;
    }
    if (curr == NULL) return head;  

    if (curr->prev) {
        curr->prev->next = curr->next;
    }
    if (curr->next) {
        curr->next->prev = curr->prev;
    }
    if (head == curr) {
        head = curr->next; 
    }
    free(curr);
    return head;
}

void ForwardTraversal(struct Node* head) { 
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
	struct Node* head = NULL;
	int n, a[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		head = addlast(head, a[i]);
	}
	char s[30], ss[10];
	int u, v;
	while(1) {
		fgets(s, sizeof(s), stdin);
		s[strcspn(s, "\n")] = '\0';
		if (strcmp(s, "#") == 0) {
			break;
		}
		else {
			if (strstr(s, "addafter") != NULL) {
				sscanf(s, "%s %d %d", ss, &u, &v);
				if (search(head, v) != -1 && search(head, u) == -1) {
				    head = addafter(head, v, u);
			        //ForwardTraversal(head);
				}
			}
			if (strstr(s, "addbefore") != NULL) {
				sscanf(s, "%s %d %d", ss, &u, &v);
				if (search(head, v) != -1 && search(head, u) == -1) {
				    head = addbefore(head, v, u);
			        //ForwardTraversal(head);
				}
			}
			if (strstr(s, "remove") != NULL) {
				sscanf(s, "%s %d", ss, &u);
				int pos = search(head, u);
				if (pos != -1) {
                    head = delPos(head, pos);
                    //ForwardTraversal(head);
                }
			}
			if (strstr(s, "reverse") != NULL) {
				head = reverse(head);
				//ForwardTraversal(head);
			}
			if (strstr(s, "addfirst") != NULL) {
				sscanf(s, "%s %d", ss, &u);
				if (search(head, u) == -1) {
					head = addfirst(head, u);
					//ForwardTraversal(head);
				}
			}
			if (strstr(s, "addlast") != NULL) {
				sscanf(s, "%s %d", ss, &u);
				if (search(head, u) == -1) {
					head = addlast(head, u);
					//ForwardTraversal(head);
				}
			}
		}
	}
	ForwardTraversal(head);
}

