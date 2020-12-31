#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <cmath>
using namespace std;
fstream InputFile;
int i=0,j=0;
void ReadFromFile(vector<int>& Array)
{
    InputFile.open("input.txt",ios::in);
    InputFile >> j;
    for(i=0; i<j; i++)
    {
        int Temp;
        InputFile >> Temp;
        Array.push_back(Temp);
    }
    InputFile.close();
}

void Merging(vector<int>& Array, int Start, int Middle, int End)
{
    vector<int> Temp;
    int i=Start, j=Middle+1;
    while(i < Middle+1 && j < End+1)
    {
        if(Array[i]<Array[j])
        {
            Temp.push_back(Array[i++]);
        }
        else
        {
            Temp.push_back(Array[j++]);
        }
    }
    while(i < Middle+1)
    {
        Temp.push_back(Array[i++]);
    }
    while(j < End+1)
    {
        Temp.push_back(Array[j++]);
    }
    i=0;
    while(i<Temp.size())
    {
        Array[Start+i] = Temp[i];
        i++;
    }
}
int Middle(int Start,int End)
{
int Result=(Start+End)/2;
return(Result);
}
void MergeSorting(vector<int>& Array, int Start, int End)
{
    if(End>Start)
    {
        thread Thread1
        {[&]()
        {
            MergeSorting(Array, Start, Middle(Start,End));
        }
        };
        thread Thread2
        {[&]()
        {
            MergeSorting(Array, Middle(Start,End)+1, End);
        }
        };
        Thread1.join();
        Thread2.join();
        Merging(Array, Start, Middle(Start,End), End);
    }
}


void Output(vector<int>& Array)
{
    for(auto& num : Array)
    {
        cout<<num<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<int> Array;
    ReadFromFile(Array);
    MergeSorting(Array, 0, Array.size()-1);
    Output(Array);
    return 0;
}
