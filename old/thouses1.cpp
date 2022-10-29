#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    vector<node *>child;
};
node *newnode(int key){
    node *temp = new node;
    temp->val = key;
    return temp;
}

void levelOrderTraverseTree(node * root){
    if(root == NULL){
        return;
    }
    queue<node *>q;
    q.push(root);//enqueuing top root element
    while (!q.empty()){
        int n = q.size();
        while (n>0){
            node * p = q.front();
            q.pop();
            cout<<p->val<<" ";

            for(int i = 0; i < p->child.size(); i++){
                q.push(p->child[i]);
            }
            n--;
        }
        cout<<"\n";
    }
}



int main(){
    node *root = newnode(7);
    (root->child).push_back(newnode(2));
    (root->child).push_back(newnode(49));
    (root->child).push_back(newnode(37));
    (root->child[0]->child).push_back(newnode(101));

    

    cout<<"Mango mango\n";
    levelOrderTraverseTree(root);
    return 0;
}