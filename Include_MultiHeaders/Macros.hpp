#ifndef SO_MACROS_HPP
#define SO_MACROS_HPP

#include <set>
#include <string>
namespace SimpleOverride
{
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

    //==============================================================================
    //Macro argument expandsion
    //==============================================================================

    #define SO_INTERNAL_APPEND_ARGS_NOT_EMPTY(...) , __VA_ARGS__
    #define SO_INTERNAL_APPEND_ARGS_EMPTY(...)

    //NOTE: Up to 20 arguments
    #define SO_INTERNAL_EXPAND_IF_EMPTY() ,,,,,,,,,,,,,,,,,,,,
    #define SO_INTERNAL_ESCAPE_BRACKET(...) __VA_ARGS__ ()
    #define SO_INTERNAL_TEST_EMPTY(...)\
        SO_INTERNAL_CAT_ALLOW_GARBAGE(  SO_INTERNAL_EXPAND_IF_EMPTY, \
                                        SO_INTERNAL_ESCAPE_BRACKET __VA_ARGS__ ())
    
    #define SO_INTERNAL_SELECT_TAG( _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
                                    _15, _16, _17, _18, _19, _20, _21, _TAG, ...) _TAG
    
    #define SO_INTERNAL_CAT_ALLOW_GARBAGE(a, b, ...) a b
    #define SO_INTERNAL_CAT(a, b) a b
    #define SO_INTERNAL_FUNC_CAT(a, b) a ## b

    #define SO_INTERNAL_GET_TAG(...)\
        SO_INTERNAL_CAT(    SO_INTERNAL_SELECT_TAG, \
                            (SO_INTERNAL_TEST_EMPTY(__VA_ARGS__), \
                            _EMPTY, \
                            _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                            _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                            _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY, _NOT_EMPTY,\
                            _NOT_EMPTY, _NOT_EMPTY) )

    //Debug
    //#define SO_INTERNAL_GET_TAG(...) SO_INTERNAL_CAT( SO_INTERNAL_SELECT_TAG, ( SO_INTERNAL_EXPAND_IF_EMPTY __VA_ARGS__ (), _0,
    //                                                    _20, _19, _18, _17, _16, _15, _14, _13, _12, _11,
    //                                                    _10, _9, _8, _7, _6, _5, _4, _3, _2, _1) )

    //MSVC workaround: https://stackoverflow.com/questions/48710758/how-to-fix-variadic-macro-related-issues-with-macro-overloading-in-msvc-mic

    #ifndef _MSC_VER
        #define SO_INTERNAL_APPEND_ARGS(...)\
            SO_INTERNAL_CAT( SO_INTERNAL_FUNC_CAT,\
                            (SO_INTERNAL_APPEND_ARGS, SO_INTERNAL_GET_TAG(__VA_ARGS__) (__VA_ARGS__)) )
    #else
        #define SO_INTERNAL_VA_ARGS_FIX( macro, args ) macro args
        #define SO_INTERNAL_APPEND_ARGS(...)\
            SO_INTERNAL_VA_ARGS_FIX(    SO_INTERNAL_CAT, \
                                        ( SO_INTERNAL_FUNC_CAT, (SO_INTERNAL_APPEND_ARGS,\
                                        SO_INTERNAL_GET_TAG(__VA_ARGS__) (__VA_ARGS__)) ) )
    #endif

    #define SO_INTERNAL_STR(x) #x

    #define SO_INTERNAL_FUNC_SIG(functionSig) \
        SimpleOverride::Internal_ProcessFunctionSig(SO_INTERNAL_STR(functionSig))

    //==============================================================================
    //Public Macros
    //==============================================================================


    //-------------------------------------------------------
    //Return Modifying Macros for implementations
    //-------------------------------------------------------
    #define SO_RETURN_IF_FOUND(overrideObjName, functionSig, returnType, ...)\
    do\
    {\
        returnType returnVal;\
        if(SO_CHECK_RETURN_OVERRIDE(overrideObjName, returnVal, functionSig, __VA_ARGS__))\
            return returnVal;\
    } while(0)

    #define SO_RETURN_REF_IF_FOUND(overrideObjName, functionSig, returnType, ...)\
    do\
    {\
        INTERNAL_SO_PURE_TYPE(returnType)* returnVal;\
        if(SO_CHECK_RETURN_OVERRIDE(overrideObjName, returnVal, functionSig, __VA_ARGS__))\
            return *returnVal;\
    } while(0)

    #define SO_CHECK_RETURN_OVERRIDE(overrideObjName, returnRef, functionSig, ...)\
        overrideObjName.Internal_CheckOverrideAndReturn(returnRef, \
            SO_INTERNAL_FUNC_SIG(functionSig)\
            SO_INTERNAL_APPEND_ARGS(__VA_ARGS__) )

    //-------------------------------------------------------
    //Returns Overriding Macros
    //-------------------------------------------------------

    #define SO_OVERRIDE_RETURNS(overrideObjName, functionSig) \
        overrideObjName.Internal_OverrideReturns(SO_INTERNAL_FUNC_SIG(functionSig))
    
    #define SO_CLEAR_OVERRIDE_RETURNS(overrideObjName, functionSig)\
        overrideObjName.Internal_ClearOverrideReturns(SO_INTERNAL_FUNC_SIG(functionSig))


    //-------------------------------------------------------
    //Argument Modifying Macros for implementations
    //-------------------------------------------------------

    #define SO_MODIFY_ARGS_IF_FOUND(overrideObjName, functionSig, ...)\
        SO_CHECK_ARGS_OVERRIDE(overrideObjName, functionSig, __VA_ARGS__)
            
    #define SO_MODIFY_ARGS_AND_RETURN_IF_FOUND(overrideObjName, returnValue, functionSig, ...)\
    do\
    {\
        if(SO_CHECK_ARGS_OVERRIDE(overrideObjName, functionSig, __VA_ARGS__))\
            return returnValue;\
    } while(0)

    #define SO_CHECK_ARGS_OVERRIDE(overrideObjName, functionSig, ...)\
            overrideObjName.Internal_CheckOverrideAndSetArgs(   SO_INTERNAL_FUNC_SIG(functionSig)\
                                                                SO_INTERNAL_APPEND_ARGS(__VA_ARGS__) )


    //-------------------------------------------------------
    //Argumetns Overriding Macros
    //-------------------------------------------------------

    #define SO_OVERRIDE_ARGS(overrideObjName, functionSig)\
        overrideObjName.Internal_OverrideArgs(SO_INTERNAL_FUNC_SIG(functionSig))

    #define SO_CLEAR_OVERRIDE_ARGS(overrideObjName, functionSig)\
        overrideObjName.Internal_ClearOverrideArgs(SO_INTERNAL_FUNC_SIG(functionSig))


    //-------------------------------------------------------
    //Delacration Macros
    //-------------------------------------------------------
    #define SO_DECLARE_MEMBER_INSTNACE(OverrideObjName) mutable SimpleOverride::Overrider OverrideObjName
    #define SO_DECLARE_INSTNACE(OverrideObjName) SimpleOverride::Overrider OverrideObjName
            
    #define SO_DECLARE_OVERRIDE_METHODS(OverrideObjName)\
    inline SimpleOverride::ArgumentsProxy Internal_OverrideArgs(std::string functionName)\
    {\
        return OverrideObjName.Internal_OverrideArgs(functionName);\
    }\
    inline void Internal_ClearOverrideArgs(std::string functionName)\
    {\
        OverrideObjName.Internal_ClearOverrideArgs(functionName);\
    }\
    inline void ClearAllOverrideArgs()\
    {\
        OverrideObjName.ClearAllOverrideArgs();\
    }\
    inline SimpleOverride::ReturnProxy Internal_OverrideReturns(std::string functionName)\
    {\
        return OverrideObjName.Internal_OverrideReturns(functionName);\
    }\
    inline void Internal_ClearOverrideReturns(std::string functionName)\
    {\
        OverrideObjName.Internal_ClearOverrideReturns(functionName);\
    }\
    inline void ClearAllOverrideReturns()\
    {\
        OverrideObjName.ClearAllOverrideReturns();\
    }\
    inline SimpleOverride::Overrider* GetOverrideObject()\
    {\
        return &OverrideObjName;\
    }
    
    //#if 1
    #ifdef SO_NO_OVERRIDE
        #undef SO_RETURN_IF_FOUND
        #undef SO_CHECK_RETURN_OVERRIDE
        #undef SO_OVERRIDE_RETURNS
        #undef SO_CLEAR_OVERRIDE_RETURNS
        #undef SO_MODIFY_ARGS_IF_FOUND
        #undef SO_MODIFY_ARGS_AND_RETURN_IF_FOUND
        #undef SO_CHECK_ARGS_OVERRIDE
        #undef SO_OVERRIDE_ARGS
        #undef SO_CLEAR_OVERRIDE_ARGS
        #undef SO_DECLARE_INSTNACE
        #undef SO_DECLARE_OVERRIDE_METHODS
    
        #define SO_RETURN_IF_FOUND(...)
        #define SO_CHECK_RETURN_OVERRIDE(...) SO_CHECK_RETURN_OVERRIDE
        #define SO_OVERRIDE_RETURNS(...)
        #define SO_CLEAR_OVERRIDE_RETURNS(...)
        #define SO_MODIFY_ARGS_IF_FOUND(...)
        #define SO_MODIFY_ARGS_AND_RETURN_IF_FOUND(...)
        #define SO_CHECK_ARGS_OVERRIDE(...) false
        #define SO_OVERRIDE_ARGS(...)
        #define SO_CLEAR_OVERRIDE_ARGS(...)
        #define SO_DECLARE_INSTNACE(...)
        #define SO_DECLARE_OVERRIDE_METHODS(...)
    #endif
}

#endif