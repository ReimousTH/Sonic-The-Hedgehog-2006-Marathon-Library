#include "ObjectPlayer.h"

using namespace Sonicteam::Player;


int Sonicteam::Player::ObjectPlayer::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	return 0;
}



char* Sonicteam::Player::ObjectPlayer::GetObjectType()
{
	return "ObjectPlayer";
}

void Sonicteam::Player::ObjectPlayer::OnTaskUpdate(float)
{
	
}

#define RemovePluginName(vector_it, vectorType, pluginname) \
	for (std::vector<boost::shared_ptr<vectorType>>::iterator it = vector_it.begin(); it != vector_it.end(); ) { \
		if (PluginMatcher(pluginname)(*it)) { \
			it = vector_it.erase(it); \
		}\
		else\
		{\
			it++;\
		}\
	}\

void Sonicteam::Player::ObjectPlayer::RemovePlugin(std::string plugin)
{
	RemovePluginName(this->PlayerPlugins,Sonicteam::Player::IPlugIn,plugin);
	RemovePluginName(this->PlayerIVarible,Sonicteam::Player::IVariable,plugin);
	RemovePluginName(this->PlayerIDynamicLink,Sonicteam::Player::IDynamicLink,plugin);
	RemovePluginName(this->PlayerIFlagCommunicator,Sonicteam::Player::IFlagCommunicator,plugin);
	RemovePluginName(this->PlayerIStepable1,Sonicteam::Player::IStepable,plugin);
	RemovePluginName(this->PlayerIStepable2,Sonicteam::Player::IStepable,plugin);
	RemovePluginName(this->PlayerIStepable3,Sonicteam::Player::IStepable,plugin);
	RemovePluginName(this->PlayerIStepable4,Sonicteam::Player::IStepable,plugin);
	RemovePluginName(this->PlayerIExportExternalFlag,Sonicteam::Player::IExportExternalFlag,plugin);
	RemovePluginName(this->PlayerIExportPostureRequestFlag,Sonicteam::Player::IExportPostureRequestFlag,plugin);
	RemovePluginName(this->PlayerIExportWeaponRequestFlag,Sonicteam::Player::IExportWeaponRequestFlag,plugin);
	RemovePluginName(this->PlayerIImportAnimation,Sonicteam::Player::IImportAnimation,plugin);
	RemovePluginName(this->PlayerINotification,Sonicteam::Player::INotification,plugin);
	RemovePluginName(this->PlayerEventer->EventerListener,Sonicteam::Player::IEventerListener,plugin);


}






boost::shared_ptr<Sonicteam::Player::IPlugIn> Sonicteam::Player::ObjectPlayer::FindPluginLast(std::string plugin) {
	for (std::vector<boost::shared_ptr<Sonicteam::Player::IPlugIn>>::reverse_iterator it = this->PlayerPlugins.rbegin(); it != this->PlayerPlugins.rend(); ++it) {
		if (PluginMatcher(plugin)(*it)) {
			return *it; // Return the last matching plugin
		}
	}
	return boost::shared_ptr<Sonicteam::Player::IPlugIn>((Sonicteam::Player::IPlugIn*)(0)); // Return nullptr if no matching plugin is found
}