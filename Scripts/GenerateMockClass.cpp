//An extremely crude C++ header file parser for extracting class and function details
//Generated output probably still need some manual adjustment

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

enum class ParseState
{
    NONE = 0,
    IN_LINE_COMMENT = 1 << 0,
    IN_BLOCK_COMMENT = 1 << 1,
    IN_CLASS_DECLARATION = 1 << 2,
    IN_CLASS_DEFINITION = 1 << 3,
    IN_FUNCTION_DECLARATION = 1 << 4,
    IN_FUNCTION_DEFINITION = 1 << 5,
    IN_PREPROCESSOR_DIRECTIVE = 1 << 6,
    IN_PUBLIC_SECTION = 1 << 7,
    IN_PRIVATE_SECTION = 1 << 8,
    IN_PROTECTED_SECTION = 1 << 9,
    IN_NAMESPACE_DECLARATION = 1 << 10,
    COUNT = 1 << 11
};

ParseState operator|(ParseState a, ParseState b)
{
    return static_cast<ParseState>(static_cast<int>(a) | static_cast<int>(b));
}

ParseState operator|=(ParseState& a, ParseState b)
{
    a = a | b;
    return a;
}

ParseState operator&(ParseState a, ParseState b)
{
    return static_cast<ParseState>(static_cast<int>(a) & static_cast<int>(b));
}

ParseState operator&=(ParseState& a, ParseState b)
{
    a = a & b;
    return a;
}

ParseState operator^(ParseState a, ParseState b)
{
    return static_cast<ParseState>(static_cast<int>(a) ^ static_cast<int>(b));
}

ParseState operator^=(ParseState& a, ParseState b)
{
    a = a ^ b;
    return a;
}

ParseState operator~(ParseState a)
{
    return static_cast<ParseState>(~static_cast<int>(a));
}

bool operator!(ParseState a)
{
    return !static_cast<int>(a);
}

bool operator==(ParseState a, ParseState b)
{
    return !!(a & b);
}

bool operator!=(ParseState a, ParseState b)
{
    return !(a == b);
}

struct ParenthesisDetails
{
    bool FunctionArguments = false;
    int TokenIndex = -1;
    
    ParenthesisDetails( bool functionArguments, 
                        int tokenIndex) :   FunctionArguments(functionArguments), 
                                            TokenIndex(tokenIndex)
    {}
};

enum class CurlyBraceType
{
    UNKNOWN,
    FUNCTION_BODY,
    CLASS_BODY,
    NAMESPACE_BODY
};

#include <sstream>

struct FunctionDetails 
{
    std::string Visibility;
    std::vector<std::string> PrependAttributes;
    std::string ReturnType;
    std::string Name;
    std::vector<std::string> ArgTypes;
    std::vector<std::string> ArgDefaultValues;
    std::vector<std::string> AppendAttributes;
    
    void ToString(std::string indent, std::stringstream& outString) const
    {
        outString << indent << "Function: " << Name << std::endl;
        outString << indent << "    Visibility: " << Visibility << std::endl;
        
        {
            outString << indent << "    Prepend Attributes: " << std::endl;
            for(int k = 0; k < PrependAttributes.size(); ++k)
            {
                outString << indent << "    -   " << PrependAttributes[k];
                if(k < PrependAttributes.size() - 1)
                    outString << std::endl;
            }
            
            outString << std::endl;
        }
        outString << indent << "    Return Type: " << ReturnType << std::endl;
        
        {
            outString << indent << "    Arguments Types: " << std::endl;
            for(int k = 0; k < ArgTypes.size(); ++k)
            {
                outString << indent << "    -   " << ArgTypes[k];
                if(k < ArgTypes.size() - 1)
                    outString << std::endl;
            }
            outString << std::endl;

            outString << indent << "    Arguments Values: " << std::endl;
            for(int k = 0; k < ArgTypes.size(); ++k)
            {
                outString << indent << "    -   \"" << ArgDefaultValues[k] << "\"";

                if(k < ArgDefaultValues.size() - 1)
                    outString << std::endl;
            }
            outString << std::endl;
        }
        
        outString << indent << "    Append Attributes: " << std::endl;
        for(int k = 0; k < AppendAttributes.size(); ++k)
        {
            outString << indent << "    -   " << AppendAttributes[k];
            
            if(k < AppendAttributes.size() - 1)
                    outString << std::endl;
        }
        
        outString << std::endl << std::endl;
    }

};

struct ClassDetails
{
    std::vector<std::string> Namespaces;
    std::vector<std::string> PrependAttributes;
    std::string Name;
    std::vector<std::string> AppendAttributes;
    std::vector<FunctionDetails> Functions;
    
    void ToString(std::string indent, std::stringstream& outString) const
    {
        outString << indent << "Class: " << Name << std::endl;
                
        outString << indent << "    Namespaces:" << std::endl;
        for(int i = 0; i < Namespaces.size(); ++i)
            outString << indent << "    -   " << Namespaces[i] << std::endl;
        
        outString << indent << "    PrependAttributes:" << std::endl;
        for(int i = 0; i < PrependAttributes.size(); ++i)
            outString << indent << "    -   " << PrependAttributes[i] << std::endl;
        
        outString << indent << "    AppendAttributes:" << std::endl;
        for(int i = 0; i < AppendAttributes.size(); ++i)
            outString << indent << "    -   " << AppendAttributes[i] << std::endl;
        
        for(int i = 0; i < Functions.size(); ++i)
            Functions[i].ToString("    ", outString);
        
        outString << std::endl;
    }
};

struct Parser
{
    ParseState CurrentState = ParseState::NONE;
    std::stack<ParenthesisDetails> CurrentParenthesis;
    std::stack<CurlyBraceType> CurrentCurlyBrace;
    
    std::vector<std::string> CurrentTokens;
    int LastLineNumber = 0;
    std::string LastLine;
    
    std::vector<std::string> Namespaces;
    FunctionDetails CurrentFunction;
    ClassDetails CurrentClass;
    
    std::vector<ClassDetails>& ParsedClasses;
    std::vector<std::string>& ParsedIncludes;
    
    inline Parser(  std::vector<ClassDetails>& outParsedClasses, 
                    std::vector<std::string>& outParsedIncludes) :  CurrentState(ParseState::NONE), 
                                                                    CurrentParenthesis(),
                                                                    CurrentCurlyBrace(),
                                                                    CurrentTokens(),
                                                                    LastLineNumber(0),
                                                                    LastLine(),
                                                                    CurrentFunction(),
                                                                    CurrentClass(),
                                                                    ParsedClasses(outParsedClasses),
                                                                    ParsedIncludes(outParsedIncludes)
    {}
    
    
    void ResetTokensForEndOfStatement()
    {
        CurrentTokens.clear();
        CurrentParenthesis = std::stack<ParenthesisDetails>();
    }
};

inline std::string Trim(std::string line)
{
    //Trimming
    int firstCharIndex = -1;
    for(int i = 0; i < line.size(); ++i)
    {
        if(line[i] != ' ' && line[i] != '\t')
        {
            firstCharIndex = i;
            break;
        }
    }
    
    int lastCharIndex = -1;
    for(int i = line.size() - 1; i >= 0; --i)
    {
        if(line[i] != ' ' && line[i] != '\t')
        {
            lastCharIndex = i;
            break;
        }
    }
    
    if(firstCharIndex == -1 || lastCharIndex == -1)
        return line;
    
    return line.substr(firstCharIndex, lastCharIndex - firstCharIndex + 1);
}

void TrimStringVector(const std::vector<std::string>& inStrings, std::vector<std::string>& outStrings)
{
    outStrings.clear();
    for(int i = 0; i < inStrings.size(); ++i)
        outStrings.emplace_back(Trim(inStrings[i]));
}

void ClearStringVectorIfAllEmpty(std::vector<std::string>& inOutStrings)
{
    for(int i = 0; i < inOutStrings.size(); ++i)
    {
        if(!inOutStrings.empty())
            break;
        
        if(i == inOutStrings.size() - 1)
            inOutStrings.clear();
    }
}

const std::unordered_set<char> SkippableTokens = {' ', '\t'};
const std::unordered_set<char> CharTokens = {'(', ')', ';', '{', '}', '/', '#', ',', '=', '<', '>'};

void ClearNonBlockParseStates(ParseState& state)
{
    state &= ~ParseState::IN_LINE_COMMENT;
    state &= ~ParseState::IN_FUNCTION_DECLARATION;
    state &= ~ParseState::IN_CLASS_DECLARATION;
    state &= ~ParseState::IN_NAMESPACE_DECLARATION;
}

bool ProcessComments(const std::string& token, int lineNumber, Parser& outParser)
{
    //Check end of line comment
    if(outParser.CurrentState == ParseState::IN_LINE_COMMENT)
    {
        if(lineNumber > outParser.LastLineNumber)
        {
            outParser.CurrentState &= ~ParseState::IN_LINE_COMMENT;
            outParser.ResetTokensForEndOfStatement();
        }
        else
            return true;;
    }
    
    //Check end of block comment
    if(outParser.CurrentState == ParseState::IN_BLOCK_COMMENT)
    {
        if(token == "*")
            outParser.CurrentTokens.push_back(token);
        else if(token == "/" && 
                !outParser.CurrentTokens.empty() && 
                outParser.CurrentTokens.back() == "*")
        {
            outParser.ResetTokensForEndOfStatement();
            outParser.CurrentState &= ~ParseState::IN_BLOCK_COMMENT;
        }
        
        return true;;
    }
    
    //Check start of comment
    if( outParser.CurrentState != ParseState::IN_LINE_COMMENT && 
        outParser.CurrentState != ParseState::IN_BLOCK_COMMENT &&
        !outParser.CurrentTokens.empty())
    {
        //Line comment
        if(token == "/" && outParser.CurrentTokens.back() == "/")
        {
            outParser.CurrentState |= ParseState::IN_LINE_COMMENT;
            outParser.ResetTokensForEndOfStatement();
            return true;
        }
        //Block comment
        else if(token == "*" && outParser.CurrentTokens.back() == "/")
        {
            outParser.CurrentState |= ParseState::IN_BLOCK_COMMENT;
            outParser.ResetTokensForEndOfStatement();
            return true;
        }
    }
    
    return false;
}

bool ProcessPreprocessorDirectives(const std::string& token, int lineNumber, Parser& outParser)
{
    if(outParser.CurrentState == ParseState::IN_PREPROCESSOR_DIRECTIVE)
    {
        if(lineNumber > outParser.LastLineNumber)
        {
            //If it is multi-line preprocessor, we don't care about the tokens so continue
            if(!outParser.CurrentTokens.empty() && outParser.CurrentTokens.back() == "\\")
                return true;
            
            //Check if we have an include
            bool hasInclude = false;
            for(int i = 0; i < outParser.CurrentTokens.size(); ++i)
            {
                if(outParser.CurrentTokens[i] == "include")
                {
                    hasInclude = true;
                    break;
                }
            }
            
            if(hasInclude)
                outParser.ParsedIncludes.push_back(outParser.LastLine);
            
            outParser.ResetTokensForEndOfStatement();
            
            if(token != "#")
                outParser.CurrentState &= ~ParseState::IN_PREPROCESSOR_DIRECTIVE;
        }
        else
        {
            outParser.CurrentTokens.push_back(token);
            return true;
        }
    }
    
    if(token == "#")
    {
        outParser.ResetTokensForEndOfStatement();
        outParser.CurrentState |= ParseState::IN_PREPROCESSOR_DIRECTIVE;
        outParser.CurrentTokens.push_back(token);
        return true;
    }
    
    return false;
}

bool ProcessEndOfFunctionDeclaration(const std::string& token, Parser& outParser)
{
    if(token == ";" || token == "{")
    {
        //Handle function append attributes
        for(int i = outParser.CurrentTokens.size() - 1; i >= 0; --i)
        {
            if(outParser.CurrentTokens[i] == ")")
            {
                for(int j = i + 1; j < outParser.CurrentTokens.size(); ++j)
                {
                    outParser   .CurrentFunction
                                .AppendAttributes
                                .push_back(outParser.CurrentTokens[j]);
                }
                break;
            }
            else if(i == 0)
                outParser.CurrentFunction.AppendAttributes.clear();
        }
        
        outParser.CurrentState &= ~ParseState::IN_FUNCTION_DECLARATION;
        
        if(outParser.CurrentState == ParseState::IN_PUBLIC_SECTION)
            outParser.CurrentFunction.Visibility = "public";
        else if(outParser.CurrentState == ParseState::IN_PRIVATE_SECTION)
            outParser.CurrentFunction.Visibility = "private";
        else if(outParser.CurrentState == ParseState::IN_PROTECTED_SECTION)
            outParser.CurrentFunction.Visibility = "protected";
        else
            outParser.CurrentFunction.Visibility = "private";
        
        outParser.CurrentClass.Functions.push_back(outParser.CurrentFunction);
        
        if(token == "{")
        {
            outParser.CurrentState |= ParseState::IN_FUNCTION_DEFINITION;
            outParser.CurrentCurlyBrace.push(CurlyBraceType::FUNCTION_BODY);
        }
        
        ClearNonBlockParseStates(outParser.CurrentState);
        outParser.ResetTokensForEndOfStatement();
        return true;
    }
    
    return false;
}

bool ProcessFunctionParameters(const std::string& token, Parser& outParser)
{
    if(token == "(")
    {
        outParser.CurrentParenthesis.push(ParenthesisDetails(   false, 
                                                                outParser.CurrentTokens.size()));
        
        outParser.CurrentTokens.push_back(token);
        return true;
    }
    
    if(token == ")" && !outParser.CurrentParenthesis.empty())
    {
        //We are still inside function arguments, append current token and continue
        if(!outParser.CurrentParenthesis.top().FunctionArguments)
        {
            outParser.CurrentParenthesis.pop();
            outParser.CurrentTokens.push_back(token);
            return true;
        }

        //Parse function arguments
        int lastParameterStartIndex = outParser.CurrentParenthesis.top().TokenIndex + 1;
        int localTemplateBracketCounter = 0;
        for(int i = lastParameterStartIndex; i < outParser.CurrentTokens.size(); ++i)
        {
            //Ignore any commas in < or >
            if(outParser.CurrentTokens[i] == "<")
                ++localTemplateBracketCounter;
            else if (outParser.CurrentTokens[i] == ">")
                --localTemplateBracketCounter;
            
            if(localTemplateBracketCounter != 0 || outParser.CurrentTokens[i] != ",")
            {
                if(i == outParser.CurrentTokens.size() - 1)
                    ++i;
                else
                    continue;
            }
            
            //If we only have 1 token, it probably is type
            if(i - lastParameterStartIndex == 1)
            {
                outParser   .CurrentFunction
                            .ArgTypes
                            .push_back(outParser.CurrentTokens[i - 1]);
            }
            else
            {
                std::string currentArgType;
                std::string currentDefaultValue;
                int typeSearchEndIndex = i;
                bool hasDefaultValue = false;

                //Process default value
                for(int j = i - 1; j >= lastParameterStartIndex; --j)
                {
                    if(outParser.CurrentTokens[j] == "=")
                    {
                        hasDefaultValue = true;
                        typeSearchEndIndex = j;
                        break;
                    }
                    currentDefaultValue = outParser.CurrentTokens[j] + " " + currentDefaultValue;
                }

                //Process type
                for(int j = lastParameterStartIndex; j < typeSearchEndIndex - 1; ++j)
                    currentArgType += outParser.CurrentTokens[j] + " ";

                currentArgType = Trim(currentArgType);
                outParser.CurrentFunction.ArgTypes.push_back(currentArgType);
                if(hasDefaultValue)
                    outParser.CurrentFunction.ArgDefaultValues.push_back(Trim(currentDefaultValue));
                else
                    outParser.CurrentFunction.ArgDefaultValues.push_back("");
            }
            
            lastParameterStartIndex = i + 1;
        }
        
        outParser.CurrentTokens.push_back(token);
        return true;
    }
    
    return false;
}

bool ProcessBeforeFunctionParameters(const std::string& token, Parser& outParser)
{
    if( token == "(" && 
        outParser.CurrentState == ParseState::IN_CLASS_DEFINITION &&
        outParser.CurrentState != ParseState::IN_FUNCTION_DEFINITION &&
        outParser.CurrentTokens.size() >= 2)
    {
        outParser.CurrentFunction = FunctionDetails();
        
        //Handle operator
        int operatorIndex = -1;
        for(int i = outParser.CurrentTokens.size() - 1; i >= 0; --i)
        {
            const std::string operatorStr = "operator";
            
            if( outParser.CurrentTokens[i].size() >= operatorStr.size() &&
                outParser.CurrentTokens[i].substr(0, operatorStr.size()) == operatorStr)
            {
                operatorIndex = i;
                break;
            }
        }
        
        int returnIndexInclusiveEnd = -1;
        if(operatorIndex != -1)
        {
            for(int i = operatorIndex; i < outParser.CurrentTokens.size(); ++i)
                outParser.CurrentFunction.Name += outParser.CurrentTokens[i];
            
            returnIndexInclusiveEnd = operatorIndex - 1;
        }
        else
        {
            outParser.CurrentFunction.Name = outParser.CurrentTokens.back();
            returnIndexInclusiveEnd = outParser.CurrentTokens.size() - 2;
        }
        
        //Handle constructor destructor
        if( outParser.CurrentFunction.Name == outParser.CurrentClass.Name || 
            outParser.CurrentFunction.Name == "~" + outParser.CurrentClass.Name)
        {
            returnIndexInclusiveEnd = -1;
        }
        
        //Handle return type
        if(returnIndexInclusiveEnd >= 0)
        {
            bool returnTypeIsTemplate = false;
            
            if(outParser.CurrentTokens[returnIndexInclusiveEnd] == ">")
                returnTypeIsTemplate = true;
            
            //Handle template for return type
            if(returnTypeIsTemplate)
            {
                int localTemplateBracketCounter = 0;
                
                do
                {
                    if(outParser.CurrentTokens[returnIndexInclusiveEnd] == ">")
                        localTemplateBracketCounter++;
                    else if(outParser.CurrentTokens[returnIndexInclusiveEnd] == "<")
                        localTemplateBracketCounter--;
                    
                    //Add the current token which is considered as template return type
                    outParser.CurrentFunction.ReturnType = 
                        outParser.CurrentTokens[returnIndexInclusiveEnd] + 
                        " " +
                        outParser.CurrentFunction.ReturnType;
                    
                    --returnIndexInclusiveEnd;
                    
                    if(localTemplateBracketCounter == 0)
                        break;
                }
                while(returnIndexInclusiveEnd > 0);
            }
            
            //Store return type
            {
                outParser.CurrentFunction.ReturnType = 
                    outParser.CurrentTokens[returnIndexInclusiveEnd] + " " + 
                    outParser.CurrentFunction.ReturnType;
            }
            
            //Handle return type with scope operator
            do
            {
                int previousTokenColonCount = 0;
                
                //Check if previous word has scope operator
                for(int i = 0; i < 2; ++i)
                {
                    if( outParser.CurrentTokens[returnIndexInclusiveEnd + 1].size() > i + 1 &&
                        outParser.CurrentTokens[returnIndexInclusiveEnd + 1][i] == ':')
                    {
                        ++previousTokenColonCount;
                    }
                    else
                        break;
                }
                
                int currentTokenColonCount = 0;
                
                //Check if current word has scope operator
                for(int i = 0; i < 2; ++i)
                {
                    const std::string& currentToken = 
                        outParser.CurrentTokens[returnIndexInclusiveEnd];
                    
                    int currentTokenSize = currentToken.size();
                    
                    if( currentTokenSize > i + 1 && currentToken[currentTokenSize - 1] == ':')
                        ++currentTokenColonCount;
                    else
                        break;
                }

                if(currentTokenColonCount + previousTokenColonCount < 2)
                    break;
                
                outParser.CurrentFunction.ReturnType = 
                    outParser.CurrentTokens[returnIndexInclusiveEnd] + " " + 
                    outParser.CurrentFunction.ReturnType;
            
                --returnIndexInclusiveEnd;
            }
            while(returnIndexInclusiveEnd > 0);
        }
        else
            outParser.CurrentFunction.ReturnType = "";
        
        outParser.CurrentFunction.ReturnType = Trim(outParser.CurrentFunction.ReturnType);
        int prependIndexInclusiveEnd = -1;
        
        //If this is not a constuctor or destructor
        if(returnIndexInclusiveEnd >= 1)
            prependIndexInclusiveEnd = returnIndexInclusiveEnd - 1;
        
        if(prependIndexInclusiveEnd >= 0)
        {
            for(int i = 0; i <= prependIndexInclusiveEnd; ++i)
                outParser.CurrentFunction.PrependAttributes.push_back(outParser.CurrentTokens[i]);
        }
        
        outParser.CurrentState |= ParseState::IN_FUNCTION_DECLARATION;
        outParser.CurrentParenthesis.push(ParenthesisDetails(true, outParser.CurrentTokens.size()));
        outParser.CurrentTokens.push_back(token);
        return true;
    }
    
    return false;
}

bool ProcessFunction(const std::string& token, Parser& outParser)
{
    if(outParser.CurrentState == ParseState::IN_FUNCTION_DECLARATION)
    {
        if(ProcessFunctionParameters(token, outParser))
            return true;
        
        if(ProcessEndOfFunctionDeclaration(token, outParser))
            return true;
    }
    else if(outParser.CurrentState == ParseState::IN_FUNCTION_DEFINITION)
    {
        if(token == "}")
        {
            if(outParser.CurrentCurlyBrace.top() == CurlyBraceType::FUNCTION_BODY)
            {
                outParser.CurrentCurlyBrace.pop();
                outParser.CurrentTokens.clear();
                outParser.CurrentState &= ~ParseState::IN_FUNCTION_DEFINITION;
                ClearNonBlockParseStates(outParser.CurrentState);
                return true;
            }
        }
    }
    else if(ProcessBeforeFunctionParameters(token, outParser))
        return true;
    
    return false;
}

bool ProcessClass(const std::string& token, Parser& outParser)
{
    if(token == "class")
    {
        outParser.CurrentState |= ParseState::IN_CLASS_DECLARATION;
        outParser.CurrentTokens.push_back(token);
        return true;
    }
    
    if(outParser.CurrentState == ParseState::IN_CLASS_DECLARATION)
    {
        //We reached the beginning of the class definition
        if(token == "{")
        {
            outParser.CurrentState &= ~ParseState::IN_CLASS_DECLARATION;
            outParser.CurrentState |= ParseState::IN_CLASS_DEFINITION;

            //Find the "class" token and get the class name
            if(outParser.CurrentTokens.size() >= 2)
            {
                for(int i = 0; i < outParser.CurrentTokens.size(); ++i)
                {
                    if(outParser.CurrentTokens[i] == "class" && i + 1 < outParser.CurrentTokens.size())
                    {
                        outParser.CurrentClass.Name = outParser.CurrentTokens[i + 1];
                        outParser.CurrentClass.Namespaces = outParser.Namespaces;
                        
                        for(int j = 0; j < i; ++j)
                            outParser.CurrentClass.PrependAttributes.push_back(outParser.CurrentTokens[j]);
                        
                        for(int j = i + 2; j < outParser.CurrentTokens.size(); ++j)
                            outParser.CurrentClass.AppendAttributes.push_back(outParser.CurrentTokens[j]);
                        
                        outParser.ResetTokensForEndOfStatement();
                        outParser.CurrentCurlyBrace.push(CurlyBraceType::CLASS_BODY);
                        return true;
                    }
                }
            }
            
            return false;
        }
        
        //Just a forward declaration, ignore it
        if(token == ";")
        {
            outParser.CurrentState &= ~ParseState::IN_CLASS_DECLARATION;
            outParser.ResetTokensForEndOfStatement();
            return true;
        }
    }
    
    if(outParser.CurrentState == ParseState::IN_CLASS_DEFINITION)
    {
        //Visibility
        {
            //we need to retain the visibility label in the mock class. 
            if(token == "public:" || token == "protected:" || token == "private:")
            {
                outParser.ResetTokensForEndOfStatement();
                
                if(token == "public:")
                {
                    outParser.CurrentState |= ParseState::IN_PUBLIC_SECTION;
                    outParser.CurrentState &= ~ParseState::IN_PRIVATE_SECTION;
                    outParser.CurrentState &= ~ParseState::IN_PROTECTED_SECTION;
                }
                else if(token == "private:")
                {
                    outParser.CurrentState &= ~ParseState::IN_PUBLIC_SECTION;
                    outParser.CurrentState |= ParseState::IN_PRIVATE_SECTION;
                    outParser.CurrentState &= ~ParseState::IN_PROTECTED_SECTION;
                }
                else if(token == "protected:")
                {
                    outParser.CurrentState &= ~ParseState::IN_PUBLIC_SECTION;
                    outParser.CurrentState &= ~ParseState::IN_PRIVATE_SECTION;
                    outParser.CurrentState |= ParseState::IN_PROTECTED_SECTION;
                }
                
                return true;
            }
        }
        
        //Function
        if(ProcessFunction(token, outParser))
            return true;
        
        if( token == "}" && 
            !outParser.CurrentCurlyBrace.empty() && 
            outParser.CurrentCurlyBrace.top() == CurlyBraceType::CLASS_BODY)
        {
            outParser.CurrentCurlyBrace.pop();
            outParser.CurrentState &= ~ParseState::IN_CLASS_DEFINITION;
            outParser.CurrentState &= ~ParseState::IN_PUBLIC_SECTION;
            outParser.CurrentState &= ~ParseState::IN_PRIVATE_SECTION;
            outParser.CurrentState &= ~ParseState::IN_PROTECTED_SECTION;
            outParser.ParsedClasses.push_back(outParser.CurrentClass);
            outParser.CurrentClass = ClassDetails();
            
            outParser.ResetTokensForEndOfStatement();
            ClearNonBlockParseStates(outParser.CurrentState);
            return true;
        }
    }
    
    return false;
}

bool ProcessNamespace(const std::string& token, Parser& outParser)
{
    //Check namespace keyword, if so set IN_NAMESPACE_DECLARATION
    if(token == "namespace")
    {
        outParser.CurrentState |= ParseState::IN_NAMESPACE_DECLARATION;
        outParser.CurrentTokens.push_back(token);
        return true;
    }
    
    if(outParser.CurrentState == ParseState::IN_NAMESPACE_DECLARATION && token == "{")
    {
        for(int i = outParser.CurrentTokens.size() - 1; i >= 0; --i)
        {
            if(outParser.CurrentTokens[i] == "namespace" && i < outParser.CurrentTokens.size() - 1)
            {
                outParser.Namespaces.push_back(outParser.CurrentTokens[i + 1]);
                break;
            }
        }
        
        outParser.CurrentCurlyBrace.push(CurlyBraceType::NAMESPACE_BODY);
        outParser.ResetTokensForEndOfStatement();
        ClearNonBlockParseStates(outParser.CurrentState);
        return true;
    }
    
    if( token == "}" && 
        !outParser.CurrentCurlyBrace.empty() && 
        outParser.CurrentCurlyBrace.top() == CurlyBraceType::NAMESPACE_BODY)
    {
        if(!outParser.Namespaces.empty())
            outParser.Namespaces.pop_back();
        else
        {
            std::cout <<    "WARNING: Namespace close curly brace found" << 
                            " but no namespace was found" << std::endl;
        }
        
        outParser.CurrentCurlyBrace.pop();
        outParser.ResetTokensForEndOfStatement();
        ClearNonBlockParseStates(outParser.CurrentState);
        return true;
    }
    
    return false;
}


void ProcessOthers(const std::string& token, Parser& outParser)
{
    if(token == "{")
    {
        outParser.CurrentTokens.push_back(token);
        outParser.CurrentCurlyBrace.push(CurlyBraceType::UNKNOWN);
        return;
    }
    
    if(token == "}")
    {
        if(!outParser.CurrentCurlyBrace.empty())
        {
            outParser.CurrentCurlyBrace.pop();
            outParser.ResetTokensForEndOfStatement();
            ClearNonBlockParseStates(outParser.CurrentState);
            return;
        }
    }

    if(token == ";")
    {
        outParser.ResetTokensForEndOfStatement();
        ClearNonBlockParseStates(outParser.CurrentState);
        return;
    }
    
    //Unknown token
    outParser.CurrentTokens.push_back(token);
}

void ParseToken(const std::string& token, 
                const std::string& line,
                int lineNumber,
                Parser& outParser)
{
    do
    {
        //Handle Comments
        if(ProcessComments(token, lineNumber, outParser))
            break;
        
        //Preprocessor directives
        if(ProcessPreprocessorDirectives(token, lineNumber, outParser))
            break;

        //Handle namespace
        if(ProcessNamespace(token, outParser))
            break;
        
        //TODO: For { and }, check if it is in double quotes or single quotes
        //      Or rather, handle things in double quote and ignore it

        //Class
        if(ProcessClass(token, outParser))
            break;
        
        ProcessOthers(token, outParser);
    }
    while(0);
    
    outParser.LastLineNumber = lineNumber;
}

// Function to parse a C++ header file
void ParseHeaderFile(   const std::string& filename, 
                        std::vector<ClassDetails>& outClassDetails, 
                        std::vector<std::string>& outIncludes)
{
    std::ifstream file(filename);

    if (!file.is_open()) 
    {
        std::cout << "Error: Unable to open file: " << filename << std::endl;
        return;
    }

    outClassDetails.clear();
    outIncludes.clear();
    
    Parser parser(outClassDetails, outIncludes);
    int currentLineNumber = -1;
    std::string currentLine;

    while(std::getline(file, currentLine))
    {
        //std::cout << "Processing line: " << currentLine << std::endl;
        
        ++currentLineNumber;
        
        if(currentLine.empty())
            continue;
        
        currentLine = Trim(currentLine);
        
        std::string token;
        for(int i = 0; i < currentLine.size(); ++i)
        {
            //If we encountered a character that ends current token
            if(SkippableTokens.find(currentLine[i]) != SkippableTokens.end())
            {
                if(!token.empty())
                {
                    ParseToken(token, currentLine, currentLineNumber, parser);
                    token.clear();
                }
                continue;
            }
            //If we encounter a character that count as a token itself
            else if(CharTokens.find(currentLine[i]) != CharTokens.end())
            {
                if(!token.empty())
                {
                    ParseToken(token, currentLine, currentLineNumber, parser);
                    token.clear();
                }
                
                token += currentLine[i];
                ParseToken(token, currentLine, currentLineNumber, parser);
                token.clear();
                continue;
            }
            else
                token += currentLine[i];
            
            if(i == currentLine.size() - 1)
                ParseToken(token, currentLine, currentLineNumber, parser);
        }
        
        parser.LastLine = currentLine;
    }
    
    file.close();
}

#include <cctype>

void GenerateMockClass( const std::vector<ClassDetails>& classesDetails, 
                        const std::vector<std::string>& includes,
                        const std::vector<std::string>& excludeNames,
                        std::string originalFileName,
                        bool useMacroMethod,
                        bool useInputClasses)
{
    std::string filenameWithoutDir;
    std::unordered_set<std::string> excludeNamesSet;
    for(int i = 0; i < excludeNames.size(); ++i)
        excludeNamesSet.insert(excludeNames[i]);
    
    //Header guard
    {
        std::string headerGuardName;
        int extensionIndex = -1;
        int parentDirIndex = -1;
        
        for(int i = originalFileName.size() - 1; i >= 0; --i)
        {
            if(originalFileName[i] == '.' && extensionIndex == -1)
                extensionIndex = i;
            else if(parentDirIndex == -1 && (originalFileName[i] == '/' || originalFileName[i] == '\\'))
                parentDirIndex = i;
        }
        
        int substrStartIndex = parentDirIndex == -1 ? 0 : parentDirIndex + 1;
        int substrLength =  extensionIndex == -1 ? 
                            originalFileName.size() - substrStartIndex :
                            extensionIndex - substrStartIndex - 1;
        
        headerGuardName = originalFileName.substr(substrStartIndex, substrLength);
        filenameWithoutDir = originalFileName.substr(substrStartIndex);
        
        for(int i = 0; i < headerGuardName.size(); ++i)
        {
            if(headerGuardName[i] == '-')
            {
                headerGuardName[i] = '_';
                continue;
            }
            
            headerGuardName[i] = toupper(headerGuardName[i]);
        }
        
        headerGuardName += "_HPP";
        
        //Output header guard
        std::cout << "#ifndef " << headerGuardName << std::endl;
        std::cout << "#define " << headerGuardName << std::endl << std::endl;
    }
    
    //Output the mock includes
    {
        std::cout << "#include \"CppOverride.hpp\"" << std::endl;
        
        if(useInputClasses)
            std::cout << "#include \"" << filenameWithoutDir << "\"" << std::endl;
        else
        {
            //Output the original includes
            for(int i = 0; i < includes.size(); ++i)
                std::cout << includes[i] << std::endl;
        }
        
        std::cout << std::endl;
    }
    
    //For each class
    std::vector<std::string> currentNamespaces;
    bool changeNamespace = false;
    for(int i = 0; i < classesDetails.size(); ++i)
    {
        if(excludeNamesSet.count(classesDetails[i].Name))
        {
            continue;
        }
        
        for(int j = 0; j < currentNamespaces.size(); ++j)
        {
            if(excludeNamesSet.count(currentNamespaces[j]))
                continue;
        }

        //Namespace check
        {
            if(currentNamespaces.size() != classesDetails[i].Namespaces.size())
                changeNamespace = true;
            else
            {
                for(int j = 0; j < currentNamespaces.size(); ++j)
                {
                    if(currentNamespaces[j] != classesDetails[i].Namespaces[j])
                    {
                        changeNamespace = true;
                        break;
                    }
                }
            }
            
            if(changeNamespace)
            {
                changeNamespace = false;
                
                for(int j = 0; j < currentNamespaces.size(); ++j)
                    std::cout << "}" << std::endl;
                    
                for(int j = 0; j < classesDetails[i].Namespaces.size(); ++j)
                {
                    std::cout << "namespace " << classesDetails[i].Namespaces[j] << std::endl;
                    std::cout << "{" << std::endl << std::endl;
                }
                
                currentNamespaces = classesDetails[i].Namespaces;
            }
        }
        
        //Populate class declaration
        for(int j = 0; j < classesDetails[i].PrependAttributes.size(); ++j)
            std::cout << classesDetails[i].PrependAttributes[j] << " ";
        
        if(!classesDetails[i].PrependAttributes.empty())
            std::cout << std::endl;
        
        std::cout << "class Mock" << classesDetails[i].Name;
        
        if(!useInputClasses)
        {
            for(int j = 0; j < classesDetails[i].AppendAttributes.size(); ++j)
                std::cout << " " << classesDetails[i].AppendAttributes[j];
        }
        else
            std::cout << " : " << "public " << classesDetails[i].Name;

        if(useMacroMethod)
        {
            bool hasInheritance = useInputClasses;
            
            for(int j = 0; j < classesDetails[i].AppendAttributes.size(); ++j)
            {
                if(hasInheritance)
                    break;
                
                const std::string& currentAttribute = classesDetails[i].AppendAttributes[j];
                
                if(currentAttribute.empty())
                    continue;
                
                if(currentAttribute.size() == 1)
                {
                    if(currentAttribute.front() == ':')
                    {
                        hasInheritance = true;
                        break;
                    }
                    else
                        continue;
                }
                
                if(currentAttribute[0] == ':' && currentAttribute[1] != ':')
                {
                    hasInheritance = true;
                    break;
                }
                
                if( currentAttribute[currentAttribute.size() - 1] == ':' && 
                    currentAttribute[currentAttribute.size() - 2] != ':')
                {
                    hasInheritance = true;
                    break;
                }
            }
            
            if(!hasInheritance)
                std::cout << " : ";
            else
                std::cout << ", ";
            
            std::cout << "public CppOverride::MockClass";
        }

        std::cout << std::endl << "{" << std::endl;
        
        if(!useMacroMethod)
        {
            std::cout << "private:" << std::endl;
            std::cout << "    CO_DECLARE_MEMBER_INSTANCE(OverrideInstance);" << std::endl;
            std::cout << std::endl;
            std::cout << "public:" << std::endl;
            std::cout << "    CO_DECLARE_OVERRIDE_METHODS(OverrideInstance);" << std::endl;
            std::cout << std::endl;
        }
        else
            std::cout << "public:" << std::endl;
        
        std::string currentVisibility = "public";
        
        //Add onstructor and destructors
        std::cout << "    inline Mock" << classesDetails[i].Name << "(){}" << std::endl;
        std::cout << "    inline virtual ~Mock" << classesDetails[i].Name << "(){}" << std::endl;

        //Populate functions
        for(int j = 0; j < classesDetails[i].Functions.size(); ++j)
        {
            const FunctionDetails& currentFunc = classesDetails[i].Functions[j];
            
            if(excludeNamesSet.count(currentFunc.Name))
                continue;
            
            if(classesDetails[i].Functions[j].Visibility != currentVisibility)
            {
                std::cout << currentFunc.Visibility << ":" << std::endl;
                currentVisibility = currentFunc.Visibility;
            }
            
            if(currentFunc.ReturnType.empty())
            {
                //std::cout << "    /* Insert Constructor/Destructor Here */" << std::endl;
                //std::cout << std::endl;
                continue;
            }
            
            std::string currentPrepend;
            
            for(int k = 0; k < currentFunc.PrependAttributes.size(); ++k)
            {
                if(currentFunc.PrependAttributes[k] == "inline")
                    continue;
                
                currentPrepend += currentFunc.PrependAttributes[k];
                
                if(k != currentFunc.PrependAttributes.size() - 1)
                    currentPrepend += " ";
            }
            
            std::vector<std::string> filteredPrependAttributes;
            TrimStringVector(currentFunc.PrependAttributes, filteredPrependAttributes);
            ClearStringVectorIfAllEmpty(filteredPrependAttributes);
            if( filteredPrependAttributes.empty() || 
                (filteredPrependAttributes.size() == 1 && 
                filteredPrependAttributes[0] == "inline"))
            {
                currentPrepend = "/* no prepend */";
            }
            
            if(useMacroMethod)
            {
                std::cout << "    CO_MOCK_METHOD(";
                
                if(currentPrepend.find(',') != std::string::npos)
                    std::cout << "(" << currentPrepend << "), ";
                else
                    std::cout << currentPrepend << ", ";
                
                if(currentFunc.ReturnType.find(',') != std::string::npos)
                    std::cout << "(" << currentFunc.ReturnType << "), ";
                else
                    std::cout << currentFunc.ReturnType << ", ";
                    
                std::cout << currentFunc.Name << ", (";
                for(int k = 0; k < currentFunc.ArgTypes.size(); ++k)
                {
                    if(currentFunc.ArgTypes[k].find(',') != std::string::npos)
                        std::cout << "(" << currentFunc.ArgTypes[k] <<")";
                    else
                        std::cout << currentFunc.ArgTypes[k];
                    
                    if(k != currentFunc.ArgTypes.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "), (";
                
                std::vector<std::string> filteredDefaultValues;
                TrimStringVector(currentFunc.ArgDefaultValues, filteredDefaultValues);
                for(int k = 0; k < filteredDefaultValues.size(); ++k)
                {
                    if(!filteredDefaultValues[k].empty())
                        std::cout << "= " << filteredDefaultValues[k];
                    else
                        std::cout << "/* no default */";
                    
                    if(k != currentFunc.ArgTypes.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "), ";
                
                std::vector<std::string> filteredAppendAttributes;
                TrimStringVector(currentFunc.AppendAttributes, filteredAppendAttributes);
                ClearStringVectorIfAllEmpty(filteredAppendAttributes);
                std::string currentAppend;
                for(int k = 0; k < filteredAppendAttributes.size(); ++k)
                {
                    if(filteredAppendAttributes[k] == "=")
                        break;
                    
                    currentAppend += filteredAppendAttributes[k];
                    
                    if(k != filteredAppendAttributes.size() - 1)
                        currentAppend += " ";
                }
                
                if(filteredAppendAttributes.empty())
                    std::cout << "/* no append */";

                if(currentAppend.find(',') != std::string::npos)
                    std::cout << "(" << currentAppend << ")";
                else
                    std::cout << currentAppend;
                
                std::cout << ")" << std::endl;
            }
            else
            {
                bool hasInlineInPrepend = false;
                std::string currentPrepend;
    
                for(int k = 0; k < filteredPrependAttributes.size(); ++k)
                {
                    if(filteredPrependAttributes[k] == "inline")
                        hasInlineInPrepend = true;
    
                    currentPrepend += filteredPrependAttributes[k] + " ";
                }
    
                if(!hasInlineInPrepend)
                    currentPrepend += "inline ";
    
                std::cout <<    "    " << 
                                currentPrepend << 
                                currentFunc.ReturnType << " " << 
                                currentFunc.Name << "(";
                
                for(int k = 0; k < currentFunc.ArgTypes.size(); ++k)
                {
                    std::cout << currentFunc.ArgTypes[k] << " arg" << std::to_string(k);
                    if(!currentFunc.ArgDefaultValues[k].empty())
                        std::cout << " = " << currentFunc.ArgDefaultValues[k];
                    
                    if(k != currentFunc.ArgTypes.size() - 1)
                        std::cout << ", ";
                }
                std::cout << ") ";
                
                for(int k = 0; k < currentFunc.AppendAttributes.size(); ++k)
                {
                    if(currentFunc.AppendAttributes[k] == "=")
                        break;
                    
                    std::cout << currentFunc.AppendAttributes[k] << " ";
                }
                std::cout << std::endl;
                
                std::cout << "    {" << std::endl;
                std::cout << "    ";
                std::cout << "    CO_OVERRIDE_IMPL(OverrideInstanceName, ";
                
                if(currentFunc.ReturnType.find(',') != std::string::npos)
                    std::cout << "(" << currentFunc.ReturnType << "), ";
                else
                    std::cout << currentFunc.ReturnType << ", ";
                
                std::cout << "(";
                for(int k = 0; k < currentFunc.ArgTypes.size(); ++k)
                {
                    std::cout << "arg" << std::to_string(k);
                    
                    if(k != currentFunc.ArgTypes.size() - 1)
                        std::cout << ", ";
                }
                std::cout << "));" << std::endl;
                std::cout << "    }" << std::endl << std::endl;
            }
        }
        
        std::cout << "};" << std::endl << std::endl;
    }
    
    for(int i = 0; i < currentNamespaces.size(); ++i)
        std::cout << "}" << std::endl;
    
    std::cout << "#endif" << std::endl;
}

void PrintMockClassContents(const std::vector<ClassDetails>& classesDetails,
                            const std::vector<std::string>& includes)
{
    std::cout << "Includes: " << std::endl;
    for(int i = 0; i < includes.size(); ++i)
        std::cout << "-   " << includes[i] << std::endl;
    
    std::cout << std::endl;
    
    std::stringstream ss;
    
    for(int i = 0; i < classesDetails.size(); ++i)
    {
        classesDetails[i].ToString("", ss);
        
        
        #if 0
        std::cout << "Class: " << classesDetails[i].Name << std::endl;
        
        std::cout << "    Namespaces:" << std::endl;
        for(int j = 0; j < classesDetails[i].Namespaces.size(); ++j)
            std::cout << "    -   " << classesDetails[i].Namespaces[j] << std::endl;
        
        std::cout << "    PrependAttributes:" << std::endl;
        for(int j = 0; j < classesDetails[i].PrependAttributes.size(); ++j)
            std::cout << "    -   " << classesDetails[i].PrependAttributes[j] << std::endl;
        
        std::cout << "    AppendAttributes:" << std::endl;
        for(int j = 0; j < classesDetails[i].AppendAttributes.size(); ++j)
            std::cout << "    -   " << classesDetails[i].AppendAttributes[j] << std::endl;
        
        for(int j = 0; j < classesDetails[i].Functions.size(); ++j)
        {
            std::cout << "    Function: " << classesDetails[i].Functions[j].Name << std::endl;
            
            {
                std::cout << "        Prepend Attributes: " << std::endl;
                for(int k = 0; k < classesDetails[i].Functions[j].PrependAttributes.size(); ++k)
                {
                    std::cout << "        -   " << classesDetails[i].Functions[j].PrependAttributes[k];
                    if(k < classesDetails[i].Functions[j].PrependAttributes.size() - 1)
                        std::cout << std::endl;
                }
                
                std::cout << std::endl;
            }
            std::cout << "        Return Type: " << classesDetails[i].Functions[j].ReturnType << std::endl;
            
            {
                std::cout << "        Arguments Types: " << std::endl;
                for(int k = 0; k < classesDetails[i].Functions[j].ArgTypes.size(); ++k)
                {
                    std::cout << "        -   " << classesDetails[i].Functions[j].ArgTypes[k];
                    if(k < classesDetails[i].Functions[j].ArgTypes.size() - 1)
                        std::cout << std::endl;
                }
                std::cout << std::endl;

                std::cout << "        Arguments Values: " << std::endl;
                for(int k = 0; k < classesDetails[i].Functions[j].ArgTypes.size(); ++k)
                {
                    std::cout << "        -   \"" << classesDetails[i].Functions[j].ArgDefaultValues[k] << "\"";
                    if(k < classesDetails[i].Functions[j].ArgDefaultValues.size() - 1)
                        std::cout << std::endl;
                }
                std::cout << std::endl;
            }
            
            std::cout << "        Append Attributes: " << std::endl;
            for(int k = 0; k < classesDetails[i].Functions[j].AppendAttributes.size(); ++k)
            {
                std::cout << "        -   " << classesDetails[i].Functions[j].AppendAttributes[k];
                if(k < classesDetails[i].Functions[j].AppendAttributes.size() - 1)
                        std::cout << std::endl;
            }
            
            std::cout << std::endl << std::endl;
        }
        
        std::cout << std::endl;
        #endif
    }
    
    if(ss.rdbuf()->in_avail() != 0)
        std::cout << ss.rdbuf();
}

#include <unordered_set>
#include <unordered_map>

int main(int argc, char** argv) 
{
    auto printHelp = [argv]()
    {
        std::cout << "Usage: " << argv[0] << " [options] <input file>" << std::endl;
        std::cout << "Options: " << std::endl;
        std::cout <<    "-h, --help             " << 
                        "Prints this help message" <<   std::endl;
        
        std::cout <<    "-p, --print            " << 
                        "Prints parsed contents instead of generated mock class" << std::endl;
        
        std::cout <<    "-m, --macro-method     " << 
                        "Use macro methods and inherits from CppOverride::MockClass instead. " << std::endl;
        std::cout <<    "                       " << 
                        "This creates a shorter file but more prone to preprocessing errors." << std::endl;

        std::cout <<    "-i, --use-input-classes" << 
                        "This includes the input file and inherits the classes we are mocking" << std::endl;

        std::cout <<    "-e, --exclude-names    " << 
                        "Anything that matches the specified names (case sensitive) " << std::endl;
        std::cout <<    "                       " << 
                        "will not be generated as mock function/class." << std::endl;
        std::cout <<    "                       " << 
                        "This expects a comma separated list of names" << std::endl;
    };
    
    if(argc < 2)
    {
        //std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        printHelp();
        return 1;
    }
    
    std::unordered_map<std::string, std::string> options;

    std::string inputFile;
    
    std::string previousOption = "";
    
    for(int i = 1; i < argc; ++i)
    {
        std::string current_arg(argv[i]);
        current_arg = Trim(current_arg);
        
        if(current_arg.empty())
            continue;
        
        if(current_arg.size() >= 2 && current_arg[0] == '-')
        {
            options[current_arg] = "";
            previousOption = current_arg;
        }
        else
        {
            if(!previousOption.empty())
            {
                options[previousOption] = current_arg;
            }
            else if(i != argc - 1)
            {
                std::cout << "inputFile must be the last argument" << std::endl;
                return 1;
            }
            
            previousOption = "";
        }
    }
    
    if(options.count("-h") || options.count("--help"))
    {
        printHelp();
        return 0;
    }
    
    std::string lastArg(argv[argc - 1]);
    if(lastArg[0] != '-')
        inputFile = lastArg;
    
    if(inputFile.empty())
    {
        std::cout << "input file not supplied" << std::endl;
        return 1;
    }
    
    std::vector<ClassDetails> classesDetails;
    std::vector<std::string> includes;
    ParseHeaderFile(inputFile, classesDetails, includes);
    std::vector<std::string> excludeNames;
    
    if(options.count("-e") || options.count("--exclude-names"))
    {
        const std::string& excludeString =  options.count("-e") ? 
                                            options.at("-e") : 
                                            options.at("-exclude-names");
        
        int lastIndex = 0;
        for(int i = 0; i < excludeString.size(); ++i)
        {
            if(excludeString[i] == ',' || i == excludeString.size() - 1)
            {
                excludeNames.emplace_back(Trim(excludeString.substr(lastIndex, 
                                                                    excludeString[i] == ',' ?
                                                                    i - lastIndex :
                                                                    i - lastIndex + 1)));
                
                lastIndex = i + 1;
            }
        }
    }
   
    if(options.count("-p") || options.count("--print"))
        PrintMockClassContents(classesDetails, includes);
    else
    {
        GenerateMockClass(  classesDetails, 
                            includes, 
                            excludeNames,
                            inputFile, 
                            options.count("-m") || options.count("--macro-method"), 
                            options.count("-i") || options.count("--use-input-classes"));
    }

    return 0;
}
