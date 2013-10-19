#include "task.h"
#include "dispatch.h"

void Task::regCmdFn()
{
	regChatCmdFn();
	regMoveCmdFn();
}

bool Task::doCmd(NullCmd* cmd, size_t len)
{
	return Dispatch<Task>::doCmd(this, cmd, len);
}