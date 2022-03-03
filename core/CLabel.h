#ifndef CLABEL_H_
#define CLABEL_H_
#include<string.h>
#include"CTool.h"
#include "CControlBase.h"

class CLabel:public CControlBase
{
public:
    CLabel(int x,int y,int height,int width,char text[TEXTNUM],int type=LABEL);
    void setLab(char *text);
    void show();
    int keyhandle(char ch);
//	void doAction(char ch);
};


#endif // CLABEL_H_INCLUDED
