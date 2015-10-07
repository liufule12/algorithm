/*
 * KNN
 * 游戏玩家分类，http://hihocoder.com/contest/ntest2015septdm/problem/3
 * AC。
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
// 以距离升序排序，若距离相等，label小的在前
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
        distance += (data1[i] - data2[i]) * (data1[i] - data2[i]);
    return sqrt(distance);
}


void KNN(vector<vector<double> > trainData, vector<vector<double> > testData,
         vector<char> trainLabel, vector<char> &testLabel, int k, int L, int M, int N)
// KNN.
// 注意：如果前K个相似类型中，出现数量最多的类型有重复，则一起输出，以ABCD升序排列
// 这里采用的思想是计算出排序后测试样本与训练样本的距离，
// 继续看 前第K+1个训练样本与测试样本的距离 是否 与前第k个训练样本 相同，如果相同，则将前第k+1以后测试样本放入考虑之中。
// 以此类推，直至不同。
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

/*
测试数据：
3 5 16 2
0.19 0.04 0.06 0.22 0.11 A
0.28 0.42 0.38 0.39 0.44 B
0.71 0.61 0.54 0.52 0.54 C
0.98 0.82 0.92 0.98 0.97 D
0.05 0.03 0.15 0.01 0.11 A
0.33 0.29 0.33 0.47 0.27 B
0.72 0.52 0.61 0.71 0.68 C
0.78 0.86 0.91 1.0 0.76 D
0.01 0.17 0.14 0.15 0.2 A
0.44 0.36 0.32 0.32 0.35 B
0.67 0.65 0.57 0.58 0.52 C
0.87 0.92 0.8 0.83 0.77 D
0.01 0.11 0.14 0.12 0.07 A
0.33 0.43 0.43 0.45 0.38 B
0.57 0.54 0.75 0.7 0.64 C
0.9 0.94 0.83 0.96 0.77 D
0.29 0.29 0.42 0.36 0.27
0.56 0.67 0.71 0.66 0.7
输出：
B
C
2 2 5 2
0 0 C
1 0 B
1 1 B
1 2 A
2 1 A
1 1
3 3
输出：
AB
A
 */
