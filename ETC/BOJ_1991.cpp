#include <iostream>

using namespace std;

template<typename T>
class BinaryNode
{
	T data;
	BinaryNode* left;
	BinaryNode* right;
public:
	BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r=NULL):
		data(val), left(l), right(r) { }
	T getData() {return data;}
	BinaryNode* getLeft() {return left;}
	BinaryNode* getRight() {return right;}
	
	void setLeft(BinaryNode* l) { left = l;} 
	void setRight(BinaryNode* r) {right = r;}
};
		
template<typename T>
class BinaryTree
{								  
	BinaryNode<T>* root;

public:
	BinaryTree(): root(NULL) { }
	void setRoot(BinaryNode<T>* node) {root = node;}
	
	void inorder() {inorder(root); cout << endl;}
	void inorder(BinaryNode<T>* node)
	{
		if(node != NULL)
		{
			inorder(node->getLeft());
			cout << node->getData();
			inorder(node->getRight());
		}
	}
	
	void preorder() {preorder(root); cout << endl;}
	void preorder(BinaryNode<T>* node)
	{
		if(node != NULL)
		{
			cout << node->getData();
			preorder(node->getLeft());
			preorder(node->getRight());
		}
	}
	
	void postorder() {postorder(root); cout << endl;}
	void postorder(BinaryNode<T>* node)
	{
		if(node != NULL)
		{
			postorder(node->getLeft());
			postorder(node->getRight());
			cout << node->getData();
		}
	}
};

int main(int argc, char* argv[]) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	BinaryNode<char>* node_arr = new BinaryNode<char>[N];
	
	for(int i=0; i<N; i++)
	{
		char data = i + 'A';
		BinaryNode<char> *node = new BinaryNode<char>(data, NULL, NULL); 
		node_arr[i] = *node;
	}
	
	for(int i=0; i<N; i++)
	{
		char node_data, l_data, r_data;
		cin >> node_data >> l_data >> r_data;
			
		BinaryNode<char>* node = &node_arr[node_data-'A'];
		BinaryNode<char>* l;
		BinaryNode<char>* r;
		
		if(l_data != '.')
		{
			l = &node_arr[l_data - 'A'];
			node->setLeft(l);
		}
		
		if(r_data != '.')
		{
			r = &node_arr[r_data- 'A'];
			node->setRight(r);	
		}
	}
	
	BinaryTree<char> tree;
	tree.setRoot(&node_arr[0]);
	
	tree.preorder();
	tree.inorder();
	tree.postorder();
}