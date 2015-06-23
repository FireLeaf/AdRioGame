--
-- Author: Yangcao
-- Date: 2015-06-19 15:29:54
--
--send server code
SSC = 
{
	REGISTER_ACCOUNT = 0,--通知服务器注册角色
}

--recv server code
RSC = 
{
	SERVER_ERROR_CODE = 0,--服务器错误代码
	REGISTER_ACCOUNT_RE = 1,--注册返回客户端通知
}