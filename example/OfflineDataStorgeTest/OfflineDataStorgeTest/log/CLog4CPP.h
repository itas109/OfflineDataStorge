/*
**************************************************************************************
**
**	FILENAME			CLog4CPP.h
**
**	PURPOSE				����һ��C++����־������,����ASNI��UINCODE����
**
**	CREATION DATE		2016-08-12
**
**	AUTHOR				itas109
**
**  Blog                http://blog.csdn.net/itas109
**
**  Git                 https://github.com/itas109
**
**************************************************************************************
**  author: itas109  date:2016-08-15
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� Init��������Ĭ�ϳ�ʼ������
**  2�� �������
**  3�� �Ż����������
**************************************************************************************
**  author: itas109  date:2016-08-17
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� Init�������أ���ʱ�������ļ���
**  2�� ��־�ļ�Ĭ�Ϸŵ�Log�ļ�����
**  3�� ����int2string�����������������ַ���ת��
**************************************************************************************
**  author: itas109  date:2016-08-18
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� ȥ����MFC������
**  2�� ����C++ͨ����������
**************************************************************************************
**  author: itas109  date:2016-08-26
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� ����ͨ���Ե�#ifndef�滻#pragma once
**  2�� �滻һЩ�궨��
**************************************************************************************
**  author: itas109  date:2016-09-12
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1�� ȥ��int2string����
**  2�� ʱ���ʽͳһΪxxxx-xx-xx xx:xx:xx������λ��0����2016-09-12 16:28:01
**************************************************************************************
**  author: itas109  date:2016-10-13
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  _mkdir�����ļ���ʱ���������þ���·������ֹ������ʱ�޷������ļ���
**************************************************************************************
**  author: itas109  date:2017-03-29
**  Blog��blog.csdn.net/itas109
**  �Ľ�
**  1) �޸�ָ���ͷ�����
**  2) LogOut���������Ƿ񸲸�д���ļ�����
**************************************************************************************
**  author: itas109  date:2017-06-03
**  Blog��blog.csdn.net/itas109
**  Version��2.1.1.170603
**  �Ľ�
**  1) ����namespace
**  2) ʹ��_s�İ�ȫ����
**  3) �޸����������г���һ�����־��������д���ʼ�������ļ�������
**  4) ���Ӱ汾�ź���
*/
#ifndef CLOG4CPP_H
#define CLOG4CPP_H

#include <string>
#include <sstream>
#include <direct.h>
#include "atltime.h"

namespace itas109
{
	class CLog4CPP
	{
	public:

		CLog4CPP();
		~CLog4CPP();

		std::string getVersion();

		//��ʼ��
		void Init(std::string stringpOutputFilename);
		void Init();//���յ�������������־�ļ�

		//������֣�������TRACE��printf
		//isOverlayWrite �Ƿ񸲸�д���ļ�
		bool LogOut(std::string text, bool isOverlayWrite = false);

		//����ʹ��
		void IsEnable(bool bEnable);

		//�Ƿ���ÿ�м���ʱ���
		void IsPrintTime(bool b) { m_bPrintTime = b; }

	private:
		//������
		enum { TBUF_SIZE = 3000 };
		std::string m_tBuf[TBUF_SIZE];

		std::string m_csFileName;

		//�ٽ���
		CRITICAL_SECTION  m_crit;

		//ʹ��
		bool m_bEnable;//�Ƿ��ӡ
		bool m_bPrintTime;//�Ƿ����ʱ���
		bool m_bNamedByDate;//�Ƿ�����������

		//�ַ�����
		std::string GetBaseDir(std::string & path);
		std::string GetFileExtensions(std::string & fileName);

		//class version
		const std::string version = "2.1.1.170603";		
	};
}
#endif CLOG4CPP_H