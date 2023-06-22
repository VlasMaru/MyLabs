#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>

class KinematicSolver

{
private:
    int m_L1, m_L2;
    float m_rad_v;
    float m_alpha, m_beta,m_sup_gam, m_sup_A, m_sup_B;
    int m_x, m_y = 0;
    int error_flag = 0;
public:

    KinematicSolver(int l1, int l2) : m_L1(l1), m_L2(l2)
    {
        if ((l1 <= 0) or (l2 <= 0))
        {
            std::cout << "SIZE ERROR!" << std::endl;
            error_flag++;
        }
    }

    void SetNewLinks(int l1, int l2)
    {
        if (error_flag == 0)
        {
            if ((l1 <= 0) or (l2 <= 0))
            {
                std::cout << "SIZE ERROR!" << std::endl;
            }
            else if ((l1 > 0) and (l2 > 0))
            {
                m_L1 = l1;
                m_L2 = l2;
            }
        }
        if (error_flag < 0)
        {
            std::cout << "SIZE ERROR!" << std::endl;
        }
    }

    
    void Solve(int x, int y)
    {
        if (m_L1 + m_L2 < sqrt(pow(x, 2) + pow(y, 2))) { error_flag++; }
        if (error_flag > 0)
        {
            std::cout << "SIZE ERROR!" << std::endl;
        }

        if (error_flag == 0)
        {
            m_rad_v = sqrt(pow(x, 2) + pow(y, 2)); //

            m_sup_gam = acos( x / m_rad_v); //
            m_sup_A = acos((pow(m_L1, 2) + pow(m_rad_v, 2) - pow(m_L2, 2)) / (2 * m_rad_v * m_L1)); //

            m_sup_B = acos((pow(m_L1, 2) + pow(m_L2, 2) - pow(m_rad_v, 2)) / (2 * m_L2 * m_L1)); //

            m_beta = M_PI - m_sup_B; 
            
            m_alpha = m_sup_gam - m_sup_A;
            





            m_alpha = (m_alpha * 180) / M_PI;
            m_beta = (m_beta * 180) / M_PI;

        }
    }




    void ShowCur()
    {
        std::cout << "Link 1: " << m_L1 << "    Link 2: " << m_L2 << std::endl;
        std::cout << "Alpha: " << m_alpha << "    Beta: " << m_beta << std::endl;
    }



};



int main()
{
    KinematicSolver sa(1,1);
    sa.Solve(0, 1);
    sa.ShowCur();
}

/*void Solve(int x, int y)
    {
        if (error_flag < 0)
        {
            std::cout << "SIZE ERROR!" << std::endl;
        }

        if (error_flag == 0)
        {
            m_rad_v = sqrt(pow(x, 2) + pow(y, 2));
            m_sup_1_a = acos(x / m_rad_v);
            m_sup_2_a = acos((pow(m_L1, 2) + pow(m_rad_v, 2) - pow(m_L2, 2)) / (2*m_rad_v*m_L1));
            if (m_sup_1_a >= m_sup_2_a)
            {
                m_alpha = m_sup_1_a - m_sup_2_a;
                m_beta = M_PI - acos((pow(m_L1, 2) + pow(m_L2, 2) - pow(m_rad_v, 2)) / (2 * m_rad_v * m_L1));
            }
            if (m_sup_1_a < m_sup_2_a)
            {
                m_alpha = m_sup_1_a + m_sup_2_a;
                m_beta = -(M_PI - acos((pow(m_L1, 2) + pow(m_L2, 2) - pow(m_rad_v, 2)) / (2 * m_rad_v * m_L1)));
            }
            m_alpha = (m_alpha * 180) / M_PI;
            m_beta = (m_beta * 180) / M_PI;

        }
    }*/
