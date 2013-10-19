#pragma once
#include "cmd.h"

enum MoveCmdType
{
	STOP_MOVE_CMD=1,
};


#define DEC_MOVE_CMD_FN(paramnum) \
	DEC_CMD_FN(MOVE_CMD, paramnum)

struct MoveCmd : public NullCmd
{
	MoveCmd(uint8 param):NullCmd(MOVE_CMD, param)
	{
	}
};


struct StopMoveCmd : public MoveCmd
{
	DEC_MOVE_CMD_FN(STOP_MOVE_CMD);
	StopMoveCmd():MoveCmd(STOP_MOVE_CMD)
	{
	}
};