#pragma once

#include "cmd.h"

enum ChatCmdType
{
	SYS_CHAT_CMD,
};

#define DEC_CHAT_CMD_FN(paramnum) \
	DEC_CMD_FN(CHAT_CMD, paramnum)

struct ChatCmd : public NullCmd
{
	ChatCmd(uint8 param):NullCmd(CHAT_CMD, param)
	{
	}
};

struct SysChatCmd : public ChatCmd
{
	DEC_CHAT_CMD_FN(SYS_CHAT_CMD);
	SysChatCmd():ChatCmd(SYS_CHAT_CMD)
	{
	}
};