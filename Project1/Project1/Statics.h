#include<iostream>
#include<cmath>
#include <stdlib.h>
#include<string>
#include"Student.h"

using namespace std;

//统计函数
void Graduate_a::statisticalData(){
	if (aHead->pnext == NULL)
	{
		cerr << "错误0x456121" << endl;
		cerr << "请联系管理员解决（链表中无数据）" << endl;
		system("pause");
		exit(0);
	}
	Graduate_a *p = aHead->pnext;
	while (p != NULL)
	{
		countAcademicNumber++;
		sumAcademicScore = (double)(sumAcademicScore + p->tscore);
		if (fabs((float)(p->tscore - 100.0)) < 0.00001)//注意说明
		{
			a[0]++;
		}
		else if (p->tscore >= 90.0000 && p->tscore <= 99.0000)
		{
			a[1]++;
		}
		else if (p->tscore >= 80.0000 && p->tscore <= 89.0000)
		{
			a[2]++;
		}
		else if (p->tscore >= 70.0000 && p->tscore <= 79.0000)
		{
			a[3]++;
		}
		else if (p->tscore >= 60.0000 && p->tscore <= 69.0000)
		{
			a[4]++;
		}
		else if (p->tscore < 60.0000)
		{
			a[5]++;
		}
		p = p->pnext;
	}
	averageAcademicScore = (double)((sumAcademicScore)*1.0 / countAcademicNumber);
	//统计完毕,开始输出相关信息
	cout << "学术硕士总人数为：" << countAcademicNumber << endl;
	cout << "其中他们的平均分为：" << averageAcademicScore << endl;
	cout << "成绩分布为：" << endl;
	cout << "100分人数为：" << a[0] << "\t占总人数百分比为：" << 100 * (double)(a[0] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "90~99分人数为：" << a[1] << "\t占总人数百分比为：" << 100 * (double)(a[1] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "80~89分人数为：" << a[2] << "\t占总人数百分比为：" << 100 * (double)(a[2] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "70~79分人数为：" << a[3] << "\t占总人数百分比为：" << 100 * (double)(a[3] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "60~69分人数为：" << a[4] << "\t占总人数百分比为：" << 100 * (double)(a[4] * 1.0 / countAcademicNumber) << "%" << endl;
	cout << "不及格人数为：" << a[5] << "\t占总人数百分比为：" << 100 * (double)(a[5] * 1.0 / countAcademicNumber) << "%" << endl;
	return;
}

void Graduate_e::statisticalData() {
	if (eHead->pnext == NULL)
	{
		cerr << "错误0x456121" << endl;
		cerr << "请联系管理员解决（链表中无数据）" << endl;
		system("pause");
		exit(0);
	}
	Graduate_e *p = eHead->pnext;
	while (p != NULL)
	{
		countEngineeringNumber++;
		sumEngineeringScore = (double)(sumEngineeringScore + p->tscore);
		if (fabs((float)(p->tscore - 100.0)) < 0.00001)//注意说明
		{
			e[0]++;
		}
		else if (p->tscore >= 90.0000 && p->tscore <= 99.9999)
		{
			e[1]++;
		}
		else if (p->tscore >= 80.0000 && p->tscore <= 89.9999)
		{
			e[2]++;
		}
		else if (p->tscore >= 70.0000 && p->tscore <= 79.9999)
		{
			e[3]++;
		}
		else if (p->tscore >= 60.0000 && p->tscore <= 69.9999)
		{
			e[4]++;
		}
		else if (p->tscore < 60.0000)
		{
			e[5]++;
		}
		p = p->pnext;
	}
	averageEngineeringScore = (double)((sumEngineeringScore)*1.0 / countEngineeringNumber);
	//统计完毕,开始输出相关信息
	cout << "工程硕士总人数为：" << countEngineeringNumber << endl;
	cout << "其中他们的平均分为：" << averageEngineeringScore << endl;
	cout << "成绩分布为：" << endl;
	cout << "100分人数为：" <<e[0] << "\t占总人数百分比为：" << 100 * (double)(e[0] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "90~99分人数为：" << e[1] << "\t占总人数百分比为：" << 100 * (double)(e[1] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "80~89分人数为：" << e[2] << "\t占总人数百分比为：" << 100 * (double)(e[2] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "70~79分人数为：" << e[3] << "\t占总人数百分比为：" << 100 * (double)(e[3] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "60~69分人数为：" << e[4] << "\t占总人数百分比为：" << 100 * (double)(e[4] * 1.0 / countEngineeringNumber) << "%" << endl;
	cout << "不及格人数为：" << e[5] << "\t占总人数百分比为：" << 100 * (double)(e[5] * 1.0 / countEngineeringNumber) << "%" << endl;
	return;
}

void Graduate_a::Bsort(int i) {
	int min=0;
	if (aHead->pnext == NULL){
		cerr << "错误0x456121" << endl;
		cerr << "请联系管理员解决（链表中无数据）" << endl;
		system("pause");
		exit(0);
	}
	
	//=============冒泡排序====================
	Graduate_a *head_1 = aHead;
	Graduate_a *pre, *cur, *next, *end, *temp;
	end = NULL;
	
	switch (i) {
	case 1:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//相邻的节点比较
				if (cur->tscore < next->tscore) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
		break;
	case 2:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//相邻的节点比较
				if (cur->getNum()>next->getNum()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	case 3:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//相邻的节点比较
				if (cur->getName()>next->getName()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	}
}



void Graduate_e::Bsort(int i) {
	int min = 0;
	if (eHead->pnext == NULL) {
		cerr << "错误0x456121" << endl;
		cerr << "请联系管理员解决（链表中无数据）" << endl;
		system("pause");
		exit(0);
	}

	//=============冒泡排序====================
	Graduate_e *head_1 = eHead;
	Graduate_e *pre, *cur, *next, *end, *temp;
	end = NULL;

	switch (i) {
	case 1:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//相邻的节点比较
				if (cur->getTscore() < next->getTscore()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
		break;
	case 2:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//相邻的节点比较
				if (cur->getNum() > next->getNum()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	case 3:
		while (head_1->pnext != end)
		{
			for (pre = head_1, cur = pre->pnext, next = cur->pnext; next != end; pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
				//相邻的节点比较
				if (cur->getName() > next->getName()) {
					cur->pnext = next->pnext;
					pre->pnext = next;
					next->pnext = cur;
					temp = next;
					next = cur;
					cur = temp;
				}
			}
			end = cur;
		}
	}
	
}
