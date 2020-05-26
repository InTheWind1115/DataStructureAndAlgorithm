#include<iostream>
#include<string>
using namespace std;
const int N = 133, M=5;
int main() {
    int id[N]; //定义一维整形数组，存放学生的学号
    string name[N]; //定义字符数组，存放学生的姓名
	double score[N][M]; //行为学生 列为成绩
	double averStu[N]={0}; //存放每个同学的平均分
	double averCourse[M]={0}; //存放每门课程的平均分
    double minScore[M]; //找出各科分数的最低值
    double maxScore[M]; //找出各科分数的最高值


	int i,j;
	cout<<"Enter student ID number, his/her name and 5 scores:"<<endl;
	cout<<"Id Name Key1 Key2 Key3 Key4 Key5"<<endl;
	for (i = 0; i < N; i++) {
		cin>>id[i];
        cin>>name[i];
		for (j = 0; j < M; j++)
			cin>>score[i][j];
	}

    //计算每个同学的平均分----求各行的和/平均
    double oneStuTotalScore;
    for (i = 0; i < N; i++) {
        oneStuTotalScore = 0;
        for (j = 0; j < M; j++) {
            oneStuTotalScore += score[i][j];
        }
        averStu[i] = oneStuTotalScore * 1.0 / M; 
    }

    //计算各门课程的平均分----求各列的和/平均
    double oneCourseTotalScore;
    for (i = 0; i < M; i++) {
        oneCourseTotalScore = 0;
        for (j = 0; j < N; j++) {
            oneCourseTotalScore += score[j][i];
        }
        averCourse[i] = oneCourseTotalScore * 1.0 / N; 
    }

    //找出各科分数最高/低----求各列的最大/小值
    double maxValue, minValue;
    for (i = 0; i < M; i++) {
        maxValue = score[0][i];
        minValue = score[0][i];
        for (j = 0; j < N; j++) {
            if (score[j][i] < minValue)
                minValue = score[j][i];
            if (score[j][i] > maxValue)
                maxValue = score[j][i]; 
        }
        maxScore[i] = maxValue;
        minScore[i] = minValue;
    }

    //按各个同学的平均分进行排序(姓名、学号与各科成绩同时变化)

    //排序算法 此处采用冒泡法降序排序
    for (i = 1; i < N; i++) {
        for (j = 0; j < N - i; j++) {
            if (averStu[j] < averStu[j + 1]) {
                //每个同学的平均成绩变化
                int temp = averStu[j];
                averStu[j] = averStu[j + 1];
                averStu[j + 1] = temp;

                //每个同学的姓名变化
                string tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;

                //每个同学的学号变化
                int tempId = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tempId;

                //各科成绩变化
                for (int k = 0; k < M; k++) {
                    double tempScore = score[j][k];
                    score[j][k] = score[j + 1][k];
                    score[j + 1][k] = tempScore;
                }
            }
        }
    }

    system("pause");
    return 0;

}