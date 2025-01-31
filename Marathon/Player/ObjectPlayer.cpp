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

void Sonicteam::Player::ObjectPlayer::RemovePlugin(std::string plugin)
{

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IPlugIn>>::iterator it = this->PlayerPlugins.begin(); 
		it != this->PlayerPlugins.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerPlugins.erase(it); // Erase returns the next iterator
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IVariable>>::iterator it = this->PlayerIVarible.begin(); 
		it != this->PlayerIVarible.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerIVarible.erase(it);
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>::iterator it = this->PlayerIDynamicLink.begin(); 
		it != this->PlayerIDynamicLink.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerIDynamicLink.erase(it);
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IFlagCommunicator>>::iterator it = this->PlayerIFlagCommunicator.begin(); 
		it != this->PlayerIFlagCommunicator.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerIFlagCommunicator.erase(it);
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = this->PlayerIStepable1.begin(); 
		it != this->PlayerIStepable1.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerIStepable1.erase(it);
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = this->PlayerIStepable2.begin(); 
		it != this->PlayerIStepable2.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerIStepable2.erase(it);
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = this->PlayerIStepable3.begin(); 
		it != this->PlayerIStepable3.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this->PlayerIStepable3.erase(it);
			} else {
				++it;
			}
	}

	for (std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = this->PlayerIStepable4.begin(); 
		it != this-> PlayerIStepable4.end(); ) {
			if (PluginMatcher(plugin)(*it)) {
				it = this-> PlayerIStepable4.erase(it);
			} else {
				++it;
			}
	}


	for (std::vector<boost::shared_ptr<Sonicteam::Player::IExportExternalFlag>>::iterator it = this-> PlayerIExportExternalFlag.begin(); 
		it != this-> PlayerIExportExternalFlag.end(); ) {
			if (PluginMatcher(plugin)(*it)) { 
				it = this -> PlayerIExportExternalFlag.erase(it); 
			} else { 
				++it; 
			} 
	}

	for (std::vector<boost::shared_ptr<Sonicteam:: Player :: IExportPostureRequestFlag>>::iterator it = this -> PlayerIExportPostureRequestFlag.begin();
		it != this -> PlayerIExportPostureRequestFlag.end();) { 
			if (PluginMatcher(plugin)(*it)) { 
				it = this -> PlayerIExportPostureRequestFlag.erase(it); 
			} else { 
				++it; 
			} 
	}

	for (std :: vector < boost :: shared_ptr < Sonicteam :: Player :: IExportWeaponRequestFlag >> :: iterator it = this -> PlayerIExportWeaponRequestFlag.begin();
		it != this -> PlayerIExportWeaponRequestFlag.end();) { 
			if (PluginMatcher(plugin)(*it)) { 
				it = this -> PlayerIExportWeaponRequestFlag.erase(it); 
			} else { 
				++it; 
			} 
	}

	for (std :: vector < boost :: shared_ptr < Sonicteam :: Player :: IImportAnimation >> :: iterator it = this -> PlayerIImportAnimation.begin();
		it != this -> PlayerIImportAnimation.end();) { 
			if (PluginMatcher(plugin)(*it)) { 
				it = this -> PlayerIImportAnimation.erase(it); 
			} else { 
				++it; 
			} 
	}

	for (std :: vector < boost :: shared_ptr < Sonicteam :: Player :: INotification >> :: iterator it = this -> PlayerINotification.begin();
		it != this -> PlayerINotification.end();) { 
			if (PluginMatcher(plugin)(*it)) { 
				it = this -> PlayerINotification.erase(it); 
			} else { 
				++it; 
			} 
	}


	for (std :: vector < boost :: shared_ptr < Sonicteam :: Player :: IEventerListener >> :: iterator it = this -> PlayerEventer->EventerListener.begin();
		it != this -> PlayerEventer->EventerListener.end();) { 
			if (PluginMatcher(plugin)(*it)) { 
				it = this -> PlayerEventer->EventerListener.erase(it); 
			} else { 
				++it; 
			} 
	}

}
