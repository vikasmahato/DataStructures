class BSTNode {
private:
	BSTNode *left_;
	BSTNode *right_;
	int data_;
public:
	BSTNode(int data) : left_(nullptr), right_(nullptr), data_(data) {}
	BSTNode* getLeft() { return left_; }
	void setLeft(BSTNode* left) { left_ = left; }

	BSTNode* getRight() { return right_; }
	void setRight(BSTNode* right) { right_ = right; }

	int getData() { return data_; }
};

class BST {
public:
	BST() : root(nullptr) {}

	// insert value into tree
	void insert(int value) {
		BSTNode *node = new BSTNode(value);

		if( root == nullptr){ // empty tree
			root = node;
			return;
		}

		 
	}

	// get count of values stored
	int get_node_count() {

	}

	// prints the values in the tree, from min to max
	void print_values() {

	}

	void delete_tree() {

	}

	// returns true if given value exists in the tree
	bool is_in_tree(int value) {

	}

	// returns the height in nodes (single node's height is 1)
	int get_height() {

	}

	// returns the minimum value stored in the tree
	int get_min() {

	}

	// returns the maximum value stored in the tree
	int get_max() {

	}

	bool is_binary_search_tree() {

	}

	void delete_value(int value) {

	}

	// returns next-highest value in tree after given value, -1 if none
	int get_successor(int value) {

	}

private:
	BSTNode *root;

};