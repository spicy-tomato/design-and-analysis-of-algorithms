/*
 * http://laptrinhonline.club/problem/tichpcatkimloai
 */

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *parent, *left, *right;
    int maxLength, leftValue, rightValue;

    Node(int maxLength, int leftValue, int rightValue, Node *parent)
    {
        this->parent = parent;
        this->left   = nullptr;
        this->right  = nullptr;

        this->leftValue  = leftValue;
        this->rightValue = rightValue;
        this->maxLength  = maxLength;
    }

    Node(int length) : Node(length, 1, length, nullptr) {}
};

Node *findPositionToAddNewNode(Node *node, int index)
{
    if (node->left == nullptr)
    {
        return node;
    }

    Node *leftNode  = node->left;
    Node *rightNode = node->right;

    if (index < leftNode->rightValue)
    {
        return findPositionToAddNewNode(leftNode, index);
    }

    return findPositionToAddNewNode(rightNode, index);
}

void update(Node *node)
{
    while (node != nullptr)
    {
        node->maxLength = max(node->left->maxLength, node->right->maxLength);
        node = node->parent;
    }
}

void makeNode(Node *root, int value)
{
    Node *node = findPositionToAddNewNode(root, value);
    node->left  = new Node(value - node->leftValue + 1, node->leftValue, value           , node);
    node->right = new Node(node->rightValue - value   , value + 1      , node->rightValue, node);

    update(node);
}

int main()
{
    int n, m, tmp;
    cin >> n >> m;

    Node *root = new Node(m);

    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        makeNode(root, tmp);
        cout << root->maxLength << ' ';
    }
}
