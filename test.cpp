#include <iostream>
#include "move_cmd.h"
#include "chat_cmd.h"
#include "player.h"
#include "task.h"

using namespace std;

int main()
{
	Player::regCmdFn();
	StopMoveCmd cmd;
	Player player;
	player.doCmd(&cmd, sizeof(cmd));
	
	Task::regCmdFn();
	Task task;
	task.doCmd(&cmd, sizeof(cmd));
	return 0;
}