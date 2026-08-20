class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;

    TrieNode(char val) {
        this->data = val;
        this->isTerminal = false;
    }
};
class Solution {
public:
    void insertWord(TrieNode* root, string word) {
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        char ch = word[0];
        TrieNode* child;

        if (root->children.find(ch) != root->children.end()) {
            child = root->children[ch];
        } else {
            child = new TrieNode(ch);
            root->children[ch] = child;
        }

        insertWord(child, word.substr(1));
        return;
    }

    string joinWithSpace(vector<string>& arr) {
        if (arr.empty())
            return "";

        string result = arr[0];

        // Baaki words ko space ke sath append karo
        for (int i = 1; i < arr.size(); i++) {
            result += " " + arr[i];
        }

        return result;
    }

    void findSol(TrieNode* root, vector<string>& arr, int i, string word, string ans){
        if(root->isTerminal){
            ans.push_back(root->data);
            arr[i] = ans.substr(1);
            return;
        }
        if(word.empty()) return;

        char ch = word[0];
        TrieNode* child;

        if(root->children.find(ch) != root->children.end()){
            ans.push_back(root->data);
            child = root->children[ch];
        }
        else{
            return;
        }

        findSol(child,arr,i,word.substr(1),ans);
        return;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        TrieNode* root = new TrieNode('-');
        for (string s : dictionary) {
            insertWord(root, s);
        }

        stringstream ss(sentence);
        vector<string> arr;
        string word;

        while (ss >> word) {
            arr.push_back(word);
        }

        for (int i = 0; i < arr.size(); i++) {
            string ans = "";
            findSol(root, arr, i, arr[i], ans);
        }

        return joinWithSpace(arr);
    }
};