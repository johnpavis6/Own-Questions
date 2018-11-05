#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node *newNode(int);
Node *insert(Node *, int, int);
int getCount(Node *root, int ele, int &count)
{
    if (root)
    {
        if (root->data == ele)
        {
            count++;
        }
        return 1 + getCount(root->left, ele, count) + getCount(root->right, ele, count);
    }
    else
    {
        return 0;
    }
}
int setNode(Node *root, int ele)
{
    if (root)
    {
        if (root->data == -1)
        {
            root->data = ele;
        }
        int count = 0;
        if (root->data == ele)
        {
            count = 1;
        }
        return count + setNode(root->left, ele) + setNode(root->right, ele);
    }
    else
    {
        return 0;
    }
}
void traverse(Node *root, int ele)
{
    if (root)
    {
        if (root->data == ele)
        {
            if (root->left && root->left->data != ele)
            {
                root->left->data = -1;
            }
            if (root->right && root->right->data != ele)
            {
                root->right->data = -1;
            }
        }
        else
        {
            if (root->left && root->left->data == ele)
            {
                root->data = -1;
            }
            else if (root->right && root->right->data == ele)
            {
                root->data = -1;
            }
        }
        traverse(root->left, ele);
        traverse(root->right, ele);
    }
}
int burnTree(Node *root, int ele)
{
    int count = 0;
    int n = getCount(root, ele, count), t = 0;
    while (count && count < n)
    {
        traverse(root, ele);
        count = setNode(root, ele);
        t++;
    }
    if (!count)
    {
        return -1;
    }
    return t;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        Node *root = NULL;
        cin >> n;
        for (int i = 0, data; i < n; i++)
        {
            cin >> data;
            root = insert(root, data, i);
        }
        int ele;
        cin >> ele;
        cout << burnTree(root, ele) << endl;
    }
}
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node *insert(Node *root, int data, int size)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    Node *queue[size];
    queue[0] = root;
    int front = 0, end = 1;
    while (front < end)
    {
        Node *temp = queue[front++];
        if (!temp->left)
        {
            temp->left = newNode(data);
            return root;
        }
        else
        {
            queue[end++] = temp->left;
        }
        if (!temp->right)
        {
            temp->right = newNode(data);
            return root;
        }
        else
        {
            queue[end++] = temp->right;
        }
    }
}