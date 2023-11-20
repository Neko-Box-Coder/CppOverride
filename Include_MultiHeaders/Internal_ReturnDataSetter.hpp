#ifndef CO_INTERNAL_RETURN_DATA_SETTER_HPP
#define CO_INTERNAL_RETURN_DATA_SETTER_HPP

#include "./ProxiesDeclarations.hpp"
#include "./Internal_OverrideReturnData.hpp"
#include "./Internal_OverrideReturnDataList.hpp"
#include "./ProxiesDeclarations.hpp"
#include "./StaticAssertFalse.hpp"
#include "./Any.hpp"

#include <iostream>
#include <unordered_map>

namespace CppOverride
{
    class Internal_ReturnDataSetter
    {
        friend class ReturnProxy;
    
        public:
            using ReturnInfosType = std::unordered_map<std::string, Internal_OverrideReturnDataList>;
        
        protected:
            ReturnInfosType& OverrideReturnInfos;
            
            //------------------------------------------------------------------------------
            //Methods for setting return data
            //------------------------------------------------------------------------------
            template<typename T>
            inline ReturnProxy& ReturnsByAction(ReturnProxy& proxy, 
                                                std::function<void( const std::vector<void*>& args, 
                                                                    void* out)> returnAction)
            {
                static_assert(  !std::is_same<T, Any>(), "You can't return nothing in return action");

                Internal_OverrideReturnData& lastData = 
                    OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back();

                lastData.ReturnDataInfo.DataAction = returnAction;
                lastData.ReturnDataInfo.DataActionSet = true;
                lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
                return proxy;
            }
            
            template<typename T>
            inline ReturnProxy& Returns(ReturnProxy& proxy, T returnData)
            {
                if(!std::is_same<T, Any>())
                {
                    Internal_OverrideReturnData& lastData = 
                        OverrideReturnInfos[proxy.FunctionSignatureName].ReturnDatas.back();
                    
                    lastData.ReturnDataInfo.Data = new T(returnData);
                    lastData.ReturnDataInfo.CopyConstructor = 
                        [](void* data) { return new T(*static_cast<T*>(data)); };
                    
                    lastData.ReturnDataInfo.Destructor = 
                        [](void* data) { delete static_cast<T*>(data); }; 
                    
                    lastData.ReturnDataInfo.DataSet = true;
                    lastData.ReturnDataInfo.DataType = typeid(T).hash_code();
                }
                
                return proxy;
            }
            
            template<typename T>
            inline ReturnProxy& ReturnsReference(ReturnProxy& proxy, T& returnData)
            {
                return Returns(proxy, &returnData);
            }
            
        public:
            inline Internal_ReturnDataSetter(ReturnInfosType& overrideReturnInfos) : 
                OverrideReturnInfos(overrideReturnInfos)
            {}
    };
}


#endif