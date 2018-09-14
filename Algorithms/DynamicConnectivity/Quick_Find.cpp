#include <iostream>

// initialize N
// Union N
// find 1
// defect: Union too expensive
class QuickFindUF
{
private:
    int* m_id;
    int length;

public:
    QuickFindUF(int N)
        :length(N)
    {
        m_id = new int[N];
        for (int i = 0; i < N; i++)
        {
            m_id[i] = i;
        }
    }

    bool connected(int p, int q)
    {
        return m_id[p] == m_id[q];
    }

    void Union(int p, int q)
    {
        int pid = m_id[p];
        int qid = m_id[q];
        for (int i = 0; i < length; i++)
        {
            if (m_id[i] == pid)
            {
                m_id[i] = qid;
            }
        }
    }
};

int main() 
{
    
}


