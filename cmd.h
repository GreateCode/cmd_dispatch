#pragma once
#include "config.h"
//#include "dispatch.h"

struct NullCmd
{
	uint8 byCmd;
	uint8 byParam;
	NullCmd(uint8 cmd=0, uint8 param=0):byCmd(cmd),byParam(param)
	{
	}
};

enum CmdType
{
	CHAT_CMD,
	MOVE_CMD,
};

#define DEC_CMD_FN(cmdnum, paramnum) \
	template <typename T> \
	struct DoCmd \
	{ \
		static bool doCmd(T*, NullCmd*, size_t); \
	}; \
	enum \
	{ \
		CmdNum = cmdnum, \
		ParamNum = paramnum, \
	};

//#define REG_CMD_FN(owner_type, cmd_type) \
//	Dispatch<owner_type>::g_cmd_fns[cmd_type::CmdNum][cmd_type::ParamNum] = CmdFn<owner_type>(&(cmd_type::DoCmd<owner_type>::doCmd));


//#define CAST_CMD(cmd_type, cmd_name) \
	