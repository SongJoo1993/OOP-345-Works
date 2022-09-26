/*
  File Name: carads.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Sept-25-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <string.h>
#include"TennisLog.h"


namespace sdds {

	// TennisMatch Member Functions

	ostream& operator<<(std::ostream& os, TennisMatch T)
	{
		if (T.t_tournament_id.empty())
		{
			os << "Empty Match";
		}
		else
		{
			// TOURNEY ID
			os.width(20);
			os.fill('.');
			os << "Tourney ID";
			os << " : ";
			os.width(30);
			os.fill('.');
			os.setf(std::ios::left);
			os << T.t_tournament_id << std::endl;
			std::cout.unsetf(std::ios::left);
			// MATCH ID
			os.width(20);
			os.fill('.');
			os << "Match ID";
			os << " : ";
			os.width(30);
			os.fill('.');
			os.setf(std::ios::left);
			os << T.t_match_id << std::endl;
			os.unsetf(std::ios::left);
			// TOURNEY
			os.width(20);
			os.fill('.');
			os << "Tourney";
			os << " : ";
			os.width(30);
			os.fill('.');
			os.setf(std::ios::left);
			os << T.t_tournament_name << std::endl;
			os.unsetf(std::ios::left);
			// WINNER
			os.width(20);
			os.fill('.');
			os << "Winner";
			os << " : ";
			os.width(30);
			os.fill('.');
			os.setf(std::ios::left);
			os << T.t_winner << std::endl;
			os.unsetf(std::ios::left);
			// LOSER
			os.width(20);
			os.fill('.');
			os << "Loser";
			os << " : ";
			os.width(30);
			os.fill('.');
			os.setf(std::ios::left);
			os << T.t_loser << std::endl;
			os.unsetf(std::ios::left);
		}
		return os;
	}

	// TennisLog Member Functions

	TennisLog::TennisLog(const char* fileName)
	{
		std::ifstream ifs (fileName);
		string temp{};
		unsigned i = 0;

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

		ifs.close();
	}

	void TennisLog::addMatch(TennisMatch obj)
	{
		unsigned i{};
		TennisMatch* temp = nullptr;
		temp = new TennisMatch[counter+1];

		for (i = 0; i < counter; i++) 
		{
			temp[i] = t_matches[i];
		}
		temp[counter++] = obj;
		delete[] t_matches;
		t_matches = temp;
	}

	TennisLog TennisLog::findMatches(const char* playerName)
	{
		TennisLog matches{};

		for (unsigned i = 0; i < counter; i++)
		{
			if (t_matches[i].t_loser == playerName || t_matches[i].t_winner == playerName)
			{
				matches.addMatch(t_matches[i]);
			}
		}

		return matches;
	}

	TennisMatch TennisLog::operator[](size_t s)
	{
		TennisMatch temp{};


		if (t_matches != nullptr && !t_matches[s].t_tournament_id.empty()) {
			temp.t_tournament_id = t_matches[s].t_tournament_id;
			temp.t_tournament_name = t_matches[s].t_tournament_name;
			temp.t_match_id = t_matches[s].t_match_id;
			temp.t_winner = t_matches[s].t_winner;
			temp.t_loser = t_matches[s].t_loser;
		}

		return temp;

	}

	TennisLog::operator size_t()
	{
		return counter;
	}

	TennisLog::TennisLog(const TennisLog& T)
	{
		operator=(T);
	}

	TennisLog::TennisLog(TennisLog&& T)
	{
		operator=(move(T));
	}

	TennisLog& TennisLog::operator=(TennisLog&& T)
	{
		if (this != &T)
		{
			counter = T.counter;
			T.counter = 0;
			delete[] t_matches;
			t_matches = T.t_matches;
			T.t_matches = nullptr;
		}
		return *this;
	}

	TennisLog& TennisLog::operator=(const TennisLog& T)
	{
		if (this != &T)
		{
			counter = T.counter;
			delete[] t_matches;
			t_matches = new TennisMatch[T.counter];

			for (unsigned i = 0; i < T.counter; i++)
			{
				t_matches[i] = T.t_matches[i];
			}
		}
		return *this;
	}

	TennisLog::~TennisLog()
	{
		delete[] t_matches;
	}
}