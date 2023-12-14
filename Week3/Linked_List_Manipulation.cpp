#include <bits/stdc++.h>

using namespace std;
// Định nghĩa cấu trúc node 
struct Node{
    int data;
    Node *next;
};

typedef struct Node* node;

node makeNode(int x){
    node tmp = new Node();// Khai báo và Cấp phát động cho phần tử tmp/ tmp phải được khai báo kiểu node
    tmp->data = x;//         vì danh sách liên kết
    tmp->next = NULL;// trỏ tiếp vào null
    return tmp;
}

bool check(node &a,int k){
    bool check = true;
    node p = a;
    while(p != NULL){
        if(p->data == k){
            check = false;
            break;
        }
        p = p->next;
    }
    return check;
}

int Size(node a){
    int cnt = 0;
    while(a != NULL){
        cnt++;
        a = a->next;
    }
    return cnt;
}

void addfirst(node &a,int x){
    if(check(a,x))
    {
        node tmp = makeNode(x);
        if(a == NULL){
            a = tmp;
        }
        else{
            tmp->next = a;
            a = tmp;
        }
    }
    else   return;
}

void addlast(node &a,int x){
    if(check(a,x)){
        node tmp = makeNode(x);
        if(a == NULL){
            a = tmp;
        }
        else{
            node p = a;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = tmp;
        }
    }
    else return;
}

void addafter(node &a,int u,int v){
    if(check(a,v)) return;
    else if(check(a,u)){
            node newNode = makeNode(u);
            node p = a;
            while(p->data != v){
                p = p->next;
            }
            newNode->next = p->next;
            p->next = newNode;
        }
        else return;
}

void addbefore(node &a,int u,int v){
    if(check(a,v)) return;
    else if(check(a,u)){
        node newNode = makeNode(u);
        if(a->data == v){
            newNode->next = a;
            a = newNode;
        }
        else{
            node p = a;
            while(p->next != NULL){
                if(p->next->data == v){
                    newNode->next = p->next;
                    p->next = newNode;
                    break;
                }
                p = p->next;
            }
        }
    }
}

void Remove(node &a, int k){
    if (a == nullptr) {
        return;
    }
    
    if (a->data == k){
        node tmp = a;
        a = a->next;
        delete tmp;
        return;
    }
    
    node p = a;
    while (p->next != nullptr){
        if (p->next->data == k){
            node tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
            p = p->next;
    }
}

void reverse(node &a){
    node current = a;
    node next,prev = NULL;
    
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    a = prev;
}

int main(){
    int n;
    cin >> n;
    node a = NULL;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        addlast(a,x);
    }
    string command;
    while(cin >> command){
        if(command == "addlast"){
            int k;
            cin >> k;
            addlast(a,k);
        }
        else if(command == "addfirst"){
            int k;
            cin >> k;
            addfirst(a,k);
            }
            else if(command == "addafter"){
                    int u,v;
                    cin >> u >> v;
                    addafter(a,u,v);
                }
                else if(command == "addbefore"){
                    int u,v;
                    cin >> u >> v;
                    addbefore(a,u,v);
                    }
                    else if(command == "remove"){
                            int k;
                            cin >> k;
                            Remove(a,k);
                        }
                        else if(command == "reverse"){
                                reverse(a);
                            }
                            else if(command == "#")
                                    break;
    }
    node p = a;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    delete a;
}