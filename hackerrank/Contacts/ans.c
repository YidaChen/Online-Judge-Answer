#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct TrieNode 
{
    unsigned count;
    struct TrieNode *next[26];
} TrieNode;

TrieNode* new_TrieNode()
{
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    node->count = 0;
    return node;
}
void add_string(TrieNode *node, char *str)
{
    size_t i, idx, len = strlen(str);

    for(i = 0; i < len; i++)
    {
        idx = str[i]-97;
        if(!node->next[idx])
            node->next[idx] = new_TrieNode();

        node = node->next[idx];
        node->count++; //方便find starting with partial數量
    }
    //node->count++;
}
int find_partial(TrieNode *node, char *str)
{
    size_t i, idx, len = strlen(str);

    for(i = 0; i < len; i++)
    {
        idx = str[i]-97;
        if(!node->next[idx])
            return 0;

        node = node->next[idx];
    }
    return node->count;
}
int main() 
{
    int n;
    scanf("%d", &n);
    TrieNode *root = new_TrieNode();

    while(n--)
    {
        char op[5], str[22];
        scanf("%s", op);
        scanf("%s", str);

        if(strcmp(op, "add") == 0)
            add_string(root, str);
        
        else if(strcmp(op, "find") == 0)
        {
            int num = find_partial(root, str);
            printf("%d\n", num);
        }
    }
    return 0;
}
