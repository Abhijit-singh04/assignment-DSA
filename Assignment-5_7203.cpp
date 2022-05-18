#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the 
//return lowest frequency
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}
	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "Huffman Codes are :\n" << '\n';
	for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}
	cout << "\nOriginal string was :\n" << text << '\n';
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "\nEncoded string is :\n" << str << '\n';

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
	cout<<"\n";
}


int main()
{
    string text;
    bool flag = true;
    while(flag){
    cout<<"------------MENU------------\n";
    cout<<"1.Enter the string \n";
    cout<<"2.Get the encoding and decoding of data\n";
    cout<<"3.Exit\n";
    cout<<"Enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:{
            cout<<"Enter the string\n";
            cin>>text;
            break;
        }
        case 2:{
            buildHuffmanTree(text);
            break;
        }
        case 3:{
            cout<<"Thank you\n";
            flag =false;
            break;
        }
        default :{
            cout<<"Enter the correct choice\n";
            break;
        }
    }
    }
	return 0;
}