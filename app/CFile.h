#ifndef _CFILE_H_
#define _CFILE_H_
#include<fstream>
#include<list>
#include<map>
#include<vector>
#include<algorithm>
#include"CStaff.h"
#include"CGoods.h"
#include"CGoodsStockRecord.h"
#include<iostream>
#include<conio.h>
using namespace std;

class CFile
{
public:
    CFile();
    ~CFile();
    static list<CStaff> *Staff_init(char *filename);
    static map<int,CGoods> *Goods_init(char *filename);
    static vector<CGoodsStockRecord> *Record_init(char *filename);

    static void Goods_Filewrite(char *filename,map<int,CGoods> *Goods);//写入文件指针
    static void Staff_Filewrite(char *filename,list<CStaff> *Staff);
    static void Record_Filewrite(char *filename,vector<CGoodsStockRecord> *Record);
private:
    fstream fs;
};


#endif // _CFILE_H_
