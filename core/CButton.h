#ifndef CBUTTON_H_
#define CBUTTON_H_
#include<string.h>
#include"CTool.h"
#include "CControlBase.h"


class CButton:public CControlBase
{
public:
    CButton(int x,int y,int height,int width,char text[TEXTNUM],int type=BUTTON);
    void show();
	int keyhandle(char ch);
};
#endif // CBUTTON_H_INCLUDED
