//heap.cpp

#include <iostream>
#include <stack>

using namespace std;

struct node{
	int value;
	node* left;
	node* right;
};

class Heap{
	public:
		stack<node*> s;
	    int wholeTree[63] = {4,19,6,27,20,8,7,43,0,0,0,14,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,25,0,0,0,0,0,0};
		int tree1[15] = {4 , 19 , 8 , 27 , 20 , 12 , 0 , 43 , 0 , 0 , 0 , 15 , 25 , 0 , 0};
	    int tree2[7] = {6 , 8 , 7 , 14 , 0 , 0 , 0};
		node* root1;
		node* root2;
		node* root3;
		
		Heap();
		node* merge(node* x , node* y , bool shift);
		int nullDis(int t[] , int index , int distance);
		void printHeap();
};

Heap::Heap(){
	node* l;
	node* r;

	root1 = new node;
	root1->value = 0;
	root1->left = NULL;
	root1->right = NULL;
	
	
	//tree1 heap
	root2 = new node;
	root2->value = 4;
	root2->left = new node;
	l = root2->left;
	l->value = 19;
	l->left = new node;
	l->right = new node;
	r = l->right;
	r->value = 20;
	l = l->left;
	l->value = 27;
	l->left = new node;
	l = l->left;
	l->value = 43;
	root2->right = new node;
	r = root2->right;
	r->value = 8;
	r->left = new node;
	l = r->left;
	l->value = 12;
	l->left = new node;
	l->right = new node;
	r = l->right;
	r->value - 25;
	l = l->left;
	l->value = 15;
	
	
	//tree2 heap
	root3 = new node;
	root3->value = 6;
	root3->left = new node;
	l = root3->left;
	l->value = 8;
	l->left = new node;
	l = l->left;
	l->value = 14;
	root3->right = new node;
	r = root3->right;
	r->value = 7;
	
	
}




//merge two trees
node* Heap::merge(node* x , node* y , bool shift){
	if(shift != true){
		if(x->value < y->value){
			s.push(x);
			if(x->right != NULL){
				merge(x->right , y , false);
			}
			else{
				merge(x , y , true);
			}
		}
		else{
			s.push(y);
			if(y->right != NULL){
				merge(x , y->right , false);
			}
			else{
				merge(x , y , true);
			}
		}
	}
	else if(shift == true){
		if(!s.empty()){
			s.top()->right = x;
			x = s.top();
			s.pop();
			merge(x , y , true);
		}
		else{
			return x;
		}
	}
}

//get the distanse to the nearest null spot
int Heap::nullDis(int t[] , int index , int distance){
	if(t[index*2] == 0 || t[(index*2) + 1] == 0){
		return distance;
	}
	
	else{
		distance++;
		return nullDis(t , index*2 , distance);
		return nullDis(t , (index*2)+1 , distance);
	}
}

//prints the heap
void Heap::printHeap(){
	
	cout << "Merged Tree (N = NULL)" << endl;
	for(int i=1 ; i< (sizeof(wholeTree) / sizeof(wholeTree[0]))+1 ; i++){
		if(wholeTree[i-1] == 0){
			cout << "N" << " ";
		}
		else{
			cout << wholeTree[i-1] << " ";
		}
		
		if(i == 1 || i == 3 || i == 7 || i == 15 || i == 31 ){
			cout << endl;
		}
	}
	cout << endl;
	
}



int main(){
	Heap* h = new Heap();
	
	//merge the two trees
	h->root1 = h->merge(h->root2 , h->root3 , false);
	
	//print the merged tree
	h->printHeap();
	
}
