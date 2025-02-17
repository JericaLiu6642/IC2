#pragma once
#ifndef ORCPLAYER_H
#define ORCPLAYER_H
#include "NovicePlayer.h"
#include <string>

class OrcPlayer : public NovicePlayer
{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	void setLevel(int);
	virtual string serialize();
	static NovicePlayer* unserialize(string);
};
#endif