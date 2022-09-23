#include<iostream>
#include <fstream>
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
			std::cout << "Loser";
			std::cout << " : ";
			std::cout.width(30);
			std::cout.fill('*');
			std::cout.setf(std::ios::left);
			std::cout << t_loser << std::endl;
			std::cout.unsetf(std::ios::left);
		}
		return os;
	}

	// TennisLog Member Functions
	/*static int counter = 0;*/

	TennisLog::TennisLog(const char* fileName)
	{
		std::ifstream ifs (fileName);
		string temp{};
		int i = 0;
	
		while (getline(ifs,temp)) {
			if (ifs.good()) {
				counter++;
			}
		}

		
		t_matches = new TennisMatch[--counter];
		ifs.clear();
		ifs.seekg(i);

		while (i < counter)
		{
			if (i == 0) getline(ifs, temp);

			if (ifs.good()) {
				getline(ifs, t_matches[i].t_tournament_id, ',');
				getline(ifs, t_matches[i].t_tournament_name, ',');
				ifs >> t_matches[i].t_match_id;
				ifs.ignore();
				getline(ifs, t_matches[i].t_winner, ',');
				getline(ifs, t_matches[i++].t_loser);
			}
		}

		std::cout << counter << std::endl;

		ifs.close();
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