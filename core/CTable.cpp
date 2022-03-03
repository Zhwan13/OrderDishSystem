#include"CTable.h"

CTable::CTable(int x,int y,int height,int width,void *data,int type)
:CControlBase(x,y,height,width,"",type)
{
    this->x=x;
    this->y=y;
    this->height=height;
    this->width=width;
    this->curPage=1;//当前页初始化为1
    this->pageNum=1;//页数初始化为1
    this->NumPerPage=3;//每页打印数据条数
    this->data=data;
}
void CTable::setData(void *data)
{
    this->data=data;
    return ;
}

void CTable::show()
{
    int i=0,j=0;
    CTool::gotoxy(this->x,this->y);
    for(i=0;i<=this->height;i++)
    {
        if(i%2==0||i==this->height)
        {
            CTool::gotoxy(this->x,this->y+i);
            for(j=this->x;j<this->x+this->width;j++)
            {
                if(j==this->x)
                    cout<<"|";//
                else if(j==this->x+this->width-1)
                    cout<<"|"<<endl;
                else
                    cout<<"-";
            }
        }
        else
        {
            CTool::gotoxy(this->x,this->y+i);
            cout<<"|";
            CTool::gotoxy(this->x+this->width-1,this->y+i);
            cout<<"|";
        }
    }
    if(this->getType()==GOODSTABLE)//商品查询显示商品信息
        this->show_tabledata(this->data);
    else if(this->getType()==RECORDTABLE)//记录查询显示查询记录
    {
        this->show_recordtabledata(this->data);
    }

    CTool::gotoxy(this->x+this->width/2-2,this->y+this->height+2);
    cout<<this->curPage<<"/"<<this->pageNum<<endl;

}

//16,12,8,70datedate
//flag用来判断是左翻页3还是右翻页4
void CTable::show_tabledata(void *data)//精确查找
{
    map<int,CGoods> *Goods=(map<int,CGoods> *)data;
	int i=0,Goodscount=0;
    int start;
    Goodscount=Goods->size();//商品个数
    if(Goodscount%this->NumPerPage==0)
        this->pageNum=Goodscount/this->NumPerPage;
    else
    {
        this->pageNum=Goodscount/this->NumPerPage+1;
    }
	if(Goodscount==0)
	{
        CTool::gotoxy(15,7);
		cout<<"无数据可显示";
		CTool::gotoxy(15,15);
		system("pause");
	}
    i=0;
    start=(curPage-1)*3;
    map<int,CGoods>::iterator it;
    it=Goods->begin();
    advance(it,start);//advance
    for(i=0;i<NumPerPage;i++)
    {
        if(it==Goods->end())
            break;
        CTool::gotoxy(this->x+1+12*0,this->y+3+2*i);
        cout<<it->second.getNo();
        CTool::gotoxy(this->x+1+12*1,this->y+3+2*i);
        cout<<it->second.getName();
        CTool::gotoxy(this->x+1+12*2,this->y+3+2*i);
        cout<<it->second.getType();
        CTool::gotoxy(this->x+1+12*3,this->y+3+2*i);
        cout<<it->second.getPrice();
        CTool::gotoxy(this->x+1+12*4,this->y+3+2*i);
        cout<<it->second.getCount();
        CTool::gotoxy(this->x+1+12*5,this->y+3+2*i);
        cout<<it->second.getLocation();
        it++;
    }
	return ;
}


void CTable::show_recordtabledata(void *data)//精确查找
{
    vector<CGoodsStockRecord>*InstockRecord=new vector<CGoodsStockRecord>;
    InstockRecord=(vector<CGoodsStockRecord> *)data;
	int i=0,Recordcount=0;
    int start;
    Recordcount=InstockRecord->size();//商品个数
    if(Recordcount%this->NumPerPage==0)
        this->pageNum=Recordcount/this->NumPerPage;
    else
    {
        this->pageNum=Recordcount/this->NumPerPage+1;
    }
	if(Recordcount==0)
	{
        CTool::gotoxy(15,7);
		cout<<"无数据可显示";
		CTool::gotoxy(15,15);
		system("pause");
	}
    i=0;
    start=(this->curPage-1)*3;
    vector<CGoodsStockRecord>::iterator it;
    it=InstockRecord->begin();
    advance(it,start);//advance
    for(i=0;i<NumPerPage;i++)
    {
        if(it==InstockRecord->end())
            break;
        CTool::gotoxy(this->x+1+12*0,this->y+3+2*i);
        cout<<it->getNo();
        CTool::gotoxy(this->x+1+12*1,this->y+3+2*i);
        cout<<it->getName();
        CTool::gotoxy(this->x+1+12*2,this->y+3+2*i);
        cout<<it->getDate();
        CTool::gotoxy(this->x+1+12*3,this->y+3+2*i);
        cout<<it->getCount();
        CTool::gotoxy(this->x+1+12*4,this->y+3+2*i);
        cout<<it->getLocation();
        it++;
    }
	return ;
}


/******************************
*函数名 keyhandle()
*函数功能：对键盘输入的键值进行判断是否要做出响应：光标跳转、翻页
*输入 键盘输入的键值 char ch
*输出 响应值
************************************/
int CTable::keyhandle(char ch)
{
    if(ch==KEY_RIGHT&&this->curPage!=this->pageNum)
    {
        this->curPage++;
        return CHANGEPAGE;//翻页
    }
    else if(ch==KEY_LEFT&&this->curPage!=1)
    {
        this->curPage--;
        return CHANGEPAGE;//翻页
    }
    else if(ch=='\t')
    {
        return CHANGEFOCUS;
    }
    return INSTOCKRECORDWIN;
}


