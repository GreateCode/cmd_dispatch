#pragma once
#include "config.h"

struct NullCmd;
struct MoveCmd;
struct ChatCmd;

class Player
{
public: 
	static void regCmdFn();
	bool doCmd(NullCmd*, size_t);
	
	uint32 id() const {return id_;}
private:
	static void regChatCmdFn();
	//bool doChatCmd(ChatCmd*, size_t);
	static void regMoveCmdFn();
	//bool doMoveCmd(MoveCmd*, size_t);

	uint32 id_;
};