#include "Management.h"
#include "Student.h"
#include <iostream>

using namespace std;

///<summary> ���� �����ϴ� ���� �Լ� </summary>
bool Management::ManageScores()
{
	int iInput(0), iCount(0);

	system("cls");
	cout << "�� ���� ���� ���α׷� ��" << endl;
	cout << "1. �Է� 2. ��� 3. ����" << endl;
	cin >> iInput;

	switch (iInput)
	{
		case 1:
		{
			system("cls");
			cout << "�� �Է��� �л��� ����� �Է��Ͽ� �ֽʽÿ�." << endl;
			cin >> iCount;

			m_iTotal += iCount;
			Student* m_pArraySub = new Student[m_iTotal]; // ���������� �����ͺ��� ���� �� ����

			if (m_pArray != nullptr)
			{
				memcpy(m_pArraySub, m_pArray, sizeof(Student) * m_iTotal); // ������ �޾Ҵ� �����Ҵ� �޸𸮸� �� ũ�� �����Ҵ� ���� �޸𸮿� �־��ֱ�
			}
			
			InputStudent(m_pArraySub, iCount, m_iTotal); //�ڿ� �߰����� �л� ���� �Է��ϴ� �κ�

			if (m_pArray != nullptr)
				delete[] m_pArray;

			m_pArray = new Student[m_iTotal];
			memcpy(m_pArray, m_pArraySub, sizeof(Student) * m_iTotal);	// sizeof������ �� ���� ����
			
			delete[] m_pArraySub;
			m_pArraySub = nullptr;
			break;
		}	
		case 2:
			PrintStudent(m_pArray, m_iTotal);
			break;
		case 3:
			delete[] m_pArray;
			m_pArray = nullptr;
			return false;
		default:
			break;
	}

	return true;
}

///<summary> �л� �̸��� ������ �Է� �޴´� </summary>
void Management::InputStudent(Student*  pArray, int iCount, int iTotal)
{
	int iKor(0), iEng(0), iMath(0), iSum(0);
	float fAver(0.f);

	//ZR - iInput ����ó��

	for (int i = iTotal - iCount; i < iTotal; ++i)
	{
		cout << "============================================================" << endl;
		cout << "�Ѣ� �л��� �̸��� �Է��Ͽ� �ֽʽÿ�." << endl;
		cin >> pArray[i].m_szName;

		cout << "�Ѣ� ����, ����, ���� ������ ���ʷ� �Է��Ͽ� �ֽʽÿ�." << endl;
		cin >> iKor >> iEng >> iMath;
		pArray[i].Set_iKor(iKor);
		pArray[i].Set_iEng(iEng);
		pArray[i].Set_iMath(iMath);

		iSum = iKor + iEng + iMath;
		pArray[i].Set_iTotal(iSum);

		fAver = (float)iSum / 3.f;
		pArray[i].Set_fAver(fAver);
	}
}

///<summary> �л� �̸��� ������ ����Ѵ� </summary>
void Management::PrintStudent(Student*  pArray, int iTotal) //�б� ����!
{
	system("cls");

 	for (int i = 0; i < iTotal; ++i)
	{
		cout << "�� �л� �̸� : " << pArray[i].m_szName << endl;
		cout << "����\t����\t����\t����\t���" << endl;
		cout << pArray[i].Get_iKor() << "\t" << pArray[i].Get_iEng() << "\t" << pArray[i].Get_iMath() << "\t" << pArray[i].Get_iTotal() << "\t" << pArray[i].Get_fAver() << endl;
		cout << "============================================================" << endl;
	}

	system("pause");
}