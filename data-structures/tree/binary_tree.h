#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

typedef enum { false, true} bool;

#define GET_BIGGER(a, b) (a > b) ? (a) : (b);

typedef int key_t;
typedef unsigned int counter_t;
typedef unsigned int binaryTreeHeight_t;

typedef struct {
  key_t key;
} item_t;

typedef struct node *nodeBinaryTreePtr_t;

typedef struct node {
  item_t item;
  nodeBinaryTreePtr_t left;
  nodeBinaryTreePtr_t right;
} BinaryTree_t;

#define BINARY_TREE_NODE_SIZE sizeof(BinaryTree_t)

void createBinaryTree(BinaryTree_t **);
bool isEmptyBinaryTree(BinaryTree_t **);
void insertItemInBinaryTree(BinaryTree_t **, item_t);
counter_t countBinaryTreeNodes(BinaryTree_t *);
counter_t countBinaryTreeLeafs(BinaryTree_t *);
void printBinaryTree(BinaryTree_t *);
bool isItemExistInBinaryTree(item_t, BinaryTree_t *);
binaryTreeHeight_t getBinaryTreeHeight(BinaryTree_t *);
bool isStrictlyBinary(BinaryTree_t *);

#endif