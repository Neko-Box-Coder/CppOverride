#ifndef CO_OVERRIDE_STATUS_HPP
#define CO_OVERRIDE_STATUS_HPP

#include <string>

namespace CppOverride
{
    enum class OverrideStatus
    {
        //------------------------------------------
        //Override status
        //------------------------------------------
        //Default status.
        //  Any matching override will modify the status to not be this value.
        //  If the status is not modified (i.e. staying in this value), 
        //  Could be one of these reasons:
        //  - Function name not matching
        //  - Argument types not matching
        //  - Return type not matching
        NO_OVERRIDE,
        
        //The last override was successful. 
        //  Please reset the status to NO_OVERRIDE before every expected override. 
        //  If the status is not reset, it will not be modified if no matching override is found.
        OVERRIDE_SUCCESS,
        
        MATCHING_CONDITION_VALUE_FAILED,
        MATCHING_CONDITION_ACTION_FAILED,
        MATCHING_OVERRIDE_TIMES_FAILED,
        
        //------------------------------------------
        //Internal error
        //------------------------------------------
        INTERNAL_MISSING_CHECK_ERROR,
        
        //------------------------------------------
        //Unsupported operation errors
        //------------------------------------------
        MODIFY_NON_ASSIGNABLE_ARG_ERROR,
        MODIFY_CONST_ARG_ERROR,
        CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR,
        
        COUNT
    };
    
    
    //const OverrideStatus DEFAULT_STATUS = OverrideStatus::NO_OVERRIDE;

    inline std::string OverrideStatusToString(OverrideStatus status)
    {
        static_assert((int)OverrideStatus::COUNT == 9, "");
        
        switch (status)
        {
            case OverrideStatus::NO_OVERRIDE:
                return "NO_OVERRIDE";
            case OverrideStatus::OVERRIDE_SUCCESS:
                return "OVERRIDE_SUCCESS";
            case OverrideStatus::MATCHING_CONDITION_VALUE_FAILED:
                return "MATCHING_CONDITION_VALUE_FAILED";
            case OverrideStatus::MATCHING_CONDITION_ACTION_FAILED:
                return "MATCHING_CONDITION_ACTION_FAILED";
            case OverrideStatus::MATCHING_OVERRIDE_TIMES_FAILED:
                return "MATCHING_OVERRIDE_TIMES_FAILED";
            case OverrideStatus::INTERNAL_MISSING_CHECK_ERROR:
                return "INTERNAL_MISSING_CHECK_ERROR";
            case OverrideStatus::MODIFY_NON_ASSIGNABLE_ARG_ERROR:
                return "MODIFY_NON_ASSIGNABLE_ARG_ERROR";
            case OverrideStatus::MODIFY_CONST_ARG_ERROR:
                return "MODIFY_CONST_ARG_ERROR";
            case OverrideStatus::CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR:
                return "CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR";
            case OverrideStatus::COUNT:
                return "COUNT";
            default:
                return "UNKNOWN";
        }
    }
    
}



#endif