/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-25-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TENNISLOG_H_
#define SDDS_TENNISLOG_H_

#include<string>
using namespace std;

namespace sdds 
{
	struct TennisMatch {
		string t_tournament_id{};
		string t_tournament_name{};
		unsigned t_match_id{};
		string t_winner{};
		string t_loser{};
	};

	class TennisLog {
		TennisMatch* t_matches{};
		unsigned counter{};
	public:
		TennisLog() {};
		TennisLog(const char* fileName);
		void addMatch(struct TennisMatch obj);
		TennisLog findMatches(const char* playerName);
		TennisMatch operator[](size_t);
		operator size_t();
		
		TennisLog(const TennisLog& T);
		TennisLog(TennisLog&& T);
		TennisLog& operator=(TennisLog&& T);
		TennisLog& operator=(const TennisLog& T);

		~TennisLog();
	};

	ostream& operator<<(std::ostream& os, TennisMatch);
}


#endif // !
