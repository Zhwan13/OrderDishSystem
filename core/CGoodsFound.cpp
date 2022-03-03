#include"CGoodsFound.h"

CGoodsFound::CGoodsFound(int x,int y,int height,int width,void *data,int type)
:CControlBase(x,y,height,width,"",type)
{

    this->newGoods=NULL;
}

CGoodsFound::~CGoodsFound()
{

}

void CGoodsFound::setnewGoods(map<int,CGoods> *data)
{
    /***指挥传进一个key_value键值对
    if(this->newGoods!=NULL)
    {
        this->newGoods->erase(newGoods->begin());
    }
    ***/
    this->newGoods=data;

}


void CGoodsFound::show()
{
    int i=0,j=0;


    CTool::gotoxy(this->x,this->y);
    for(i=0;i<(this->height);i++)
	{
		if(i==0)
		{
			printf("┌");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┐");
			CTool::gotoxy(this->x,this->y+1);
			continue;
		}
		if(i==(this->height)-1)
		{
			printf("└");
			for(j=0;j<this->width/2;j++)
			{
				printf("─");
			}
			printf("┘");
			continue;
		}
		if(i>0&&i<(this->height)-1)
		{
			printf("│");
			for(j=0;j<this->width;j++)
			{
				printf(" ");
			}
			printf("│");
			CTool::gotoxy(this->x,this->y+i);
			continue;
		}
	}
	    if(this->newGoods!=NULL)//传进有数据就
	{
	    this->showdata(this->newGoods);
	}

}

void CGoodsFound::showdata(map<int,CGoods> *data)//显示查询到的数据
{
    map<int,CGoods>::iterator it=data->begin();
    CTool::gotoxy(this->x+12,this->y+1);
    cout<<it->second.getName();
    CTool::gotoxy(this->x+12,this->y+3);
    cout<<it->second.getType();
    CTool::gotoxy(this->x+12,this->y+5);
    cout<<it->second.getPrice();
    if(this->type==INFORMATION)
    {
        CTool::gotoxy(this->x+12,this->y+7);
        cout<<it->second.getCount();
        CTool::gotoxy(this->x+12,this->y+9);
        cout<<it->second.getLocation();
    }
    else
    {
        CTool::gotoxy(this->x+12,this->y+7);
        cout<<it->second.getLocation();
    }


}

/******************************
*函数名 keyhandle()
*函数功能：对键盘输入的键值进行判断是否要做出响应：控件跳转
*输入 键盘输入的键值 char ch
*输出 响应值
************************************/

int CGoodsFound::keyhandle(char ch)
{
    if(ch=='\t')
    {
        return CHANGEFOCUS;
    }
}
