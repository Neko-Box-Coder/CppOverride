#ifndef CO_OVERRIDE_STATUS_HPP
#define CO_OVERRIDE_STATUS_HPP

namespace CppOverride
{
    enum class OverrideStatus
    {
        //------------------------------------------
        //Override status
        //------------------------------------------
        //Default status.
        //  Any matching overrde will modify the status to not be this value.
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
        CHECK_ARG_MISSING_INEQUAL_OPERATOR_ERROR
    };
    
    
    const OverrideStatus DEFAULT_STATUS = OverrideStatus::NO_OVERRIDE;
}



#endif