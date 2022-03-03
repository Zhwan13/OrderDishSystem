#include "CGoodsAddWin.h"



/******************************
*������ CGoodsAddWin()
*�������ܣ�������湹�캯�����Դ���Ŀؼ����г�ʼ��
*���� ���������Ϳ�ȡ��߶ȡ���������
*��� ��
************************************/
CGoodsAddWin::CGoodsAddWin(int x,int y,int height,int width,char *text,int winNo)
:CWinBase(x,y,height,width,text,winNo)
{

    this->WelcomeLab=new CLabel(this->x+6,this->y+3,2,6,"��ӭ:");
    this->DateLab=new CLabel(this->x+this->width-20,this->y+3,2,6,"����:");
    this->GoodsNoLab=new CLabel(this->x+8,this->y+5,2,10,"��Ʒ���:");
    this->GoodsNo=new CLabel(this->x+19,this->y+5,2,10,CTool::temp);//(CTool::getTemp())
    this->GoodsNameLab=new CLabel(this->x+8,this->y+8,2,10,"��Ʒ����:");
    this->GoodsNameEdt=new CEdit(this->x+19,this->y+8,2,22,"",CHNEDIT);
    this->GoodsTypeLab=new CLabel(this->x+8,this->y+11,2,10,"��Ʒ����:");
    this->GoodsTypeEdt=new CEdit(this->x+19,this->y+11,2,22,"",CHNEDIT);
    this->GoodsPriceLab=new CLabel(this->x+8,this->y+14,2,10,"��Ʒ�۸�:");
    this->GoodsPriceEdt=new CEdit(this->x+19,this->y+14,2,22,"",CHNEDIT);
    this->GoodsPositionLab=new CLabel(this->x+8,this->y+17,2,10,"��λ���:");
    this->GoodsPositionEdt=new CEdit(this->x+19,this->y+17,2,22,"",EMPTYEDIT);//�˱༭�򲻱��༭
    this->Enter=new CButton(this->x+14,this->y+21,2,4,"ȷ��");
    this->Esc=new CButton(this->x+this->width-16,this->y+21,2,4,"ȡ��");


    this->addControl(this->WelcomeLab);
    this->addControl(this->DateLab);
    this->addControl(this->GoodsNoLab);
    this->addControl(this->GoodsNo);
    this->addControl(this->GoodsNameLab);
    this->addControl(this->GoodsNameEdt);//��Ʒ���� 5
    this->addControl(this->GoodsTypeLab);
    this->addControl(this->GoodsTypeEdt);//��Ʒ���� 7
    this->addControl(this->GoodsPriceLab);
    this->addControl(this->GoodsPriceEdt);//��Ʒ�۸� 9
    this->addControl(this->GoodsPositionLab);
    this->addControl(this->GoodsPositionEdt);//��λ��� 11
    this->addControl(this->Enter);
    this->addControl(this->Esc);
}

CGoodsAddWin::~CGoodsAddWin()
{

}
/******************************
*������ doAction()
*�������ܣ��԰���������������Ӧ
*���� �������ݣ�����Ʒ��Ϣ��Ա����Ϣ���������Ϣ
*���� �����
************************************/
int CGoodsAddWin::doAction(void *data)
{
    int No=0;
    int price=0;
    map<int,CGoods>*Goods=(map<int,CGoods>*)data;
    if(strcmp(this->controls[this->curControl]->getText(),"ȷ��")==0)
    {
        //�½���Ʒ�ڵ�
        if(strlen(this->controls[5]->getText())==0||strlen(this->controls[7]->getText())==0||strlen(this->controls[9]->getText())==0)
        {
            CTool::gotoxy(28,29);
            cout<<"��Ʒ��Ϣδ��������������������";
            return GOODSADDWIN;
        }
        else
        {
            sscanf(CTool::temp,"%d",&No);
            sscanf(this->controls[9]->getText(),"%d",&price);
            Goods->insert(map<int,CGoods>::value_type(No,CGoods(No,this->controls[5]->getText(),this->controls[7]->getText(),price,0)));//��Ʒ������ʼ��Ϊ0
            map<int,CGoods>::iterator it;
            it=Goods->find(No);
            CTool::gotoxy(this->x+19,this->y+17);
            cout<<it->second.getLocation();//��ʾ��λ���
            CFile::Goods_Filewrite("data/Goods.txt",Goods);//д���ļ�
            CTool::gotoxy(this->x+19,this->y+19);
            cout<<"�����ɹ�!";
            system("pause");
            return INSTOCKWIN;
        }
    }
    else if(strcmp(this->controls[this->curControl]->getText(),"ȡ��")==0)
    {
        return INSTOCKWIN;
    }
}

/******************************
*������ UpdateControls()
*�������ܣ����´���ؼ�����Ҫ�ǵ�¼�ߵ���ݺ͵�ǰ����
*���� ��
*��� ��
************************************/
void CGoodsAddWin::UpdateControls()
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
