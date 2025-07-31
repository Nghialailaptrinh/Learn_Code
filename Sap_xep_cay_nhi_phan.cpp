//Đây là code sort bằng cây nhị phân
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int du_lieu;
	node* left, *right;
	node(int n=0) {
		du_lieu = n;
		left = nullptr;
		right = nullptr;
	}
	~node() {
		delete left, right;
	}
};

vector<int> day_so;
void sap_xep(node* head) {
	if (head == nullptr)return;
	else {
		if (head->left != nullptr) { sap_xep(head->left); }
		day_so.push_back(head->du_lieu);
		if (head->right != nullptr) { sap_xep(head->right); }
	}
}

void nhap(node* head, int n) {
	
	if (n <= head->du_lieu) {
		if (head->left == nullptr) { head->left = new  node(n); }
		else nhap(head->left, n);
	}
	else {
		if (head->right == nullptr) { head->right = new node(n); }
		else  nhap(head->right, n); 
	}

}

node* head;
int main() {
	cout << "\n Nhap so phan tu muon sap xep";
	int n; cin >> n;
	if (n == 0)return 0;
	int c; cin >> c;
	head = new node(c);

	for (int i = 1; i < n; i++) {
		cin >> c;
		nhap(head, c);
	}

	sap_xep(head);

	for (int i = 0; i < n; i++) {
		cout << day_so[i] << " ";
	}

	delete head;

}