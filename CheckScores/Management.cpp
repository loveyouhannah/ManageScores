#include "Management.h"
#include "Student.h"
#include <iostream>

using namespace std;

///<summary> 성적 관리하는 메인 함수 </summary>
bool Management::ManageScores()
{
	int iInput(0), iCount(0);

	system("cls");
	cout << "▷ 성적 관리 프로그램 ◁" << endl;
	cout << "1. 입력 2. 출력 3. 종료" << endl;
	cin >> iInput;

	switch (iInput)
	{
		case 1:
		{
			system("cls");
			cout << "▶ 입력할 학생의 명수를 입력하여 주십시오." << endl;
			cin >> iCount;

			m_iTotal += iCount;
			Student* m_pArraySub = new Student[m_iTotal]; // 지역변수로 포인터변수 선언 및 정의

			if (m_pArray != nullptr)
			{
				memcpy(m_pArraySub, m_pArray, sizeof(Student) * m_iTotal); // 기존에 받았던 동적할당 메모리를 더 크게 동적할당 받은 메모리에 넣어주기
			}
			
			InputStudent(m_pArraySub, iCount, m_iTotal); //뒤에 추가적인 학생 정보 입력하는 부분

			if (m_pArray != nullptr)
				delete[] m_pArray;

			m_pArray = new Student[m_iTotal];
			memcpy(m_pArray, m_pArraySub, sizeof(Student) * m_iTotal);	// sizeof연산할 때 개수 지정
			
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

///<summary> 학생 이름과 성적을 입력 받는다 </summary>
void Management::InputStudent(Student*  pArray, int iCount, int iTotal)
{
	int iKor(0), iEng(0), iMath(0), iSum(0);
	float fAver(0.f);

	//ZR - iInput 예외처리

	for (int i = iTotal - iCount; i < iTotal; ++i)
	{
		cout << "============================================================" << endl;
		cout << "☞☞ 학생의 이름을 입력하여 주십시오." << endl;
		cin >> pArray[i].m_szName;

		cout << "☞☞ 국어, 영어, 수학 점수를 차례로 입력하여 주십시오." << endl;
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

///<summary> 학생 이름과 성적을 출력한다 </summary>
void Management::PrintStudent(Student*  pArray, int iTotal) //읽기 전용!
{
	system("cls");

 	for (int i = 0; i < iTotal; ++i)
	{
		cout << "▶ 학생 이름 : " << pArray[i].m_szName << endl;
		cout << "국어\t영어\t수학\t총점\t평균" << endl;
		cout << pArray[i].Get_iKor() << "\t" << pArray[i].Get_iEng() << "\t" << pArray[i].Get_iMath() << "\t" << pArray[i].Get_iTotal() << "\t" << pArray[i].Get_fAver() << endl;
		cout << "============================================================" << endl;
	}

	system("pause");
}