/*
 * 游戏玩家分类，http://hihocoder.com/contest/ntest2015septdm/problem/3
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>

using namespace std;


struct sample {
    char label;
    double distance;
};


bool cmp1(sample a, sample b)
{
    if (a.distance == b.distance)
        return a.label < b.label;
    return a.distance < b.distance;
}


bool cmp2(pair<char, int> a, pair<char, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}


void readTrainData(vector<vector<double> > &trainData, vector<char> &trainLabel, int L, int M)
{
    for (int i = 0; i < M; ++i) {
        // 读入训练数据特征
        vector<double> lineData;
        double tmpData;
        for (int j = 0; j < L; ++j) {
            cin >> tmpData;
            lineData.push_back(tmpData);
        }
        trainData.push_back(lineData);

        // 读入训练数据类别
        char label;
        cin >> label;
        trainLabel.push_back(label);
    }
}


void readTestData(vector<vector<double> > &testData, int L, int N)
{
    for (int i = 0; i < N; ++i) {
        vector<double> lineData;
        double tmpData;
        for (int j = 0; j < L; ++j) {
            cin >> tmpData;
            lineData.push_back(tmpData);
        }
        testData.push_back(lineData);
    }
}


double calcDistance(vector<double> data1, vector<double> data2)
{
    int length = data1.size();
    double distance = 0.0;
    for (int i = 0; i < length; ++i)
        distance += pow(data1[i] - data2[i], 2);
    return sqrt(distance);
}


void KNN(vector<vector<double> > trainData, vector<vector<double> > testData,
         vector<char> trainLabel, vector<char> &testLabel, int k, int L, int M, int N)
{
    for (int i = 0; i < N; ++i) {
        // 计算每一个测试样本与所有训练样本的距离，并排序。
        vector<sample> distances;
        for (int j = 0; j < M; ++j) {
            sample tmpDistance;
            tmpDistance.distance = calcDistance(testData[i], trainData[j]);
            tmpDistance.label = trainLabel[j];
            distances.push_back(tmpDistance);
        }
        sort(distances.begin(), distances.end(), cmp1);

        // 选择前k个样本的距离，投票选择类别。
        map<char, int> labelMap;
        for (int j = 0; j < k; ++j) {
            if (!labelMap[distances[j].label])
                labelMap[distances[j].label] = 0;
            labelMap[distances[j].label] += 1;
        }
        // 如果k个样本后面的距离和第k个相比相同，则存入该类别。
        for (int j = k; j < M; ++j) {
            if (distances[j].distance == distances[k-1].distance) {
                if (!labelMap[distances[j].label])
                    labelMap[distances[j].label] = 0;
                labelMap[distances[j].label] += 1;
            } else
                break;
        }

        // 将labelMap转换成labelVec，并排序。
        vector<pair<char, int> > labelVec;
        for (map<char, int>::iterator it = labelMap.begin(); it != labelMap.end(); ++it)
            labelVec.push_back(make_pair((*it).first, (*it).second));
        sort(labelVec.begin(), labelVec.end(), cmp2);

        // 输出类别。
        string res = "";
        for (int j = 0; j < labelVec.size(); ++j) {
            res += labelVec[j].first;
            if (j + 1 >= labelVec.size() || labelVec[j].second != labelVec[j+1].second)
                break;
        }

        if (i == 0)
            cout << res;
        else
            cout << "\n" << res;
    }
}

int main()
{
    int k, L, M, N;
    cin >> k >> L >> M >> N;
    vector<vector<double> > trainData;
    vector<vector<double> > testData;
    vector<char> trainLabel;
    vector<char> testLabel;

    readTrainData(trainData, trainLabel, L, M);
    readTestData(testData, L, N);

    KNN(trainData, testData, trainLabel, testLabel, k, L, M, N);

    return 0;
}
