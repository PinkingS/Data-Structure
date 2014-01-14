#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);

#endif