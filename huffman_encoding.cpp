
/* HUFFMAN ENCODING is used to store large data in small space using variable length for a particular character. Basically it creates a tree of each char based on its frequencies
Time O(nlogn)
Space O(n);
*/
class Solution{
    private:
        struct MinHeapNode{
        char data;
        unsigned freq;
        MinHeapNode *left,*right;
        MinHeapNode(char data,unsigned freq){
            left=right=NULL;
            this->data=data;
            this->freq=freq;
        }
    };
    struct compare{
      bool operator()(MinHeapNode* l,MinHeapNode* r)  {
          return (l->freq>r->freq);
      }
    };
	public:
	    void printCode(struct MinHeapNode* root,vector<string>&ans,string s){
	        if(!root) return;
	        if(root->data!='$')
	            {
	                ans.push_back(s);
	                return;
	            }
	        printCode(root->left,ans,s+"0");
	        printCode(root->right,ans,s+"1");
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    struct MinHeapNode *left,*right,*top;
		    priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare>minHeap;
		    for(int i=0;i<N;i++)
		        minHeap.push(new MinHeapNode(S[i],f[i]));
		    while(minHeap.size()!=1){
		        left=minHeap.top();
		        minHeap.pop();
		        right=minHeap.top();
		        minHeap.pop();
		        top=new MinHeapNode('$',left->freq+right->freq);
		        top->left=left;
		        top->right=right;
		        minHeap.push(top);
		    }
		    vector<string>ans;
		    printCode(minHeap.top(),ans,"");
		    return ans;
		}
};
