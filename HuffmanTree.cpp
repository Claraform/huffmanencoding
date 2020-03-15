#include "HuffmanTree.h"

namespace STSCLA001
{

using namespace std;

// Get Map
 std::unordered_map<char, int> HuffmanTree::getMap(void) const
 {
  return tree;
 }

// Get Root Node
shared_ptr<HuffmanNode> HuffmanTree::getRoot(void) const
{
 return root;
}

// Create Unordered Frequency Map
void HuffmanTree::createMap()
{
 for (char c: data)
 {
  tree[c]++;
 }
 fieldcount = tree.size();
}

// Build Tree
void HuffmanTree::buildTree(string infile)
{
 // Read Input File
 ifstream ifs(infile);
 if (!ifs)
 {
  cout << "Error opening " << infile << " ASCII file." << endl;
  cout << "Does the file exist in the working directory?" << endl;
  return;
 }
 string temp;
 while(getline(ifs, temp))
 {
  if (temp != "")
  {
   data += temp;
  }
 }
 ifs.close();

 // Create Frequency Map 
 createMap();

 // Create Priority Queue to Assist Tree Building
 priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, compare> pq;

 // Create a Leaf Node for Each Letter in The Map
 // and Add to Queue
 for (auto node : tree)
 {
  pq.push(shared_ptr<HuffmanNode>(new HuffmanNode(node.first, node.second)));
 }

 // Create Tree from Queue
 while (pq.size() != 1)
 {
  // Remove 2 Nodes with Lowest Frequencies
  shared_ptr<HuffmanNode> l = pq.top(); pq.pop();
  shared_ptr<HuffmanNode> r = pq.top(); pq.pop();
 
  // Compute Sum of Frequencies
  int sum = l->getFreq() + r->getFreq();

  // Create Internal with Previous Nodes
  // as Children and Frequency Equal to
  // Sum of Children
  shared_ptr<HuffmanNode> parent(new HuffmanNode());
  
  parent->setFreq(sum);
 
  parent->setLeft(l);
  
  parent->setRight(r);
 
  // Add Parent Node Back to Queue
  pq.push(parent);
 }
 // Queue will Now Have 1 Element Remaining
 // Set this to Root Node
 root = pq.top(); 
 //pq.pop();
} 

 // Encode Data
 void HuffmanTree::encode(string outfile)
 {
  
  codeTable(root, "");

  // Save Code Table to File
  ofstream ofs(outfile + ".hdr");
  ofs << fieldcount << endl;
  for (auto pair: code)
  {
   ofs << pair.first << "\t" << pair.second << endl;
  }
  ofs.close();

  // Create Encoded String
  string encoded = "";
  for (char c: data)
  {
   string temp = code[c];
   compress(temp, outfile);
   encoded += temp;
  }
  // Write Encoded String to File
  ofstream of(outfile + ".out");
  of << encoded;
  of.close();
 }

 // Build Code Table
 void HuffmanTree::codeTable(shared_ptr<HuffmanNode> node, string s)
 { 
  if (node == nullptr) 
  {
   return;
  }
  // Check for a Leaf Node
  if (node->getLeft() == nullptr && node->getRight() == nullptr)
  {
   code[node->getLetter()] = s;
   s = "";
  }
  codeTable(node->getLeft(), s+"0");
  codeTable(node->getRight(), s+"1");
  }

 // Compress Data
 void HuffmanTree::compress(string byte, string outfile)
 {
  bitset<1> b(byte);
  unsigned long n = b.to_ulong();
  unsigned char c = static_cast<unsigned char>(n);
  streampos size;
  ofstream ofs(outfile + ".bin", ios::app|ios::out|ios::binary);
  if (ofs.is_open())
  {
   ofs.write(reinterpret_cast<char*>(&n), 8);
  }

 }

 // Comparison Structure Used to Order the Queue
 bool compare::operator()(const shared_ptr<HuffmanNode> &lhs, const shared_ptr<HuffmanNode> &rhs) const
 {
  return (*lhs) > (*rhs);
}
} // namespace STSCLA001