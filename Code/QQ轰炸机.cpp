/*QQ轰炸机
爱唯逸网络科技 
web.857xx.cn
*/ 
#include "stdio.h"
#include "Windows.h"//Api接口 
int main()
{
	begin:
	//Windows编程->消息机制 SendMessage
	//第一步 轰炸的消息次数
	int a,Message_Num;
	char RongQi[50];
	printf("\n");
	printf("作者：Gery_Bell\n");
	printf("官网：web.857xx.cn\n");
	printf("声明：请勿用与非法用途！\n");
	printf("提示：本程序只能用于QQ独立聊天窗口\n");
	printf("说明：先复制要发送的信息后运行该程序\n");
	printf("输入 1 同意条款，反之则不同意：");
	scanf("%d",&a);
	if(a==1){
		printf("\n请输入轰炸次数：");
		scanf("%d",&Message_Num);
		printf("请输入轰炸的对象：");
		scanf("%s",&RongQi);
		//第二步 轰炸1的目标/对象-> 某人
		FindWindow(NULL,RongQi);//从桌面链接窗口，指定 
		//第七步 实现第三步、第四步执行 Message_Num 次 
		if(!FindWindow(NULL,RongQi)){
			printf("\n窗口“%s”不存在！\n",RongQi); 
			system("pause");
			goto begin;
		}else{
			while(Message_Num>0){
				//第三步 粘贴消息->消息机制 虚拟键 
				SendMessage(FindWindow(NULL,RongQi),WM_PASTE,NULL,NULL);
			    //第四步 发送消息 虚拟键 
	    		SendMessage(FindWindow(NULL,RongQi),WM_KEYDOWN,VK_RETURN,NULL);
				Message_Num--;//自减
				if(Message_Num==0){
					printf("\n");
					system("pause");
					goto begin;
				}
			}
			return 0;
		}
	}else{
		printf("");
	}
}