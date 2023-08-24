#include "Student.h"
#include <iostream>

Student::Student()
{}

Student::~Student()
{}

Student* Student::Create()
{
	Student* pInstance = new Student;

	if (pInstance != nullptr)
	{
		pInstance->Initialize();
	}

	return pInstance;
}

void Student::Initialize()
{
	strcpy_s(m_szName, sizeof(m_szName), "-");
	m_iKor  = 0;
	m_iEng  = 0;
	m_iMath = 0;
	m_iTotal = 0;
	m_fAver = 0;
}