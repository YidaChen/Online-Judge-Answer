#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Trie
{
    unsigned count;
    bool isLastStr;
    struct Trie *next[26];
} Trie;

Trie* new_Trie()
{
    Trie *node = (Trie*)malloc(sizeof(Trie));
    node->count = 0;
    node->isLastStr = false;
    return node;
}
bool add_string(Trie *node, char *str)
{
    size_t i, len = strlen(str);
    for(i = 0; i < len; i++)
    {
        if(!node->next[str[i]-'a'])
            node->next[str[i]-'a'] = new_Trie();

        node = node->next[str[i]-'a'];
        node->count++;
        //如果找到prefix
        if(node->isLastStr && node->count > 1)
            return true;
    }
    //如果自己就是prefix
    if((node->isLastStr = true) && node->count > 1)
        return true;
    return false;
}
int main()
{
    int n;
    scanf("%d", &n);
    char str[n][61];
    Trie *root = new_Trie();

    for(int i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
        if(add_string(root, str[i]))
        {
            printf("BAD SET\n%s", str[i]);
            return 0;
        }
    }
    printf("GOOD SET");
    return 0;
}
