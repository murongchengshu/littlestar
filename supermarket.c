/*                         超市商品管理系统
数据包括：商品名称、商品编号、商品类别、进价、售价、库存数量、供应商等。
功能包括：添加商品信息、查询商品详情、修改商品数据、删除商品记录、商品进货、商品销售、库存盘点、成本利润计算

添加商品信息功能：用于新商品的录入，确保系统数据库中的商品数据完整。

查询商品详情功能：方便快速了解某种商品的具体情况，为管理和销售提供支持。

修改商品数据功能：可根据实际情况对商品的相关信息进行更新。

删除商品记录功能：对于不再销售或过期的商品进行清理，保持数据的有效性和准确性。

商品进货功能：记录进货情况，及时补充库存。

商品销售功能：处理销售操作，与库存数量和利润计算相关联。

成本利润计算功能：帮助管理者了解商品的经营效益。*/
#include<stdio.h>
#include<stdlib.h>     //超市管理系统退出exit
#include<string.h>     //查找商品编号
//商品结构体定义
typedef struct goods
{
	char name[50];  	     //商品名称
	char id[20];   		     //商品编号
	char category[30];       //商品类别
	float inPrice;       	 //商品进价
	float outPrice;    	     //出售价格
	int  Leftnumbers; 	     //库存数量
	char offercompany[50];   //供货商
}goods;
goods Goodsum[100];     //定义货架可以存放100件物品
int goodscount=0;       //定义现在商品为0
double AllMoney=0;
//1.添加商品功能
void addgoods()
{
	system("cls");
	goods newgoods;
	printf("请输入商品名称:\n");
	scanf("%s",&newgoods.name);
	printf("请输入商品编号:\n");
	scanf("%s",&newgoods.id);
	printf("请输入商品类别：\n");
	scanf("%s",&newgoods.category);
	printf("请输入商品进价(元)：\n");
	scanf("%f",&newgoods.inPrice);
	printf("请输入商品出售价格（元）\n");
	scanf("%f",&newgoods.outPrice);
	printf("请输入商品的的库存数量:\n");
	scanf("%d",&newgoods.Leftnumbers);
	printf("请输入商品的供货商：\n");
	scanf("%s",&newgoods.offercompany);
	Goodsum[goodscount++]=newgoods;  //将新商品导入到商品列表里
	printf("商品添加成功！\n");
}
//2.查询商品
void searchgoods()
{
	system("cls");
	char SearchId[20];
	printf("请输入商品编号：\n");
	scanf("%s",SearchId);
	for(int i=0;i<=goodscount;i++)
	{
		if(strcmp(Goodsum[i].id,SearchId)==0)
		{
			printf("商品名称：%s\n",Goodsum[i].name);
			printf("商品编号：%s\n",Goodsum[i].id);
			printf("商品类别：%s\n",Goodsum[i].category);
			printf("商品进价（元）：%f\n",Goodsum[i].inPrice);
			printf("商品出售价格（元）：%lf\n",Goodsum[i].outPrice);
			printf("商品的库存数量：%d\n",Goodsum[i].Leftnumbers);
			printf("商品的供货商：%s\n",Goodsum[i].offercompany);
		}
	}
	return;
}
//3.修改商品数据
void modifygoods()
{
	system("cls");
	char ModifyId[20];
	printf("请输入要修改的商品编号: ");
	scanf("%s", ModifyId);
	for (int i = 0; i < goodscount; i++) 
	{
		if (strcmp(Goodsum[i].id, ModifyId) == 0) 
		{
			printf("请输入新的商品名称: ");
			scanf("%s", &Goodsum[i].name);
			printf("请输入新的商品类别: ");
			scanf("%s", &Goodsum[i].category);
			printf("请输入新的进价（元）: ");
			scanf("%f", &Goodsum[i].inPrice);
			printf("请输入新的售价（元）: ");
			scanf("%f", &Goodsum[i].outPrice);
			printf("请输入新的库存数量: ");
			scanf("%d", &Goodsum[i].Leftnumbers);
			printf("请输入新的供应商: ");
			scanf("%s", Goodsum[i].offercompany);
			printf("商品信息修改成功!\n");
			return;
		}
	}
	printf("未找到对应商品编号的商品，无法修改!\n");
}
//4.删除商品记录
void deletegoods()
{
	system("cls");
	char DeleteId[20];
	printf("请输入要删除的商品编号: \n");
	scanf("%s", DeleteId);
	for (int i = 0; i < goodscount; i++) {
		if (strcmp(Goodsum[i].id, DeleteId) == 0) 
		{
			for (int j = i; j < goodscount - 1; j++)
			{
				Goodsum[j] = Goodsum[j + 1];
			}
			goodscount--;
			printf("商品记录删除成功!\n");
			return;
		}
	}
	printf("未找到对应商品编号的商品，无法删除!\n");
}
//5.商品进货
void InputGoods()
{
	system("cls");
	char InputId[20];
	int InputNumbers;
	printf("请输入要进货的商品编号: \n");
	scanf("%s", InputId);
	printf("请输入进货的商品数量：\n");
	scanf("%d",&InputNumbers);
	for (int i = 0; i < goodscount; i++)
	{
		if (strcmp(Goodsum[i].id, InputId) == 0) 
		{
			Goodsum[i].Leftnumbers+=InputNumbers;
			AllMoney-=Goodsum[i].inPrice*InputNumbers;
			return;
		}
	}
	printf("未找到对应商品编号的商品，请核对进货商品的Id!\n");
}
//6.商品销售
void SellGoods()
{
	system("cls");
	char SellId[20];
	int SellNumbers;
	printf("请输入要进货的商品编号: \n");
	scanf("%s", SellId);
	printf("请输入进货的商品数量：\n");
	scanf("%d",&SellNumbers);
	for (int i = 0; i < goodscount; i++)
	{
		if (strcmp(Goodsum[i].id, SellId) == 0) 
		{
			Goodsum[i].Leftnumbers-=SellNumbers;
			AllMoney+=Goodsum[i].outPrice*SellNumbers;
			return;
		}
	}
	printf("未找到对应商品编号的商品，请核对出售商品的Id!\n");
}
// 7.库存盘点
void inventoryGoods() 
{
	system("cls");
	printf("库存盘点情况如下:\n");
	for (int i = 0; i < goodscount; i++)
	{
		printf("商品名称: %s, 库存数量: %d\n", Goodsum[i].name, Goodsum[i].Leftnumbers);
	}
}
// 8.查询总资产
void AskMoney()
{
	system("cls");
	system("cls");
	printf("您所拥有的总资产为:%f元\n",AllMoney);
	return;
}
//主函数
int main() 
{
	int choice;
	while (1) {
		printf("超市商品管理系统\n");
		printf("1. 添加商品信息\n");
		printf("2. 查询商品详情\n");
		printf("3. 修改商品数据\n");
		printf("4. 删除商品记录\n");
		printf("5. 商品进货\n");
		printf("6.商品出售\n");
		printf("7.库存盘点\n");
		printf("8。查询总资产\n");
		printf("9. 退出\n");
		printf("请输入你的选择: ");
		scanf("%d", &choice);
		
		switch (choice)
		{
		case 1:
			addgoods();
			system("pause");
			system("cls");
			break;
		case 2:
			searchgoods();
			system("pause");
			system("cls");
			break;
		case 3:
			modifygoods();
			system("pause");
			system("cls");
			break;
		case 4:
			deletegoods();
			system("pause");
			system("cls");
			break;
		case 5:
			InputGoods();
			system("pause");
			system("cls");
			break;
		case 6:
			SellGoods();
			system("pause");
			system("cls");
			break;
		case 7:
			inventoryGoods();
			system("pause");
			system("cls");
			break;
		case 8:
			AskMoney();
			system("pause");
			system("cls");
			break;
		case 9:
			printf("感谢使用，程序退出!\n");
			exit(0);
		default:
			printf("无效的选择，请重新输入!\n");
		}
	}
	return 0;
}

