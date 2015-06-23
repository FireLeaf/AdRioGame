// NetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

enum
{
	NONE,
	COMMMENT,
	TABLE_DEF,
	TABLE_BEGIN,
	TABLE_END,
	TABLE_KEYVALUE,
	RETURN,
};

struct LuaLine 
{
	LuaLine()
	{
		code_type = NONE;
	}
	int code_type;
	std::string table_name;//表名
	std::string key;
	std::string value;
	std::string comment;//注释
	std::string strput;
};

void ParserLuaCode(const char* line, LuaLine& ll)
{
	if (line[0] == '-' && line[1] == '-')
	{
		ll.code_type = COMMMENT;
		ll.comment = "//";
		ll.comment += (const char*)(&line[2]);
	}
	else if (line[0] == '\n')
	{
		ll.code_type = RETURN;
		ll.strput = "\n";
	}
	else if (NULL != strstr(line, "{"))
	{
		ll.code_type = TABLE_BEGIN;
		ll.strput = "{";
	}
	else if (NULL != strstr(line, "}"))
	{
		ll.code_type = TABLE_END;
		ll.strput = "}";
	}
	else if (NULL != strstr(line, "	"))
	{
		char key[256] = {'\0'};
		char value[256] = {'\0'};
		char comment[256] = {'\0'};
		ll.code_type = TABLE_KEYVALUE;
		sscanf(line, "	%s = %[^,],%s", key, value, comment);
		ll.key = key;
		ll.value = value;
		if (comment[0] == '-' && comment[1] == '-')
		{
			ll.comment = "//";
			ll.comment += (const char*)(&comment[2]);
		}
	}
	else if (NULL != strstr(line, "="))
	{
		char table_name[64] = {'\0'};
		ll.code_type = TABLE_DEF;
		sscanf(line, "%s =", table_name);
		ll.table_name = table_name;
	}
}

bool TransCodeLuaToJS(FILE* infile, FILE* outfile)
{
	const static int MaxLineBuf = 1024;
	char buf[MaxLineBuf] = {'\0',};
	while (fgets(buf, MaxLineBuf - 1, infile) != NULL)
	{
		LuaLine ll;
		ParserLuaCode(buf, ll);
		switch(ll.code_type)
		{
		case NONE:
			break;
		case COMMMENT:
			fprintf(outfile, "%s", ll.comment.c_str());
			break;
		case TABLE_DEF:
			fprintf(outfile, "var %s = \n", ll.table_name.c_str());
			break;
		case TABLE_BEGIN:
			fprintf(outfile, "{\n");
			break;
		case TABLE_END:
			fprintf(outfile, "}\n");
			break;
		case TABLE_KEYVALUE:
			fprintf(outfile, "\t%s : %s, %s\n", ll.key.c_str(), ll.value.c_str(), ll.comment.c_str());
			break;
		case RETURN:
			fprintf(outfile, "\n");
			break;
		default:
			break;
		}
		memset(buf, 0, sizeof(MaxLineBuf));
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 3)
	{
		printf("useage: NetCode.exe inputfile outputdir");
		return -1;
	}
	std::string netcode_infile = argv[1];
	std::string netcode_outfile = argv[2];
	FILE* in_fp = fopen(netcode_infile.c_str(), "r");
	if (!in_fp)
	{
		printf("%s 文件不存在\n", netcode_infile.c_str());
		return -1;
	}

	netcode_outfile += "NetCode.js";
	FILE* out_fp = fopen(netcode_outfile.c_str(), "w");
	if (!out_fp)
	{
		printf("%s 文件不可写\n", netcode_outfile.c_str());
		return -1;
	}

	TransCodeLuaToJS(in_fp, out_fp);
	return 0;
}

