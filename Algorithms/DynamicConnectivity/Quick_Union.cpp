#include <iostream>

/*
// defect: trees can get too tall.(Find too expensive)
class QuickUnionUF
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

    int root(int i)
    {
        while (i != m_id[i])
            i = m_id[i];
        return i;
    }

    bool connected(int p, int q)
    {
        return root(p) == root(q)
    }

    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        m_id[i] = j;
    }
};

// Improvement 1 - weighted
class QuickUnionUF
{
private:
    int* m_id;
    int length;
    int* sz;

public:
    QuickFindUF(int N)
        :length(N)
    {
        m_id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++)
        {
            m_id[i] = i;
            sz[i] = 1;
        }
    }

    int root(int i)
    {
        while (i != m_id[i])
            i = m_id[i];
        return i;
    }

    bool connected(int p, int q)
    {
        return root(p) == root(q)
    }

    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i == j) return;
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
};
*/

// Improvement 2 - compression
class QuickUnionUF
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

    int root(int i)
    {
        while (i != m_id[i])
        {
            m_id[i] = m_id[m_id[i]];
            i = m_id[i];
        }
        return i;
    }

    bool connected(int p, int q)
    {
        return root(p) == root(q)
    }

    void Union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        m_id[i] = j;
    }
};