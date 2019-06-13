#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
//constants
#define NX_PER_DAY 5000
#define NX_PER_AP_RESET 3100
#define STAT_MAX 30000
#define HT_LVL 155
#define HT_DAMAGE 7950
#define MAX_LVL 200

//menu constants
#define ARCHER 1
#define SPEARMAN 2
#define PALADIN_OR_HERO 3
#define THEIF 4
#define MAGE 5
#define PIRATE 6
#define BEGINNER 7
#define EXIT 8
#define REPRINT_MENU 9

//**wash values**
//HP gain per AP
#define BEGINNER_AP_HP_GAIN 10
#define WARRIOR_AP_HP_GAIN 52
#define THIEF_AP_HP_GAIN 18
#define ARCHER_AP_HP_GAIN 18
#define MAGE_AP_HP_GAIN 15
#define PIRATE_AP_HP_GAIN 20
//MP lost per reset
#define BEGINNER_MP_LOSS 6
#define WARRIOR_MP_LOSS 4
#define THIEF_MP_LOSS 12
#define ARCHER_MP_LOSS 12
#define MAGE_MP_LOSS 90
#define PIRATE_MP_LOSS 16
//base MP
#define BEGINNER_BASE_MP 2
#define SPEARMAN_BASE_MP 156 
#define PALADIN_HERO_BASE_MP 56
#define THIEF_BASE_MP 148
#define ARCHER_BASE_MP 148
#define MAGE_BASE_MP 488
#define PIRATE_BASE_MP 111
//MP per level
#define BEGINNER_MP_PER_LVL 10
#define WARRIOR_MP_PER_LVL 4
#define THIEF_MP_PER_LVL 14
#define ARCHER_MP_PER_LVL 14
#define MAGE_MP_PER_LVL 22
#define PIRATE_MP_PER_LVL 18
//base HP
#define BEGINNER_BASE_HP 50
#define SPEARMAN_BASE_HP 172 
#define PALADIN_HERO_BASE_HP 472
#define THIEF_BASE_HP 378
#define ARCHER_BASE_HP 378
#define MAGE_BASE_HP 64
#define PIRATE_BASE_HP 380
//HP per level
#define BEGINNER_HP_PER_LVL 12
#define WARRIOR_HP_PER_LVL 24
#define THIEF_HP_PER_LVL 20
#define ARCHER_HP_PER_LVL 20
#define MAGE_HP_PER_LVL 10
#define PIRATE_HP_PER_LVL 22

//**declaring functions
//general functions
void printInfo();
void printMenu();
int safeReadInt();
//wash functions
void archerWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);
void beginnerWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);
void mageWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);
void thiefWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);
void paladinHeroWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);
void spearmanWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);
void pirateWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT);

int main()
{
	//mathmatical variables
	int level = 0;
	int classs = 0;
	int currentHP = 0;
	int currentMP = 0;
	int goalLevel = 0;
	int baseINT = 0;
	int gearINT = 0;
	//system variables
	int userCommand = 0;

	printInfo();
	printMenu();
	while (userCommand != EXIT)
	{
		cout << endl;
		cout << "Enter next command: (to print menu again enter 9)" << endl;
		userCommand = safeReadInt();
		if (userCommand >= ARCHER && userCommand <= BEGINNER)//all wash options
		{
			classs = userCommand;
			cout << "Enter your level: " << endl;
			level = safeReadInt();
			cout << "Enter your current HP: " << endl;
			currentHP = safeReadInt();
			cout << "Enter your current MP: " << endl;
			currentMP = safeReadInt();
			cout << "Enter your base INT: " << endl;
			baseINT = safeReadInt();
			cout << "Enter your INT gear's total INT: " << endl;
			gearINT = safeReadInt();
			cout << "Enter your level goal: " << endl;
			goalLevel = safeReadInt();
		}

		switch (userCommand)
		{
		case ARCHER:
			archerWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case SPEARMAN:
			spearmanWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case PALADIN_OR_HERO:
			paladinHeroWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case THEIF:
			thiefWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case MAGE:
			mageWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case PIRATE:
			pirateWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case BEGINNER:
			beginnerWash(level, classs, currentHP, currentMP, goalLevel, baseINT, gearINT);
			break;
		case EXIT:
			break;
		case REPRINT_MENU:
			printMenu();
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
	}

	//system("PAUSE");
	return 0;
}

int safeReadInt()
{
	int res = 0;
	cin >> res;
	cin.clear();
	cin.ignore(100, '\n');
	return res;
}


void printInfo()
{
	cout << "Welcome to BattleCat's HP wash calculator :3" << endl;
	cout << "============================================" << endl;
	cout << endl;
}

void printMenu()
{
	cout << "For archer wash enter 1" << endl;
	cout << "For spearman wash enter 2" << endl;
	cout << "For paladin/hero wash enter 3" << endl;
	cout << "For theif wash enter 4" << endl;
	cout << "For mage wash enter 5" << endl;
	cout << "For pirate wash enter 6" << endl;
	cout << "For beginner wash enter 7" << endl;
	cout << "To exit enter 8" << endl;
}

void archerWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Archer wash:" << endl;
	cout << "============" << endl << endl;

	int voteDays = 0;
	int NXWorth = 0;
	int minHP = 0;
	int minMP = 0;
	int minMPatGoal = 0;
	int MPperLevel = 0;
	int axcessMP = 0;
	int potentialApInAxcessMp = 0;
	int extraHP = 0;	

	if (level < goalLevel)
	{
		minHP = ARCHER_BASE_HP + (ARCHER_HP_PER_LVL * level);
		if (currentHP > minHP)
		{
			minHP = currentHP - minHP + ARCHER_BASE_HP + (ARCHER_HP_PER_LVL * goalLevel); //min HP at goal
		}
		minMP = ARCHER_BASE_MP + (ARCHER_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		minMPatGoal = ARCHER_BASE_MP + (ARCHER_MP_PER_LVL * goalLevel);
		MPperLevel = (baseINT + gearINT) / 10;
		axcessMP += MPperLevel * (goalLevel - level);
		potentialApInAxcessMp = axcessMP / ARCHER_MP_LOSS;
		extraHP = potentialApInAxcessMp * ARCHER_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Washing ALL your axcess MP your HP at level " << goalLevel << " will be: " << extraHP + minHP << endl;
		cout << "Your axcess mana at "<< goalLevel << " will be: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << "HP" << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
		cout << "Reseting your base INT will cost you " << (baseINT - 4) * NX_PER_AP_RESET << "NX (" << (baseINT - 4) * NX_PER_AP_RESET / NX_PER_DAY << " vote days)" << endl;
	}
	else
	{
		minHP = ARCHER_BASE_HP + (ARCHER_HP_PER_LVL * level);
		minMP = ARCHER_BASE_MP + (ARCHER_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		potentialApInAxcessMp = axcessMP / ARCHER_MP_LOSS;
		extraHP = potentialApInAxcessMp * ARCHER_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Your axcess mana is: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
	}
}

void beginnerWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Begginer wash:" << endl;
	cout << "=============" << endl << endl;
	int voteDays = 0;
	int NXWorth = 0;
	int minHP = 0;
	int minMP = 0;
	int minMPatGoal = 0;
	int MPperLevel = 0;
	int axcessMP = 0;
	int potentialApInAxcessMp = 0;
	int extraHP = 0;

	if (level < goalLevel)
	{
		minHP = BEGINNER_BASE_HP + (BEGINNER_HP_PER_LVL * level);
		if (currentHP > minHP)
		{
			minHP = currentHP - minHP + BEGINNER_BASE_HP + (BEGINNER_HP_PER_LVL * goalLevel); //min HP at goal
		}
		minMP = BEGINNER_BASE_MP + (BEGINNER_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		minMPatGoal = BEGINNER_BASE_MP + (BEGINNER_MP_PER_LVL * goalLevel);
		MPperLevel = (baseINT + gearINT) / 10;
		axcessMP += MPperLevel * (goalLevel - level);
		potentialApInAxcessMp = axcessMP / BEGINNER_MP_LOSS;
		extraHP = potentialApInAxcessMp * BEGINNER_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Washing ALL your axcess MP your HP at level " << goalLevel << " will be: " << extraHP + minHP << endl;
		cout << "Your axcess mana at " << goalLevel << " will be: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << "HP" << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
		cout << "Reseting your base INT will cost you " << (baseINT - 4) * NX_PER_AP_RESET << "NX (" << (baseINT - 4) * NX_PER_AP_RESET / NX_PER_DAY << " vote days)" << endl;
	}
}

void spearmanWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Spearman wash:" << endl;
	cout << "=============" << endl << endl;
	int voteDays = 0;
	int NXWorth = 0;
	int minHP = 0;
	int minMP = 0;
	int minMPatGoal = 0;
	int MPperLevel = 0;
	int axcessMP = 0;
	int potentialApInAxcessMp = 0;
	int extraHP = 0;

	if (level < goalLevel)
	{
		minHP = SPEARMAN_BASE_HP + (WARRIOR_HP_PER_LVL * level);
		if (currentHP > minHP)
		{
			minHP = currentHP - minHP + SPEARMAN_BASE_HP + (WARRIOR_HP_PER_LVL * goalLevel); //min HP at goal
		}
		minMP = SPEARMAN_BASE_MP + (WARRIOR_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		minMPatGoal = SPEARMAN_BASE_MP + (WARRIOR_MP_PER_LVL * goalLevel);
		MPperLevel = (baseINT + gearINT) / 10;
		axcessMP += MPperLevel * (goalLevel - level);
		potentialApInAxcessMp = axcessMP / WARRIOR_MP_LOSS;
		extraHP = potentialApInAxcessMp * WARRIOR_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Washing ALL your axcess MP your HP at level " << goalLevel << " will be: " << extraHP + minHP << endl;
		cout << "Your axcess mana at " << goalLevel << " will be: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << "HP" << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
		cout << "Reseting your base INT will cost you " << (baseINT - 4) * NX_PER_AP_RESET << "NX (" << (baseINT - 4) * NX_PER_AP_RESET / NX_PER_DAY << " vote days)" << endl;
	}
}

void paladinHeroWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Paladin/Hero wash:" << endl;
	cout << "=================" << endl << endl;
	int voteDays = 0;
	int NXWorth = 0;
	int minHP = 0;
	int minMP = 0;
	int minMPatGoal = 0;
	int MPperLevel = 0;
	int axcessMP = 0;
	int potentialApInAxcessMp = 0;
	int extraHP = 0;

	if (level < goalLevel)
	{
		minHP = PALADIN_HERO_BASE_HP + (WARRIOR_HP_PER_LVL * level);
		if (currentHP > minHP)
		{
			minHP = currentHP - minHP + PALADIN_HERO_BASE_HP + (WARRIOR_HP_PER_LVL * goalLevel); //min HP at goal
		}
		minMP = PALADIN_HERO_BASE_MP + (WARRIOR_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		minMPatGoal = PALADIN_HERO_BASE_MP + (WARRIOR_MP_PER_LVL * goalLevel);
		MPperLevel = (baseINT + gearINT) / 10;
		axcessMP += MPperLevel * (goalLevel - level);
		potentialApInAxcessMp = axcessMP / WARRIOR_MP_LOSS;
		extraHP = potentialApInAxcessMp * WARRIOR_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Washing ALL your axcess MP your HP at level " << goalLevel << " will be: " << extraHP + minHP << endl;
		cout << "Your axcess mana at " << goalLevel << " will be: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << "HP" << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
		cout << "Reseting your base INT will cost you " << (baseINT - 4) * NX_PER_AP_RESET << "NX (" << (baseINT - 4) * NX_PER_AP_RESET / NX_PER_DAY << " vote days)" << endl;
	}
}

void thiefWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Thief wash:" << endl;
	cout << "==========" << endl << endl;
	int voteDays = 0;
	int NXWorth = 0;
	int minHP = 0;
	int minMP = 0;
	int minMPatGoal = 0;
	int MPperLevel = 0;
	int axcessMP = 0;
	int potentialApInAxcessMp = 0;
	int extraHP = 0;

	if (level < goalLevel)
	{
		minHP = THIEF_BASE_HP + (THIEF_HP_PER_LVL * level);
		if (currentHP > minHP)
		{
			minHP = currentHP - minHP + THIEF_BASE_HP + (THIEF_HP_PER_LVL * goalLevel); //min HP at goal
		}
		minMP = THIEF_BASE_MP + (THIEF_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		minMPatGoal = THIEF_BASE_MP + (THIEF_MP_PER_LVL * goalLevel);
		MPperLevel = (baseINT + gearINT) / 10;
		axcessMP += MPperLevel * (goalLevel - level);
		potentialApInAxcessMp = axcessMP / THIEF_MP_LOSS;
		extraHP = potentialApInAxcessMp * THIEF_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Washing ALL your axcess MP your HP at level " << goalLevel << " will be: " << extraHP + minHP << endl;
		cout << "Your axcess mana at " << goalLevel << " will be: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << "HP" << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
		cout << "Reseting your base INT will cost you " << (baseINT - 4) * NX_PER_AP_RESET << "NX (" << (baseINT - 4) * NX_PER_AP_RESET / NX_PER_DAY << " vote days)" << endl;
	}
}

void mageWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Mage wash:" << endl;
	cout << "=========" << endl << endl;
	cout << "I don't know the math behind MP washing on mage," << endl;
	cout << "What I do know is the methood to MP wash" << endl;
	cout << "In order to MP wash you will have to equip your INT gear" << endl;
	cout << "and try to get a MW20 buff, after you done that you put" << endl;
	cout << "your fresh AP into MP, take off your INT equip, remove the MW" << endl;
	cout << "and use AP resets from your MP to INT" << endl;
}

void pirateWash(int level, int classs, int currentHP, int currentMP, int goalLevel, int baseINT, int gearINT)
{
	cout << "Pirate wash:" << endl;
	cout << "===========" << endl << endl;
	int voteDays = 0;
	int NXWorth = 0;
	int minHP = 0;
	int minMP = 0;
	int minMPatGoal = 0;
	int MPperLevel = 0;
	int axcessMP = 0;
	int potentialApInAxcessMp = 0;
	int extraHP = 0;

	if (level < goalLevel)
	{
		minHP = PIRATE_BASE_HP + (PIRATE_HP_PER_LVL * level);
		if (currentHP > minHP)
		{
			minHP = currentHP - minHP + PIRATE_BASE_HP + (PIRATE_HP_PER_LVL * goalLevel); //min HP at goal
		}
		minMP = PIRATE_BASE_MP + (PIRATE_MP_PER_LVL * level);
		axcessMP = currentMP - minMP;
		minMPatGoal = PIRATE_BASE_MP + (PIRATE_MP_PER_LVL * goalLevel);
		MPperLevel = (baseINT + gearINT) / 10;
		axcessMP += MPperLevel * (goalLevel - level);
		potentialApInAxcessMp = axcessMP / PIRATE_MP_LOSS;
		extraHP = potentialApInAxcessMp * PIRATE_AP_HP_GAIN;
		NXWorth = potentialApInAxcessMp * NX_PER_AP_RESET;
		if (NXWorth % NX_PER_DAY == 0)
		{
			voteDays = NXWorth / NX_PER_DAY;
		}
		else
		{
			voteDays = NXWorth / NX_PER_DAY + 1;
		}
		cout << "Washing ALL your axcess MP your HP at level " << goalLevel << " will be: " << extraHP + minHP << endl;
		cout << "Your axcess mana at " << goalLevel << " will be: " << axcessMP << endl;
		cout << "You can wash that mana for: " << extraHP << "HP" << endl;
		cout << "It will cost you " << potentialApInAxcessMp << " AP resets which is " << NXWorth << "NX (" << voteDays << " vote days)" << endl;
		cout << "Reseting your base INT will cost you " << (baseINT - 4) * NX_PER_AP_RESET << "NX (" << (baseINT - 4) * NX_PER_AP_RESET / NX_PER_DAY << " vote days)" << endl;
	}
}