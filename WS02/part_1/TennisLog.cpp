#include<iostream>
#include"TennisLog.h"


namespace sdds {

	// TennisMatch Member Functions
	ostream& TennisMatch::operator<<(ostream& os)
	{
		if (t_tournament_id.empty()) 
		{
			std::cout << "Empty Match" << std::endl;
		}
		else
		{
			// TOURNEY ID
			std::cout.width(20);
			std::cout.fill('*');
			std::cout << "Tourney ID";
			std::cout << " : ";
			std::cout.width(30);
			std::cout.fill('*');
			std::cout.setf(std::ios::left);
			std::cout << t_tournament_id << std::endl;
			std::cout.unsetf(std::ios::left);
			// MATCH ID
			std::cout.width(20);
			std::cout.fill('*');
			std::cout << "Match ID";
			std::cout << " : ";
			std::cout.width(30);
			std::cout.fill('*');
			std::cout.setf(std::ios::left);
			std::cout << t_match_id << std::endl;
			std::cout.unsetf(std::ios::left);
			// TOURNEY
			std::cout.width(20);
			std::cout.fill('*');
			std::cout << "Tourney";
			std::cout << " : ";
			std::cout.width(30);
			std::cout.fill('*');
			std::cout.setf(std::ios::left);
			std::cout << t_tournament_name << std::endl;
			std::cout.unsetf(std::ios::left);
			// WINNER
			std::cout.width(20);
			std::cout.fill('*');
			std::cout << "Winner";
			std::cout << " : "; 
			std::cout.width(30);
			std::cout.fill('*');
			std::cout.setf(std::ios::left);
			std::cout << t_winner << std::endl;
			std::cout.unsetf(std::ios::left);
			// LOSER
			std::cout.width(20);
			std::cout.fill('*');
			std::cout << "Loser : " << std::endl;
			std::cout.setf(std::ios::left);
			std::cout << t_loser << std::endl;
		}
		return os;
	}

	// TennisLog Member Functions
	static int counter = 0;

	TennisLog::TennisLog(const char* fileName)
	{
	}
	void TennisLog::addMatch(TennisMatch obj)
	{
	}
	TennisLog& TennisLog::findMatches(const char* playerName)
	{
		return *this;
	}
	TennisLog& TennisLog::operator[](size_t)
	{
		return *this;
	}
	TennisLog::operator size_t()
	{
		return 0;
	}
}