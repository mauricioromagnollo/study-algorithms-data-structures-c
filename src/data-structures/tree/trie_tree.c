#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie_tree.h"

void createTrieTree(TrieTree_t *tree) {
  tree->root = getNewTrieNode();
  tree->countNode = 0;
}

trieTreeNode_t *getNewTrieNode() {
  trieTreeNode_t *node = (trieTreeNode_t *)malloc(SIZE_TRIE_TREE_NODE);
  if(node) {
    level_t level;
    node->key = 0;
    for(level = 0; level < SIZE_ALPHABET; level++) {
      node->childNode[ level ] = NULL;
    }
  }
  return node;
}

void insertTrieTreeKey(TrieTree_t *tree, char *key) {
  level_t level;
  strSize_t keySize = strlen(key);
  int index;
  trieTreeNode_t *node;

  tree->countNode++;
  node = tree->root;

  for(level = 0; level < keySize; level++) {
    index = INDEX_OF_ASCII(key[ level ]);

    if(node->childNode[ index ]) {
      node = node->childNode[ index ];
    } else {
      node->childNode[ index ] = getNewTrieNode();
      node = node->childNode[ index ];
    }
  }
  node->key = tree->countNode;
}

bool isTrieTreeKey(TrieTree_t *tree, char *key) {
  level_t level;
  strSize_t keySize = strlen(key);
  int index;
  trieTreeNode_t *node;
  node = tree->root;

  for(level = 0; level < keySize; level++) {
    index = INDEX_OF_ASCII(key[ level ]);
    if(!node->childNode[ index ]) {
      return false;
    }
    node = node->childNode[ index ];
  }
  return (0 != node && node->key);
}

bool isLeafTrieNode(trieTreeNode_t *tree) {
  return (tree->key != 0);
}

bool isFreeTrieNode(trieTreeNode_t *tree) {
  for(level_t i = 0; i < SIZE_ALPHABET; i++) {
    if(tree->childNode[i]) {
      return false;
    }
  }
  return true;
}

bool removeTrieNode(trieTreeNode_t *tree, char *key, level_t level, strSize_t strSize) {
  if(tree) {
    if(level == strSize) {
      if(tree->key) {
        tree->key = 0;
        if(isFreeTrieNode(tree)) {
          return true;
        }
        return false;
      }
    } else {
      int index = INDEX_OF_ASCII(key[ level ]);
      if(removeTrieNode(tree->childNode[ index ], key, level + 1, strSize)) {
        FREE_TRIE_NODE(tree->childNode[ index ]);
        return (!isLeafTrieNode(tree) && isFreeTrieNode(tree));       
      }
    }    
  }
  return false;
}

void removeTrieKey(TrieTree_t *tree, char *key) {
  strSize_t sizeKey = strlen(key);
  if(sizeKey > 0) {
    removeTrieNode(tree->root, key, 0, sizeKey);
  }
}
