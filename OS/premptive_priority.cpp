#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>

struct Times
{
    std::string processID;
    int arrivalTime = 0;
    int burstTime = 0;
    int priority = 0;
};
struct Report
{
    std::string processId;
    int completionTime = 0;
    double turnAroundTime = 0;
    double waitingTime = 0;
};
struct priorityCompare
{
    bool operator()(const std::pair<size_t, Times> &p1, const std::pair<size_t, Times> &p2)
    {
        return p1.second.priority >= p2.second.priority;
    }
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
            std::cout << "Enter {processID,arrivalTime,burstTime,priority}: ";
            std::cin >> row;

            std::stringstream rowStream(row);

            std::string value;

            std::getline(rowStream, value, ',');
            info[i].processID = value;

            std::getline(rowStream, value, ',');
            info[i].arrivalTime = stoi(value);

            std::getline(rowStream, value, ',');
            info[i].burstTime = stoi(value);

            std::getline(rowStream, value, ',');
            info[i].priority = stoi(value);
        }
    }
    std::pair<size_t, Times> findFirst(const std::pair<size_t, Times> &proc, int time)
    {
        for (int i = proc.first; i < info.size(); i++)
        {
            if (info[i].arrivalTime > time)
                return {i, info[i]};
        }
        return {-1, Times()};
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
        report.turnAroundTime = double(avgTurnAroundTime) / info.size();
        report.waitingTime = double(avgWaitingTime) / info.size();

        return report;
    }

    void priorityPremptive()
    {
        const size_t &infoSize = info.size();
        std::sort(info.begin(), info.end(), [](const Times &p1, Times &p2)
                  { return p1.arrivalTime < p2.arrivalTime; });
        std::priority_queue<std::pair<size_t, Times>, std::vector<std::pair<size_t, Times>>, priorityCompare> schedulerQueue;
        std::vector<Report> rep(infoSize);
        std::vector<size_t> burstTimes(infoSize, 0);

        size_t time = info[0].arrivalTime;
        size_t iter = 0;
        while (time >= info[iter].arrivalTime && iter < infoSize)
        {
            schedulerQueue.push({iter, info[iter]});
            ++iter;
        }
        while (!schedulerQueue.empty())
        {
            std::pair<size_t, Times> proc = schedulerQueue.top();
            schedulerQueue.pop();

            std::pair<size_t, Times> nextProc = findFirst(proc, time);
            if (nextProc.first != -1)
            {
                int diff = nextProc.second.arrivalTime - proc.second.arrivalTime;
                if (proc.second.burstTime >= diff)
                {
                    time += diff;
                    burstTimes[proc.first] += diff;
                    proc.second.burstTime -= diff;
                }
                else
                {
                    time += proc.second.burstTime;
                    burstTimes[proc.first] += proc.second.burstTime;
                    proc.second.burstTime = 0;

                    rep[proc.first].processId = proc.second.processID;
                    rep[proc.first].completionTime = time;
                    rep[proc.first].turnAroundTime = rep[proc.first].completionTime - info[proc.first].arrivalTime;
                    rep[proc.first].waitingTime = rep[proc.first].turnAroundTime - burstTimes[proc.first];
                }
                if (proc.second.burstTime != 0)
                {
                    schedulerQueue.push({proc.first, proc.second});
                }
                else
                {
                    rep[proc.first].processId = proc.second.processID;
                    rep[proc.first].completionTime = time;
                    rep[proc.first].turnAroundTime = rep[proc.first].completionTime - info[proc.first].arrivalTime;
                    rep[proc.first].waitingTime = rep[proc.first].turnAroundTime - burstTimes[proc.first];
                }
            }
            else
            {
                time += proc.second.burstTime;
                burstTimes[proc.first] += proc.second.burstTime;
                proc.second.burstTime = 0;

                rep[proc.first].processId = proc.second.processID;
                rep[proc.first].completionTime = time;
                rep[proc.first].turnAroundTime = rep[proc.first].completionTime - info[proc.first].arrivalTime;
                rep[proc.first].waitingTime = rep[proc.first].turnAroundTime - burstTimes[proc.first];
            }
            while (time >= info[iter].arrivalTime && iter < infoSize)
            {
                schedulerQueue.push({iter, info[iter]});
                ++iter;
            }
        }

        display();
        std::cout << "------------------------------\n";
        for (const Report &r : rep)
        {
            std::cout << "PROCESS ID: " << r.processId << " COMPLETION TIME: " << r.completionTime << " TURN AROUND TIME: " << r.turnAroundTime << " WAITING TIME: " << r.waitingTime << std::endl;
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
            std::cout << "PROCESS ID: " << info[i].processID << " ARRIVAL TIME: " << info[i].arrivalTime << " BURST TIME: " << info[i].burstTime << std::endl;
        }
    }
};

int main()
{
    int nProcesses = 0;
    std::cout << "Enter the number of processes: ";
    std::cin >> nProcesses;

    SchedulingAlgorithms s(nProcesses);
    s.priorityPremptive();
    return 0;
}