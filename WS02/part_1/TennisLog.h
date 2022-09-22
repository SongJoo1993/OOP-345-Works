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
		ostream& operator<<(ostream& os);
	};

	class TennisLog {
		TennisMatch* t_matches{};
		unsigned counter{};
	public:
		TennisLog() {};
		TennisLog(const char* fileName);
		void addMatch(struct TennisMatch obj);
		TennisLog& findMatches(const char* playerName);
		TennisLog& operator[](size_t);
		operator size_t();

	};
}


#endif // !
