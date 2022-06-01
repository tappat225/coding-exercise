#include<iostream>
#include<cstring>
#include "hash.h"

using namespace std;
#define Maxsize 2000

HashTable:: HashTable()
{
    this->m_size = hash_size;
    this->m_elem = new char* [this->m_size];
    for (int i = 0; i < this->m_size; i++) {
        this->m_elem[i] = NULL;
    }
}

int HashTable::Hash(char value[])//哈希函数
{
    int code = 0;
    for (size_t i = 0; i < strlen(value); i++)//因为涉及到char数组，所以要使用无符号(size_t)下标
    {
        code = (code * 256 + 128 + value[i]) % this->m_size;//这里是使用的开放地址法，函数根据题目而定；
    }
    return code;
}

int HashTable::search(char value[], int& pos, int& times)
{
    pos = Hash(value);
    times = 0;
    while (this->m_elem[pos] != NULL && strcmp(this->m_elem[pos], value) != 0)
    {
        times++;
        if (times < this->m_size) pos = (pos + 1) % this->m_size;//使用的是线性探测法解决冲突
        else return 0;//当超出冲突次数的上限时，就表示没有找到
    }
    if (this->m_elem[pos] != NULL && strcmp(this->m_elem[pos], value) == 0) return 1;//表示找到value
    else return 0;
}

int HashTable::insert(char value[])
{
    int pos, times;
    if (search(value, pos, times)) return 2;//表示该元素已经存在，插入失败
    else if (times < this->m_size / 2)
    {
        this->m_elem[pos] = new char[strlen(value)+1];
        strcpy(this->m_elem[pos], value);
        return 1;//表示直接插入成功
    }
    else
    {
        recreate();
        insert(value);
        return 0;//重建哈希表，并插入成功
    }
}

void HashTable::recreate()
{
    char** temp_elem = new char*[this->m_size];
    int i;
    for (i = 0; i < this->m_size; i++)//将原哈希表中的元素赋给temp_elem
    {
        if (this->m_elem[i])
        {
            temp_elem[i] = new char[strlen(this->m_elem[i]) + 1];
            strcpy(temp_elem[i], this->m_elem[i]);
        }
        else temp_elem[i] = NULL;
    }
    for (i = 0; i < this->m_size; i++) //释放掉原elem
    {
        if (this->m_elem[i]) delete[]this->m_elem[i];
    }
    delete[]this->m_elem;
    int temp_size = this->m_size;
    this->m_size = this->m_size * 2;
    this->m_elem = new char*[this->m_size];//扩充m_elem并初始化
    for (i = 0; i < this->m_size; i++)  this->m_elem[i] = NULL;
    for (i = 0; i < temp_size; i++) //将temp_elem赋值到新的m_elem上
    {
        if (temp_elem[i]) insert(temp_elem[i]);
    }
    for (i = 0; i < temp_size; i++)//释放掉temp_elem
    {
        if (temp_elem[i]) delete[]temp_elem[i];
    }
    delete[]temp_elem;
}

HashTable::~ HashTable()
{
    for (int i = 0; i < this->m_size; i++) {
        if (this->m_elem[i]) delete []this->m_elem[i];
    }
    delete[]this->m_elem;
}
