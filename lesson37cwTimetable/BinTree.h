#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
	T info;
	Node* left;
	Node* right;

	Node(T value) { info = value; left = right = nullptr; }
	void showNode() {
		cout << "INFO: " << info << endl;
		cout << "\t Left: " << left << " Right: " << right << endl;
	}
};


template <typename U>
class BinTree {
	Node<U>* root; //Вказівник на перший вузол у дереві

	void showSubTree(Node<U>* p) {
		if (p != nullptr) {
			//cout << p->info << " "; //preOrder tree traversal
			showSubTree(p->left);
			cout << p->info << " "; //inOrder tree traversal
			showSubTree(p->right);
			//cout << p->info << " "; //postOrder tree traversal
		}
	}

	void delSubTree(Node<U>* p) {
		if (p != nullptr) {
			delSubTree(p->left);
			delSubTree(p->right);
			delete p;
		}
	}

public:
	BinTree() { root = nullptr; }
	~BinTree() {
		delSubTree(root);
		root = nullptr;
	}

	void insert(U value) {
		Node<U>* el = new Node<U>(value);
		if (root == nullptr) {
			root = el;
		}
		else {
			//find
			Node<U>* p = root;
			Node<U>* pPrev = root;
			while (p != nullptr) {
				/*if (el->info < p->info) {
					p = p->left;
				}
				else if (el->info > p->info) {
					p = p->right;
				}*/
				pPrev = p;
				p = (el->info < p->info) ? p->left : p->right;
			}
			//setting
			if (el->info < pPrev->info) pPrev->left = el;
			else pPrev->right = el;
		}
	}

	Node<U>* search(U value) {
		Node<U>* el = new Node<U>(value);
		if (root == nullptr) {
			//throw exception("Empty tree");
			cout << "Empty tree" << endl;
			return nullptr;
		}
		else {
			//find
			Node<U>* p = root;
			Node<U>* find = root;
			while (p != nullptr) {
				/*if (el->info < p->info) {
					p = p->left;
				}
				else if (el->info > p->info) {
					p = p->right;
				}*/
				find = p;
				if (find->info == el->info) { find->showNode(); return find; }
				p = (el->info < p->info) ? p->left : p->right;
			}
			return nullptr;

		}
	}

	//Повний обхід дерева
	void showTree() {
		if (root == nullptr)
			cout << "Empty tree" << endl;
		else {
			showSubTree(root);
		}
	}

};
