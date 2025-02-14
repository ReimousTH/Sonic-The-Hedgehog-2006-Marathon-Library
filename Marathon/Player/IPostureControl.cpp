#include "IPostureControl.h"
using namespace Sonicteam::Player;


Sonicteam::Player::IPostureControl::IPostureControl(REF_TYPE(Sonicteam::Player::RootFrame) RootFrame,REF_TYPE(Sonicteam::SoX::Physics::Havok::WorldHavok) WorldHavok)
{
	this->RootFrame = RootFrame;
	this->RotationFixed = XMVectorSet(0,0,0,1);
	this->RotationFixed = XMVectorSet(0,0,0,1);
	this->WorldHavok = WorldHavok;
	this->PostureTask =0;
	this->GravityDirection = XMVectorSet(0,-1,0,1);
	this->GravityDirectionPower = 0;
	this->NormalizedSurface = XMVectorSet(0,0,0,1);
	this->Position = XMVectorSet(0,0,0,1);
	this->Rotation = XMVectorSet(0,0,0,1);
	this->unk0xD0 = XMVectorSet(0,0,0,1);
	this->ImpulseFlag = 1;
	this->ImpulseZX = 0;
	this->ImpulseY =0;
	this->ImpulseVectorUP = XMVectorSet(0,1,0,1);
	this->PostureFlag0x110 = 0;
	this->IPostureControlFlag0x114.PostureFlag0x114 = 0;
	this->IPostureControlFlag0x114.PostureFlag0x118 = 0;

}

Sonicteam::Player::IPostureControl::~IPostureControl(void)
{

}

void Sonicteam::Player::IPostureControl::IPostureControlStep(double delta)
{
	if (Sonicteam::Player::State::ICommonContextIF* context =  this->IContextIF.get()){
		this->ImpulseZX = context->GetTotalSpeedZ();
		this->ImpulseY = context->GetTotalSpeedY();
	}
	if ((this->IPostureControlFlag0x114.PostureFlag0x114 &  0x8000) == 0){
		this->IPostureControlImport(PlayerGetTransformData(),1.0);
	}
	else{
		Sonicteam::Player::Input::IListener* AmigoAI = this->AmigoListener.get();
		if (AmigoAI->IsListenerEnabled()){
			this->IPostureControlImport(*AmigoAI->ListenerGetStickVector4(delta,0),delta);
		}
		else{
			Sonicteam::Player::Input::IListener* InputListener = this->InputListener.get();
			this->IPostureControlImport(*InputListener->ListenerGetStickVector4(delta,0),delta);
		}
	}
	/* not implemented yet :)
	if (Sonicteam::Player::Gravity* gravity = this->Gravity.get()){
		gravity->
	}
	*/
}

//custom 821F1B38
XMVECTOR Sonicteam::Player::IPostureControl::PlayerGetTransformData()
{
	if (!this->PostureTask) return XMVectorSet(0,0,0,1);
	Sonicteam::SoX::MessageTemplate<0x40> Message = Sonicteam::SoX::MessageTemplate<0x40>(0x1300C); // Get Actor
	this->PostureTask->OnMessageRecieved(&Message); // Get Actor ID 
	Sonicteam::Actor* actor =  this->ActorManager->SearchActorByID(*Message.GetValueAtRef<unsigned int>(0));
	if (!actor) return XMVectorSet(0,0,0,1);

	Sonicteam::SoX::MessageTemplate<0x50> ActorTransformMessage = Sonicteam::SoX::MessageTemplate<0x50>(0x10009); //Get Transform
	
	XMMATRIX ActorTransform;
	actor->OnMessageRecieved(&ActorTransformMessage);
	ActorTransform = ActorTransformMessage.GetValueAt<XMMATRIX>(0x10); //since padding
	XMVECTOR ActorTransformCord =  XMVector3Transform(XMVectorSet(0,0,1,1),ActorTransform); //missing store VectorForward to Matrix 0x0 

	return CreateRotationQuaternionFromXMVectors(ActorTransformCord,XMVectorSet(0,0,1,1),XMVectorSet(0,1,0,1));


}

DESTRUCTION_CPP(IPostureControl);