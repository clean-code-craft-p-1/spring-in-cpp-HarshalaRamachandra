#include <vector>
#include <math.h>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;
namespace Statistics {
    // define the Stats structure here. See the tests to infer its properties
    
    struct Stats
    {
        double avg;
        double max;
        double min;
    };
    
    Stats ComputeStatistics(const std::vector<double>&);

    template <typename T>
    T FindAverage(const std::vector<T>& input) 
	{
        T sum = std::accumulate(input.begin(), input.end(), 0.0);
        if (sum == 0)
            return NAN;
        else
            return sum / static_cast<double>(input.size());
    }

    template <typename T>
    T FindMax(const std::vector<T>& input) 
	{
        return *max_element(input.begin(), input.end());
    }

    template <typename T>
    T FindMin(const std::vector<T>& input) 
	{
        return *min_element(input.begin(), input.end());
    }
}

class IAlerter
{
public:
	virtual void sendAlert() = 0;
};

class EmailAlert : public IAlerter
{
public:
	virtual void sendAlert() override;
    bool emailSent = false;
};


class LEDAlert :public IAlerter
{
public:
	virtual void sendAlert() override;
    bool ledGlows = false;
};



class StatsAlerter
{
public:
	StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters);
	void checkAndAlert(const std::vector<double>& val);
private:
	float maxThreshold;
	std::vector<IAlerter*> alerters;
};