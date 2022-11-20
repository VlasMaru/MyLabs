
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class circle
{
private:
	double m_pi = M_PI;
	double m_rad = 0;
	long double  m_area = 0;

public:
	circle(double rad)
	{
		m_rad = rad;
		m_area = CircArea(rad);
	}

	~circle()
	{
		std::cout << "Destructor Wins!";
	}

	bool SetRad(double rad)
	{
		if (rad <= 0)
		{
			std::cout << "Rad Error!" << std::endl;
			return false;
		}
		m_rad = rad;
	}

	double CircArea(double rad)
	{
		if (SetRad(rad))
		{
			m_area = (m_rad * m_rad) * m_pi;
			return m_area;
		}
		return m_area;

	}
	void ShowArea()
	{
		if (m_area == 0) { std::cout << "The circle does not exist!" << std::endl; }
		else { std::cout << m_area << std::endl; };
	}
};

int main()
{
	double x;
	std::cin >> x;
	circle circ1(x);
	circ1.ShowArea();
}

