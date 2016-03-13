#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <c++/bits/stl_algo.h>

using std::cout;
using std::endl;

int fibIter(int start = 0, int secStart = 1, int count = 0)
{
    cout<<"params by order "<<start<<secStart<<count<<endl;
    if(start < 0 || secStart < 0 || count < 0)
    {
        return 0;
    }

    int fibResult = 0;
    for(int i=0; i < count; i++)
    {
        fibResult = start + secStart;
        start = secStart;
        secStart = fibResult;
    }

    return fibResult;
}

int fibRec(int num)
{
    if(num < 0 )
    {return -1;}
    else if (num > 1)
    {return  fibRec(num - 1) + fibRec(num - 2);}
    else if (num == 0)
    {return 0;}
    else if(num == 1)
    {
        return 1;
    }

    return 0;
}

class Connection
{
public:
    Connection(bool activeState = false, int priorityS = 0):
    priority(priorityS),active(activeState)
            {}
    ~Connection(){};

    bool& isActive()
    {
        return active;
    }

    const int& getPriority()
    {
        return priority;
    }


private:
    int priority = {};
    bool active = {};
};

void conArraySlicer(Connection source[], Connection targetArr[], int startPoint = 0,  int cutSize=0)
{
    for(int i=startPoint;i<cutSize;i++)
    {
        targetArr[i] = source[i];
    }
}

Connection* connectionOrgenizer(Connection connArr[], int size) {

    if(size == 1)
    {
       return connArr;
    }
    else if (size == 2)
    {
        if (connArr[1].isActive() && connArr[2].isActive() )
        {
            if (connArr[1].getPriority() < connArr[2].getPriority())
            {
                Connection temp = connArr[1];
                connArr[1] = connArr[2];
                connArr[2] = temp;
            }
            return connArr;
        }
        else if(!connArr[1].isActive() && connArr[2].isActive())
        {
            return &connArr[2];
        }
        else if(connArr[1].isActive() && !connArr[2].isActive())
        {
            return &connArr[1];
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        Connection* partA = new Connection[(size+1)/2];
        conArraySlicer(connArr, partA, 0, (size+1)/2);

        Connection* partB = new Connection[(size/2)];
        conArraySlicer(connArr, partB, (size+1)/2, (size+1)/2);

        partA  = connectionOrgenizer(partA ,(size + 1)/2);

        partB  = connectionOrgenizer(partB ,(size/2));




        if(partA[size-1].getPriority() < partB[0].getPriority())
        {

        }
        else if(partA[0].getPriority() > partB[size-1].getPriority())
        {

        }
        else
        {

        }
    }
    return  nullptr;
}

enum Braces {regular=1, sqaured, curly};
bool checkBraces(std::string testStr)
{
    std::stack<Braces> braces;
    char testChr;
    for(unsigned int i=0;i<testStr.size()+1;i++)
    {
        testChr = testStr[i];
        if(testChr == '(' || testChr==')')
            {
                if(testChr==')')
                {
                    if (braces.top() != Braces::regular) {
                        return false;
                    }
                    braces.pop();
                }
                else
                {
                    braces.push(Braces::regular);
                }

            }
            else if(testChr == '[' || testChr==']')
            {
                if(testChr==']') {
                    if (braces.top() != Braces::sqaured) {
                        return false;
                    }
                    braces.pop();

                }
                else
                {
                    braces.push(Braces::sqaured);
                }

            }
        else if(testChr == '{' || testChr=='}')
            {
                if(testChr=='}') {
                    if (braces.top() != Braces::curly) {
                        return false;
                    }
                    braces.pop();

                }
                else
                {
                    braces.push(Braces::curly);
                }
            }
    }
    cout<<endl;
    return true;
}

int onesBinCounter(int bin)
{
    int res =0;
    while (bin != 0 )
    {
        if(bin%2 == 1)
        {
            res++;
        }
        bin = bin /2;
    }

    return res;
}

//to be continued + inplace with pointer
int* dupArrCleaner(int workArr[], int& size)
{
    bool bucketArr[size] = {false};
    for(int i=0;i<size;i++)
    {
        if(bucketArr[i])
        {
            bucketArr[i] = false;
            size--;
            continue;
        }
        bucketArr[i] = true;
        bucketArr[workArr[i]]++;
    }
//    int result[size]={};
//    for(int j=0;j < size;j++)
//    {
//        if()
//        {
//            result[j] = workArr[]
//        }

//    }
    return nullptr;
}

bool isActive(Connection& testedCon)
{
    return !testedCon.isActive();
}

std::vector<Connection>& sortConnections(std::vector<Connection>& vec)
{
    vec.erase(std::remove_if(vec.begin(),vec.end(),isActive), vec.end());
    std::sort(vec.begin(),vec.end(),[]( Connection& con1,  Connection& con2){return (con1.getPriority()<con2.getPriority());});
    return vec;
}

//TODO: buffer compressor with sevral assupmtions (dict size 256)
int main(int argc, char* argv[]) {
    cout<<argc<<"-"<<argv[1]<<endl;
    int action = atoi(argv[1]);
   int res = 0;
    std::vector<Connection> tempVec({Connection(true, 5), Connection(true, 4), Connection(false, 1), Connection(true, 9),
                                     Connection(true, 3), Connection(false, 6), Connection(true, 0), Connection(true, 2)
                                            , Connection(true, 7), Connection(true, 8)});
    switch(action)
    {
        case(1):
            cout<<"iterating fib"<<endl;
            res = fibIter(atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
            break;
        case(2):
            cout<<"Recursive fib"<<endl;
            res = fibIter(atoi(argv[2]));
            break;
        case (3):
            cout<<"sequance orgenzier"<<endl;
            /*Connection l[10]={Connection(true, 5), Connection(true, 4), Connection(false, 1), Connection(true, 9),
                                Connection(true, 3), Connection(false, 6), Connection(true, 0), Connection(true, 2)
                                , Connection(true, 7), Connection(true, 8)};
            connectionOrgenizer(l, 10);
            for(int i=0; i < 8;i++)
            {
                cout<<l[i].getPriority();
            }*/
            break;
        case (4):
            cout<<"brace checker"<<endl;
            cout<< checkBraces("([{}))")<<endl;
            break;
        case 5:
            res = onesBinCounter(atoi(argv[2]));
            break;

        case 6:
//            int g[]{5,6,7,8,1,9,1,10,1,4};
//            int size = 10;
//            //int * result = dupArrCleaner(g, size);
//            for(int i=0; i<size;i++)
//            {
//                cout<<result[i];
//            }
//            cout<<endl;
            break;
        case 7:
            sortConnections(tempVec);
            for(auto iter = tempVec.begin(); iter!=tempVec.end();iter++)
            {
                std::cout<<(*iter).getPriority()<<endl;
            }
        std::cout<<"with functor"<<endl;
        std::for_each(tempVec.begin(),tempVec.end(),[](Connection &con){ std::cout<<con.getPriority()<<endl;});
            break;
        default:
            cout<<"wrong action"<<endl;
            break;
    }
    cout<<"result: "<<res<<endl;

    return 0;
}