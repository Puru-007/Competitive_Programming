#include<bits/stdc++.h>
using namespace std;


class HuffmanNode {
    public:
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode(char ch, int count) {
        data = ch;
        freq = count;
        left = NULL;
        right = NULL;
    } 
};

class CompareByMaxFreq {
    public:
    bool operator ()(HuffmanNode* n1, HuffmanNode* n2) {
        return (n1 -> freq > n2 -> freq);
    }
};

class Solution
{
	public:
	    vector<string> huffmanCodesArr;
	    
	    void fetchHuffmanCode(HuffmanNode* node, int top, int arr[]) {
	        if(node -> left != NULL) {
	            arr[top] = 0;
	           // cout<<top<<"__";
	            fetchHuffmanCode(node -> left, top+1, arr);
	        }
	        
	        if(node -> right != NULL){
	            arr[top] = 1;
	           // cout<<top<<"__";
	            fetchHuffmanCode(node -> right, top+1, arr);
	        }
	        
	        if(!(node -> left) && !(node -> right)) {
	            string s = "";
	            for(int i=0; i<top; i++) {
	               // cout<<i<<"__";
	                s += to_string(arr[i]);
	            }
	            huffmanCodesArr.push_back(s);
	        }
	    }
	    
	    
	    HuffmanNode* generateHuffmanTree(priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareByMaxFreq> pq) {
	        while(pq.size() != 1){
	            HuffmanNode* left = pq.top();
	            pq.pop();
	            HuffmanNode* right = pq.top();
	            pq.pop();
	            HuffmanNode* node = new HuffmanNode('$', left -> freq + right -> freq);
	            node -> left = left;
	            node -> right = right;
	            pq.push(node);
	        }
	        return pq.top();
	    }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareByMaxFreq> pq;
		    for(int i=0; i<N; i++) {
		        HuffmanNode* node = new HuffmanNode(S[i], f[i]);
		        pq.push(node);
		    }
		    int arr[1000099];
		    HuffmanNode* root = generateHuffmanTree(pq);
		    fetchHuffmanCode(root, 0, arr);
		    return huffmanCodesArr;
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
} 

// Example 1:

// S = "abcdef"
// f[] = {5, 9, 12, 13, 16, 45}
// Output: 
// 0 100 101 1100 1101 111
// Explanation:
// HuffmanCodes will be:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111
// Hence printing them in the PreOrder of Binary 
// Tree.
// Your Task:
// You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, frequency array f[ ] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

// Expected Time complexity: O(N * LogN) 
// Expected Space complexity: O(N) 