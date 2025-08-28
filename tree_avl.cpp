//AVL-Cây nhị phân cân bằng

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
typedef struct node {
	int data;
	int height;
	node* left;
	node* right;
};

typedef node* tree_avl;
void del_tree_avl(tree_avl& root) {
	if (root == nullptr)return;
	del_tree_avl(root->left);
	del_tree_avl(root->right);
	delete root;
	root = nullptr;
}

///////////////
void init(tree_avl& root);
int height(tree_avl root);
node* get_node(int x);
void right_rotate(tree_avl& root);
void left_rotate(tree_avl& root);
int get_balance(tree_avl root);

node* max_left_node(node*  root);
void insert_node(tree_avl& root, int x);
void create_tree_avl(tree_avl& root, int x);
void del_node(tree_avl& root, int x);
int search(tree_avl root, int x);
void NLR(tree_avl root); //Duyet truoc
void LNR(tree_avl root); //Duyet giua
void LRN(tree_avl root); //Duyet sau
void menu();             //Tao menu
int main() {
	menu();
	return 0;
}
void init(tree_avl& root) {
	root = nullptr;

}

int height(tree_avl root) {
	if (root != nullptr) {
		return root->height;
	}
	return 0;
}

node* get_node(int x) {
	node* p;
	p = new node;
	if(p != nullptr) {
		p->data = x;
		p->height = 1;
		p->left = p->right = nullptr;
		return p;
	}
	return nullptr;
}

void right_rotate(tree_avl& root) {
	node* p;
	p = root->left;
	root->left = p->right;
	p->right = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	p->height = max(height(p->left), height(p->right)) + 1;
	root = p;
}

void left_rotate(tree_avl& root) {
	node* p;
	p = root->right;
	root->right = p->left;
	p-> left = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	p->height = max(height(p->left), height(p->right)) + 1;
	root = p;
}

int get_balance(tree_avl root) {
	if (root != nullptr)return height(root->left) - height(root->right);
	return 0;
}

void insert_node(tree_avl& root, int x) {
	int bal;
	if (root == nullptr) {
		root = get_node(x);
	}
	else {
		if (x < root->data) insert_node(root->left, x);
		else insert_node(root->right, x);
		root->height = max(height(root->left), height(root->right)) + 1;
		bal = get_balance(root);
		if (bal > 1 && x< root->left->data ) right_rotate(root);
		else if (bal < -1 && x > root->right->data)left_rotate(root);
		else if(bal > 1) { left_rotate(root->left); right_rotate(root); }
		else if( bal<-1) { right_rotate(root->right); left_rotate(root); }
	}

}

void create_tree_avl(tree_avl& root, int n) {
	int i,x;
	for (int i = 0; i < n; i++) {
		cout<<"Nhap phan tu thu "<<i<<": "; cin>>x;
		insert_node(root, x);
	}
}

node* max_left_node(node* root) {
	node* cur = root->left;
	while (cur->right != nullptr) {
		cur = cur->right;
	}
	return cur;
}

void del_node(tree_avl& root, int x) {
	if (root == nullptr) return ;

	if (x < root->data) {
		del_node(root->left, x);
	}
	else if (x > root->data)
		del_node(root->right, x);
	else {
		// Trường hợp 1: Không có hoặc chỉ có 1 con
		if (root->left == nullptr || root->right == nullptr) {
			node* temp = root->left ? root->left : root->right;
			if (temp == nullptr) { // Không có con
				temp = root;
				root = nullptr;
			}
			else { // Có một con
				*root = *temp;
			}
			delete temp;
		}
		// Trường hợp 2: Có 2 con
		else {
			node* temp = max_left_node(root);
			root->data = temp->data;
			del_node(root->left, temp->data);
		}
	}

	// Nếu sau xóa cây rỗng
	if (root == nullptr) return;

	// Cập nhật lại chiều cao
	root->height = 1 + max(height(root->left), height(root->right));

	// Cân bằng lại
	int bal = get_balance(root);

	// Lệch trái
	if (bal > 1 && get_balance(root->left) >= 0) {
		right_rotate(root);
	}
		
	if (bal > 1 && get_balance(root->left) < 0) {
		left_rotate(root->left);
		right_rotate(root);
	}

	// Lệch phải
	if (bal < -1 && get_balance(root->right) <= 0)
		left_rotate(root);
	if (bal < -1 && get_balance(root->right) > 0) {
		right_rotate(root->right);
		left_rotate(root);
	}

	return ;
}

int search(tree_avl root, int x) {
	node* p;
	p = root;
	if (p != nullptr) {
		while (p != nullptr) {
			if (x < p->data) p = p->left;
			else  if (x > p->data)p = p->right;
			else return 1;
		}
	}
	return 0;
}

void NLR(tree_avl root)    //Duyet truoc ( tien thu tu)
{
	if (root == nullptr)return;
	cout << "\t" << root->data;
	NLR(root->left);
	NLR(root->right);
}

void LNR(tree_avl root) //Duyet giua ( trung thu tu)
{
	if (root == nullptr)return;
	LNR(root->left);
	cout << "\t" << root->data;
	LNR(root->right);
}

void LRN ( tree_avl root){//Duyet sasu( hau thu tu)
	if (root == nullptr)return;
	LRN(root->left);
	LRN(root->right);
	cout<<"\t"<<root-> data;

}

void menu() {
	int k;
	tree_avl root = nullptr;
	int n, i, x;
tt:
	system("CLS");
	cout << "-------------------------MENU----------------------\n";
	cout << "1. Khoi tao cay AVL\n";
	cout << "2. Tim kiem\n";
	cout << "3. Chen\n";
	cout << "4. Xoa\n";
	cout << "5. Duyet NLR\n";
	cout << "6. Duyet LNR\n";
	cout << "7. Duyet LRN\n";
	cout << "0. Thoat\n";
	cout << "\n";
	cout << "Hay chon tu 0-> 7: "; cin >> k;
	cout << "\n";
	switch (k) {
	case 1: init(root);
		cout << "Nhap so phan tu n= "; cin >> n;
		create_tree_avl(root, n);
		_getch();
		goto tt;
	case 2: cout << "Nhap khoa can tim x= "; cin >> x;
		if (search(root, x)) { cout << "\nKhoa " << x << " co trong cay"; }
		else cout <<"\n"<< x << " khong co trong cay";
		cout << "\n";
		_getch();
		goto tt;
	case 3: cout << "Nhap khoa can chen x= "; cin >> x;
		insert_node(root, x);
		cout << "\nKhoa da chen thanh cong\n";
		_getch();
		goto tt;
	case 4: cout << "Nhap khoa can xoa x= "; cin >> x;
		del_node(root, x);
		cout << "\nDa xoa thnh cong\n";
		_getch();
		goto tt;
	case 5: cout << "Duyet theo NLR\n";
		NLR(root);
		_getch();
		goto tt;
	case 6: cout << "Duyet theo LNR\n";
		LNR(root);
		_getch();
		goto tt;
	case 7: cout << " Duyet theo LRN\n";
		LRN(root);
		_getch();
		goto tt;
	case 0: del_tree_avl(root); break;
	default: cout << "Ban chon hong hop le. Chon lai\n";
		_getch();
		goto tt;
	}
}