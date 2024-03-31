class MinStack
{
public:
    stack<int> o;
    stack<int> v;
    int min;
    MinStack()
    {
    }

    void push(int val)
    {
        if (v.size() == 0)
        {
            min = val;
            v.push(val);
            o.push(val);
        }
        else
        {
            int min = o.top();
            if (min < val)
            {
                o.push(min);
            }
            else
            {
                o.push(val);
            }
            v.push(val);
        }
    }

    void pop()
    {
        v.pop();
        o.pop();
    }

    int top()
    {
        return v.top();
    }

    int getMin()
    {
        return o.top();
    }
};