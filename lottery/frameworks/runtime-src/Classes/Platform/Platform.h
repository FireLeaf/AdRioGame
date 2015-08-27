/**************************************************************************
/*		FileName: Platform.h
/*		FileDesc: Æ½Ì¨»ù´¡
/*		FileAuthor: YangCao
/*		CreateTime: 2015/07/30 19:31:55
/*		CopyRight: yc 
/*************************************************************************/

#ifndef __PLATFORM__H
#define __PLATFORM__H

enum PLATFORM_TYPE
{
	PLATFORM_INVALID,
	PLATFORM_US_IOS,
};

//struct LoginInfo
//{
//    std::string 
//};

class OGPlatform
{
	
public:
	static OGPlatform* GetInstance();
public:
	int GetPlatformType(){return m_iPlatform;}
	virtual void Login(const char* szCommand) = 0;
	virtual void Logout(const char* szCommand) = 0;
    virtual void Pay(const char* szCommand) = 0;
protected:
	int m_iPlatform;
};

#endif // Platform