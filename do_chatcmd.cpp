#include "player.h"
#include "chat_cmd.h"
#include "dispatch.h"

void Player::regChatCmdFn()
{
	REG_CMD_FN(Player, SysChatCmd);
}


template<>
bool SysChatCmd::DoCmd<Player>::doCmd(Player* player, NullCmd* cmd, size_t len)
{
	return true;
}



#include "task.h"
void Task::regChatCmdFn()
{
	REG_CMD_FN(Task, SysChatCmd);
}
template<>
bool SysChatCmd::DoCmd<Task>::doCmd(Task* task, NullCmd* cmd, size_t len)
{
	return true;
}