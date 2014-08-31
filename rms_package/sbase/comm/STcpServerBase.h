/**
 *
 * �� �� �� : STcpServerBase.h
 * �������� : 2011-11-8 17:54
 * ��    �� : �ۿ���(skt001@163.com)
 * �޸����� : $Date: $
 * ��ǰ�汾 : $Revision: $
 * �������� : 
 * �޸ļ�¼ : 
 *            $Log: $
 *
 **/

#ifndef __SKT_TCPSERVER_BASE_H__
#define __SKT_TCPSERVER_BASE_H__

#include "STcpCommBase.h"

class STcpServerBase;

//////////////////////////////////////////////////////////////////////////
// ��    ��:  STcpServerSession
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-11 8:46
// ��    ��:  ����Ự��
//////////////////////////////////////////////////////////////////////////
class STcpServerSession : public STcpCommBase
{
public:
	friend class STcpServerBase;
	STcpServerSession();
	~STcpServerSession();

	//�����Ƿ���Ч
	bool IsValid(){return m_ValidWord==0xeb903469;};
	
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �������ݵ����Ͷ��У��ڷ�����ɺ��ͷ�pPackage����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 12:40
	// ����˵��:  @pPackage�����ͱ���
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	void AddToSend(stuSTcpPackage *pPackage);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ǰ�Ự�Զ���������һ֡���ģ���ͨ�����ͻ���������ֻ����OnRecvFrame������ʹ�ã������̲߳���ȫ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-01-17 13:46
	// ����˵��:  @pPackage��ʾ�����͵����ݰ�
	//            @bAutoDelPackage��ʾ�Ƿ���ʹ����Ϻ��Զ�ɾ��pPackage
	// �� �� ֵ:  true��ʾ���ͳɹ�,false��ʾ����ʧ��
	//////////////////////////////////////////////////////////////////////////
	bool SendFrame(stuSTcpPackage *pPackage,bool bAutoDelPackage=false);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ǰ�Ự�Զ���������һ֡���ģ���ͨ�����ͻ���������ֻ����OnRecvFrame������ʹ�ã������̲߳���ȫ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-01-17 13:57
	// ����˵��:  @sHead��ʾ����ͷ�ַ���
	//            @wFrameType��ʾ��������
	//            @pAsduBuffer��ʾASDU���ݻ���������pAsduBufferΪNULL��iAsduLen��Ϊ0ʱ����ʾʹ��Ԥ��ķ��ͻ�����
	//            @iAsduLen��ʾASDU���ݳ���
	// �� �� ֵ:  true��ʾ���ͳɹ�,false��ʾ����ʧ��
	//////////////////////////////////////////////////////////////////////////
	bool SendFrame(SString &sHead,WORD wFrameType=0,BYTE *pAsduBuffer=NULL,int iAsduLen=0);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��ǰ�Ự�Զ���������һ֡���ģ���ͨ�����ͻ���������ֻ����OnRecvFrame������ʹ�ã������̲߳���ȫ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-01-17 13:57
	// ����˵��:  @wFrameType��ʾ��������
	//            @pAsduBuffer��ʾASDU���ݻ���������pAsduBufferΪNULL��iAsduLen��Ϊ0ʱ����ʾʹ��Ԥ��ķ��ͻ�����
	//            @iAsduLen��ʾASDU���ݳ���
	// �� �� ֵ:  true��ʾ���ͳɹ�,false��ʾ����ʧ��
	//////////////////////////////////////////////////////////////////////////
	bool SendFrame(WORD wFrameType,BYTE *pAsduBuffer=NULL,int iAsduLen=0);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �������ն����еı���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 21:32
	// ����˵��:  
	// �� �� ֵ:  stuSTcpPackage*
	//////////////////////////////////////////////////////////////////////////
	stuSTcpPackage* SearchRecvPackage();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ͨ������ͷ�ַ����е�act���Լ������ն����еı���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 21:32
	// ����˵��:  @act��ʾ����ı���
	// �� �� ֵ:  stuSTcpPackage*
	//////////////////////////////////////////////////////////////////////////
	stuSTcpPackage* SearchRecvPackage(SString act);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ͨ���������ͼ������ն����еı���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 21:32
	// ����˵��:  @wFrameType��ʾ
	// �� �� ֵ:  stuSTcpPackage*
	//////////////////////////////////////////////////////////////////////////
	stuSTcpPackage* SearchRecvPackage(WORD wFrameType);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �Ự����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-11 13:53
	// ����˵��:  void
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	inline void lock(){m_Lock.lock();};

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �Ự����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-11 13:53
	// ����˵��:  void
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	inline void unlock(){m_Lock.unlock();};

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �Ƿ�ͨѶ��������״̬
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-12 22:13
	// ����˵��:   void
	// �� �� ֵ:  true��ʾ������,false��ʾδ����
	//////////////////////////////////////////////////////////////////////////
	inline bool IsConnected(){return m_pSocket==NULL?false:m_pSocket->IsConnected();};

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡSocketָ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-4-26 13:55
	// ����˵��:  void
	// �� �� ֵ:  SSocket*
	//////////////////////////////////////////////////////////////////////////
	inline SSocket* GetSessionSock(){return m_pSocket;}

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ���ͻ�����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-11-17 12:09
	// ����˵��:  void
	// �� �� ֵ:  SPtrList<stuSTcpPackage>*
	//////////////////////////////////////////////////////////////////////////
	inline SPtrList<stuSTcpPackage>* GetSendPackages(){return &m_SendPackage;};

protected:
	DWORD m_ValidWord;//�Ƿ���Ч�ı����
	SLock m_Lock;
	STcpServerBase *m_pServer;//ָ��֡���������ָ��
	SSocket *m_pSocket;//�ỰSOCKET
	SPtrList<stuSTcpPackage> m_RecvPackage;//���յ������ݰ�
	SPtrList<stuSTcpPackage> m_SendPackage;//�����͵����ݰ�
	SString m_sLoginAttr;//��¼����,��: act=login;guesttype=htys.ca8110.steady;
};

//////////////////////////////////////////////////////////////////////////
// ��    ��:  CTcpClientBase
// ��    ��:  �ۿ���
// ����ʱ��:  2011-11-8 19:41
// ��    ��:  TCPͨѶ�ͻ��˷������
//////////////////////////////////////////////////////////////////////////
class STcpServerBase : public STcpCommBase, public SService
{
public:
	friend class STcpServerSession;

	STcpServerBase();
	virtual	~STcpServerBase();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��������
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-8 19:41
	// ����˵��:  @port��ʾ�˿�,@ip��ʾ�����IP��ַ
	// �� �� ֵ:  true��ʾ���������ɹ�,false��ʾ��������ʧ��
	//////////////////////////////////////////////////////////////////////////
	virtual bool Start(int port,SString ip="");

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ֹͣ����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-8 19:41
	// ����˵��:  void
	// �� �� ֵ:  true��ʾ����ֹͣ�ɹ�,false��ʾ����ֹͣʧ��
	//////////////////////////////////////////////////////////////////////////
	virtual bool Stop();

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �������ݵ����Ͷ��У��ڷ�����ɺ��ͷ�pPackage����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 12:40
	// ����˵��:  @pPackage�����ͱ���
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	void AddToSend(stuSTcpPackage *pPackage);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �������ն����еı���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 21:32
	// ����˵��:  @pSessionΪ���õĻỰָ��
	// �� �� ֵ:  stuSTcpPackage*
	//////////////////////////////////////////////////////////////////////////
	stuSTcpPackage* SearchRecvPackage(STcpServerSession* &pSession);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ͨ������ͷ�ַ����е�act���Լ������ն����еı���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 21:32
	// ����˵��:  @act��ʾ����ı���
	//            @pSessionΪ���õĻỰָ��
	// �� �� ֵ:  stuSTcpPackage*
	//////////////////////////////////////////////////////////////////////////
	stuSTcpPackage* SearchRecvPackage(SString act,STcpServerSession* &pSession);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ͨ���������ͼ������ն����еı���
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 21:32
	// ����˵��:  @wFrameType��ʾ
	//            @pSessionΪ���õĻỰָ��
	// �� �� ֵ:  stuSTcpPackage*
	//////////////////////////////////////////////////////////////////////////
	stuSTcpPackage* SearchRecvPackage(WORD wFrameType,STcpServerSession* &pSession);

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ��¼�ص��麯��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-11 18:56
	// ����˵��:  @ip��¼�ͻ��˵�IP
	//            @port��¼�ͻ��˵Ķ˿�
	//            @sLoginHead��¼�ַ���
	// �� �� ֵ:  true��ʾ������¼,false��ʾ�ܾ���¼
	//////////////////////////////////////////////////////////////////////////
	virtual bool OnLogin(SString ip,int port,SString &sLoginHead){return true;};

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  �»Ự�ص��麯��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-6-1 11:56
	// ����˵��:  @pSessionΪ�´����ĻỰʵ��
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	virtual void OnNewSession(STcpServerSession *pSession){};

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  ɾ���Ự�Ļص��麯��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2013-3-21 10:07
	// ����˵��:  @pSessionΪ������ɾ���ĻỰʵ��
	// �� �� ֵ:  void
	//////////////////////////////////////////////////////////////////////////
	virtual void OnDeleteSession(STcpServerSession *pSession){};

	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �Ự�߳̽��յ����ĺ�Ļص��麯����������ͨ���˺���������ʱ��Ϣ
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-11 13:47
	// ����˵��:  @pSessionΪ�Ựʵ��ָ�룬����ͨ��ָ����Զ˷�������
	//            @pPackageΪ�ս��յ������ݰ�
	// �� �� ֵ:  true��ʾ�Ѿ�������ϣ��˱��Ŀ����ͷ��ˣ�false��ʾδ�������˱���Ӧ������ն���
	//////////////////////////////////////////////////////////////////////////
	virtual bool OnRecvFrame(STcpServerSession *pSession,stuSTcpPackage *pPackage)=0;

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ��ǰ�����ж�Ӧ�ĻỰ����
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-2-15 14:58
	// ����˵��:  void
	// �� �� ֵ:  int
	//////////////////////////////////////////////////////////////////////////
	inline int GetSessionCount(){return m_Sessions.count();};

	//////////////////////////////////////////////////////////////////////////
	// ��    ��:  ȡ��idx���Ựʵ��ָ��
	// ��    ��:  �ۿ���
	// ����ʱ��:  2012-4-5 15:07
	// ����˵��:  @idxΪ�Ự��ţ���0��ʼ
	// �� �� ֵ:  STcpServerSession*
	//////////////////////////////////////////////////////////////////////////
	inline STcpServerSession* GetSession(int idx){return m_Sessions[idx];};

	inline void SessionsLock(){m_Sessions.lock();};

	inline void SessionsUnLock(){m_Sessions.unlock();};

	inline SPtrList<STcpServerSession>* GetSessionPtr(){return &m_Sessions;};

protected:
	
	////////////////////////////////////////////////////////////////////////
	// ��    ��:  �����֡���߳�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-8 19:41
	// ����˵��:  this
	// �� �� ֵ:  NULL
	//////////////////////////////////////////////////////////////////////////
	static void* ThreadListen(void* lp);


	////////////////////////////////////////////////////////////////////////
	// ��    ��:  ����˻Ự�߳�
	// ��    ��:  �ۿ���
	// ����ʱ��:  2011-11-10 22:20
	// ����˵��:  this
	// �� �� ֵ:  NULL
	//////////////////////////////////////////////////////////////////////////
	static void* ThreadService(void* lp);

private:
	SString m_sServerIp;//������֡��IP���ձ�ʾȫ��IP��ַ֡��
	int m_iServerPort;//�������˿ں�
	SSocket m_Socket;//�����֡����SOCKET
	SPtrList<STcpServerSession> m_Sessions;//�Ự
};

#endif//__SKT_TCPSERVER_BASE_H__