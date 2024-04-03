#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int studentCode = 83859;
	int taskVarCount = 20;

	cout << "Task number: " << studentCode % taskVarCount << endl;
	cout << "-------------------------------------------------------" << endl;

	struct Department
	{

		int departmentNo;
		string departmentName;
		int patientCount;

	};

	const int maxDepartmentCount = 5;
	Department arr[maxDepartmentCount];
	int numDepartments = 0;

	char addDepartment;
	do
	{
		if (numDepartments < maxDepartmentCount)
		{
			Department newDept;
			cout << "Enter department number: ";
			cin >> newDept.departmentNo;
			cout << "Enter department name: ";
			cin.ignore();
			getline(cin, newDept.departmentName);
			cout << "Enter patient count: ";
			cin >> newDept.patientCount;

			arr[numDepartments++] = newDept;

			cout << endl << "Type 'Y' if you want to add more departments, or any other key to see the information about all departments: ";
			cin >> addDepartment;
			cout << endl;
		}
		else
		{
			cout << "You can't add more departments" << endl;
			break;
		}

	} while (addDepartment == 'Y' || addDepartment == 'y');

	cout << "Information about all departments: " << endl << endl;
	for (int i = 0; i < numDepartments; ++i)
	{
		cout << "Department " << (i + 1) << endl;
		cout << "Department number: " << arr[i].departmentNo << endl;
		cout << "Department name: " << arr[i].departmentName << endl;
		cout << "Patient count: " << arr[i].patientCount << endl;
		cout << "-------------------------------------------------------" << endl;
	}

	int selectedDepartmentNo = 0;
	bool departmentFound = false;

	do 
	{
		cout << "Enter the department number to see the patient count: ";
		cin >> selectedDepartmentNo;

		for (int i = 0; i < numDepartments; i++) 
		{
			if (arr[i].departmentNo == selectedDepartmentNo) 
			{
				cout << "Patient count in department number " << selectedDepartmentNo << " is " << arr[i].patientCount << endl;
				departmentFound = true;
				break;
			}
		}

		if (!departmentFound) 
		{
			cout << "Department doesn't exist, please enter correct department number: " << endl;
		}
	} while (!departmentFound);


	return 0;
}