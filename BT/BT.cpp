////////////////every node hase max 2 children
/////////////////


#include <iostream>
#include <queue>
using namespace std ;

template <typename t>
class btnode {
public:
    t data ;
    btnode* left ;
    btnode* right;


    btnode(t data)
    {
        this->data=data;
        left = NULL ;
        right = NULL ;
    }

    ~btnode()
    {
        delete left ;
        delete right;
    }
};

void printTree (btnode <int>* root)
{
    if(root == NULL)return;

    cout << root ->data<<":";
    if (root -> left !=NULL)
    {
        cout << "L"  << root->left->data;
    }
    if (root -> right !=NULL)
    {
        cout << " R"<< root->right->data;
    }
    cout <<endl;
    printTree(root ->left);
    printTree(root->right);
}


btnode<int>* TakeInput ()
{
    int rootdata;
    cout << "Enter Data"<<endl;
    cin >> rootdata ;

    if (rootdata==-1)
    {
        return NULL ;
    }
    btnode<int>* root = new btnode<int>(rootdata);

    btnode<int>* leftchild = TakeInput();
    btnode<int>* rightchild = TakeInput();

    root->left = leftchild ;
    root ->right = rightchild;

    return root;

}
btnode<int>* TakeInputLevelwise ()
{
    int rootdata;
    cout << "enter root data"<<endl ;
    cin >> rootdata ;
    btnode<int>* root = new btnode<int> (rootdata);

    queue<btnode<int>*>q;
    q.push(root);
    while (!q.empty())
    {
        btnode<int>* f = q.front();
        q.pop();

        cout << "enter leftchild of "<< f->data<<endl;
        int leftchilddata;
        cin >> leftchilddata;
        if(leftchilddata!=-1)
        {
            btnode<int>* child = new btnode<int>(leftchilddata);
            q.push(child);
            f->left=child;
        }


        cout << "enter rightchild of "<< f->data<<endl;
        int rightchilddata;
        cin >> rightchilddata;
        if(rightchilddata!=-1)
        {
            btnode<int>* child = new btnode<int>(rightchilddata);
            q.push(child);
            f->right=child;
        }
    }
    return root;

}

/*/
class LevelOrderTraversal {
public:
    vector<vector<int>> levelOrder(btnode* root) {

        vector<vector<int> > v;
        if(root==NULL){
            return v;
        }
        vector<int> temp;   /// storing is storing result of current level

        queue<btnode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            btnode* f = q.front();
            q.pop();
            if(f==NULL){
                ///cout<<endl;
                v.push_back(temp);
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }

            }else{
                temp.push_back(f->val);
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
        }
        return v;
    }
};
 /*/

int countNode(btnode<int>* root)
{
if (root==NULL)return 0;
else return countNode(root->left)+countNode(root ->right)+1;
}

int Inorder(btnode<int>* root,vector<int> &ans)
{
    if (root == NULL)return 0;

    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
}

vector<int> Inorder_Traversal_LDR(btnode<int>*root)
{
    vector<int>ans;
    Inorder(root,ans);
    return ans;
}



int preorder(btnode<int>* root,vector<int> &ans)
{
    if (root == NULL)return 0;

    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}

vector<int> preorder_Traversal_DRL(btnode<int>*root)
{
    vector<int>ans;
    preorder(root,ans);
    return ans;
}



int postorder(btnode<int>* root,vector<int> &ans)
{
    if (root == NULL)return 0;

    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}

vector<int> postorder_Traversal_LRD(btnode<int>*root)
{
    vector<int>ans;
    postorder(root,ans);
    return ans;
}


int Maxdepth(btnode<int>* root)
{
    if (root == NULL)return 0;

    return max(Maxdepth(root->right),Maxdepth(root->left))+1;
}

bool helper(btnode<int> *leftTree,btnode<int> * rightTree){
    if(leftTree==NULL && rightTree!=NULL) return false;
    if(leftTree!=NULL && rightTree==NULL) return false;
    if(leftTree==NULL && rightTree==NULL) return true;

    if(leftTree->data != rightTree->data) return false;


    return helper(leftTree->left,rightTree->right) &&
           helper(leftTree->right,rightTree->left);
}
bool isSymmetric(btnode<int> * root) {
    if(root==NULL) return true;

    return helper(root->left,root->right);

}

bool searchnode(btnode<int>* root , int key)
{
    if (root == NULL)
    {
        return false ;
    }
     if (root->data == key)
     {
         return true;
     }

    return (searchnode(root ->left,key) || searchnode(root ->right,key));

}

int minvalue (btnode<int>*root)
{
    if (root == NULL)return INT_MAX;

    int leftmin = minvalue(root->left);
    int rightmin = minvalue(root->right);

    return min(root->data , min(leftmin,rightmin));
}

int countLeafNode (btnode<int>*root)
{
    if (root == NULL)return 0;
    if (root -> left==NULL and root -> right ==NULL) return 1 ;

    return (countNode(root->left) + countNode(root->right));
}
int main() {
    /*/
  btnode<int> * root = new btnode<int>(1);
  btnode<int> * n1 = new btnode<int>(2);
  btnode<int> * n2 = new btnode<int>(3);

  root -> left = n1 ;
  root -> right = n2 ;

/*/
    btnode<int>* root = TakeInputLevelwise();
    printTree(root);

    delete root;

}