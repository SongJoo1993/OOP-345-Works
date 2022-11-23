/*
  File Name: Autoshop.h
  Name: Song Joo
  Seneca email: sjoo6@myseneca.ca
  Student ID: 171 443 211
  Date: Nov-22-2022
  I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"
#include <memory>

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		size_t i{}, j{};
		string errMsg = "Unmatched Salary with the given SIN number";

		for (i = 0; i < emp.size(); i++)
		{
			for (j = 0; j < sal.size(); j++)
			{
				if (activeEmp.sinValidation(emp[i].id) || activeEmp.sinValidation(sal[j].id))
				{
					if (emp[i].id == sal[j].id)
					{
						EmployeeWage* newEmp = new EmployeeWage(emp[i].name, sal[j].salary);
						try
						{
							newEmp->rangeValidator();
							activeEmp += newEmp;
							delete newEmp;
							newEmp = nullptr;
						}
						catch (const std::string error)
						{
							delete newEmp;
							newEmp = nullptr;
							throw error;
						}
					}
				}
				else {
					throw errMsg;
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		size_t i{}, j{};
		string errMsg = "Unmatched Salary with the given SIN number";
		for (i = 0; i < emp.size(); i++)
		{
			for (j = 0; j < sal.size(); j++)
			{
				if (activeEmp.sinValidation(emp[i].id) || activeEmp.sinValidation(sal[j].id))
				{
					if (emp[i].id == sal[j].id)
					{
						std::unique_ptr<EmployeeWage> test(new EmployeeWage(emp[i].name, sal[j].salary));
						test->rangeValidator();
						activeEmp += std::move(test);
					}
				}
				else
					throw errMsg;
			}
		}
		return activeEmp;
	}
}