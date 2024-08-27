#ifndef CO_OVERRIDE_RESULT_HPP
#define CO_OVERRIDE_RESULT_HPP

#include "./OverrideStatus.hpp"

#include <memory>

namespace CppOverride
{
    struct OverrideResult
    {
        private:
            std::shared_ptr<OverrideStatus> InnerStatus;
        public:
            OverrideStatus& Status;

        inline OverrideResult() : 
            InnerStatus(std::make_shared<OverrideStatus>(OverrideStatus::NO_OVERRIDE)),
            Status(std::ref(*InnerStatus))
        {}
        
        inline OverrideResult(const OverrideResult& other) : 
            InnerStatus(other.InnerStatus),
            Status(std::ref(*InnerStatus))
        {}
        
        inline OverrideResult& operator=(const OverrideResult& other)
        {
            Status = other.Status;
            return *this;
        }
        
        inline std::shared_ptr<OverrideStatus> GetStatusRef()
        {
            return InnerStatus;
        }
    };
}

#endif
