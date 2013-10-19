#pragma once

#include "config.h"
struct NullCmd;

class Task
{
public: 
	static void regCmdFn();
	bool doCmd(NullCmd*, size_t);

	uint32 id() const {return id_;}
private:
	static void regChatCmdFn();
	static void regMoveCmdFn();

	uint32 id_;
};