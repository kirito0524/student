﻿#pragma once
#include<string>
#include<string.h>
#include<iostream>
#include"error.h"
using namespace std;


typedef struct{
	//学术硕士论文
	string name;	//论文名字
	int level;		//论文等级(1,2,3)
}paper;


class Graduate {
	//研究生基类
public:
	string getNum()const { return num; }//获取学号
	string getName()const { return name; }//获取姓名

protected:
	string num;		//学号
	string name;	//姓名
	char sex;		//性别
	int age;		//年龄
	double score;		//课程成绩
};


class Graduate_a:public Graduate
{
public:
	Graduate_a *pnext;
	static Graduate_a *aHead;
	static Graduate_a *del_aHead;
	Graduate_a() {
		pnext = NULL;
	}

	~Graduate_a() {
	}

	void saveAcademicStudentData();

	double calculatePaperScore() {
		//计算论文分数
		double s = 0;
		for (int i = 0; i < pnum; ++i) {
			s += (p[i].level * 10.0 / 90) * 100;
		}
		pscore = s;
		return s;
	}
	
	double calculateSumScore() {
		//计算总成绩
		tscore = score * 0.7 + pscore * 0.3;
		return tscore;
	}

	//重载函数
	friend ostream& operator<<(ostream& output, Graduate_a& a) {
		output << "学号:" << a.num << "\t姓名:" << a.name << "\t性别:" << a.sex << endl;
		for (int i = 0; i < a.pnum; ++i) {
			output << "论文" << (i + 1) << "名称:" << a.p[i].name << "\t该论文级别:" << a.p[i].level << endl;
		}
		output << "论文成绩:" << a.pscore <<"\t课程成绩"<<a.score<< "\t总成绩:" << a.tscore << endl;
		return output;
	}

	friend istream& operator>>(istream& input, Graduate_a& astu) {

		cout << "学号:";
		input >> astu.num;
		if (astu.num == "0")
		{
			return input;
		}
		cout << "姓名:";
		input >> astu.name;
		
		cout << "性别(男输入m,女输入f):";
		input >> astu.sex;
		while (!(astu.sex == 'm' || astu.sex == 'f')) {
			cerr << "性别输入错误，请重新输入:";
			input >> astu.sex;
		}

		cout << "年龄:";
		Inputdata(astu.age, input);
		while (astu.age<=0) {
			cout << "年龄输入错误，请重新输入" << endl;
			Inputdata(astu.age, input);
		}

		cout << "课程成绩:";
		Inputdata(astu.score, input);

		while (!(astu.score >= 0 && astu.score<=100))
		{
			cerr << "课程成绩输入有误，请重新输入!" << endl;
			Inputdata(astu.score, input);
		}

		cout << "专业:";
		input >> astu.major;

		cout << "发表论文篇数:";
		Inputdata(astu.pnum, input);

		while (!(astu.pnum <= 3 && astu.pnum > 0))
		{
			cerr << "输入有误，论文篇数范围1 - 3" << endl;
			Inputdata(astu.pnum, input);
		}

		for (int i = 0; i < astu.pnum; ++i) {

			cout << "论文"<<(i+1)<<":" << endl << "论文名称:";
			input >> astu.p[i].name;

			cout << "论文级别(1,2,3):";
			Inputdata(astu.p[i].level, input);
			while (astu.p[i].level < 1 || astu.p[i].level>3) {
				cerr << "论文级别输入错误，请重新输入:";
				Inputdata(astu.p[i].level,input);
			}

		}
		astu.calculatePaperScore();
		astu.calculateSumScore();
		return input;

	}
	//统计函数
	static void Bsort(int i);
	static void statisticalData();
	static double sumAcademicScore; // 学术硕士全体总成绩
	static int countAcademicNumber;//学术硕士总人数
	static double averageAcademicScore;//学术硕士平均成绩
	static int a[6];//学术硕士总分分段人数
private:
	string major;	//专业
	paper p[3];		//论文
	double tscore;	//总成绩
	int pnum;		//论文篇数
	double pscore;	//论文成绩
};


class Graduate_e :public Graduate
{
	//工程硕士
public:
	Graduate_e *pnext;
	static Graduate_e *eHead;

	double getTscore() { return tscore; }
	static Graduate_e *del_eHead;
	Graduate_e() {
		pnext = NULL;
	}

	~Graduate_e() {
	}

	void saveEngineerStudentData();

	double calculateEngineerScore() {
		//计算项目分数
		switch (p.second) {
		case 'A':
			pscore = 90; break;
		case 'B':
			pscore = 75; break;
		case 'C':
			pscore = 60; break;
		default:
			pscore = 0; break;
		}

		return pscore;
	}

	double calculateSumScore() {
		//计算总成绩
		tscore = (score + pscore)*0.5;
		return tscore;
	}

	//重载函数
	friend ostream& operator<<(ostream& output, Graduate_e& a) {
		output << "学号:" << a.num << "\t姓名:" << a.name << "\t性别:" << a.sex << endl;
		output << "项目名称:" << a.p.first << "\t项目级别" << a.p.second << endl;
		output << "项目成绩:" << a.pscore <<"\t课程成绩:"<<a.score<< "\t总成绩:" << a.tscore << endl;
		return output;
	}

	friend istream& operator>>(istream& input, Graduate_e& a) {
		cout << "学号:";
		input >> a.num;
		if (a.num == "0") {
			return input;
		}

		cout << "姓名:";
		input >> a.name;

		cout << "性别(男输入m,女输入f):";
		input >> a.sex;

		while (!(a.sex == 'm' || a.sex == 'f')) {
			cerr << "性别输入错误，请重新输入";
			input >> a.sex;
		}

		cout << "年龄:";
		Inputdata(a.age, input);
		while (a.age <= 0) {
			cerr << "年龄输入错误，请重新输入" << endl;
			Inputdata(a.age, input);
		}

		cout << "课程成绩:";
		Inputdata(a.score, input);
		while (a.score < 0 || a.score>100) {
			cerr << "成绩输入错误，请重新输入" << endl;
			Inputdata(a.score, input);
		}

		cout << "领域:";
		input >> a.area;


		cout << "项目名称:";
		input >> a.p.first;

		cout << "项目级别(A,B,C):";
		input >> a.p.second;
		while (!(a.p.second == 'A' || a.p.second == 'B' || a.p.second == 'C')) {
			cerr << "项目级别输入错误，请重新输入:";
			input >> a.p.second;
		}

		a.calculateEngineerScore();
		a.calculateSumScore();

		return input;
	}
	//统计函数
	static void Bsort(int i);
	static void statisticalData();
	static double sumEngineeringScore;//工程硕士全体总成绩
	static int countEngineeringNumber;//工程硕士总人数
	static double averageEngineeringScore;//工程硕士平均成绩
	static int e[6];//学术硕士总分分段人数
private:
	string area;	//领域
	pair<string,char> p;	//项目
	double tscore;	//总成绩
	double pscore;	//项目成绩
};



