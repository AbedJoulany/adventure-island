//#pragma once
//#include <map>
//#include "Entity.h"
//#include <string>
//
//using std::map;
//using std::string;
//
//typedef Entity* (__stdcall* CreateEntityFn)(void);
//
//class Factory {
//
//private:
//    Factory();
//    Factory(const Factory&);
//    Factory& operator=(const Factory&) { return *this; }
//
//    typedef map<string, Entity*> FactoryMap;
//    FactoryMap m_FactoryMap;
//public:
//    ~Factory();
//
//    static Factory* getInstance()
//    {
//        static Factory instance;
//        return &instance;
//    }
//
//    void Register(const string& name, CreateEntityFn pfnCreate);
//    Entity* CreateEntity(const string& name);
//};
