#include "player.h"
#include "move_cmd.h"
#include "dispatch.h"

void Player::regMoveCmdFn()
{
	REG_CMD_FN(Player, StopMoveCmd);
}

template<>
bool StopMoveCmd::DoCmd<Player>::doCmd(Player* player, NullCmd*, size_t)
{
	return true;
}

#include "task.h"
void Task::regMoveCmdFn()
{
	REG_CMD_FN(Task, StopMoveCmd);
}
template<>
bool StopMoveCmd::DoCmd<Task>::doCmd(Task* task, NullCmd*, size_t)
{
	return true;
}