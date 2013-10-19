#pragma once
#include "cmd.h"
struct NullCmd;

template <typename OwnerT>
class CmdFn
{
public:
	typedef bool (*do_cmd_fn)(OwnerT*, NullCmd*, size_t);
	static bool donull(OwnerT*, NullCmd*, size_t)
	{
		return false;
	}
	CmdFn(do_cmd_fn fn) : fn_(fn)
	{
	}
	CmdFn() : fn_(donull)
	{
	}
	bool operator()(OwnerT* owner, NullCmd* cmd, size_t len)
	{
		return fn_(owner, cmd, len);
	}
private:
	do_cmd_fn fn_;
};

template <typename OwnerT>
class Dispatch
{
public:
	static bool doCmd(OwnerT* owner, NullCmd* cmd, size_t len);
	static CmdFn<OwnerT> g_cmd_fns[256][256];
};

template <typename OwnerT>
CmdFn<OwnerT> Dispatch<OwnerT>::g_cmd_fns[256][256];

template <typename OwnerT>
bool Dispatch<OwnerT>::doCmd(OwnerT* owner, NullCmd* cmd, size_t len)
{
	return g_cmd_fns[cmd->byCmd][cmd->byParam](owner, cmd, len);
}

#define REG_CMD_FN(owner_type, cmd_type) \
	Dispatch<owner_type>::g_cmd_fns[cmd_type::CmdNum][cmd_type::ParamNum] = CmdFn<owner_type>(&(cmd_type::DoCmd<owner_type>::doCmd));
