#include <iostream>
#include <string>
#include <json/value.h>
#include "ClientOP.h"

using namespace std;

int usage();

int main()
{
	// �����ͻ��˲��������
	ClientOP op("config.json");
	while (1)
	{
		int sel = usage();
		switch (sel)
		{
		case 1:
			// ��ԿЭ��
			op.seckeyAgree();
			break;
		case 2:
			op.seckeyCheck();
			// ��ԿУ��
			break;
		case 3:
			// ��Կע��
			op.seckeyVerification();
		default:
			break;

		}
	}
	cout << "�ͻ����˳�, bye,byte..." << endl;
	return 0;
}

int usage()
{
	int nSel = -1;
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n  /*     1.��ԿЭ��                                            */");
	printf("\n  /*     2.��ԿУ��                                            */");
	printf("\n  /*     3.��Կע��                                            */");
	printf("\n  /*     4.��Կ�鿴                                            */");
	printf("\n  /*     0.�˳�ϵͳ                                            */");
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n\n  ѡ��:");

	scanf("%d", &nSel);
	while (getchar() != '\n');

	return nSel;
}
