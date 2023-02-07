//#include "Factory.h"
//#include "Hero.h"
//
//Factory::Factory()
//{
//	//Register("hero", &Hero::Create);
//}
//
//Factory::Factory(const Factory&)
//{
//}
//
//Factory::~Factory()
//{
//	m_FactoryMap.clear();
//}
//
//void Factory::Register(const string& name, CreateEntityFn pfnCreate)
//{
//	m_FactoryMap[name] = pfnCreate;
//
//}
//
//Entity* Factory::CreateEntity(const string& name)
//{
//	FactoryMap::iterator it = m_FactoryMap.find(name);
//	if (it != m_FactoryMap.end())
//		return it->second();
//	return nullptr;
//}
