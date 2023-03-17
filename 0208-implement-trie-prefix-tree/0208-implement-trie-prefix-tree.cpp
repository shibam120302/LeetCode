class Node{
public:
    Node *Links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return (Links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        Links[ch-'a']=node;
    }
    
    Node* go(char ch){
        return Links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->go(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
         Node *node = root;
        
        for(int i=0;i<word.length();i++){
           if(!node->containsKey(word[i])){
               return false;
           }
            node=node->go(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
         Node *node=root;
        
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->go(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */