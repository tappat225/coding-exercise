#pragma once

class  HashTable
{
public:
    HashTable();//初始化哈希表
    int Hash(char value[]);//哈希函数
    int search(char value[], int &pos, int &times);//查找函数
    int insert(char value[]);//插入函数
    void recreate();//重建哈希表
    ~ HashTable();//释放哈希表

private:
    char** m_elem;
    int m_size;
    const int hash_size = 2000;
};
