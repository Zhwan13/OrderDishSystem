#include"CGoodSearchWin.h"


/******************************
*������ CGoodSearchWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CGoodSearchWin::CGoodSearchWin(int x,int y,int height,int width,char *text,void *data,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{
    this->curPage=0;
    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-16,this->y+3,2,6,"����:");
    this->InputNum=new CLabel(this->x+2,this->y+5,2,16,"��������Ʒ���:");
    this->ComInput=new CEdit(this->x+18,this->y+5,2,16,"",EDIT);
    this->GoodsNum=new CLabel(this->x+7,this->y+8,2,6,"��Ʒ���");
    this->GoodsName=new CLabel(this->x+19,this->y+8,2,6,"��Ʒ����");
    this->GoodsType=new CLabel(this->x+31,this->y+8,2,6,"��Ʒ����");
    this->GoodsPrice=new CLabel(this->x+43,this->y+8,2,6,"��Ʒ�۸�");
    this->GoodsCount=new CLabel(this->x+55,this->y+8,2,6,"�������");
    this->LocationNum=new CLabel(this->x+67,this->y+8,2,6,"��λ���");
    this->UpDownPage=new CLabel(this->x+this->width/2-10,this->y+this->height-5,2,20,"<��ҳ          ��ҳ>");//10,5,22,80,

    this->SearchBtn=new CButton(this->x+(this->width)-6,this->y+5,2,4,"��ѯ");
    this->ExportBtn=new CButton(this->x+(this->width)/4-1,this->y+this->height-4,2,4,"����");
    this->ExitBtn=new CButton(this->x+(this->width)*3/4-1,this->y+this->height-4,2,4,"�˳�");

    this->data=data;
    this->Table=new CTable(16,12,8,70,this->data,GOODSTABLE);

    this->addControl(this->UpDownPage);
    this->addControl(this->Table);
    this->addControl(this->InputNum);//
    this->addControl(this->ComInput);
    this->addControl(this->GoodsNum);
    this->addControl(this->GoodsName);
    this->addControl(this->GoodsType);
    this->addControl(this->GoodsPrice);
    this->addControl(this->GoodsCount);
    this->addControl(this->LocationNum);
    this->addControl(this->SearchBtn);
    this->addControl(this->ExportBtn);
    this->addControl(this->ExitBtn);
    this->addControl(this->WelcomeLab);
	this->addControl(this->DateLab);
}
CGoodSearchWin::~CGoodSearchWin()
{
}
/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CGoodSearchWin::doAction(void *data)
{
    //��ӡ��������
    int input=0;
    map<int,CGoods>*Goods=(map<int,CGoods> *)data;
    map<int,CGoods>*newGoods=new map<int,CGoods>;
    if(strcmp(this->controls[this->curControl]->getText(),"��ѯ")==0)
    {
        //�˴�����ѯҵ�񣬲鵽��������һ���µ�map������������Table�ӿں���setdata���Լ�дһ�����������������鵽�����ݣ�����ȥ�����ڿؼ�table��show����
        //��data��ȷ��ѯ��
        sscanf(this->controls[3]->getText(),"%d",&input);
        map<int,CGoods>::iterator it;
        it=Goods->find(input);
        if(it!=Goods->end())
        {//��it������������д�뵽�µ�map��
            newGoods->insert(map<int,CGoods>::value_type(it->first,CGoods(it->first,it->second.getName(),it->second.getType(),it->second.getPrice(),it->second.getCount(),it->second.getLocation())));
            this->Table->setData(newGoods);//this->data���ղ鵽������
        }
        else
        {
            CTool::gotoxy(this->x+(this->width)-16,this->y+4);
            cout<<"no find";
            getch();
        }
        return SEARCHWIN;
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"����")==0)
    {
        //��������
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"�˳�")==0)
    {
        return ADMINWIN;//�˳��ص�����Ա����
    }
    return SEARCHWIN;
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void CGoodSearchWin::UpdateControls()
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
