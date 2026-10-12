#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STRINGS 100000
#define MAX_LENGTH 50
typedef struct {
    char strings[MAX_STRINGS][MAX_LENGTH + 1];
    int size;
} StringSet;
bool find(StringSet *set, const char *str) {
    for (int i = 0; i < set->size; ++i) {
        if (strcmp(set->strings[i], str) == 0) {
            return true;
        }
    }
    return false;
}
bool insert(StringSet *set, const char *str) {
    if (find(set, str)) {
        return false;
    }
    if (set->size < MAX_STRINGS) {
        strcpy(set->strings[set->size++], str);
        return true;
    }
    return false;
}
int main() {
    StringSet set = {.size = 0};
    char buffer[MAX_LENGTH + 1];
    while (scanf("%s", buffer) == 1 && strcmp(buffer, "*") != 0) {
        insert(&set, buffer);
    }
    char operation[10];
    while (scanf("%s", operation) == 1 && strcmp(operation, "*") != 0) {
        scanf("%s", buffer);
        if (strcmp(operation, "find") == 0) {
            printf("%d\n", find(&set, buffer));
        } else if (strcmp(operation, "insert") == 0) {
            printf("%d\n", insert(&set, buffer));
        }
    }
    return 0;
}

