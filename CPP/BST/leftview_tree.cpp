
#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* left= NULL;
    node* right = NULL;

};

int thecount=0;

void bst_insert(node * root,int datum)
{
    if(root==NULL)
    {
        root = new node;
        root->data= datum;
        return;
    }

    else{
        if(root->data<datum)
        {
            bst_insert(root->right, datum);
        }
        else{

            bst_insert(root->left,datum);
        }
    }
  return;
}

node * searcher(node* root,int datum)
{
    if(root->data==datum)
    {
        return root;
    }
    else{
        if(root->data<datum)
        {
            root= searcher(root->right,datum);
        }
        else{

            root=searcher(root->left,datum);
        }

    }



}
 node * bst_insertpart2(node* root,int data)
{
    if(root==NULL)
    {
        root = new node;
        root->data= data;
        return root;
    }

    else{
        if(root->data<data)
        {
            root->right=bst_insertpart2(root->right,data);
        }
        else{

            root->left=bst_insertpart2(root->left,data);
        }
    }

}

void print_tree(node*root)
    {

        if(root!=NULL)
        {
            cout<<root->data<< " -- " ;
            print_tree(root->left);
            print_tree(root->right);
        }

    }
int height_tree(node * root)
{
    if(root==NULL)
    {
        return 0;
    }

    int maxi;
    int l = height_tree(root->left);
    int r = height_tree(root->right);
    if(l>=r)
    {
        maxi = l;
    }
    else{maxi = r;}

    return maxi+1;


}

void print_nthlevel(node*root,int l)
{if(root==NULL)
{
    return;
}
else{
    if(l==0)
    {
        if(thecount<1 )
        {cout<<root->data<<" -- ";
        thecount= thecount+1;
        return;}
    }
    else{

        print_nthlevel(root->left,l-1);
        print_nthlevel(root->right,l-1);

        }
}


}

void bfs_traversal(node * root)
{
    int height=height_tree(root);
    cout<<" height of tree is "<<height<<endl;
    int i=0;
    while(i<=height)
    {
        thecount=0;
        print_nthlevel(root,i);
        cout<<endl;
        i++;
    }

}

void delete_node(node* root,int data)
{
    node* reqnode= searcher(root,data);

    node * tempnode = reqnode;
    reqnode = reqnode->left;
    while(reqnode->right!=NULL)
    {
        reqnode= reqnode->right;
    }
    if(reqnode->left==NULL)
    {tempnode->data=reqnode->data;
        reqnode=NULL;
    }
    else{
        tempnode->data=reqnode->data;
        reqnode->data= reqnode->left->data;
        reqnode->left=NULL;
    }


}

int main()
{ node* root=NULL;
    root= new node;
    cout<<" lets make binary tree ";
    cout<<"enter input , -1 to stop ";
    int input;

    cin>>input;
    /* root->data=8;
    cout<<root->data<<endl; */

    while(input!=-1)
    {
        bst_insertpart2(root,input);

        cin>>input;
    }
   cout<<" lets check the tree "<<endl;
   /* cout<<" root->data is "<<root->data<<endl;
   cout<<" normal tree ";
    print_tree(root); */
   cout<<"now tree "<<endl;
   bfs_traversal(root);



}




