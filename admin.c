#include "./admin.h"
#include "./test.h" //程序调试函数库
int adminFunc(lotNode *pHead)
{
    system("clear");
    adminUI();
    char ch = myGetc();
    //每次执行操作对文件重加载，保证操作的是最新数据
    pHead = lotInfoReadFromFile();
    userNode *phUser = userInfoReadFromFile();
    buyNode *phBuy = buyInfoReadFromFile();
    switch(ch){
        case '1':
        {   //防止不正常退出造成文件丢失
            if(addLottery(pHead) && lotInfoWriteToFile(pHead))
                printf("信息添加成功\n");
            else
                printf("添加失败,请重新操作\n");
            break;
        }
        case '2':
        {
            if(deleteLot(pHead) && lotInfoWriteToFile(pHead))
                printf("删除彩票成功\n");
            else
                printf("删除失败，请重新操作\n");
            anyKey();
        }
        case '3':
        {
            if(searchID(pHead))
               ;
            else
                printf("未查找到此相关信息\n");
            break;
        }
        case '4':
        {
            if(sortID(pHead))
                printf("排序成功!");
            else
                printf("排序失败，请重新操作!");
            break;
        }
        case '5':
        {   //每个ID都会被选中，顺序为随机的，未中奖则设置中奖金额为零
            showWinLotInfo(pHead);
            lotInfoWriteToFile(pHead);
            break;
        }
        case '0':
        {
            return 0;
        }
    }
    anyKey();
    return 1;
}


int main(void)
{
    initUI();
    anyKey();
    lotNode *pHead = lotInfoReadFromFile();
    while(adminFunc(pHead))
        ;
    return 0;
}
