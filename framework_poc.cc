#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

#include "neuralNet.hcc"
#include "dataReader.hcc"

using namespace std;

//Main code
int main() 
{
    vector<unsigned> topology;
    topology.push_back(2);
    topology.push_back(3);
    topology.push_back(1);
    vector<double> inputVals;
    vector<double> targetVals;
    vector<double> resultVals;
    
    string file = DATA_FILE;
    bool finish = false;
    Net myNet(topology);
    DataReader myDataReader(file);
    
    while (!finish)
    {
        finish = myDataReader.setVals(inputVals,targetVals);
        if (finish) break;
        myNet.feedForward(inputVals);
        myNet.backProp(targetVals);
        myNet.getResults(resultVals);
        cout << "Inputs " << inputVals.front() << ";" << inputVals.back() << "\t| Output : " << resultVals.back();
        cout << "\t| Expected " << targetVals.back() << "\t| Error" << myNet.m_error << endl;
    }
    
    myDataReader.closeFile();
    cout << "DONE ;)" << endl;
    
    return 0;
}

/*
TODO
    Find a way to save and load networks
    Cut the learning set into folds and implement K fold cross validation
    Give a global ending mark with the test set after optimal training
*/