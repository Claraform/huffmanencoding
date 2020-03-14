#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <memory>

namespace STSCLA001
{

class HuffmanNode
{
private:
 char letter;
 int frequency;
 std::shared_ptr<HuffmanNode> left = nullptr;
 std::shared_ptr<HuffmanNode> right = nullptr;

public:
 // Constructors and Destructors
 HuffmanNode(char l, int f): letter(l), frequency(f){};
 ~HuffmanNode() = default; 

 // Getters and setters
 char getLetter(void);
 int getFreq(void);
 void setFreq(int f);

 void setLeft(std::shared_ptr<HuffmanNode> l);
 std::shared_ptr<HuffmanNode> getLeft(void);

 void setRight(std::shared_ptr<HuffmanNode> r);
 std::shared_ptr<HuffmanNode> getRight(void);

 // Overload the comparison operator
 bool operator<(const HuffmanNode &lhs);
};

} // namespace STSCLA001

#endif