/*QQ��ը��
��Ψ������Ƽ� 
web.857xx.cn
*/ 
#include "stdio.h"
#include "Windows.h"//Api�ӿ� 
int main()
{
	begin:
	//Windows���->��Ϣ���� SendMessage
	//��һ�� ��ը����Ϣ����
	int a,Message_Num;
	char RongQi[50];
	printf("\n");
	printf("���ߣ�Gery_Bell\n");
	printf("������web.857xx.cn\n");
	printf("��������������Ƿ���;��\n");
	printf("��ʾ��������ֻ������QQ�������촰��\n");
	printf("˵�����ȸ���Ҫ���͵���Ϣ�����иó���\n");
	printf("���� 1 ͬ�������֮��ͬ�⣺");
	scanf("%d",&a);
	if(a==1){
		printf("\n�������ը������");
		scanf("%d",&Message_Num);
		printf("�������ը�Ķ���");
		scanf("%s",&RongQi);
		//�ڶ��� ��ը1��Ŀ��/����-> ĳ��
		FindWindow(NULL,RongQi);//���������Ӵ��ڣ�ָ�� 
		//���߲� ʵ�ֵ����������Ĳ�ִ�� Message_Num �� 
		if(!FindWindow(NULL,RongQi)){
			printf("\n���ڡ�%s�������ڣ�\n",RongQi); 
			system("pause");
			goto begin;
		}else{
			while(Message_Num>0){
				//������ ճ����Ϣ->��Ϣ���� ����� 
				SendMessage(FindWindow(NULL,RongQi),WM_PASTE,NULL,NULL);
			    //���Ĳ� ������Ϣ ����� 
	    		SendMessage(FindWindow(NULL,RongQi),WM_KEYDOWN,VK_RETURN,NULL);
				Message_Num--;//�Լ�
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