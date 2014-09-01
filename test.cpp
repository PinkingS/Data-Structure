#include <iostream>
#include <vector>
#include <string.h>
#define match2(ch1,ch2) (ch1==ch2 ||ch1=='.'||ch2=='.'||ch1=='*'||ch2=='*')//检查两个字符是否匹配

using namespace std;

    bool isMatch(const char *s, const char *p) {
        int m=sizeof(s)/sizeof(char),n=sizeof(p)/sizeof(char);
		cout << strlen(s) << endl;
        if(m==0&&n==0)
            return true;
        if(m==0||n==0)
            return false;
        vector<vector<bool> >rt(m,vector<bool>(n,false));
        rt[0][0]=match2(s[0],p[0]);
        //处理第0行
        if(s[0]=='*')
            for(int j=1;j<n;j++)
                rt[0][j]=true;
        //处理第0列
        if(p[0]=='*')
            for(int i=1;i<m;i++)
                rt[i][0]=true;
        //处理其他
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
            {
                if(rt[i-1][j]&&p[j]=='*')
                {
                    rt[i][j]=true;
                    continue;
                }
                if(rt[i][j-1]&&s[i]=='*')
                {
                    rt[i][j]=true;
                    continue;
                }
                if(rt[i-1][j-1]&&match2(s[i],p[j]))
                {
                    rt[i][j]=true;
                    continue;
                }
            }
        return rt[m-1][n-1];
    }

//用动态规划
//f(i,j)表示s[0,...i]这个子串能与p[0...j]匹配上
//f(i,j)=1,当且仅当以下3种情况之一出现：
//f(i-1,j-1)=1且s[i]与s[p]能匹配上
//f(i,j-1)=1且s[i]='*'
//f(i-1,j)=1且s[j]='*'n


int main(){
	char* a = "aa";
	char* b = "bb";
	cout << isMatch(a, b) << endl;	
	
	return 0;
}
