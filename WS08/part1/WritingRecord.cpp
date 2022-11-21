#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

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
						catch (...)
						{
							delete newEmp;
							newEmp = nullptr;
							throw;
						}
					}
				}
				else
					throw errMsg;
			}
		}
		return activeEmp;
	}
}