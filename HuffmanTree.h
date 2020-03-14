#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include <memory>

namespace STSCLA001
{

class HuffmanTree
{
private:
 std::shared_ptr<HuffmanNode> root;

public:
 // Default constructor
 HuffmanTree();
 // Destructor
 ~HuffmanTree();
 // Copy Constructor
 HuffmanTree(const HuffmanTree &rhs) : root(rhs.root){};
 // Copy Assignment Operator
 HuffmanTree &operator=(const HuffmanTree &rhs){};
 // Move Constructor
 HuffmanTree(HuffmanTree &&rhs) : root(std::move(rhs.root)){};
 // Move Assignment Operator
 HuffmanTree &operator=(HuffmanTree &&rhs){};

 // Get Root Node
 std::shared_ptr<HuffmanNode> getRoot(void);

 // Build Tree
 void buildTree(void){};

 // Compress Data
 void compress(void){};
};
} // namespace STSCLA001
#endif
