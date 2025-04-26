#ifndef CO_OVERRIDE_RESULT_HPP
#define CO_OVERRIDE_RESULT_HPP

#include "./OverrideStatus.hpp"

#include <vector>
#include <memory>

namespace CppOverride
{
    class OverrideResult
    {
        private:
            std::vector<OverrideStatus> Statuses;

        public:
            inline void AddStatus(OverrideStatus status)
            {
                Statuses.push_back(status);
            }
        
            inline void ClearStatuses()
            {
                Statuses.clear();
            }
            
            inline std::vector<OverrideStatus> GetAllStatuses()
            {
                return Statuses;
            }
            
            //Helpers
            inline int GetSucceedCount()
            {
                int succeedCounter = 0;
                for(size_t i = 0; i < Statuses.size(); ++i)
                {
                    if(Statuses.at(i) == OverrideStatus::OVERRIDE_SUCCESS)
                        ++succeedCounter;
                }
                
                return succeedCounter;
            }
            
            inline int GetFailedCount()
            {
                int failedCounter = 0;
                for(size_t i = 0; i < Statuses.size(); ++i)
                {
                    if(Statuses.at(i) != OverrideStatus::OVERRIDE_SUCCESS)
                        ++failedCounter;
                }
                
                return failedCounter;
            }
            
            inline int GetStatusCount()
            {
                return (int)Statuses.size();
            }
            
            inline bool LastStatusSucceed()
            {
                return  Statuses.empty() ? 
                        false : 
                        Statuses.back() == OverrideStatus::OVERRIDE_SUCCESS;
            }
            
            inline bool LastStatusFailed()
            {
                return  Statuses.empty() ? 
                        false : 
                        Statuses.back() != OverrideStatus::OVERRIDE_SUCCESS;
            }
            
            inline OverrideStatus GetLastStatus()
            {
                return  Statuses.empty() ? OverrideStatus::NO_OVERRIDE : Statuses.back();
            }
            
            inline bool HasStatus(OverrideStatus status)
            {
                for(size_t i = 0; i < Statuses.size(); ++i)
                {
                    if(Statuses.at(i) == status)
                        return true;
                }
                
                return false;
            }
    };
    
    inline std::shared_ptr<OverrideResult> CreateOverrideResult()
    {
        return std::make_shared<OverrideResult>();
    }
}

#endif
