#pragma once

class Management
{
public:
	bool ManageScores();
	void InputStudent(class Student*  pArray, int iCount, int iTotal);
	void PrintStudent(class Student*  pArray, int iCount);

private:
	//class Student* m_pStudent = nullptr;
	class Student* m_pArray = nullptr;

private:
	int m_iTotal = 0;

};