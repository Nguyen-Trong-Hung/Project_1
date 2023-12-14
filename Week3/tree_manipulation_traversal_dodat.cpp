#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int id;
    Node *leftmost_child = nullptr;
    Node *right_sibling = nullptr;
};

Node *root = nullptr;
int added[1000] = {0};
vector<Node *> node_list;

void make_root(int id)
{
    Node *tmp_node = new Node();
    tmp_node->id = id;
    root = tmp_node;
    added[id] = 1;
    node_list.push_back(tmp_node);
}

void insert_node(int u, int v)
{
    if (added[u] == 0)
    {
        for (auto it : node_list)
        {
            if (it->id == v)
            {
                added[u] = 1;
                Node *node_add = new Node();
                node_add->id = u;
                Node *tmp_node = it->leftmost_child;
                if (tmp_node == nullptr)
                {
                    it->leftmost_child = node_add;
                    node_list.push_back(node_add);
                    break;
                }
                else
                {
                    while (tmp_node->right_sibling != nullptr)
                    {
                        tmp_node = tmp_node->right_sibling;
                    }
                    tmp_node->right_sibling = node_add;
                    node_list.push_back(node_add);
                    break;
                }
            }
        }
    }
}

void in_order(Node *tmp_node)
{
    if (tmp_node->leftmost_child == nullptr)
        cout << tmp_node->id << " ";

    else
    {
        in_order(tmp_node->leftmost_child);
        cout << tmp_node->id << " ";
        Node *sibling = tmp_node->leftmost_child->right_sibling;
        while (sibling != nullptr)
        {
            in_order(sibling);
            sibling = sibling->right_sibling;
        }
    }
}

void pre_order(Node *tmp_node)
{
    cout << tmp_node->id << " ";
    Node *child = tmp_node->leftmost_child;
    if (child != nullptr)
    {
        pre_order(child);
        while (child->right_sibling != nullptr)
        {
            child = child->right_sibling;
            pre_order(child);
        }
    }
}

void post_order(Node *tmp_node)
{
    Node *child = tmp_node->leftmost_child;
    if (child != nullptr)
    {
        post_order(child);
        while (child->right_sibling != nullptr)
        {
            child = child->right_sibling;
            post_order(child);
        }
    }
    cout << tmp_node->id << " ";
}

string s;
int u, v;

int main()
{
    cin >> s;
    while (s != "*")
    {
        if (s == "MakeRoot")
        {
            cin >> u;
            make_root(u);
        }
        else if (s == "Insert")
        {
            cin >> u >> v;
            insert_node(u, v);
        }
        else if (s == "InOrder")
        {
            in_order(root);
            cout << endl;
        }
        else if (s == "PreOrder")
        {
            pre_order(root);
            cout << endl;
        }
        else if (s == "PostOrder")
        {
            post_order(root);
            cout << endl;
        }
        cin >> s;
    }
    return 0;
}