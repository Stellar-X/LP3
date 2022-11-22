#include <bits/stdc++.h>

using namespace std;


class MinHeapNode
{
public:
    char data;
    int freq;
    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = nullptr;
        right = nullptr;
    }
};


class comparator
{
public:
    bool operator() (MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};


MinHeapNode* build_huffman_tree(vector<pair<char,int>>& v)
{
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, comparator> minHeap;
    for(int i=0; i<v.size(); i++)
        minHeap.push(new MinHeapNode(v[i].first, v[i].second));
    
    while(minHeap.size() > 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('#', left->freq + right->freq);
        top->left = left;
        top->right = right;
        
        minHeap.push(top);
    }

    return minHeap.top();
}


void print_code(MinHeapNode* root, string s)
{
    if(root==nullptr)
        return;
    
    if(root->data != '#')
        cout<<root->data<<": "<<s<<"\n";
    
    print_code(root->left, s+"0");
    print_code(root->right, s+"1");
}


bool compare(pair<char,int>& p, pair<char,int>& q)
{
    return p.second < q.second;
}

int main()
{
    int n;
    cout<<"\nEnter number of unique characters : ";
    cin>>n;
    
    cout<<"\nEnter character and its frequency : \n";
    // Vector to store character-frequency pair
    vector<pair<char,int>> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i].first>>v[i].second;

    sort(v.begin(), v.end(), compare);

    MinHeapNode* root = build_huffman_tree(v);

    cout<<"\nCodewords for characters are :\n";
    print_code(root, "");
    cout<<"\n";

    return 0;
}