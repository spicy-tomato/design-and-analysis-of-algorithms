/*
 * http://laptrinhonline.club/problem/tichpxnghichthe
 */

#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int leftLimit, rightLimit, value = 0;
        Node *left, *right;

        Node(int leftLimit, int rightLimit)
        {
            this->leftLimit = leftLimit;
            this->rightLimit = rightLimit;

            if (leftLimit < rightLimit)
            {
                int mid = (leftLimit + rightLimit) / 2;
                left = new Node(leftLimit, mid);
                right = new Node(mid + 1, rightLimit);
            }
        }

        Node(int n) : Node(0, n)
        {}
};

class Tree
{
    public:
        Node *root;
        long result = 0;

        Tree(int n)
        {
            root = new Node(n);
        }

        void add(int value)
        {
            add(value, root);
        }

        void add(int value, Node *node)
        {
            node->value++;

            if (node->leftLimit < node->rightLimit)
            {
                if (value <= node->left->rightLimit)
                {
                    add(value, node->left);
                    result += node->right->value;
                }
                else
                {
                    add(value, node->right);
                }
            }
        }
};

int main()
{
    int n, tmp;
    cin >> n;

    Tree *tree = new Tree(n);

    while (n--)
    {
        cin >> tmp;
        tree->add(tmp);
    }

    cout << tree->result;
}
