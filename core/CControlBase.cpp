#include"CControlBase.h"
#include<iostream>

using namespace std;

CControlBase::CControlBase(int x,int y,int height,int width,char text[TEXTNUM],int type)
{
	this->x=x;
    this->y=y;
    this->height=height;
    this->width=width;
	memset(this->text,0,TEXTNUM);
    strcpy(this->text,text);
	this->type=type;
}

CControlBase::~CControlBase()
{
}

void CControlBase::show()
{
}

char *CControlBase::getText()
{
    return this->text;
}

int CControlBase::getX()
{
	return (this->x);
}

int CControlBase::getY()
{
	return (this->y);
}

int CControlBase::getType()
{
	return (this->type);
}

int CControlBase::getHeight()
{
	return (this->height);
}
