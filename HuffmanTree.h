#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <queue>
#include <bitset>

namespace STSCLA001
{

class HuffmanTree
{
private:
 std::shared_ptr<HuffmanNode> root = nullptr;
 std::unordered_map<char, int> tree;
 int fieldcount = 0;
 std::string data = "";

public:
 // Code Table
 std::unordered_map<char, std::string> code;
 // Default constructor
 HuffmanTree() = default;
 // Destructor
 ~HuffmanTree(){ root = nullptr; };
 // Copy Constructor
 HuffmanTree(const HuffmanTree & rhs): root(rhs.root), data(rhs.data), fieldcount(rhs.fieldcount){};
 // Copy Assignment Operator
 HuffmanTree & operator=(const HuffmanTree &rhs)
 {
  if (this != &rhs)
  {
   root = rhs.root;
   data = rhs.data;
   fieldcount = rhs.fieldcount;
  }
  return *this;
 };
 // Move Constructor
 HuffmanTree(HuffmanTree && rhs): root(std::move(rhs.root)), data(std::move(rhs.data))
 {
  fieldcount = rhs.fieldcount;
  rhs.fieldcount = 0;
 };
 // Move Assignment Operator
 HuffmanTree & operator=(HuffmanTree && rhs)
 {
  if (this != &rhs)
  {
   root = std::move(rhs.root);
   data = std::move(rhs.data);
   fieldcount = rhs.fieldcount;
   rhs.fieldcount = 0;
  }
 };

 // Get Map
 std::unordered_map<char, int> getMap(void) const;
 // Get Root Node
 std::shared_ptr<HuffmanNode> getRoot(void) const; 

 // Create Unordered Frequency Map
 void createMap();

 // Build Tree
 void buildTree(std::string infile);

 // Encode Data
 void encode(std::string outfile);

 // Build Code Table
 void codeTable(std::shared_ptr<HuffmanNode> node, std::string s);

 // Compress Data
 void compress(std::string byte, std::string outfile);
};
// Comparison Structure Used to Order the Queue
struct compare
{
 bool operator()(const std::shared_ptr<HuffmanNode> & lhs, const std::shared_ptr<HuffmanNode> & rhs) const;
};
} // namespace STSCLA001
#endif
