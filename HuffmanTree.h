#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include <memory>
#include <unordered_map>

namespace STSCLA001
{

class HuffmanTree
{
private:
 std::shared_ptr<HuffmanNode> root = nullptr;

public:
 // Default constructor
 HuffmanTree() = default;
 // Destructor
 ~HuffmanTree(){ root = nullptr; };
 // Copy Constructor
 HuffmanTree(const HuffmanTree & rhs): root(rhs.root){};
 // Copy Assignment Operator
 HuffmanTree & operator=(const HuffmanTree &rhs)
 {
  if (this != &rhs)
  {
   root = rhs.root;
  }
  return *this;
 };
 // Move Constructor
 HuffmanTree(HuffmanTree && rhs): root(std::move(rhs.root)){};
 // Move Assignment Operator
 HuffmanTree & operator=(HuffmanTree && rhs)
 {
  if (this != &rhs)
  {
   root = std::move(rhs.root);
  }
 };

 // Get Root Node
 std::shared_ptr<HuffmanNode> getRoot(void);

 // Create Unordered Map
 unordered_map<char, int> createMap(string data);

 // Build Tree
 void buildTree(string data);

 // Compress Data
 void compress(void);
};
} // namespace STSCLA001
#endif
