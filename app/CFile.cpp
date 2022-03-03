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
*������ Staff_init()
*�������ܣ���ʼ��Ա���ļ�
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
list<CStaff> *CFile::Staff_init(char *filename)
{
    fstream fs;
    char str[40]={0};
    int ID;
    char name[10]={0};//�����ݴ��str�ָ������name�Ρ�pwd�Ρ�role��,
    char username[10]={0};
    char pwd[10]={0};
    char role[2]={0};
    list<CStaff>*Staff=new list<CStaff>;
    fs.open(filename,ios::in|ios::out);//�з���ֵ���������
    if(!fs)//����ļ�������
    {
        cout<<"�ļ�������"<<endl;
        fs.clear();//һ��Ҫ���һ�£�������bug
        fs.open(filename,ios::app|ios::in|ios::out);//ios::app���ļ������ھ��½���ֻ�е�һ��

        Staff->push_back(CStaff("admin","��÷","123456","1"));
        Staff->push_back(CStaff("lili","���","123123","0"));
        Staff->push_back(CStaff("nico","С��","112233","0"));
        Staff->push_back(CStaff("anan","����","112233","0"));
        Staff->push_back(CStaff("nana","��","221133","0"));

        list<CStaff>::iterator it=Staff->begin();
        for(;it!=Staff->end();++it)//�������ϣ�stafflist��push_back֮�������õ�����������д���ļ�
        {
            fs<<it->getID()<<" "<<it->getName()<<" "<<it->getUsername()<<" "<<it->getPwd()<<" "<<it->getRole()<<endl;
        }
        /**
        for(it=Staff->begin();it!=Staff->end();++it)
        {
            cout<<it->getID()<<" "<<it->getName()<<" "<<it->getUsername()<<" "<<it->getPwd()<<" "<<it->getRole()<<endl;
        }
**/
        cout<<"�ļ���ʼ����"<<endl;
        getch();
    }
    else//���ļ�
    {
        fs.seekg(ios::beg);
        fs.getline(str,40);//��һ��40���ֽ� �浽str��
        while(!fs.eof())//�ļ�ָ��ָ��ĩβ
        {
            sscanf(str,"%d %s %s %s %s",&ID,name,username,pwd,role);//name��pwd�����ַ�����
            Staff->push_back(CStaff(ID,name,username,pwd,role));
            fs.getline(str,40);//���ļ����һ�У�����ע��д��ʱ��Ҫ����
        }
    }
    fs.close();
    return Staff;
}

map<int,CGoods> *CFile::Goods_init(char *filename)
{
    fstream fs;
    char str[100]={0};
    int No;//��Ʒ���
    char name[20]={0};
    char type[20]={0};
    int price;//��Ʒ�۸�
    int count;
    char location[20]={0};//��λ���
    map<int,CGoods>*Goods=new map<int,CGoods>;
    fs.open(filename,ios::in|ios::out);//�з���ֵ���������
    if(!fs)//����ļ�������
    {
        cout<<"�ļ�������"<<endl;
        fs.clear();//һ��Ҫ���һ�£�������bug
        fs.open(filename,ios::app|ios::in|ios::out);

        Goods->insert(map<int,CGoods>::value_type(1001,CGoods(1001,"RedmiK30","�ֻ�",2400,500,"AX1001")));
        Goods->insert(map<int,CGoods>::value_type(1002,CGoods(1002,"С�׳�籦","�ƶ���Դ",500,2000,"AX1002")));
        Goods->insert(map<int,CGoods>::value_type(1003,CGoods(1003,"����ʼǱ�","���Ӳ�Ʒ",5000,610,"AX1003")));
        Goods->insert(map<int,CGoods>::value_type(1004,CGoods(1004,"��˶�ʼǱ�","���Ӳ�Ʒ",6000,325,"AX1004")));

        map<int,CGoods>::iterator it=Goods->begin();
        for(;it!=Goods->end();++it)
        {
            fs<<it->first<<" "<<it->second.getName()<<" "<<it->second.getType()<<" "<<it->second.getPrice()<<" "<<it->second.getCount()<<" "<<it->second.getLocation()<<endl;//д��ʱдһ��
        }
        cout<<"�ļ���ʼ����"<<endl;
    }
    else//���ļ�
    {
        fs.seekg(ios::beg);
        fs.getline(str,40);//��һ��40���ֽ� �浽str��
        while(!fs.eof())//�ļ�ָ��ָ��ĩβ
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
/Date��char*���ַ����ַ������洢XXXX-XX-XX�������գ�
************/

vector<CGoodsStockRecord> *CFile::Record_init(char *filename)
{
    fstream fs;
    char str[40]={0};
    int No;//��Ʒ���
    char name[20]={0};
    int date=0;//���ʱ��
    int count;//�������
    char location[10]={0};//��λ���
    vector<CGoodsStockRecord>*InstockRecord=new vector<CGoodsStockRecord>;
    fs.open(filename,ios::in|ios::out);//�з���ֵ���������
    if(!fs)//����ļ�������
    {
        cout<<"�ļ�������"<<endl;
        fs.clear();//һ��Ҫ���һ�£�������bug
        fs.open(filename,ios::app|ios::in|ios::out);

        InstockRecord->push_back(CGoodsStockRecord(1001,"RedmiK30",20200328,20,"AX1001"));
        InstockRecord->push_back(CGoodsStockRecord(1002,"С�׳�籦",20200401,50,"AX1002"));
        InstockRecord->push_back(CGoodsStockRecord(1002,"С�׳�籦",20200402,40,"AX1002"));
        InstockRecord->push_back(CGoodsStockRecord(1002,"С�׳�籦",20200402,60,"AX1002"));

        vector<CGoodsStockRecord>::iterator it=InstockRecord->begin();
        for(;it!=InstockRecord->end();++it)//�������ϣ�stafflist��push_back֮�������õ�����������д���ļ�
        {
            fs<<it->getNo()<<" "<<it->getName()<<" "<<it->getDate()<<" "<<it->getCount()<<" "<<it->getLocation()<<endl;//д��ʱдһ��
        }
        cout<<"�ļ���ʼ����"<<endl;
    }
    else//���ļ�
    {
        fs.seekg(ios::beg);
        fs.getline(str,40);//��һ��40���ֽ� �浽str��
        while(!fs.eof())//�ļ�ָ��ָ��ĩβ
        {
            sscanf(str,"%d %s %d %d %s",&No,name,&date,&count,location);//name��pwd�����ַ�����
            //sscanf(date,"%d-%d-%d",&year,&mon,&day);//��һ�������������з��ţ��ѷ���ȥ��֮��ת������
            //Date=year*10000+mon*100+day;
            InstockRecord->push_back(CGoodsStockRecord(No,name,date,count,location));
            fs.getline(str,40);//���ļ����һ�У�����ע��д��ʱ��Ҫ����
        }
    }
    fs.close();
    return InstockRecord;
}

void CFile::Goods_Filewrite(char *filename,map<int,CGoods> *Goods)
{
    fstream fs;
    fs.open(filename,ios::out);
    fs.clear();//һ��Ҫ���һ�£�������bug
    fs.seekp(ios::beg);
    map<int,CGoods>::iterator it=Goods->begin();
    for(it=Goods->begin();it!=Goods->end();++it)
    {
        fs<<it->first<<" "<<it->second.getName()<<" "<<it->second.getType()<<" "<<it->second.getPrice()<<" "<<it->second.getCount()<<" "<<it->second.getLocation()<<endl;//д��ʱдһ��
    }
    fs.close();
}

void CFile::Staff_Filewrite(char *filename,list<CStaff> *Staff)
{

    fstream fs;
    fs.open(filename,ios::out);
    fs.clear();//һ��Ҫ���һ�£�������bug
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
    fs.clear();//һ��Ҫ���һ�£�������bug
    fs.seekp(ios::beg);
    vector<CGoodsStockRecord>::iterator it=Record->begin();
    for(it=Record->begin();it!=Record->end();++it)
    {
        fs<<it->getNo()<<" "<<it->getName()<<" "<<it->getDate()<<" "<<it->getCount()<<" "<<it->getLocation()<<endl;//д��ʱдһ��
    }
    fs.close();
}


