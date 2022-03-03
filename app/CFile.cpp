#include"CFile.h"
#ifdef WIN32
#pragma warning(disable:4515 4786)
#endif

CFile::CFile()
{
}

CFile::~CFile()
{
}
/******************************
*函数名 Staff_init()
*函数功能：初始化员工文件
*输入 所需数据，如商品信息，员工信息，出入库信息
*返回 界面号
************************************/
list<CStaff> *CFile::Staff_init(char *filename)
{
    fstream fs;
    char str[40]={0};
    int ID;
    char name[10]={0};//用来暂存从str分割出来的name段、pwd段、role段,
    char username[10]={0};
    char pwd[10]={0};
    char role[2]={0};
    list<CStaff>*Staff=new list<CStaff>;
    fs.open(filename,ios::in|ios::out);//有返回值，返回真假
    if(!fs)//如果文件不存在
    {
        cout<<"文件不存在"<<endl;
        fs.clear();//一定要清空一下，否则会出bug
        fs.open(filename,ios::app|ios::in|ios::out);//ios::app是文件不存在就新建，只有第一次

        Staff->push_back(CStaff("admin","韩梅","123456","1"));
        Staff->push_back(CStaff("lili","王啵","123123","0"));
        Staff->push_back(CStaff("nico","小黑","112233","0"));
        Staff->push_back(CStaff("anan","李明","112233","0"));
        Staff->push_back(CStaff("nana","大花","221133","0"));

        list<CStaff>::iterator it=Staff->begin();
        for(;it!=Staff->end();++it)//跟链表结合，stafflist先push_back之后再利用迭代器遍历，写入文件
        {
            fs<<it->getID()<<" "<<it->getName()<<" "<<it->getUsername()<<" "<<it->getPwd()<<" "<<it->getRole()<<endl;
        }
        /**
        for(it=Staff->begin();it!=Staff->end();++it)
        {
            cout<<it->getID()<<" "<<it->getName()<<" "<<it->getUsername()<<" "<<it->getPwd()<<" "<<it->getRole()<<endl;
        }
**/
        cout<<"文件初始化！"<<endl;
        getch();
    }
    else//读文件
    {
        fs.seekg(ios::beg);
        fs.getline(str,40);//读一行40个字节 存到str内
        while(!fs.eof())//文件指针指到末尾
        {
            sscanf(str,"%d %s %s %s %s",&ID,name,username,pwd,role);//name和pwd都是字符数组
            Staff->push_back(CStaff(ID,name,username,pwd,role));
            fs.getline(str,40);//读文件里的一行，所以注意写的时候要换行
        }
    }
    fs.close();
    return Staff;
}

map<int,CGoods> *CFile::Goods_init(char *filename)
{
    fstream fs;
    char str[100]={0};
    int No;//商品编号
    char name[20]={0};
    char type[20]={0};
    int price;//商品价格
    int count;
    char location[20]={0};//仓位编号
    map<int,CGoods>*Goods=new map<int,CGoods>;
    fs.open(filename,ios::in|ios::out);//有返回值，返回真假
    if(!fs)//如果文件不存在
    {
        cout<<"文件不存在"<<endl;
        fs.clear();//一定要清空一下，否则会出bug
        fs.open(filename,ios::app|ios::in|ios::out);

        Goods->insert(map<int,CGoods>::value_type(1001,CGoods(1001,"RedmiK30","手机",2400,500,"AX1001")));
        Goods->insert(map<int,CGoods>::value_type(1002,CGoods(1002,"小米充电宝","移动电源",500,2000,"AX1002")));
        Goods->insert(map<int,CGoods>::value_type(1003,CGoods(1003,"联想笔记本","电子产品",5000,610,"AX1003")));
        Goods->insert(map<int,CGoods>::value_type(1004,CGoods(1004,"华硕笔记本","电子产品",6000,325,"AX1004")));

        map<int,CGoods>::iterator it=Goods->begin();
        for(;it!=Goods->end();++it)
        {
            fs<<it->first<<" "<<it->second.getName()<<" "<<it->second.getType()<<" "<<it->second.getPrice()<<" "<<it->second.getCount()<<" "<<it->second.getLocation()<<endl;//写入时写一行
        }
        cout<<"文件初始化！"<<endl;
    }
    else//读文件
    {
        fs.seekg(ios::beg);
        fs.getline(str,40);//读一行40个字节 存到str内
        while(!fs.eof())//文件指针指到末尾
        {
            sscanf(str,"%d %s %s %d %d %s",&No,name,type,&price,&count,location);
            Goods->insert(map<int,CGoods>::value_type(No,CGoods(No,name,type,price,count,location)));
            fs.getline(str,100);
        }

    }
    fs.close();
    return Goods;
}

/*****
/Date是char*型字符的字符串，存储XXXX-XX-XX（年月日）
************/

vector<CGoodsStockRecord> *CFile::Record_init(char *filename)
{
    fstream fs;
    char str[40]={0};
    int No;//商品编号
    char name[20]={0};
    int date=0;//入库时间
    int count;//入库数量
    char location[10]={0};//仓位编号
    vector<CGoodsStockRecord>*InstockRecord=new vector<CGoodsStockRecord>;
    fs.open(filename,ios::in|ios::out);//有返回值，返回真假
    if(!fs)//如果文件不存在
    {
        cout<<"文件不存在"<<endl;
        fs.clear();//一定要清空一下，否则会出bug
        fs.open(filename,ios::app|ios::in|ios::out);

        InstockRecord->push_back(CGoodsStockRecord(1001,"RedmiK30",20200328,20,"AX1001"));
        InstockRecord->push_back(CGoodsStockRecord(1002,"小米充电宝",20200401,50,"AX1002"));
        InstockRecord->push_back(CGoodsStockRecord(1002,"小米充电宝",20200402,40,"AX1002"));
        InstockRecord->push_back(CGoodsStockRecord(1002,"小米充电宝",20200402,60,"AX1002"));

        vector<CGoodsStockRecord>::iterator it=InstockRecord->begin();
        for(;it!=InstockRecord->end();++it)//跟链表结合，stafflist先push_back之后再利用迭代器遍历，写入文件
        {
            fs<<it->getNo()<<" "<<it->getName()<<" "<<it->getDate()<<" "<<it->getCount()<<" "<<it->getLocation()<<endl;//写入时写一行
        }
        cout<<"文件初始化！"<<endl;
    }
    else//读文件
    {
        fs.seekg(ios::beg);
        fs.getline(str,40);//读一行40个字节 存到str内
        while(!fs.eof())//文件指针指到末尾
        {
            sscanf(str,"%d %s %d %d %s",&No,name,&date,&count,location);//name和pwd都是字符数组
            //sscanf(date,"%d-%d-%d",&year,&mon,&day);//上一步读出的日期有符号，把符号去掉之后转成整型
            //Date=year*10000+mon*100+day;
            InstockRecord->push_back(CGoodsStockRecord(No,name,date,count,location));
            fs.getline(str,40);//读文件里的一行，所以注意写的时候要换行
        }
    }
    fs.close();
    return InstockRecord;
}

void CFile::Goods_Filewrite(char *filename,map<int,CGoods> *Goods)
{
    fstream fs;
    fs.open(filename,ios::out);
    fs.clear();//一定要清空一下，否则会出bug
    fs.seekp(ios::beg);
    map<int,CGoods>::iterator it=Goods->begin();
    for(it=Goods->begin();it!=Goods->end();++it)
    {
        fs<<it->first<<" "<<it->second.getName()<<" "<<it->second.getType()<<" "<<it->second.getPrice()<<" "<<it->second.getCount()<<" "<<it->second.getLocation()<<endl;//写入时写一行
    }
    fs.close();
}

void CFile::Staff_Filewrite(char *filename,list<CStaff> *Staff)
{

    fstream fs;
    fs.open(filename,ios::out);
    fs.clear();//一定要清空一下，否则会出bug
    fs.seekp(ios::beg);
    list<CStaff>::iterator it=Staff->begin();
    for(it=Staff->begin();it!=Staff->end();++it)
    {
        fs<<it->getID()<<" "<<it->getName()<<" "<<it->getUsername()<<" "<<it->getPwd()<<" "<<it->getRole()<<endl;
    }
    fs.close();
}


void CFile::Record_Filewrite(char *filename,vector<CGoodsStockRecord> *Record)
{
    fstream fs;
    fs.open(filename,ios::out);
    fs.clear();//一定要清空一下，否则会出bug
    fs.seekp(ios::beg);
    vector<CGoodsStockRecord>::iterator it=Record->begin();
    for(it=Record->begin();it!=Record->end();++it)
    {
        fs<<it->getNo()<<" "<<it->getName()<<" "<<it->getDate()<<" "<<it->getCount()<<" "<<it->getLocation()<<endl;//写入时写一行
    }
    fs.close();
}


