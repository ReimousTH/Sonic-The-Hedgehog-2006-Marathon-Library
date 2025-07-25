#include "ApplicationXenon.h"
#include <Sox/ErrorMSG.h>


using namespace Sonicteam::SoX;


void ApplicationXenon::ProcessDoc(double delta){
	this->AppDoc->EngineDocOnUpdate(delta);
	this->OnDocAfter();
}


void ApplicationXenon::ProcessXAM(){

	DWORD ID;
	ULONG prm;
	DWORD _lock1 = Lock1;
	if (XNotifyGetNext(HNotification,0,&ID,&prm) ){

		if ((ID != XN_SYS_UI && ID == XN_SYS_SIGNINCHANGED)){

			XUSER_SIGNIN_STATE _state =  LastSignInState;
			XUSER_SIGNIN_STATE _nstate =  XUserGetSigninState(SignInUserIndex);
			if (SignInUserIndex != 0xFF && _state != LastSignInState ){
				LastSignInState = _state;
				if (_state == XUSER_SIGNIN_STATE::eXUserSigninState_NotSignedIn && (_nstate == XUSER_SIGNIN_STATE::eXUserSigninState_SignedInLocally || _nstate == XUSER_SIGNIN_STATE::eXUserSigninState_SignedInToLive)){
					IsUserSign = 1;
				}
				else if (_nstate == XUSER_SIGNIN_STATE::eXUserSigninState_NotSignedIn){
					IsUserSign = 1;
				}	
			}
			for (int i = 0;i<4;i++){

				for (int j = 0;j<2;j++){
					XUserSetContext(i,j,DefaultUserContextValue[j]);
				}
				XUserSetContext(i,X_CONTEXT_PRESENCE,DefaultUserContextPresence);
			}
		}
		else{
			_lock1 = prm;
			Lock3 = prm;
			if (!prm) Lock2 = 0;
		}
	}
	Lock1 = _lock1;
}







void ApplicationXenon::ProcessXAM2(){

	DWORD _lock1 = this->Lock1;

	if (this->IsUserSign && !this->Lock3){

		if (this->ConfirmMessageNotify5){
			if (ConfirmMessageNotify1 == 0x3E5){
				_lock1 = 1;
			}
			else{
				this->IsUserSign = 0;
				this->ToTitle = 1;
				this->ConfirmMessageNotify5 = 0;
			}
		}
		else{
			size_t _region =  this->GetRegion();
			this->ConfirmMessageNotify1 = 0;
			this->ConfirmMessageNotify2 = 0;
			this->ConfirmMessageNotify3 = 0;
			this->ConfirmMessageNotify4 = 0;
			XShowMessageBoxUI(0xFF,Sonicteam::ErrorMSG::SONICNEXT,Sonicteam::ErrorMSG::SignInStatusChangedMSG[_region],1,&Sonicteam::ErrorMSG::ConfirmMSG[_region],0,1,&SignInStatusChangedMSGResult,0);
			this->ConfirmMessageNotify5 = 1;

		}
	}





	this->Lock1 = _lock1 == 0;


}


void ApplicationXenon::ProcessXAM3()
{
	DWORD _lock1 =  this->Lock1;
	if (this->NotifyTargetSignInState == 1){
		if (this->NotifyTargetSignInStateMSG == 0x3E5){
			_lock1 = 1;
		}
		else{
			this->NotifyTargetSignInState = 0;
			this->LastSignInState = XUserGetSigninState(SignInUserIndex);
		}
	}
	this->Lock1 = !_lock1;
}












void ApplicationXenon::Run()
{
	this->_Run();
}




bool ApplicationXenon::HandleMessage(size_t id,size_t flag1,size_t)
{
	switch (id){
		case MARATHON_APP_XENON_MESSAGE_D3D_SETTHREADOWNERSHIP:
			_D3DDevice->SetThreadOwnership(GetCurrentThreadId());
			return 1;
		case MARATHON_APP_XENON_MESSAGE_D3D_2:
			_D3DDevice->Resume(); // I THINK ????? 
			return 1;
		case MARATHON_APP_XENON_MESSAGE_XAM_RESIGN:
			this->ProcessXAM();
			this->ProcessXAM2();
			//Code later
			return 1;
		case MARATHON_APP_XENON_MESSAGE_3:
			return 1;
		case MARATHON_APP_XENON_MESSAGE_4:
			return 1;
		case MARATHON_APP_XENON_MESSAGE_GETSIGNINSTATE:
			return XUserGetSigninState(flag1) != 0;
		case MARATHON_APP_XENON_MESSAGE_SIGNIN:
			//code later
			return 1;
		case MARATHON_APP_XENON_MESSAGE_READ_PROFILESETTINGS:
			//later
			return 1;
		case MARATHON_APP_XENON_MESSAGE_SHOW_DEVICE_SELECTOR_UI:
			//later
			return 1;
		case MARATHON_APP_XENON_MESSAGE_GET_CONTENT_DEVICE_STATE:
			return 1;

		case MARATHON_APP_XENON_MESSAGE_GET_SAVE_CREATOR:
			return 1;

		case MARATHON_APP_XENON_MESSAGE_B:
			return 1;
		case MARATHON_APP_XENON_MESSAGE_C:
			return 1;
		case MARATHON_APP_XENON_MESSAGE_D:
			return 1;
		case MARATHON_APP_XENON_MESSAGE_RESET:
			return 1;

	}
}

bool ApplicationXenon::D3DSetShaderGPRAllocation()
{
	_D3DDevice->SetShaderGPRAllocation(0,ShaderVertexCount,PixelShaderCount);
	return 1;
}

void ApplicationXenon::D3DRenderFrameAndSwapBuffers()
{
	_D3DDevice->SetShaderGPRAllocation(0,0,0);
	_D3DDevice->SynchronizeToPresentationInterval();
	_D3DDevice->Resolve(0,0,FrontBufferTexture,0,0,0,0,0.0,0,0);
	_D3DDevice->Swap(this->FrontBufferTexture,0);
}

char ApplicationXenon::IsPause()
{
	return Lock1 | Lock2 | Lock3;
}

char ApplicationXenon::IsReturnToTitle()
{
	return ToTitle;
}


size_t ApplicationXenon::GetRegion()
{


	switch (DWORD region =  XGetGameRegion()) {
	case XC_GAME_REGION_NA_ALL:
	case XC_GAME_REGION_ASIA_JAPAN:
	case XC_GAME_REGION_ASIA_CHINA:
	case XC_GAME_REGION_ASIA_REST:
	case XC_GAME_REGION_ASIA_ALL:
		return 0;

	case XC_GAME_REGION_EUROPE_AUNZ:
	case XC_GAME_REGION_EUROPE_REST:
		return 2;

	default:
		if (region > XC_GAME_REGION_RESTOFWORLD_ALL) {
			return 1;
		} else if (region > XC_GAME_REGION_EUROPE_ALL) {
			return 2; // 
		} else {
			return 0; //
		}
	}
}

size_t ApplicationXenon::GetLocale()
{
	//not sure what function but should be close 
	switch (XGetLocale()){
		case 1:
			return 1;
		case 2:
			return 0;
		case 3:
			return 3;
		case 4:
			return 2;
		case 5:
			return 5;
		case 6:
			return 4;
		default:
			return 0;
	}
}




bool ApplicationXenon::WriteSaveFile(const char* SaveFileName,void* SaveFileBuffer,size_t SaveFileSize)
{
	bool _result = false;
	XCONTENT_DATA contentData = {0};
	strcpy_s( contentData.szFileName, SaveFileName );
	wcscpy_s( contentData.szDisplayName, Sonicteam::ErrorMSG::SONICNEXT );
	contentData.dwContentType = XCONTENTTYPE_SAVEDGAME;
	contentData.DeviceID = XDeviceUI;
	if (XContentCreate(SignInUserIndex,"save",&contentData,XCONTENTFLAG_CREATEALWAYS,NULL,NULL,NULL)){
		char save_file_name[64];
		sprintf((char*)&save_file_name,"save:\\%s",SaveFileName);

		// Create the file using Windows API
		HANDLE SaveHandle =  CreateFileA((const char*)&save_file_name,GENERIC_WRITE,0,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
		if (SaveHandle != INVALID_HANDLE_VALUE){
			DWORD out_size;
			if (WriteFile(SaveHandle,SaveFileBuffer,SaveFileSize,&out_size,0)) _result = true;
			CloseHandle(SaveHandle);
		}
		XContentClose("save",NULL);
	}
	return _result;
}

bool ApplicationXenon::ReadSaveFile(const char* SaveFileName,void* ReadFileBuffer,size_t ReadFileSize)
{
	bool _result = false;
	XCONTENT_DATA contentData = {0};
	strcpy_s( contentData.szFileName, SaveFileName );
	wcscpy_s( contentData.szDisplayName, Sonicteam::ErrorMSG::SONICNEXT );
	contentData.dwContentType = XCONTENTTYPE_SAVEDGAME;
	contentData.DeviceID = XDeviceUI;
	if (XContentCreate(SignInUserIndex,"save",&contentData,XCONTENTFLAG_OPENEXISTING,NULL,NULL,NULL)){
		char save_file_name[64];
		sprintf((char*)&save_file_name,"save:\\%s",SaveFileName);

		HANDLE SaveHandle =  CreateFile((const char*)&save_file_name,GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
		if (SaveHandle != INVALID_HANDLE_VALUE){
	
			DWORD save_size = GetFileSize(SaveHandle,0);
			if (save_size == ReadFileSize &&  ReadFile(SaveHandle,ReadFileBuffer,ReadFileSize,&save_size,0)) _result = true;
			CloseHandle(SaveHandle);
		}
		XContentClose("save",NULL);
	}
	return _result;
}

bool ApplicationXenon::CreateContent(const char* ContentName)
{
	bool _result = false;
	XCONTENT_DATA contentData = {0};
	strcpy_s( contentData.szFileName, ContentName );
	contentData.dwContentType = XCONTENTTYPE_SAVEDGAME;
	contentData.DeviceID = XDeviceUI;
	if (XContentCreate(SignInUserIndex,"save",&contentData,XCONTENTFLAG_OPENEXISTING,NULL,NULL,NULL)){
		_result = true;
		XContentClose("save",NULL);
	}
	return _result;
}


void ApplicationXenon::GetDownloadContent(std::vector<std::string>& content)
{
	//No idea what it doiess

}
void ApplicationXenon::AppUnk0x38()
{

}

void ApplicationXenon::OnDocAfter()
{

}



ApplicationXenon::~ApplicationXenon(void)
{

}

ApplicationXenon::ApplicationXenon(void)
{

}



void ApplicationXenon::_Run()
{
	LARGE_INTEGER unk0x58;
	LARGE_INTEGER unk0x60;
	LARGE_INTEGER unk0x68;
	LARGE_INTEGER unk0x70;
	LARGE_INTEGER unk0x90;
	LARGE_INTEGER unk0x98;
	Sonicteam::SoX::PerformanceFrequency::QueryFrequency();
	Sonicteam::SoX::PerformanceFrequency::QPerfomanceCounter(&unk0x58);
	for (;!IsDisabled;){


		Sonicteam::SoX::PerformanceFrequency::QPerfomanceCounter(&unk0x60);
		ProcessXAM();
		ProcessXAM2();
		ProcessXAM3();
		Sonicteam::SoX::PerformanceFrequency::QPerfomanceCounter(&unk0x68);
		LARGE_INTEGER unk0x68_unk0x58_calc; unk0x68_unk0x58_calc.QuadPart =  unk0x68.QuadPart - unk0x58.QuadPart;
		unk0x58.QuadPart = unk0x68.QuadPart;
		unk0x70 = Sonicteam::SoX::PerformanceFrequency::PerfomanceScaleEX(&unk0x68_unk0x58_calc);

		
		ProcessDoc(	((double)unk0x70.QuadPart * 0.000001));
		Sonicteam::SoX::PerformanceFrequency::QPerfomanceCounter(&unk0x90);
		LARGE_INTEGER unk0x90_unk0x60_calc; unk0x90_unk0x60_calc.QuadPart =  unk0x90.QuadPart - unk0x60.QuadPart;
		LARGE_INTEGER end_scale =  Sonicteam::SoX::PerformanceFrequency::PerfomanceScaleEX(&unk0x90_unk0x60_calc);
		this->PefScalePre.QuadPart = end_scale.QuadPart;

		Sonicteam::SoX::PerformanceFrequency::QPerfomanceCounter(&unk0x98);
		LARGE_INTEGER unk0x98_unk0x60_calc; unk0x98_unk0x60_calc.QuadPart =  unk0x98.QuadPart - unk0x60.QuadPart;
		LARGE_INTEGER last_scale =  Sonicteam::SoX::PerformanceFrequency::PerfomanceScaleEX(&unk0x98_unk0x60_calc);
		this->PerfScalePost.QuadPart = last_scale.QuadPart;

	}
}

DWORD Sonicteam::SoX::ApplicationXenon::SignInUserIndex = 0xFF;

DWORD Sonicteam::SoX::ApplicationXenon::XDeviceUI = 0xFF;

ApplicationXenon*& Sonicteam::SoX::ApplicationXenon::ApplicationXenonMarathon = *(ApplicationXenon**)0x82D3B6E8;
DESTRUCTION_CPP(ApplicationXenon);