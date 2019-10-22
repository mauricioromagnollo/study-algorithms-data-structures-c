#ifndef TRIE_TREE_H_INCLUDED
#define TRIE_TREE_H_INCLUDED

typedef enum { false, true } bool;

#define SIZE_ARRAY_TRIE(a) sizeof(a)/sizeof(a[0])
#define SIZE_ALPHABET 26
#define INDEX_OF_ASCII(c) ((int)c - (int)'a')

#define FREE_TRIE_NODE(p) \
  free(p); \
  p = NULL; \

typedef int key_t;
typedef int counter_t;
typedef int level_t;
typedef unsigned int strSize_t;
typedef struct node trieTreeNode_t;

struct node {
  key_t key;
  trieTreeNode_t *childNode[ SIZE_ALPHABET ];
};

#define SIZE_TRIE_TREE_NODE sizeof(trieTreeNode_t)

typedef struct {
  trieTreeNode_t *root;
  counter_t countNode;
} TrieTree_t;

void createTrieTree(TrieTree_t *);
trieTreeNode_t *getNewTrieNode();
void insertTrieTreeKey(TrieTree_t *, char *);
bool isTrieTreeKey(TrieTree_t *, char *);
bool isLeafTrieNode(trieTreeNode_t *);
bool isFreeTrieNode(trieTreeNode_t *);
bool removeTrieNode(trieTreeNode_t *, char *, level_t, strSize_t);
void removeTrieKey(TrieTree_t *, char *);

#endif