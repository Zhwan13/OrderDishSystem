#ifndef _CCHECKRECORD_H_
#define _CCHECKRECORD_H_

class CCheckRecord
{
public:
    CCheckRecord();
    ~CCheckRecord();


private:
    CLabel *GoodsNoLab;//��Ʒ���
    CLabel *GoodsNameLab;//��Ʒ����
    CLabel *StockCountLab;//�������
    CLabel *CheckCountLab;//�̵�����
    CLabel *DifferCount;//��������
};

#endif // _CCHECKRECORD_H_

