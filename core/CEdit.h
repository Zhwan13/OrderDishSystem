#ifndef CEDIT_H_
#define CEDIT_H_
#include<string.h>
#include"CTool.h"
#include "CControlBase.h"

class CEdit:public CControlBase
{
public:
    CEdit(int x,int y,int height,int width,char text[TEXTNUM],int type);
    void show();
//	int getX();
//	int getY();

	int keyhandle(char ch);

};


#endif // CEDIT_H_INCLUDED
