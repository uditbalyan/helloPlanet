#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>

using namespace std;
 
class node{
    public:
        char ch;
        node* left;
        node* right;
        int freq;


        node(char ch,int freq){
            this->ch=ch;
            this->left=NULL;
            this->right=NULL;
            this->freq=freq;
        }

};

 struct cmp1{
     bool operator()(node* const& n1, node* const& n2){
         return n1->freq > n2->freq;
     }
 };



 void printCodes(node * root, string asf, map<char,string>& mp){


     if(root->left==NULL && root->right==NULL){
         mp[root->ch]=asf;
         return;
     }

     printCodes(root->left,asf+"0",mp);
     printCodes(root->right,asf+"1",mp);

 }

 

 int main(int argc, char** argv){
     
     string seq;
     cin>>seq;

     int *freq=new int[seq.length()];

     for(int i=0;i<seq.length();i++){
        cin>>freq[i];
     }
    
     priority_queue<node*, vector<node*>, cmp1> pq;

    int i=0;
    while(i<seq.length()){

        int f=freq[i];
        char ch=seq[i];
        node * nd=new node(ch,f);
        pq.push(nd);
        i++;
    }

    while(pq.size()>1){
        node* n1=pq.top();
        pq.pop();
        node* n2=pq.top();
        pq.pop();
        node * nn=new node('$', n1->freq+n2->freq);
        nn->left=n1;
        nn->right=n2;
        pq.push(nn);
        
    }

    node * root=pq.top();
    map<char,string> mp;
    printCodes(root,"",mp);

    map<char,string>:: iterator it=mp.begin();
    for(;it!=mp.end();it++){
        cout<<it->first<<"--->"<<it->second;
        cout<<endl;
    }


    return 0;


 }