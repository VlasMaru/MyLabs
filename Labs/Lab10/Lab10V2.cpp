#include <iostream>
#include <string>
#include <vector>

class Student
{
private:
	std::string m_name = " ";
	std::string m_sname = " ";
	std::string m_lecturer = " ";
	int m_ID = 0;
public:
	Student(std::string name, std::string sname, int ID)
	{
		m_name = name;
		m_sname = sname;
		m_ID = ID;
	};

	void StudInfo()
	{
		std::cout << m_name << " ";
		std::cout << m_sname << " ";
		std::cout << m_ID << std::endl;
	}
	int RetID()
	{
		return m_ID;
	}
	void SetName(std::string name)
	{
		m_name = name;
	}
	void SetSName(std::string sname)
	{
		m_sname = sname;
	}
	void SetID(int ID)
	{
		m_ID = ID;
	}
};

class Lecturer
{
private:
	std::string m_sname;
	int m_id;
	std::vector <Student*> m_students;
	int m_SpisStud[4];
	int m_x = 0;
public:
	Lecturer(std::string sname, int id)
	{
		m_sname = sname;
		m_id = id;
	};
	
	void addStud(Student* stud)
	{
		m_students.push_back(stud);
		m_SpisStud[m_x] = stud->RetID();
		m_x += 1;
	}
	void ShowStuds()
	{
		for (int i = 0; i < m_students.size(); i++)
		{
			std::cout << m_students[i]->RetID() << std::endl;
		}
	}
	void VpyskatLiVKabinet (int x)
	{
		for (int i = 0; i < m_students.size(); i++)
		{
			if (x == m_SpisStud[i])
			{
				std::cout << "MOI STUDENT, ZAHODI, NO DOLG ZACHTY";
				return;
			}
		}
		std::cout << "YOU ARE NA FILOLOGII, A TYT MATAN, IDI DOMOI";
	}
};

int main()
{
	Lecturer lec1("Semenov", 5);
	Student stud1("Jo", "Kokov", 1);
	Student stud2("Kok", "Jojov", 2);
	lec1.addStud(&stud1);
	lec1.ShowStuds();
	lec1.VpyskatLiVKabinet(1);
}

