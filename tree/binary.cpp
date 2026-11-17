#include <iostream>
// #include <optional>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree
{
    vector<int> preorderList;
    vector<int> postorderList;
    vector<int> inorderList;

    void preorderT(Node *node)
    {
        if (node == NULL)
        {
            this->preorderList.push_back(-1);
            return;
        }

        this->preorderList.push_back(node->val);
        preorderT(node->left);
        preorderT(node->right);
    }
    void postorderT(Node *node)
    {
        if (node == NULL)
        {
            this->postorderList.push_back(-1);
            return;
        }

        postorderT(node->left);
        postorderT(node->right);
        this->postorderList.push_back(node->val);
    }
    void inorderT(Node *node)
    {
        if (node == NULL)
        {
            this->inorderList.push_back(-1);

            return;
        }

        inorderT(node->left);
        this->inorderList.push_back(node->val);
        inorderT(node->right);
    }

    Node *preorderHelper(const vector<int> &p, int &i)
    {
        i++;

        if (i < p.size() && p[i] == -1)
            return NULL;

        Node *root = new Node(p[i]);

        root->left = preorderHelper(p, i);
        root->right = preorderHelper(p, i);

        return root;
    }

public:
    void traverse(Node *root)
    {
        // create list
        this->inorderT(root);
        this->preorderT(root);
        this->postorderT(root);

        // loglist
        cout << "preorder";
        for (int i : this->preorderList)
        {
            cout << ": " << i;
        }

        cout << "\n"
             << "inorder";
        for (int i : this->inorderList)
        {
            cout << ": " << i;
        }
        cout << "\n"
             << "postorder";
        for (int i : this->postorderList)
        {
            cout << ": " << i;
        }
    }
    Node *preorder(const vector<int> &p)
    {
        int i = -1;
        return preorderHelper(p, i);
    }
};

int main()
{
    Tree tree;
    vector<int> pre = {1, 2, -1, 4, -1, 5, 10, -1, -1, -1, 3, -1, 2, 2, 15, -1, -1, -1, -1, -1};

    Node *root = tree.preorder(pre);

    tree.traverse(root);

    return 0;
}