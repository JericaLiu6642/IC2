#ifndef MAGICIANPLAYER_H
#define MAGICIANPLAYER_H
#include"NovicePlayer.h"
#include"BaseMonster.h"

class MagicianPlayer :public NovicePlayer
{
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	virtual void setLevel(int);
	virtual void specialSkill(BaseMonster*);
	virtual string serialize();
	static NovicePlayer* unserialize(string);
};
#endif