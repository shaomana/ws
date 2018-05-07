#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef int BOOL;
typedef struct bookinfo
{
    char number[15];/*��Ʒ���*/
    char name[30];/*��Ʒ����*/
    float price;/*����*/
    char auther[20];/*����*/
    BOOL isExit;/*����״̬*/
    char lendername[20];/*����������*/
    char lendersex[2];/*�������Ա�*/
    char lendernum[15];/*������ѧ��*/
}BOOKINFO;
void menu()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\tͼ�����ϵͳ\n");
    printf("\t\t\t1:�½�ͼ�������Ϣ������\n");
    printf("\t\t\t2:��ʾȫ����¼\n");
    printf("\t\t\t3:����ͼ�����Ʋ�ѯͼ�������Ϣ\n");
    printf("\t\t\t4:����ͼ�����ƶԳ�����ͼ����Ϣ����ɾ��\n");
    printf("\t\t\t5:����ͼ�����ƴ�С������\n");
    printf("\t\t\t6:ͳ��ĳ�۸����ϵ�ͼ������\n");
    printf("\t\t\t7:�г�����δ���ȥ��ͼ����Ϣ\n");
    printf("\t\t\t8:�˳�\n");
    }
void choice_1_input_new()/*�����½���ͼ����Ϣ*/
{
    char choice;
    FILE *p;
    BOOKINFO newbook;
    system("cls");
    while(1)
      {
      printf("����ͼ����:");
      gets(newbook.number);
          
      printf("����ͼ������:");
      gets(newbook.name);    
      
      printf("����ͼ�鵥��:");
      scanf("%f",&newbook.price);
      while(getchar()!='\n');
          
      printf("����ͼ�������:");
      gets(newbook.auther);    
      
      printf("�������������:");
      gets(newbook.lendername);    
      
      printf("����������Ա�:");
      gets(newbook.lendersex);    
      
      printf("���������ѧ��:");
      gets(newbook.lendernum);
      
      printf("�Ƿ񱣴������Ŀ?(Y/N)\n");
      choice=getchar();
      while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
        choice=getchar();
      if(choice=='Y'||choice=='y') 
        {
        newbook.isExit=1;/*��ͼ��״̬���ó�1����ʾû�н��*/
        
        p=fopen("c:\\bookinfo.data","ab");
        fwrite(&newbook,sizeof(BOOKINFO),1,p);
        fclose(p);    
        
        printf("\n������Ŀ����ӵ�c:\\bookinfo.data�ļ���!\n");
        }     
      else  
        {
        printf("\n������Ŀδ����!\n");    
        }
      printf("\n�Ƿ���������Ŀ?(Y/N)\n");
      choice=getchar();
      while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
        choice=getchar();
      if(choice=='Y'||choice=='y')
        continue;
      else 
        break;      
      }
    }
void choice_2_display_all()/*��ʾȫ��ͼ����Ϣ*/
{
    FILE *p;
    int n;
    BOOKINFO bookinfo[100];
    int booknumber=0;
    system("cls");
    p=fopen("c:\\bookinfo.data","rb");
    while(!feof(p))
      {
      fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
      booknumber++;    
      }
    /*booknumber--;ʹ��feof()��������һ�У������Ҫbooknumber�Լ�һ�Σ�ʹ��Ŀ��������ȷ*/
    fclose(p);  
    booknumber--;
    if(booknumber==0)
      {
      printf("û���κ�ͼ����Ϣ!\n\n");
      }
    else
      {
      n=0;
      printf("                              ͼ����Ϣ����\n");
      printf("                   ͼ����Ϣ                |         ��������Ϣ   \n");
      printf("���  ����        ����    ����    ͼ��״̬ | ����        �Ա�    ѧ��\n");
      while(n<booknumber) 
        {
        printf("%-6s%-12s%-8.1f%-8s%-9d| %-12s%-8s%-8s\n",
                                        bookinfo[n].number,bookinfo[n].name,bookinfo[n].price,
                                        bookinfo[n].auther,bookinfo[n].isExit,bookinfo[n].lendername,
                                        bookinfo[n].lendersex,bookinfo[n].lendernum);
        n++;                                    
        }
      }  
    printf("\n\n��������ص����˵�!\n");
    getchar();      
}
void choice_3_search_according_name()/*����ͼ��������ʾͼ�����Ϣ*/
{
    char search[20]="";/*search�������Ҫ��ѯ������*/
    int n;
    FILE *p;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber=0;
    
    system("cls");
    p=fopen("c:\\bookinfo.data","rb");
    while(!feof(p))
      {
      fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
      booknumber++;    
      }
    booknumber--;/*ʹ��feof()��������һ�У������Ҫbooknumber�Լ�һ�Σ�ʹ��Ŀ��������ȷ*/
    fclose(p); 
    while(1)
    {
    printf("����Ҫ��ѯ���鱾����:");
    gets(search);
    if(booknumber==0)
      {
      printf("�����û���κ���Ϣ!\n\n");
      printf("��������ص����˵�!\n\n");
      getchar();
      break;    
      }/*if����*/
    else
      {
      for(n=0;n<booknumber;n++)
        if(strcmp(bookinfo[n].name,search)==0)
          {
          printf("�������ϸ��Ϣ����:\n");
          printf("                   ͼ����Ϣ                |         ��������Ϣ   \n");
          printf("���  ����        ����    ����    ͼ��״̬ | ����        �Ա�    ѧ��\n");
          printf("%-6s%-12s%-8.1f%-8s%-9d| %-12s%-8s%-8s\n",
                                        bookinfo[n].number,bookinfo[n].name,bookinfo[n].price,
                                        bookinfo[n].auther,bookinfo[n].isExit,bookinfo[n].lendername,
                                        bookinfo[n].lendersex,bookinfo[n].lendernum);
          break;                            
          }
      if(n>=booknumber)
        printf("û�в��Ҹ�����κ���Ϣ!\n");
      printf("\n\n�Ƿ������ѯ?(Y/N)\n");
      choice=getchar();
      while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
         choice=getchar();
      if(choice=='Y'||choice=='y')
        continue;
      else 
        break;              
        }/*else����*/
      }/*while(1)����*/  
    }
void choice_4_delete_according_name()/*����ͼ�����ƶ�ͼ����Ϣ����ɾ��*/
{
    char search[20]="";/*search�������Ҫɾ��������*/
    int n,i;
    FILE *p;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber;
    
    system("cls");
    while(1)
      {
      printf("����Ҫɾ�����鱾����:");
      gets(search);
      p=fopen("c:\\bookinfo.data","rb");
      booknumber=0;
      while(!feof(p))
        {
        fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
        booknumber++;    
        }
      booknumber--;/*ʹ��feof()��������һ�У������Ҫbooknumber�Լ�һ�Σ�ʹ��Ŀ��������ȷ*/
      fclose(p); 
      if(booknumber==0)
        {
        printf("�����û���κ���Ϣ!\n\n");
        printf("��������ص����˵�!\n\n");
        getchar();
        break;   
        }/*if����*/
      else
        {    
        for(n=0;n<booknumber;n++)
          if(strcmp(bookinfo[n].name,search)==0)
            {
            break;
            }
        if(n>=booknumber)
           printf("û�в��Ҹ�����κ���Ϣ!\n");
        else
           {
           printf("�Ƿ�ȷ����Ҫɾ��������Ŀ?(Y/N)");
           choice=getchar();
             while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
             choice=getchar();
           if(choice=='Y'||choice=='y')      
             {
             for(i=n;i<booknumber-1;i++)
               bookinfo[i]=bookinfo[i+1];    
             booknumber--;
           
             p=fopen("c:\\bookinfo.data","wb");
             for(n=0;n<booknumber;n++)
               fwrite(&bookinfo[n],sizeof(BOOKINFO),1,p);
             fclose(p);
           
             printf("ɾ���ɹ�!\n");
             }
           else
              printf("\n\n������Ŀû�б�ɾ��!"); 
           }    
         printf("\n\n�Ƿ��������ɾ������?(Y/N)\n");
         choice=getchar();
         while(choice!='Y'&&choice!='y'&&choice!='N'&&choice!='n')
           choice=getchar();
         if(choice=='Y'||choice=='y')
           continue;
         else 
           break;              
        }/*else����*/
      }/*while(1)����*/
    }
void choice_5_sort_according_name()/*����ͼ����������*/
{
    FILE *p;
    int m,n;
    BOOKINFO temp;
    BOOKINFO bookinfo[100];
    int booknumber;
    
    p=fopen("c:\\bookinfo.data","rb");
    booknumber=0;
    system("cls");
    while(!feof(p))
      {
      fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
      booknumber++;    
      }
    booknumber--;/*ʹ��feof()��������һ�У������Ҫbooknumber�Լ�һ�Σ�ʹ��Ŀ��������ȷ*/
    fclose(p);  
    if(booknumber==0)
      {
      printf("û���κ�ͼ����Ϣ!\n\n");
      }
    else
      {
      for(m=0;m<booknumber-1;m++)
        for(n=m+1;n<booknumber;n++)
          if(strcmp(bookinfo[m].name,bookinfo[n].name)>0)
            {
            temp=bookinfo[m];
            bookinfo[m]=bookinfo[n];
            bookinfo[n]=temp;    
            }
      p=fopen("c:\\bookinfo.data","wb");
      for(m=0;m<booknumber;m++)
        fwrite(&bookinfo[m],sizeof(BOOKINFO),1,p);
      fclose(p);        
      printf("\n\n�������!\n\n");      
      }
    printf("��������ص����˵�!\n");
    getchar();  
}
void choice_6_display_high_price()/*���ݼ۸��г�ͼ����Ϣ*/
{
    float price;
    FILE *p;
    int n;
    int count=0;
    BOOKINFO bookinfo[100];
    int booknumber;
    
    system("cls");
    printf("������۸�:");
    scanf("%f",&price);
    p=fopen("c:\\bookinfo.data","rb");
    booknumber=0;
    while(!feof(p))
      {
      fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
      booknumber++;    
      }
    booknumber--;/*ʹ��feof()��������һ�У������Ҫbooknumber�Լ�һ�Σ�ʹ��Ŀ��������ȷ*/
    fclose(p);  
    if(booknumber==0)
      {
      printf("û���κ�ͼ����Ϣ!\n\n");
      }
    else
      {
      for(n=0;n<booknumber;n++) 
        {
        if(bookinfo[n].price>=price)
          count++;
        }
      if(count==0) 
        printf("�����û�б�%.1f$�۸�ߵ�ͼ��!",price); 
      else
        {
        printf("                          �۸����%.1f$��ͼ����Ϣ����\n",price);
        printf("                   ͼ����Ϣ                |         ��������Ϣ   \n");
        printf("���  ����        ����    ����    ͼ��״̬ | ����        �Ա�    ѧ��\n");
        for(n=0;n<booknumber;n++) 
          {
          if(bookinfo[n].price>=price)
            printf("%-6s%-12s%-8.1f%-8s%-9d| %-12s%-8s%-8s\n",
                                        bookinfo[n].number,bookinfo[n].name,bookinfo[n].price,
                                        bookinfo[n].auther,bookinfo[n].isExit,bookinfo[n].lendername,
                                        bookinfo[n].lendersex,bookinfo[n].lendernum);                                    
          }
        }
      }  
    printf("\n\n��������ص����˵�!\n");
    getchar();  
    }
void choice_7_display_according_exitflag()/*���ݴ���״̬�г�ͼ����Ϣ*/
{
    FILE *p;
    int n;
    int count=0;
    BOOKINFO bookinfo[100];
    int booknumber;
    
    system("cls");
    booknumber=0;
    p=fopen("c:\\bookinfo.data","rb");
    while(!feof(p))
      {
      fread(&bookinfo[booknumber],sizeof(BOOKINFO),1,p);
      booknumber++;    
      }
    booknumber--;  
    fclose(p);
    if(booknumber==0)
      {
      printf("�����û���κ���Ŀ����!\n");
      }    
    else
      {
      for(n=0;n<booknumber;n++)
        if(bookinfo[n].isExit==1)
          count++;
      if(count==0)
        printf("����е��鼮ȫ�����!\n");        
      else
        {
        printf("�����δ�������ͼ����Ϣ����:\n\n");
        printf("                   ͼ����Ϣ                |         ��������Ϣ   \n");
        printf("���  ����        ����    ����    ͼ��״̬ | ����        �Ա�    ѧ��\n");
        for(n=0;n<booknumber;n++)
          if(bookinfo[n].isExit==1)
            {
            printf("%-6s%-12s%-8.1f%-8s%-9d| %-12s%-8s%-8s\n",
                                        bookinfo[n].number,bookinfo[n].name,bookinfo[n].price,
                                        bookinfo[n].auther,bookinfo[n].isExit,bookinfo[n].lendername,
                                        bookinfo[n].lendersex,bookinfo[n].lendernum);    
            }    
        }   
      }  
    printf("\n��������������˵�!\n");
    getchar();  
}
void main()
{
    char choice;
    clock_t tm;
    FILE *p;
    if((p=fopen("c:\\bookinfo.data","rb"))==NULL)
      {
      p=fopen("c:\\bookinfo.data","wb");   
      fclose(p);
      }
    while(1)
      {
      system("cls");
      menu();
      choice=getchar();
      switch(choice)
        {
        case '1':choice_1_input_new();break;/*�����½���ͼ����Ϣ*/
        case '2':choice_2_display_all();break;/*��ʾȫ��ͼ����Ϣ*/
        case '3':choice_3_search_according_name();break;/*����ͼ��������ʾͼ�����Ϣ*/
        case '4':choice_4_delete_according_name();break;/*����ͼ�����ƶ�ͼ����Ϣ����ɾ��*/
        case '5':choice_5_sort_according_name();break;/*����ͼ����������*/
        case '6':choice_6_display_high_price();break;/*���ݼ۸��г�ͼ����Ϣ*/
        case '7':choice_7_display_according_exitflag();break;/*���ݴ���״̬�г�ͼ����Ϣ*/
        case '8':printf("\n\n\t\t\tллʹ��,�ټ�!\n\t\t\t��������˳�!\n");getchar();return;
        default:
                printf("\n\n\t\t\t������˵��е�����!(1~8)");    
                tm=clock();
                while(clock()<tm+1800);
                break;
        }    
      }
}