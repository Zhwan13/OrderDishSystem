#ifndef _CLIST_H
#define _CLIST_H
#include<iostream>
using namespace std;

//����ڵ���
template<class T>
class CListNode
{
public:
	T data;
	CListNode <T>*pNext;//ע�� T
	CListNode <T>*pPrev;//ע�� T
};

//������
template<class T>
class CList
{
public:
	CList():head(NULL),tail(NULL),count(0){}//ͷβ��㶼����Ҫ����

	//��β����ӽ��
	void list_push(const T &data)//��ʱ���ô��Ρ����õ������ٿռ䣬Ϊ������data���޸��������const
	{
		CListNode<T> *pNewNode=new CListNode <T>;
		memset(pNewNode,0,sizeof(CListNode <T>));
		pNewNode->data=data;//���ô��δ˴��Ͳ��ᴥ����������
		if(this->head==NULL)
		{
			head=tail=pNewNode;//����Ϊ��ʱ��ͷ����β��㶼ָ��ͬһ����
		}
		else
		{
			tail->pNext=pNewNode;
			pNewNode->pPrev=tail;
			tail=pNewNode;
		}
		this->count++;
	}

	//ɾ��β�����
	int list_pop()
	{
	    CListNode<T> *pNode=this->tail;
	    this->tail=tail->pPrev;
	    delete pNode;
	    this->count--;
	    return 1;//ɾ���ɹ�
	}

	//��ȡ�ڵ���
	int getSize()
	{
		return this->count;
	}

	CListNode<T> *getHead()
	{
	    return this->head;
	}

	//��ȡ�ڵ�
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
	void list_show()//��ӡ�����������ӡ����
	{
	    CListNode<T> *pNode=new CListNode <T>;
	    pNode=this->head;
	    while(pNode->pNext!=tail)
        {
            pNode=pNode->pNext;
            cout<<pNode->data<<endl; //�ᱨ��error: no match for 'operator<<' (operand types are 'std::ostream {aka std::basic_ostream<char>}' and 'CStaff')|
       }
        return ;
	}****/

private:
	CListNode<T> *head; //ͷ���
	CListNode<T> *tail; //β���
	int count;  //�ڵ����
};

#endif
