#include "HuffmanTree.h"

namespace STSCLA001
{

using namespace std;

// Get Root Node
shared_ptr<HuffmanNode> HuffmanTree::getRoot(void) const
{
 return root;
}

// Create Unordered Map
unordered_map<char, int> createMap(string data)
{
 unordered_map<char, int> helper;
 for (char c: data)
 {
  helper[c]++;
 }
 return helper;
}

// Build Tree
void HuffmanTree::buildTree(string data)
{
 unordered_map<char, int> helper = createMap(data);

 // Create Priority Queue to Assist Tree Building
 priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> pq;

 // Create a Leaf Node for Each Letter in The Map
 // and Add to Queue
 for (auto node : helper)
 {
  pq.push(shared_ptr<HuffmanNode>(new HuffmanNode(node.first, node.second)));
 }

 // Create Tree from Queue
 while (pq.size() > 1)
 {
  // Remove 2 Nodes with Lowest Frequencies
  shared_ptr<HuffmanNode> l = pq.top(); pq.pop();
  shared_ptr<HuffmanNode> r = pq.top(); pq.pop();

  // Compute Sum of Frequencies
  int sum = l->getFreq() + r->getFreq();

  // Create Internal with Previous Nodes
  // as Children and Frequency Equal to
  // Sum of Children
  shared_ptr<HuffmanNode> parent;
  parent->setFreq(sum);
  parent->setLeft(l);
  parent->setRight(r);
  
  // Add Parent Node Back to Queue
  pq.push(parent);
 }
 // Queue will Now Have 1 Element Remaining
 // Set this to Root Node
 root = pq.top(); pq.pop();
} 

 // Encode Data
 string HuffmanTree::encode(string data)
 {
  unordered_map<char, string> code;
  HuffmanTree::codeTable(root, "", code);
  // Print Code Table
  cout << "Huffman Code: " << endl;
  for (auto pair: code)
  {
   cout << pair.first << " = " << pair.second << endl;
  }
  // Create Encoded String
  string encoded = "";
  for (char c: data)
  {
   encoded += code[c];
  }
  return encoded;
 }

 // Build Code Table
 void HuffmanTree::codeTable(shared_ptr<HuffmanNode> node, string s, unordered_map<char, string> & code)
 { 
  if (node == nullptr) return;
  // Check for a Leaf Node
  if (node->getLeft() == nullptr && node->getRight() == nullptr)
  {
   code[node->getLetter()] = s;
  }
  codeTable(node->getLeft(), s+"0", code);
  codeTable(node->getRight(), s+"0", code);
  }

 // Compress Data
 void HuffmanTree::compress(void)
 {

}

// Comparison Structure Used to Order the Queue
bool compare::operator()(const shared_ptr<HuffmanNode> & lhs, const shared_ptr<HuffmanNode> & rhs) const
{
 return (lhs<rhs);
}
} // namespace STSCLA001