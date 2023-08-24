#pragma once

class Student
{
public:
	Student();
	~Student();

public:
	static Student* Create();
	void Initialize();

public:
	void		Set_iKor(int _iKor)	{ m_iKor = _iKor; }	
	int			Get_iKor()			{ return m_iKor; }

	void		Set_iEng(int _iEng) { m_iEng = _iEng; }
	int			Get_iEng()			{ return m_iEng; }

	void		Set_iMath(int _iMath) { m_iMath = _iMath; }
	int			Get_iMath()		  	  { return m_iMath; }

	void		Set_iTotal(int _iTotal) { m_iTotal = _iTotal; }
	int			Get_iTotal()			{ return m_iTotal; }

	void		Set_fAver(float _fAver) { m_fAver = _fAver; }
	float		Get_fAver()			    { return m_fAver; }

public:
	char m_szName[16] = "-";

private:
	int m_iKor;
	int m_iEng;
	int m_iMath;
	int m_iTotal;
	float m_fAver;
};