#ifndef CO_MACROS_HPP
#define CO_MACROS_HPP

#include "../External/MacroPowerToys/MacroPowerToy.h"

#include <set>
#include <string>

namespace CppOverride
{
    #if 0
    inline std::string Internal_RemoveNewlines(std::string functionSig)
    {
        std::set<int> newlinesToRemove;
        for(int i = 0; i < functionSig.size(); i++)
        {
            switch(functionSig[i])
            {
                case '\n':
                case '\r':
                    newlinesToRemove.insert(i);
                    break;
                default:
                    break;
            }
        }

        for(auto it = newlinesToRemove.rbegin(); it != newlinesToRemove.rend(); it++)
            functionSig.erase(functionSig.begin() + *it);

        return functionSig;
    }
    
    inline std::string Internal_RemoveSpaces(std::string functionSig)
    {
        //Remove any consecutive spaces
        std::set<int> spacesToRemove;
        bool isLastSpace = false;
        for(int i = 0; i < functionSig.size(); i++)
        {
            if(isLastSpace)
            {
                if(functionSig[i] == ' ')
                    spacesToRemove.insert(i);
                else
                    isLastSpace = false;
            }
            else if(functionSig[i] == ' ')
                isLastSpace = true;
        }
        
        //Remove spaces around parentheses and commas
        for(int i = 0; i < functionSig.size(); i++)
        {
            switch(functionSig[i])
            {
                case '(':
                case ')':
                case ',':
                case '*':
                case '&':
                case ':':
                case '<':
                case '>':
                    if(i > 0 && functionSig[i - 1] == ' ')
                        spacesToRemove.insert(i - 1);
                    
                    if(i < functionSig.size() - 1 && functionSig[i + 1] == ' ')
                        spacesToRemove.insert(i + 1);
                    break;
                default:
                    break;
            }
        }
        
        for(auto it = spacesToRemove.rbegin(); it != spacesToRemove.rend(); it++)
            functionSig.erase(functionSig.begin() + *it);

        return functionSig;
    }
    
    inline std::string Internal_Trim(std::string functionSig)
    {
        //Trimming
        int firstCharIndex = -1;
        for(int i = 0; i < functionSig.size(); i++)
        {
            if(functionSig[i] != ' ')
            {
                firstCharIndex = i;
                break;
            }
        }
        
        int lastCharIndex = -1;
        for(int i = functionSig.size() - 1; i >= 0; i--)
        {
            if(functionSig[i] != ' ')
            {
                lastCharIndex = i;
                break;
            }
        }
        
        return functionSig.substr(firstCharIndex, lastCharIndex - firstCharIndex + 1);
    }
    
    //==============================================================================
    //Macros and functions for translating function signature to string
    //==============================================================================
    inline std::string Internal_ProcessFunctionSig(std::string functionSig)
    {
        functionSig = Internal_RemoveNewlines(functionSig);
        functionSig = Internal_Trim(functionSig);
        functionSig = Internal_RemoveSpaces(functionSig);
        return functionSig;
    }
    #endif

    //==============================================================================
    //Macro for overriding method implementation
    //==============================================================================
    
    //This macro is to prepend "," if there are any arguments present, otherwise empty
    #define INTERNAL_CO_ARGS(...) \
        MPT_COMPOSE \
        ( \
            MPT_COMPOSE \
            (\
                MPT_CONCAT, \
                (INTERNAL_CO_ARGS_, MPT_IS_ARGS_EMPTY __VA_ARGS__ ) \
            ), \
            __VA_ARGS__ \
        )
    
    #define INTERNAL_CO_ARGS_EMPTY()
    #define INTERNAL_CO_ARGS_NOT_EMPTY(...) , __VA_ARGS__
    
    #define INTERNAL_CO_LOG_FOUND_INDEX 0
    
    #define CO_OVERRIDE_IMPL(overrideObjName, returnType, args) \
    do \
    { \
        int foundReturnIndex = -1; \
        int foundArgsIndex = -1; \
        bool found = overrideObjName.Internal_CheckOverride<returnType>(__func__, \
                                                                        foundReturnIndex, \
                                                                        foundArgsIndex \
                                                                        INTERNAL_CO_ARGS(args)); \
        \
        if(foundArgsIndex != -1) \
        { \
            if(INTERNAL_CO_LOG_FOUND_INDEX) \
                std::cout << "foundArgsIndex: " << foundArgsIndex << std::endl; \
            \
            overrideObjName.Internal_OverrideArgs(  foundArgsIndex, \
                                                    __func__ \
                                                    INTERNAL_CO_ARGS(args)); \
            \
            if(std::is_same<returnType, void>::value) \
                return CppOverride::EarlyReturn<returnType>(); \
        } \
        \
        if(foundReturnIndex != -1) \
        { \
            if(INTERNAL_CO_LOG_FOUND_INDEX) \
                std::cout << "foundReturnIndex: " << foundReturnIndex << std::endl; \
            \
            return overrideObjName.Internal_OverrideReturn<returnType>( foundReturnIndex, \
                                                                        __func__ \
                                                                        INTERNAL_CO_ARGS(args)); \
        } \
        \
        if(INTERNAL_CO_LOG_FOUND_INDEX) \
        { \
            std::cout << "foundArgsIndex: " << foundArgsIndex << std::endl; \
            std::cout << "foundReturnIndex: " << foundReturnIndex << std::endl; \
        } \
    } while(0)

    //-------------------------------------------------------
    //Setup overrides
    //-------------------------------------------------------

    #define CO_SETUP_OVERRIDE(overrideObjName, functionName) \
        overrideObjName.Internal_CreateOverrideInfo(#functionName)

    #define CO_REMOVE_OVERRIDE_SETUP(overrideObjName, functionName)\
        overrideObjName.Internal_RemoveOverrideInfo(functionName)

    #define CO_CLEAR_ALL_OVERRIDE_SETUP(overrideObjName) \
        overrideObjName.ClearAllOverrideInfo()

    //-------------------------------------------------------
    //Declaration Macros
    //-------------------------------------------------------
    #define CO_DECLARE_MEMBER_INSTANCE(OverrideObjName) mutable CppOverride::Overrider OverrideObjName
    #define CO_DECLARE_INSTANCE(OverrideObjName) CppOverride::Overrider OverrideObjName
            
    #define CO_DECLARE_OVERRIDE_METHODS(OverrideObjName) \
    inline CppOverride::OverrideInfoSetter Internal_CreateOverrideInfo(std::string functionName) \
    { \
        return OverrideObjName.Internal_CreateOverrideInfo(functionName); \
    } \
    inline void Internal_RemoveOverrideInfo(std::string functionName) \
    { \
        OverrideObjName.Internal_RemoveOverrideInfo(functionName); \
    } \
    inline void ClearAllOverrideInfo() \
    { \
        OverrideObjName.ClearAllOverrideInfo(); \
    } \
    inline CppOverride::Overrider* GetOverrideObject() \
    { \
        return &OverrideObjName; \
    }
    
    //#if 1
    #ifdef CO_NO_OVERRIDE
        #undef CO_OVERRIDE_IMPL
        #undef CO_SETUP_OVERRIDE
        #undef CO_REMOVE_OVERRIDE_SETUP
        #undef CO_CLEAR_ALL_OVERRIDE_SETUP
        #undef CO_DECLARE_MEMBER_INSTANCE
        #undef CO_DECLARE_INSTANCE
        #undef CO_DECLARE_OVERRIDE_METHODS
    
        #define CO_OVERRIDE_IMPL(...)
        #define CO_SETUP_OVERRIDE(...)
        #define CO_REMOVE_OVERRIDE_SETUP(...)
        #define CO_CLEAR_ALL_OVERRIDE_SETUP(...)
        #define CO_DECLARE_MEMBER_INSTANCE(...)
        #define CO_DECLARE_INSTANCE(...)
        #define CO_DECLARE_OVERRIDE_METHODS(...)
    #endif
}

#endif