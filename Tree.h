#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree CreateTree();
SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
void displayTree(SearchTree T);

#endif