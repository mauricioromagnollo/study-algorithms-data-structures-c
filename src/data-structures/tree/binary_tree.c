#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void createBinaryTree(BinaryTree_t **tree) {
  *tree = NULL;
}

bool isEmptyBinaryTree(BinaryTree_t **tree) {
  return (*tree == NULL);
}

void insertItemInBinaryTree(BinaryTree_t **tree, item_t item) {
  if(*tree == NULL) {
    *tree = (nodeBinaryTreePtr_t *)malloc(BINARY_TREE_NODE_SIZE);
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    (*tree)->item.key = item.key;
  } else {
    if(item.key < ((*tree)->item.key)) {
      insertItemInBinaryTree(&((*tree)->left), item);
    } else {
      insertItemInBinaryTree(&((*tree)->right), item);
    }
  }
}

counter_t countBinaryTreeNodes(BinaryTree_t *tree) {
  if(tree == NULL) {
    return 0;
  } else {
    return 1 + countBinaryTreeNodes(tree->left) + countBinaryTreeNodes(tree->right);
  }
}

counter_t countBinaryTreeLeafs(BinaryTree_t *tree) {
  if(tree == NULL) {
    return 0;
  }
  
  if(tree->left == NULL && tree->right == NULL) {
    return 1;
  }

  return countBinaryTreeLeafs(tree->left) + countBinaryTreeLeafs(tree->right);
}

void printBinaryTree(BinaryTree_t *tree) {
  if(tree != NULL) {
    printBinaryTree(tree->left);
    printf("\n%d", tree->item.key);
    printBinaryTree(tree->right);
  }
}

bool isItemExistInBinaryTree(item_t itemSearched, BinaryTree_t *tree) {
  if(tree == NULL) {
    return false;
  } else if(tree->item.key < itemSearched.key) {
    return isItemExistInBinaryTree(tree->right, itemSearched);
  } else if(tree->item.key > itemSearched.key) {
    return isItemExistInBinaryTree(tree->right, itemSearched);
  } else {
    return true;
  }
}

binaryTreeHeight_t getBinaryTreeHeight(BinaryTree_t *tree) {
  if((tree == NULL) || (tree->left == NULL && tree->right == NULL)) {
    return 0;
  } else {
    return 1 + GET_BIGGER(getBinaryTreeHeight(tree->left), getBinaryTreeHeight(tree->right));
  }
}

bool isStrictlyBinary(BinaryTree_t *tree) {
  if(!tree->right && !tree->left) {
    return 1;
  }
  if(tree->right && tree->left) {
    return (isStrictlyBinary(tree->left) && isStrictlyBinary(tree->right));
  }
}