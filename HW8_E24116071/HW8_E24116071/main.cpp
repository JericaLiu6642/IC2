#include "NovicePlayer.h"
#include "OrcPlayer.h"
#include "KnightPlayer.h"
#include "MagicianPlayer.h"
#include "BaseMonster.h"
#include "GoblinMonster.h"
#include "ZombieMonster.h"
#include "JWMonster.h"
#include<iostream>
using namespace std;

//Operator overloading ��X player �Ҧ��Ѽ�
ostream& operator<<(ostream& os, const NovicePlayer& player) {
	os << "name:    " << player.getname() << endl;
	os << "level:   " << player.getLevel() << endl;
	os << "attack:  " << player.getAttack() << endl;
	os << "defense: " << player.getDefense() << endl;
	os << "hp:      " << player.gethp() << " / " << player.getMaxHP() << endl;
	os << "mp:      " << player.getmp() << " / " << player.getMaxMP() << endl;
	os << "exp:     " << player.getexp() << " / " << player.getLvupExp() << endl;
	os << "money:   " << player.getmoney() << endl;
	return os;
}

//Operator overloading ��X monster �Ҧ��Ѽ�
ostream& operator<<(ostream& os, const BaseMonster& monster) {
	os << "name:    " << monster.name << endl;
	os << "attack:  " << monster.attack << endl;
	os << "defense: " << monster.defense << endl;
	os << "hp:      " << monster.getHP() << " / " << monster.max_hp << endl;
	os << "mp:      " << monster.getMP() << " / " << monster.max_mp << endl;
	os << "exp:     " << monster.exp << endl;
	os << "money:   " << monster.money << endl;
	return os;
}


#include <vector>

int main() {
	/*NovicePlayer player_novice(8, "novice");
	string str_save_novice;						 
	str_save_novice = player_novice.serialize();
	NovicePlayer* ptr_player_novice_resume;								
	ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice);*/
	// NovicePlayer
	cout << ">>> NovicePlayer player_novice(8, \"novice\")" << endl << endl;
	NovicePlayer player_novice(8, "novice");				//����� player
	player_novice.sethp(player_novice.gethp() - 1);
	cout << player_novice << endl;							//��X player

	cout << ">>> str_save_novice = player_novice.serialize()" << endl << endl;
	string str_save_novice;						 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_novice = player_novice.serialize(); //�N player ��U�����A�s�� string
	cout << str_save_novice << endl << endl;	 //��X str_save

	cout << ">>> ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice)" << endl << endl;
	NovicePlayer* ptr_player_novice_resume;								   //�ŧi type �� NovicePlayer* �� pointer �ӱ� unserialize ����X
	ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice); //�N str_save Ū�� ptr_player_resume
	cout << *ptr_player_novice_resume << endl;							   //��X *ptr_player_resume

	// OrcPlayer
	cout << ">>> OrcPlayer player_orc(8, \"orc\")" << endl << endl;
	OrcPlayer player_orc(8, "orc");				//����� player
	player_orc.sethp(player_orc.gethp() - 1);
	cout << player_orc << endl;							//��X player

	cout << ">>> str_save_orc = player_orc.serialize()" << endl << endl;
	string str_save_orc;						 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_orc = player_orc.serialize(); //�N player ��U�����A�s�� string
	cout << str_save_orc << endl << endl;	 //��X str_save

	cout << ">>> ptr_player_orc_resume = OrcPlayer::unserialize(str_save_orc)" << endl << endl;
	NovicePlayer* ptr_player_orc_resume;						  //�ŧi type �� NovicePlayer* �� pointer �ӱ� unserialize ����X
	ptr_player_orc_resume = OrcPlayer::unserialize(str_save_orc); //�N str_save Ū�� ptr_player_resume
	cout << *ptr_player_orc_resume << endl;						  //��X *ptr_player_resume

	// KnightPlayer
	cout << ">>> KnightPlayer player_knight(8, \"knight\")" << endl << endl;
	KnightPlayer player_knight(8, "knight");				//����� player
	player_knight.sethp(player_knight.gethp() - 1);
	cout << player_knight << endl;							//��X player

	cout << ">>> str_save_knight = player_knight.serialize()" << endl << endl;
	string str_save_knight;						 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_knight = player_knight.serialize(); //�N player ��U�����A�s�� string
	cout << str_save_knight << endl << endl;	 //��X str_save

	cout << ">>> ptr_player_knight_resume = KnightPlayer::unserialize(str_save_knight)" << endl << endl;
	NovicePlayer* ptr_player_knight_resume;								   //�ŧi type �� NovicePlayer* �� pointer �ӱ� unserialize ����X
	ptr_player_knight_resume = KnightPlayer::unserialize(str_save_knight); //�N str_save Ū�� ptr_player_resume
	cout << *ptr_player_knight_resume << endl;							   //��X *ptr_player_resume

	cout << ">>> ptr_player_knight_resume->setHP(1)" << endl << endl;
	ptr_player_knight_resume->sethp(1);		  //�]�w hp = 1
	cout << *ptr_player_knight_resume << endl; //��X player_resume

	cout << ">>> ptr_player_knight_resume->specialSkill()" << endl << endl;
	ptr_player_knight_resume->specialSkill();  //�ϥ� specialSkill �N mp ��Ʀ� hp
	cout << *ptr_player_knight_resume << endl; //��X player_resume
	
	// MagicianPlayer
	cout << ">>> MagicianPlayer player_magician(8, \"magician\")" << endl << endl;
	MagicianPlayer player_magician(8, "magician"); //����� player
	player_magician.sethp(player_magician.gethp() - 1);
	cout << player_magician << endl;			   //��X player

	cout << ">>> str_save_magician = player_magician.serialize()" << endl << endl;
	string str_save_magician;						 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_magician = player_magician.serialize(); //�N player ��U�����A�s�� string
	cout << str_save_magician << endl << endl;		 //��X *ptr_player_resume

	cout << ">>> ptr_player_magician_resume = MagicianPlayer::unserialize(str_save_magician)" << endl << endl;
	NovicePlayer* ptr_player_magician_resume;								     //�ŧi type �� NovicePlayer* �� pointer �ӱ� unserialize ����X
	ptr_player_magician_resume = MagicianPlayer::unserialize(str_save_magician); //�N str_save Ū�� ptr_player_resume
	cout << *ptr_player_magician_resume << endl;								 //��X player_resume

	cout << ">>> ptr_player_magician_resume->setMP(1)" << endl << endl;
	ptr_player_magician_resume->setmp(1);		 //�]�w mp = 1
	cout << *ptr_player_magician_resume << endl; //��X player_resume

	cout << ">>> ptr_player_magician_resume->specialSkill()" << endl << endl;
	ptr_player_magician_resume->specialSkill();	 //�ϥ� specialSkill �N hp ��Ʀ� mp
	cout << *ptr_player_magician_resume << endl; //��X player_resume
	

	cout << ">>> BaseMonster::getInstanceCount()" << endl << endl;
	cout << BaseMonster::getInstanceCount() << endl << endl;

	cout << ">>> GoblinMonster goblin" << endl << endl;
	GoblinMonster goblin;
	goblin.setHP(goblin.getHP() - 1);
	cout << goblin << endl;

	cout << ">>> str_save_goblin = goblin.serialize()" << endl << endl;
	string str_save_goblin;					 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_goblin = goblin.serialize();	 //�N monster ��U�����A�s�� string
	cout << str_save_goblin << endl << endl; //��X str_save

	cout << ">>> ptr_goblin_resume = GoblinMonster::unserialize(str_save_goblin)" << endl << endl;
	BaseMonster* ptr_goblin_resume;									 //�ŧi type �� BaseMonster* �� pointer �ӱ� unserialize ����X
	ptr_goblin_resume = GoblinMonster::unserialize(str_save_goblin); //�N str_save Ū�� ptr_monster_resume
	cout << *ptr_goblin_resume << endl;								 //��X *ptr_monster_resume

	cout << ">>> ZombieMonster zombie" << endl << endl;
	ZombieMonster zombie;
	zombie.setHP(zombie.getHP() - 1);
	cout << zombie << endl;

	cout << ">>> str_save_zombie = zombie.serialize()" << endl << endl;
	string str_save_zombie;					 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_zombie = zombie.serialize();	 //�N monster ��U�����A�s�� string
	cout << str_save_zombie << endl << endl; //��X str_save

	cout << ">>> ptr_zombie_resume = ZombieMonster::unserialize(str_save_zombie)" << endl << endl;
	BaseMonster* ptr_zombie_resume;									 //�ŧi type �� BaseMonster* �� pointer �ӱ� unserialize ����X
	ptr_zombie_resume = ZombieMonster::unserialize(str_save_zombie); //�N str_save Ū�� ptr_monster_resume
	cout << *ptr_zombie_resume << endl;								 //��X *ptr_monster_resume

	cout << ">>> JWMonster JW" << endl << endl;
	JWMonster JW;
	JW.setHP(JW.getHP() - 1);
	cout << JW << endl;

	cout << ">>> str_save_JW = JW.serialize()" << endl << endl;
	string str_save_JW;					 //�ŧi�@ string �Ψӱ� serialize() ����X
	str_save_JW = JW.serialize();		 //�N monster ��U�����A�s�� string
	cout << str_save_JW << endl << endl; //��X str_save

	cout << ">>> ptr_JW_resume = JWMonster::unserialize(str_save_JW)" << endl << endl;
	BaseMonster* ptr_JW_resume;							 //�ŧi type �� BaseMonster* �� pointer �ӱ� unserialize ����X
	ptr_JW_resume = JWMonster::unserialize(str_save_JW); //�N str_save Ū�� ptr_monster_resume
	cout << *ptr_JW_resume << endl;						 //��X *ptr_monster_resume

	cout << ">>> BaseMonster::getInstanceCount()" << endl << endl;
	cout << BaseMonster::getInstanceCount() << endl;


	return 0;
}