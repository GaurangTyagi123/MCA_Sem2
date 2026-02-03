#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>

struct Times
{
    std::string processsID;
    int arrivalTime = 0;
    int burstTime = 0;
};
struct Report
{
    std::string processId;
    int completionTime = 0;
    int turnAroundTime = 0;
    int waitingTime = 0;
};
class SchedulingAlgorithms
{
private:
    std::vector<Times> info;

public:
    SchedulingAlgorithms(const int &n)
    {
        info.resize(n);

        for (int i = 0; i < n; i++)
        {
            std::string row;
            std::cout << "Enter {processID,arrivalTime,burstTime}: ";
            std::cin >> row;

            std::stringstream rowStream(row);

            std::string value;

            std::getline(rowStream, value, ',');
            info[i].processsID = value;

            std::getline(rowStream, value, ',');
            info[i].arrivalTime = stoi(value);

            std::getline(rowStream, value, ',');
            info[i].burstTime = stoi(value);
        }
    }
    Report calcAverage(const std::vector<Report> &rep)
    {
        Report report;
        double avgTurnAroundTime = 0;
        double avgWaitingTime = 0;
        for (const Report &r : rep)
        {
            avgTurnAroundTime += r.turnAroundTime;
            avgWaitingTime += r.waitingTime;
        }
        report.turnAroundTime = avgTurnAroundTime / info.size();
        report.waitingTime = avgWaitingTime / info.size();

        return report;
    }
    void fcfs()
    {
        std::sort(info.begin(), info.end(), [](const Times &p1, const Times &p2)
                  { return p1.arrivalTime < p2.arrivalTime; });
        std::vector<Report> rep(info.size());
        int completionTime = 0;
        for (int i = 0; i < info.size(); i++)
        {
            rep[i].processId = info[i].processsID;
            completionTime += info[i].burstTime;

            rep[i].completionTime = completionTime;
            rep[i].turnAroundTime = rep[i].completionTime - info[i].arrivalTime;
            rep[i].waitingTime = rep[i].turnAroundTime - info[i].burstTime;
        }
        display();

        std::cout << "------------------------------" << std::endl;
        for (const Report &r : rep)
        {
            std::cout << "PROCESSS ID: " << r.processId << " COMPLETION TIME: " << r.completionTime << " TURN AROUND TIME: " << r.turnAroundTime << " WAITING TIME: " << r.waitingTime << std::endl;
        }
        Report avg_report = calcAverage(rep);
        std::cout << "------------------------------\n";
        std::cout << "AVG TURN AROUND TIME: " << avg_report.turnAroundTime << " AVG WAITING TIME: " << avg_report.waitingTime << std::endl;
    }
    void sjf()
    {
        std::sort(info.begin(), info.end(), [](const Times &p1, const Times &p2)
                  { return p1.arrivalTime < p2.arrivalTime; });
        int infoSize = info.size();
        std::vector<Report> rep(infoSize);
        std::vector<bool> isComplete(infoSize, false);
        int time = info[0].arrivalTime;
        for (int i = 0; i < infoSize; i++)
        {
            size_t index = i;
            int minBurst = INT_MAX;
            for (int j = 0; j < infoSize; j++)
            {
                if (!isComplete[j] && info[j].arrivalTime <= time && info[j].burstTime < minBurst)
                {
                    index = j;
                }
            }
            rep[index].processId = info[index].processsID;
            time += info[index].burstTime;
            rep[index].completionTime = time;
            rep[index].turnAroundTime = rep[index].completionTime - info[index].arrivalTime;
            rep[index].waitingTime = rep[index].turnAroundTime - info[index].burstTime;
            isComplete[index] = true;
        }

        display();
        std::cout << "------------------------------\n";
        for (const Report &r : rep)
        {
            std::cout << "PROCESSS ID: " << r.processId << " COMPLETION TIME: " << r.completionTime << " TURN AROUND TIME: " << r.turnAroundTime << " WAITING TIME: " << r.waitingTime << std::endl;
        }
        Report avg_report = calcAverage(rep);
        std::cout << "------------------------------\n";
        std::cout << "AVG TURN AROUND TIME: " << avg_report.turnAroundTime << " AVG WAITING TIME: " << avg_report.waitingTime << std::endl;
    }
    void display() const
    {
        const size_t infoSize = info.size();
        std::cout << "------------------------------\n";
        for (int i = 0; i < infoSize; i++)
        {
            std::cout << "PROCESS ID: " << info[i].processsID << " ARRIVAL TIME: " << info[i].arrivalTime << " BURST TIME: " << info[i].burstTime << std::endl;
        }
    }
};

int main()
{
    SchedulingAlgorithms fcfs(4);
    fcfs.sjf();
    return 0;
}

// TAT :