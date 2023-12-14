#include <bits/stdc++.h>

using namespace std;

struct Node
{
    string name;
    Node *leftmost_child = nullptr;
    Node *right_sibling = nullptr;
};

vector<Node *> parent_list;

void add_relation(string c, string p)
{
    Node *parent = new Node();
    parent->name = p;
    Node *child = new Node();
    child->name = c;

    // 0 tree yet
    if (parent_list.size() == 0)
    {
        parent->leftmost_child = child;
        parent_list.push_back(parent);
    }
    else
    {
        bool added = false;
        for (auto it : parent_list)
        {
            // exist that parent
            if (it->name == p)
            {
                Node *tmp_node = it->leftmost_child;
                while (tmp_node->right_sibling != nullptr)
                    tmp_node = tmp_node->right_sibling;
                tmp_node->right_sibling = child;
                added = true;
            }
        }
        if (!added)
        {
            parent->leftmost_child = child;
            parent_list.push_back(parent);
        }
    }
}

int count_des = 0;
void descendants_num(string s)
{
    for (auto it : parent_list)
        if (it->name == s)
        {
            Node *tmp_node = it->leftmost_child;
            while (tmp_node != nullptr)
            {
                count_des += 1;
                // cout << tmp_node->name << endl;
                descendants_num(tmp_node->name);
                tmp_node = tmp_node->right_sibling;
            }
        }
}

int max_gen = 0, count_gen = 0;
void generation_num(string s)
{
    for (auto it : parent_list)
        if (it->name == s)
        {
            Node *tmp_node = it->leftmost_child;
            while (tmp_node != nullptr)
            {
                count_gen += 1;
                generation_num(tmp_node->name);
                if (count_gen > max_gen)
                    max_gen = count_gen;
                count_gen -= 1;
                tmp_node = tmp_node->right_sibling;
            }
        }
}

int main()
{
    string c, p;
    cin >> c;
    while (c != "***")
    {
        cin >> p;
        add_relation(c, p);
        cin >> c;
    }

    string query, tmp_name;
    cin >> query;
    while (query != "***")
    {
        cin >> tmp_name;
        if (query == "descendants")
        {
            count_des = 0;
            descendants_num(tmp_name);
            cout << count_des << endl;
        }
        else
        {
            max_gen = 0;
            generation_num(tmp_name);
            cout << max_gen << endl;
        }
        cin >> query;
    }
    return 0;
}