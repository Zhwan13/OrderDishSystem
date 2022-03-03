#ifndef _CLIST_H
#define _CLIST_H
#include<iostream>
using namespace std;

//链表节点类
template<class T>
class CListNode
{
public:
	T data;
	CListNode <T>*pNext;//注意 T
	CListNode <T>*pPrev;//注意 T
};

//链表类
template<class T>
class CList
{
public:
	CList():head(NULL),tail(NULL),count(0){}//头尾结点都不需要传参

	//往尾部添加结点
	void list_push(const T &data)//此时引用传参、不用单独开辟空间，为了限制data被修改所以添加const
	{
		CListNode<T> *pNewNode=new CListNode <T>;
		memset(pNewNode,0,sizeof(CListNode <T>));
		pNewNode->data=data;//引用传参此处就不会触发拷贝构造
		if(this->head==NULL)
		{
			head=tail=pNewNode;//链表为空时，头结点和尾结点都指向同一块结点
		}
		else
		{
			tail->pNext=pNewNode;
			pNewNode->pPrev=tail;
			tail=pNewNode;
		}
		this->count++;
	}

	//删除尾部结点
	int list_pop()
	{
	    CListNode<T> *pNode=this->tail;
	    this->tail=tail->pPrev;
	    delete pNode;
	    this->count--;
	    return 1;//删除成功
	}

	//获取节点数
	int getSize()
	{
		return this->count;
	}

	CListNode<T> *getHead()
	{
	    return this->head;
	}

	//获取节点
	T getNodeData(int pos)
	{
		int i=0;
		CListNode<T> *pNode=new CListNode <T>;
		pNode=this->head;
		if(pos>this->count)
		{
			return *((T *)NULL);
		}
		for(i=1;i<=this->count;i++)
		{
			if(i==pos)
			{
				break;
			}
			pNode=pNode->pNext;
		}
		return pNode->data;
	}
	/******
	void list_show()//打印链表——好像打印不了
	{
	    CListNode<T> *pNode=new CListNode <T>;
	    pNode=this->head;
	    while(pNode->pNext!=tail)
        {
            pNode=pNode->pNext;
            cout<<pNode->data<<endl; //会报错error: no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'CStaff')|
       }
        return ;
	}****/

private:
	CListNode<T> *head; //头结点
	CListNode<T> *tail; //尾结点
	int count;  //节点计数
};

#endif
