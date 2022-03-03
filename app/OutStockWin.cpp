#include"OutStockWin.h"
/******************************
*������ OutStockWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
OutStockWin::OutStockWin(int x,int y,int height,int width,char *text,void *record,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->newGoods=new map<int,CGoods>;
    this->WelcomeLab=new CLabel(this->x+6,this->y+4,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+4,2,6,"����:");
    this->NoLab=new CLabel(this->x+2,this->y+6,2,18,"��������Ʒ���:");
    this->NoEdt=new CEdit(this->x+22,this->y+6,2,20,"",EDIT);
    this->SearchBtn=new CButton(this->x+this->width-8,this->y+6,2,4,"��ѯ");
    this->Goods_Found=new CGoodsFound(this->x+3,this->y+8,13,28,NULL);

    this->GoodsName=new CLabel(this->x+6,this->y+9,2,10,"��Ʒ����:");
    this->GoodsType=new CLabel(this->x+6,this->y+11,2,10,"��Ʒ����:");
    this->GoodsPrice=new CLabel(this->x+6,this->y+13,2,10,"��Ʒ�۸�:");
    this->GoodsCount=new CLabel(this->x+6,this->y+15,2,10,"�������:");
    this->LocationNum=new CLabel(this->x+6,this->y+17,2,10,"λ�ñ��:");

    this->CountLab=new CLabel(this->x+this->width-24,this->y+9,2,25,"���������������1-10000��");
    this->CountEdt=new CEdit(this->x+this->width-20,this->y+11,2,16,"",EDIT);
    this->EnterBtn=new CButton(this->x+this->width-20,this->y+16,2,4,"ȷ��");//ȷ����ť
    this->EscBtn=new CButton(this->x+this->width-12,this->y+16,2,4,"ȡ��");//

    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->NoLab);
    this->addControl(this->NoEdt);
    this->addControl(this->SearchBtn);
    this->addControl(this->Goods_Found);
    this->addControl(this->GoodsName);
    this->addControl(this->GoodsType);
    this->addControl(this->GoodsPrice);
    this->addControl(this->GoodsCount);
    this->addControl(this->LocationNum);

    this->addControl(this->CountLab);
    this->addControl(this->CountEdt);//12
    this->addControl(this->EnterBtn);
    this->addControl(this->EscBtn);

    this->input=0;
    this->Record=(vector<CGoodsStockRecord>*)record;
}
OutStockWin::~OutStockWin()
{
    delete this->WelcomeLab;
    delete this->DateLab;
    delete this->NoLab;
    delete this->NoEdt;
    delete this->SearchBtn;
    delete this->GoodsName;
    delete this->GoodsType;
    delete this->GoodsPrice;
    delete this->GoodsCount;
    delete this->LocationNum;
    delete this->Goods_Found;
    delete this->CountLab;
    delete this->CountEdt;
    delete this->EnterBtn;
    delete this->EscBtn;

}

/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/

int OutStockWin::doAction(void *data)
{
    int nowcount=0,deccount=0;//ԭ������Ʒ���������������
    int date=0;//��������ʱ��
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    sscanf(this->controls[3]->getText(),"%d",&input);
    map<int,CGoods>::iterator it;//�˾�֮ǰ������--ԭ����Goods����������--��������ʱ������
    it=Goods->find(input);
    if(strcmp(this->controls[this->curControl]->getText(),"��ѯ")==0)
    {

        if(it!=Goods->end())//��it������������д�뵽�µ�map��,��map ��ֻ��һ��key_value ��
        {
            //���ҵ������ݴ�������
            //this->newGoods->erase(this->newGoods->begin());//�����
            this->newGoods->insert(map<int,CGoods>::value_type(999,CGoods("��ʼ��","����",1205,"1000")));//�ȳ�ʼ��һ����ֵ����ɾ��
            this->newGoods->insert(map<int,CGoods>::value_type(1000,CGoods("��ʼ��","����",1205,"1002")));

            this->newGoods->erase(this->newGoods->begin(),this->newGoods->end());

            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Goods_Found->setnewGoods(this->newGoods);
        }
        else//д������Ʒ����
        {
            cout<<"δ�ҵ�����Ʒ�������²�ѯ";
            getch();
        }
        /***
        map<int,CGoods>::iterator iter2=newGoods->begin();
            for(;iter2!=newGoods->end();++iter2)
            {
                cout<<iter2->first<<" "<<iter2->second.getName()<<" "<<iter2->second.getType()<<" "<<iter2->second.getPrice()<<" "<<iter2->second.getCount()<<" "<<iter2->second.getLocation()<<endl;
            }
            ***/
        return OUTSTOCKWIN;
    }
    if(strcmp(this->controls[this->curControl]->getText(),"ȷ��")==0&&strlen(this->controls[8]->getText())!=0)//ȷ��ʱ�в�ѯ����Ʒ��Ϣ������������ݲŽ��в���
    {

        sscanf(this->controls[12]->getText(),"%d",&deccount);//�޴�
        nowcount=it->second.getCount()-deccount;//���������Ʒ����
        if(nowcount<0||deccount<(-10000))
        {
            cout<<"����������������������";
        }
        else
        {
            it->second.setCount(nowcount);//it��ָ����ҵ�����Ʒ�ĵ�����,��Ʒ�����������޸�
            if(this->newGoods!=NULL)
            {
                this->newGoods->erase(this->newGoods->begin());
            }
            this->newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),nowcount,it->second.getLocation())));
            //this->Goods_Found->setnewGoods(this->newGoods);
            //Goods[input]=CGoods(input,iter->second.getName(),iter->second.getType(),iter->second.getPrice(),iter->second.getCount(),iter->second.getLocation());
            CFile::Goods_Filewrite("data/Goods.txt",Goods);
            cout<<"����ɹ�";

            time_t nowtime=time(NULL);//��ȡ��ǰϵͳ��ʱ�䣬��λΪ��
            struct tm* t=localtime(&nowtime);//ת����tm���͵Ľṹ��
            date=(t->tm_year+1900)*10000+(t->tm_mon+1)*100+t->tm_mday;//��������-int��
            this->Record->push_back(CGoodsStockRecord(this->input,it->second.getName(),date,deccount,it->second.    getLocation()));
            //д���ļ�
            CFile::Record_Filewrite("data/OutRecord.txt",this->Record);
            //cout<<"д���ļ��ɹ�!";

        }
        system("pause");//�˴�������getch()�����򰴷������ᱻ�༭����յڶ�����ֵ
        return OUTSTOCKWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"ȡ��")==0)
    {
        this->Goods_Found->setnewGoods(NULL);
        return OUTSTOCKMENUWIN;//INSTOCKMENUWIN �������˵�����
    }
            return OUTSTOCKWIN;
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void OutStockWin::UpdateControls()
{
    char *Date=new char[20];
    CTool::getDate(Date);
    char newLab[25]={0};
    sprintf(newLab,"����:%s",Date);
    this->DateLab->setLab(newLab);
    if (strcmp(CTool::role,"1")==0)
    {
        this->WelcomeLab->setLab("��ӭ:�ֿ����Ա");
    }
    else
    {
        this->WelcomeLab->setLab("��ӭ:�̵�Ա");
    }

    delete Date;
    return ;
}
