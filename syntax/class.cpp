#include <bits/stdc++.h>

using namespace std;

class Node {
	public:
		int size;
		virtual ~Node() = default;
};

class MidNode : public Node {
	public:
		Node* left;
		Node* right;
		
		MidNode(Node* l, Node* r) : left(l), right(r) {
			size = right->size + left->size;
		}
};

class LeafNode : public Node {
	public:
		string word;
		
		LeafNode(string w) : word(w) {
			size = word.size();
		}
};

char getKth(Node* root, int k) {
	if (k >= root->size) {
		throw string("Out of bounds");
	}
	
	MidNode* mid = dynamic_cast<MidNode*>(root);
	if (mid) {
		if (k < mid->left->size) {
			return getKth(mid->left, k);
		}
		return getKth(mid->right, k - mid->left->size);
	}
	LeafNode* leaf = dynamic_cast<LeafNode*>(root);
	return leaf->word[k];
}

int main() {
	ios::sync_with_stdio(false);
	LeafNode* rl = new LeafNode("fgh");
	LeafNode* rr = new LeafNode("ijklm");
	MidNode* r = new MidNode(rl, rr);
	
	LeafNode* l = new LeafNode("abcde");
	
	MidNode* root = new MidNode(l, r);
	
	for (int i = 0; i < root->size; i++) {
		cout << getKth(root, i) << " ";
	}
	cout << endl;
	
	try {
		getKth(root, 20);
	} catch(string ex) {
		cout << ex << endl;
	}
	
	return 0;
}
