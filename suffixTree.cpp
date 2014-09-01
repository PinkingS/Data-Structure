#include<iostream>  
#include<cstring>  

using namespace std;  
  
const int MAX=26;  
struct Trie //Trie结点声明  
{  
    bool isStr;//标记该结点处是否构成一个串  
    Trie *next[MAX];//一个指针数组，存放着指向各个儿子节点的指针  
};  
  
void insert(Trie *root,const char *s) //将单词s插入到字典树中  
{  
    if(root==NULL||*s=='\0')  
        return;  
    Trie *p=root;  
    while(*s)  
    {  
        if(p->next[*s-'a']==NULL)//如果不存在存储该字符的节点，则建立结点  
        {  
            Trie *temp=new Trie;  
            for(int i=0; i<MAX; i++)  
            {  
                temp->next[i]=NULL;  
            }  
            temp->isStr=false;  
            p->next[*s-'a']=temp;  
            p=p->next[*s-'a'];  
        }  
        else  
        {  
            p=p->next[*s-'a'];  
        }  
        s++;//让指针s指向下一个字符  
    }  
    p->isStr=true;//单词结束的地方标记此处可以构成一个串  
} 

void del(Trie *root)//释放整个字典树占的堆区空间  
{  
    for(int i=0; i<MAX; i++)  
    {  
        if(root->next[i]!=NULL)  
        {  
            del(root->next[i]);  
        }  
    }  
    delete root;  
} 

int matchLength(const char *text, Trie *root) {
	int len = 0;
	Trie *p = root;
	while(*text) {
		if(p->next[*text-'a'] == NULL)
			break;
		p = p->next[*text-'a'];
		++len;
		++text;
	}
	return len;
}

int longestSubStr(const char *query, const char *text) {
	Trie *root = new Trie;  
    for(int i=0; i<MAX; i++)  
    {  
        root->next[i]=NULL;  
    }  
    root->isStr=false;  
	
	// construct suffix tree
	const char *s = query;
	while(*s) {
		insert(root, s);
		++s;
	}

	int maxLength = 0;
	while(*text) {
		int len = matchLength(text, root);
		if(len > maxLength)
			maxLength = len;
		++text;
	}

	del(root);

	return maxLength;
}


int main()  
{  
	char *query = "acbac";
	char *text = "acaccbabb";
	cout << longestSubStr(query, text) << endl;
	 
    return 0;  
}
