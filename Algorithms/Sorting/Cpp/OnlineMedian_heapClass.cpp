// a simple solution for finding the median from a input stream.
/*
example:
print 15 if the sequence is (15)
print 10 if the sequence is (15, 10)
print 1 if the sequence is (15, 10, 1)
print 20 if the sequence is (15, 10, 1, 20)
print 30 if the sequence is (15, 10, 1, 20, 30)
*/
#include <cstdlib>
#include <vector>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

inline void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int Average(const int& a, const int& b)
{
    return (a + b) / 2;
}

class Heap
{
protected:
    vector<int> A;

    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        if (i < 0)
        {
            return -1;
        }

        return (i - 1) / 2;
    }
public:
    // constructors
    Heap()
    {}

    Heap(vector<int> array)
        :A(array)
    {}
    // destructor
    ~Heap()
    {}
    // Virtual Functions
    virtual void Fix_down(int k) = 0;
    virtual void Insert(int x) = 0;

    int size() const
    {
        return A.size();
    }
    int getTop() const
    {
        return A[0];
    }
    int ExtractTop()
    {
        int res = A[0];
        A[0] = A[A.size() - 1];
        A[A.size() - 1] = res;
        A.pop_back();
        if(!A.empty())
            Fix_down(0);
        return res;
    }
    void Heapify()
    {
        if (parent(A.size() - 1) > 0)
        {
            for (int i = parent(A.size() - 1); i >= 0; i--)
            {
                Fix_down(i);
            }
        }
    }
};

class MaxHeap : public Heap
{
private:
public:
    // constructor
    MaxHeap()
        : Heap()
    {
    }

    MaxHeap(vector<int> array)
        : Heap(array)
    {
    }

    // destructor
    ~MaxHeap() {}

    void Fix_down(int k)
    {
        while (2 * k + 1 <= A.size() - 1)
        {
            int j = left(k);
            if (j < A.size() - 1 && A[j + 1] > A[j])
                j++;
            if (A[k] >= A[j]) break;
            swap(A[j], A[k]);
            k = j;
        }
    }

    void Insert(int x)
    {
        A.push_back(x);

        int k = A.size() - 1;
        while (parent(k) >= 0 && A[parent(k)] < A[k])
        {
            swap(A[k], A[parent(k)]);
            k = parent(k);
        }
    }
};

class MinHeap : public Heap
{
private:
public:
    // constructor
    MinHeap()
        :Heap()
    {
    }

    MinHeap(vector<int> array)
        :Heap(array)
    {
    }

    // destructor
    ~MinHeap() {}

    void Fix_down(int k)
    {
        while (2 * k + 1 <= A.size() - 1)
        {
            int j = left(k);
            if (j < A.size() - 1 && A[j + 1] < A[j])
                j++;
            if (A[k] <= A[j]) break;
            swap(A[j], A[k]);
            k = j;
        }
    }
    void Insert(int x)
    {
        A.push_back(x);

        int k = A.size() - 1;
        while (parent(k) >= 0 && A[parent(k)] > A[k])
        {
            swap(A[k], A[parent(k)]);
            k = parent(k);
        }
    }
};


class OnlineMedian {
private:
    Heap * leftHeap;
    Heap* rightHeap;
    int m_median;
public:
    OnlineMedian()
        :m_median(0)
    {
        leftHeap = new MaxHeap();
        rightHeap = new MinHeap();
    }

    ~OnlineMedian()
    {
        delete leftHeap;
        delete rightHeap;
    }

    void insert(int x) {
        if (leftHeap->size() > rightHeap->size()) // l.size > r.size
        {
            if (x <= m_median)
            {
                rightHeap->Insert(leftHeap->ExtractTop());
                leftHeap->Insert(x);
            }
            else
            {
                rightHeap->Insert(x);
            }
            // m = the average
            m_median = leftHeap->getTop();
        }
        else if (leftHeap->size() == rightHeap->size()) // l.size = r.size
        {
            // when both heaps are empty
            if (leftHeap->size() == 0)
            {
                leftHeap->Insert(x);
                m_median = leftHeap->getTop();
            }
            else// heap is not empty
            {
                if (x <= m_median)
                {
                    leftHeap->Insert(x);
                    m_median = leftHeap->getTop();
                }
                else
                {
                    rightHeap->Insert(x);
                    m_median = rightHeap->getTop();
                }
            }
        }
        else // l.size < r.size
        {
            if (x <= m_median)
            {
                leftHeap->Insert(x);
            }
            else
            {
                leftHeap->Insert(rightHeap->ExtractTop());
                rightHeap->Insert(x);
            }
            // m = the average
            m_median = leftHeap->getTop();
        }
    }

    int getMedian() {
        return m_median;
    }
};

int main() {
    string line;
    OnlineMedian med = OnlineMedian();

    while (true) {
        getline(cin, line);
        if (cin.eof())
            break;
        int a = atoi(line.c_str());
        med.insert(a);
        cout << "reading: " << a << endl;
        cout << "median so far: " << med.getMedian() << endl;
    };
}


