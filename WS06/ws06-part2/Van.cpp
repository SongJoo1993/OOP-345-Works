/*
  File Name: Van.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-06-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Van.h"

namespace sdds {
	Van::Van(std::istream& istr)
	{
		std::string condition{};
		char type {};
		char purpose{};
		std::string comma{};
		int position{};

		if (istr.good()) {
			position = istr.tellg();
			position -= 2;
			istr.seekg(position);
			std::getline(istr, comma, ',');

			std::getline(istr, v_maker, ',');
			trim(v_maker);
			
			istr >> type;
			if (type == 'p') {
				v_type = pickup;
			}
			else if (type == 'm') {
				v_type = minibus;
			}
			else if (type == 'c') {
				v_type = camper;
			}
			else
			{
				throw "Invalid record!";
			}
			istr.ignore();

			istr >> purpose;
			if (purpose == 'd') {
				v_purpose = delivery;
			}
			else if (purpose == 'p') {
				v_purpose = passenger;
			}
			else if (purpose == 'c') {
				v_purpose = camping;
			}
			else
			{
				throw "Invalid record!";
			}
			istr.ignore();
			
			std::getline(istr, condition, ',');
			trim(condition);
			if (condition == "n" || condition.empty()) {
				v_conditions = newVan;
			}
			else if (condition == "u") {
				v_conditions = usedVan;
			}
			else if (condition == "b") {
				v_conditions = brokenVan;
			}
			else
			{
				throw "Invalid record!";
			}
			istr.ignore();
			
			istr >> v_topSpeed;

			if (comma == "v" || comma == "V") {
				istr.ignore(100,'\n');
			}
			else {
				istr.ignore();
			}
		}
	}

	std::string Van::condition() const
	{
		std::string condition{};
		if (v_conditions == VanCondition::newVan) {
			condition = "new";
		}
		else if (v_conditions == VanCondition::usedVan) {
			condition = "used";
		}
		else if (v_conditions == VanCondition::brokenVan) {
			condition = "broken";
		}
		return condition;
	}

	double Van::topSpeed() const
	{
		return v_topSpeed;
	}

	std::string Van::type() const
	{
		std::string condition{};
		if (v_type == Type::pickup) {
			condition = "pickup";
		}
		else if (v_type == Type::minibus) {
			condition = "mini-bus";
		}
		else if (v_type == Type::camper) {
			condition = "camper";
		}
		return condition;
	}

	std::string Van::usage() const
	{
		std::string condition{};
		if (v_purpose == Purpose::delivery) {
			condition = "delivery";
		}
		else if (v_purpose == Purpose::passenger) {
			condition = "passenger";
		}
		else if (v_purpose == Purpose::camping) {
			condition = "camping";
		}
		return condition;
	}

	void Van::display(std::ostream& ostr) const
	{
		ostr << "| ";
		ostr.width(8);
		ostr << v_maker;
		ostr << " | ";
		ostr.setf(std::ios::left);
		ostr.width(12);
		ostr << type();
		ostr << " | ";
		ostr.width(12);
		ostr << usage();
		ostr << " | ";
		ostr.width(6);
		ostr << condition();
		ostr.unsetf(std::ios::left);
		ostr << " | ";
		ostr.width(6);
		ostr.setf(std::ios::fixed);
		ostr.precision(2);
		ostr << topSpeed();
		ostr.unsetf(std::ios::fixed);
		ostr << " |";
	}
}