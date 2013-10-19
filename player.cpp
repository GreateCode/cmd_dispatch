#include "player.h"
#include "dispatch.h"

void Player::regCmdFn()
{
	regChatCmdFn();
	regMoveCmdFn();
}

bool Player::doCmd(NullCmd* cmd, size_t len)
{
	return Dispatch<Player>::doCmd(this, cmd, len);
}