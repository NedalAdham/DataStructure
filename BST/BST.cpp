#include <iostream>

#include <queue>
using namespace std ;

template <typename t>
class btnode   {
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
btnode<int>* searchBST (btnode<int>*root , int val )
{
    if (root == NULL)return NULL;
    if (root ->data == val)return root;
    if (val > root->data)return searchBST(root->right,val);
    else if (val < root->data)return searchBST(root->left,val);

    return NULL ;
}

int  minvalue (btnode<int>*root )
{
//left most node
    if (root == NULL) return -1 ;
    while (root -> left != NULL)
    {
        root = root -> left  ;
    }
    return root ->data ;
}

int  RangesumBST (btnode<int>*root , int l , int r) {
    if (root == NULL)return 0;
    int sum = 0;

    if (root->data >= l and root->data <= r) {
        sum += root->data;
    }
    if (root->data > r) {
        sum += RangesumBST(root->left, l, r);
    } else if (root->data < l) {
        sum += RangesumBST(root->right, l, r);
    } else {
        sum += RangesumBST(root->left, l, r)
               +
               RangesumBST(root->right, l, r);
    }
}


bool help (btnode<int>*root , long long minv = -10000000000,long long maxv = 10000000000)
{
    if(root==NULL)return true;
    bool left = help(root->left , minv , root ->data);
    bool right = help(root->right ,  root ->data, maxv );

    if (left and right and minv < root-> data < maxv  ) return true;
    else return false ;
}
bool isBST (btnode<int>*root)
{
    return help(root);
}


btnode<int>* balancearr(vector <int> arr , int s , int e)
{
    if (s>e)return NULL ;

    int mid =  (s+e)/2 ;
    int rootdata = arr[mid];

    btnode<int>* root = new btnode<int>(rootdata);
   root ->left= balancearr(arr, s , mid-1);
    root -> right =balancearr(arr , mid+1 , e);


}
btnode<int>* sortedarraytobst(vector<int>& nums) {
    int n = nums.size();
    return balancearr(nums, 0, n - 1);
}



class BST{
    btnode<int>* root;

    void printTree(btnode<int>* root){
        if(root==NULL){   /// base case
            return;
        }

        cout<<root->data<<": ";
        if(root->left!=NULL){
            cout<<"L"<<root->left->data;
        }

        if(root->right!=NULL){
            cout<<"R"<<root->right->data;
        }
        cout<<endl;

        printTree(root->left);
        printTree(root->right);
    }
    bool hasData(btnode<int>* node, int data){
        if(node==NULL){
            return false;
        }
        if(node->data == data){
            return true;
        }

        if(node->data > data){
            return hasData(node->left, data);
        }else{
            return hasData(node->right, data);
        }
    }

    btnode<int>* insert(btnode<int>* node, int data){
        if(node == NULL){
            btnode<int> *n = new btnode<int>(data);
            return n;
        }
        if(data < node->data){
            node->left = insert(node->left , data);
        }else{
            node->right = insert(node->right, data);
        }
        return node;
    }

    btnode<int>* deletedata (btnode<int>* node, int data)
    {
        if (node == NULL)return NULL;

        if (data>node->data)
        {
            node->right=deletedata(node->right , data);
        }

        else if (data < node->data)
        {
            node->left=deletedata(node->left , data);
        }
        else
            {
                if (node->left==NULL and node ->right ==NULL)
                {
                    delete node ;
                    return NULL ;
                }
                else if (node->right==NULL)
                {
                    btnode<int>*temp = node ->left;
                    node ->left =NULL;
                    delete node;
                    return temp;
                }
                else if (node->left==NULL)
                {
                    btnode<int>*temp = node ->right;
                    node ->right =NULL;
                    delete node;
                    return temp;
                }
                else
                {
                    btnode<int>*minnode = node->right;
                    while (minnode->left)
                    {
                        minnode = minnode->left;
                    }
                    int rightmin = minnode->data;
                    node->data = rightmin ;
                    node -> right =deletedata(node->right,rightmin);
                }
            }
        return node ;
    }
public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }

    void deleteData(int data){

    }
    void insert(int data){
        root = insert(root, data);
    }
    bool hasData(int data){
        return hasData(root, data);
    }
    void print(){
        printTree(root);
    }

    void deletedata (int data)
    {
        root = deletedata(root,data);
    }
};





































int main()
{
    BST b ;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.print();
    cout<<"-------------------"<<endl;

    b.deletedata(10);
    b.print();


}