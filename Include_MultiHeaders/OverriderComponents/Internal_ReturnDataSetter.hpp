#ifndef CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_SETTER_HPP
#define CO_OVERRIDER_COMPONENTS_INTERNAL_RETURN_DATA_SETTER_HPP

//#include "./ProxiesDeclarations.hpp"
//#include "./Internal_OverrideReturnData.hpp"
//#include "./Internal_OverrideReturnDataList.hpp"
#include "../OverrideInfoSetterDeclaration.hpp"
#include "../Internal_OverrideData.hpp"
#include "./StaticAssertFalse.hpp"
#include "./Any.hpp"

#include <iostream>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ReturnDataSetter
    {
        public:
            using OverrideDatas = std::unordered_map<std::string, Internal_OverrideDataList>;
        
        protected:
            OverrideDatas& CurrentOverrideDatas;
            
            //------------------------------------------------------------------------------
            //Methods for setting return data
            //------------------------------------------------------------------------------
            template<typename T>
            inline OverrideInfoSetter& 
            ReturnsByAction(OverrideInfoSetter& infoSetter, 
                            std::function<void( const std::vector<void*>& args, 
                                                void* out)> returnAction)
            {
                static_assert(!std::is_same<T, Any>(), "You can't return nothing in return action");

                Internal_OverrideData& lastData = 
                    CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();

                lastData.ReturnDataActionInfo.DataAction = returnAction;
                lastData.ReturnDataActionInfo.DataActionSet = true;
                lastData.ReturnDataActionInfo.DataType = typeid(T).hash_code();
                return infoSetter;
            }
            
            template<typename T>
            inline OverrideInfoSetter& Returns(OverrideInfoSetter& infoSetter, T returnData)
            {
                if(!std::is_same<T, Any>())
                {
                    Internal_OverrideData& lastData = 
                        CurrentOverrideDatas[infoSetter.GetFunctionSignatureName()].back();
                    
                    lastData.ReturnDataInfo.Data = new T(returnData);
                    lastData.ReturnDataInfo.CopyConstructor = 
                        [](void* data) { return new T(*static_cast<T*>(data)); };
                    
                    lastData.ReturnDataInfo.Destructor = 
                        [](void* data) { delete static_cast<T*>(data); }; 
                    
                    lastData.ReturnDataInfo.DataSet = true;
                    lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
                }
                
                return infoSetter;
            }
            
            template<typename T>
            inline OverrideInfoSetter& ReturnsReference(OverrideInfoSetter& infoSetter, T& returnData)
            {
                return Returns(infoSetter, &returnData);
            }
            
        public:
            inline Internal_ReturnDataSetter(OverrideDatas& overrideDatas) : 
                CurrentOverrideDatas(overrideDatas)
            {}
    };
}


#endif