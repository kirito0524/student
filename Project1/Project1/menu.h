#pragma once

void menu()//�˵�����
{
	int i = 0;
loop:
	cout << "***************************************************" << endl;
	cout << "*" << "             ****�о�������ϵͳ****              " << "*" << endl;
	cout << "*" << "                1.�о�����Ϣ¼��*                " << "*" << endl;
	cout << "*" << "                2.�о�����Ϣ����                 " << "*" << endl;
	cout << "*" << "                3.�о�����Ϣɾ��                 " << "*" << endl;
	cout << "*" << "                4.�о�����Ϣ���                 " << "*" << endl;
	cout << "*" << "                5.�о�����Ϣ�޸�                 " << "*" << endl;
	cout << "*" << "                6.�о�����Ϣ����                 " << "*" << endl;
	cout << "*" << "                7.�о�����Ϣͳ��                 " << "*" << endl;
	cout << "*" << "                8.�˳�ϵͳ                       " << "*" << endl;
	cout << "*" << "                9.��ʼ����ϵͳ                   " << "*" << endl;
	cout << "****************************************************" << endl;

	cout << "��ѡ��:" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		addStudentData();//��Ϣ¼��
		cout << "¼��ɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 2:
		insertData();//��Ϣ����
		cout << "����ɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 3:
		delData();//��Ϣɾ��
		cout << "ɾ���ɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 4:
		printData();//��Ϣ���
		cout << "����ɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 5:
		modifyData();//��Ϣ�޸�
		cout << "�޸ĳɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 6:
		seekGraduateStudent();//��Ϣ����
		cout << "���ҳɹ���" << endl;
		system("pause");
		system("cls");
		break;
	case 7:
		statisticalStudentData();//��Ϣͳ��
		system("pause");
		system("cls");
		break;
	case 8:
		exitSystem();//ϵͳ�˳�����
		break;
	case 9:
		initSystem();//��ʼ��ϵͳ
		break;
	default:
		cout << "�����������������룡" << endl;
		goto loop;
	}
	goto loop;
	return;
}


void welcome()//��ӭ����
{
	cout << "************************************" << endl;
	cout << "*****         ��ӭʹ��         *****" << endl << endl;
	cout << "****     �о����ɼ�����ϵͳ     ****" << endl << endl;;
	cout << "*  ���ߣ���Ϣ��ѧ�빤��ѧԺ�ƿ�1705   *" << endl << endl;;
	cout << "****   ��Ʒ���ڣ�2018��1��14��  ****" << endl;
	cout << "************************************" << endl;
	//�������
	int i = 0;
	string user;
	string key;
loop:
	cout << "�������û�����" << endl;
	cin >> user;
	cout << "��������" << endl;
	cin >> key;
	if (!(user == "xin" && key == "xin"))
	{
		i++;
		if (i >= 3)
		{
			cout << "���ѳ������������ϵͳ���Զ��˳���" << endl;
			system("pause");
			exit(0);
		}
		cout << "�˻�������������������������" << endl;
		goto loop;
	}
	else
	{
		cout << "��ϲ��������ȷ��" << endl;
		system("pause");
		system("cls");
	}
	return;
}