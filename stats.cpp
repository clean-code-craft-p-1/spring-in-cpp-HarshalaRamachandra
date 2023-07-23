#include "stats.h"
#include <limits.h>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& input)
{
    //Implement statistics here
    Stats element;
    
    if(input.empty())
    {
		element.avg = NAN;
		element.max = NAN;
		element.min = NAN;
    }
    else
    {
		element.avg = FindAverage(input);
		element.max = FindMax(input);
		element.min = FindMin(input);
    }

    return element;
}


void EmailAlert::sendAlert()
{
    emailSent = true;
}

void LEDAlert::sendAlert()
{
    ledGlows = true;
}

StatsAlerter::StatsAlerter(float maxThreshold, std::vector<IAlerter*> alerters)
{
    this->maxThreshold = maxThreshold;

    for(unsigned int i = 0; i < alerters.size(); i++)
    {
        this->alerters.push_back(alerters[i]);
    }
    
} 
void StatsAlerter::checkAndAlert(const std::vector<double>& val)
{
    auto computeMax = Statistics::ComputeStatistics(val);
    if(computeMax.max > maxThreshold)
    {
        for(unsigned int i = 0; i < alerters.size(); i++)
        {
            //send sendAlert for all the alerters classes
            alerters[i]->sendAlert();
        }
    }
}