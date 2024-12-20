#include<iostream>
using namespace std;

class node {
public:    
    char data;
    node *left;
    node *right;
    
    node(char c) 
	{
        data=c;
        left=nullptr;
        right=nullptr;
    }
};

class tree {
public:
    node *root;
   
    tree() 
	{
        root=nullptr;
    }
    
    void preorder(node *temp) 
	{
        if(temp!=nullptr) 
		{
            cout<<temp->data<< " ";      
            preorder(temp->left);           
            preorder(temp->right);          
        }
}
    void postorder(node *temp) 
	{
        if(temp!=nullptr) {
            postorder(temp->left);          
            postorder(temp->right);        
            cout<<temp->data<<" ";      
        }
    }

    void inorder(node *temp) 
	{
        if(temp!=nullptr) 
		{
            inorder(temp->left);           
            cout<<temp->data <<" ";      
            inorder(temp->right);         
        }
    }

    node* Insert(node* n, char c) 
	{
        if(n == nullptr) 
		{
            return new node(c);  
        }
        if(c<n->data) 
		{
            n->left=Insert(n->left,c);  
        } 
		else 
		{
            n->right=Insert(n->right,c);  
        }
        return n;
    }
    
	void insert(int c) 
	{
        root=Insert(root,c); 
    }

    void preorderh() 
	{
        cout<<"Preorder:";
        preorder(root);
        cout<<endl;
    }

    void postorderh() 
	{
        cout<<"Postorder:";
        postorder(root);
        cout<<endl;
    }

    void inorderh() 
	{
        cout<<"Inorder: ";
        inorder(root);
        cout<<endl;
    }
};

int main() 
{
    tree t;
    t.insert('A');
    t.insert('L');
    t.insert('E');
    t.insert('E');
    t.insert('N');
    t.insert('A');
    t.insert('A');
    cout << "Preorder " << endl;
    t.preorderh();
    cout << "Postorder " << endl;
    t.postorderh();
    cout << "Inorder " << endl;
    t.inorderh();
    return 0;
}