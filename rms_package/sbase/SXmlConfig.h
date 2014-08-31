/**
 *
 * �� �� �� : SXmlConfig.h
 * �������� : 2007-07-14
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: 2011/08/31 08:43:35 $
 * ��ǰ�汾 : $Revision: 1.1 $
 * �������� : ʵ�������ļ�����ӿڵ�XML������
 * �޸ļ�¼ : 
 *            $Log: SXmlConfig.h,v $
 *            Revision 1.1  2011/08/31 08:43:35  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2011/02/25 03:12:07  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2010/08/09 03:04:44  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2010/01/22 01:24:26  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2009/09/15 02:14:09  shaokt
 *            ͨѸ��¼����װ����Ŀ�״��ύ
 *
 *            Revision 1.4  2009/05/19 02:50:38  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2008/12/22 08:54:13  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.2  2008/10/06 08:48:29  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 11:38:29  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.1  2008/09/01 08:58:04  shaokt
 *            *** empty log message ***
 *
 *            Revision 1.3  2007/10/29 07:30:23  shaokt
 *            ���Ӷ����ַ�Ƿ�Ϊ4�ı����ļ�⺯����Ϊ���ARM������pack(1)��ɵ��ڴ�����
 *
 *            Revision 1.2  2007/09/11 08:17:53  shaokt
 *            �������
 *
 *            Revision 1.1  2007/08/15 03:09:22  shaokt
 *            *** empty log message ***
 *
 **/

#ifndef __SKTXMLCONFIG_H__
#define __SKTXMLCONFIG_H__

#include "SBaseConfig.h"
#include "SFile.h"

//////////////////////////////////////////////////////////////////////////
// ��    ��:  SXmlConfig
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-24 15:10
// ��    ��:  �����ļ�����
//////////////////////////////////////////////////////////////////////////
class SXmlConfig : public SBaseConfig
{
	enum STR_ENCODING
	{
		STR_ENCODING_GB2312,
		STR_ENCODING_UTF8
	};
public:
	SXmlConfig();
	virtual ~SXmlConfig();
	
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���ı��ַ�������XML
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-24 15:10
	// ����˵��:  @sXmlTextΪ�ı�����
	// �� �� ֵ:  true��ʾ��ȡ�ɹ���false��ʾ��ȡʧ��
	//////////////////////////////////////////////////////////////////////////
	bool ReadText(char* sXmlText);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �õ�ǰʵ������XML�����ļ�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-24 15:11
	// ����˵��:  @sXmlFileΪĿ���ļ���
	//            @sEncoding�ַ�������,ȱʡΪGB
	// �� �� ֵ:  true��ʾ����ɹ���falseΪʧ��
	//////////////////////////////////////////////////////////////////////////
	bool SaveConfig(SString sXmlFile,SString sEncoding="GB2312");

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���ļ���ȡXML
	// ��    ��:  �ۿ���
	// ����ʱ��:  2010-1-7 14:12
	// ����˵��:  @sXmlFile�ļ�����
	// �� �� ֵ:  true��ȡ�ļ�
	//////////////////////////////////////////////////////////////////////////
	bool ReadConfig(SString sXmlFile);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ���ı��ַ�������XML
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-24 15:10
	// ����˵��:  @szXmlTextΪ�ı�����
	// �� �� ֵ:  true��ʾ��ȡ�ɹ���false��ʾ��ȡʧ��
	//////////////////////////////////////////////////////////////////////////
	bool LoadXmlByText(char * szXmlText);

private:
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ����ָ���Ľڵ�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-24 15:12
	// ����˵��:  @fileΪ�ļ�ʵ��
	//            @pNodeΪ�ڵ�ʵ��
	//            @levelΪ��ǰ����
	// �� �� ֵ:  
	//////////////////////////////////////////////////////////////////////////
	bool SaveNode(SFile &file,SBaseConfig *pNode,int &level);

	STR_ENCODING m_iEncodeing;
};

#endif
