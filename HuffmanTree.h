#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include <iostream>
#include <memory>
#include <unordered_map>
#include <queue>

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
 std::shared_ptr<HuffmanNode> getRoot(void) const; 

 // Create Unordered Map
 std::unordered_map<char, int> createMap(std::string data);

 // Build Tree
 void buildTree(std::string data);

 // Encode Data
 std::string encode(std::string data);

 // Build Code Table
 void codeTable(std::shared_ptr<HuffmanNode> node, std::string s, std::unordered_map<char, std::string> & code);

 // Compress Data
 void compress(void);
};
// Comparison Structure Used to Order the Queue
struct compare
{
 bool operator()(const std::shared_ptr<HuffmanNode> & lhs, const std::shared_ptr<HuffmanNode> & rhs) const;
};
} // namespace STSCLA001
#endif
