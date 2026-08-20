class TrieNode{
    public:
    char data;
    unordered_map<char,TrieNode*>children;
    bool isTerminal;
    int childCount;

    TrieNode(char val){
        this->data = val;
        isTerminal = false;
        childCount = 0;
    }
};
class Solution {
public:
    void insertWord(TrieNode* root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        TrieNode* child;

        if(root->children.find(ch) != root->children.end()){
            //present
            child = root->children[ch];
        }
        else{
            // absent
            child = new TrieNode(ch);
            root->children[ch] = child;
            root->childCount++;
        }

        insertWord(child, word.substr(1));
        return;
    }

    void findLCP(TrieNode* root, string& ans){
        if(root->isTerminal) return;

        while(root->childCount == 1){
            
            if(root->isTerminal) break;

            ans.push_back(root->data);
            
            for(auto i: root->children){
                if(i.second != nullptr){
                    root = i.second;
                }
            }
        }
        ans.push_back(root->data);
        return;
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');

        for(auto s: strs){
            insertWord(root,s);
        }

        string ans;
        findLCP(root,ans);
        return ans.size() > 0? ans.substr(1): ans;
    }
};