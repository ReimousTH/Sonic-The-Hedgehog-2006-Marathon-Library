#pragma once


#ifndef __MARATHON__
#define __MARATHON__

#include <Head.h>

#define LAST_IND(x,part_type)    (sizeof(x)/sizeof(part_type) - 1)
#define LOW_IND(x,part_type)   LAST_IND(x,part_type)
#define HIGH_IND(x,part_type)  0

#define DWORDn(x, n)  (*((_DWORD*)&(x)+n))
#define LODWORD(x) DWORDn(x,LOW_IND(x,_DWORD))
#define HIDWORD(x) DWORDn(x,HIGH_IND(x,_DWORD))




//#include <xtl.h>
//#include <cassert>
//#include <boost/smart_ptr.hpp>
//#
//# 
#ifndef  __BASICS_
#include "../Basics.h"
#endif
#include <xstring>
//#include <xstring>

#define _DWORD DWORD
#define _BYTE BYTE

struct CmnEffect02
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	int field_10;
	int field_14;
	int field_18;
};


struct NORT
{
	_DWORD dword0;
	_BYTE byte4;
	_BYTE gap5[15];
	_DWORD dword14;
	_DWORD dword18;
};



#define Make06String(ths,str) BranchTo(0x821620E8,int,ths,str);


#define Free06String(ths)  if (    *(DWORD*)(((DWORD)ths) + 0x18) >= 0x10   ) CBranchTo(0x82186190,__cdecl,int, *(DWORD*)    (((DWORD)ths)+0x4)  );


#define std_string_assign(strths,strright,roff,count) CBranchTo(0x82161D10,__cdecl,int,strths,strright,roff,count);

#define std_string_assign2(strths,charpstr,sizet) CBranchTo(0x82161E08,__fastcall,int,strths,charpstr,sizet);



DWORD _std_string_getpointer(int* str);


#define std_string_getpointer(strths) (char*)_std_string_getpointer((int*)strths);



FastcallFunctionPointer(int*,MarahonFindPluginByName,(int,int),0x825F7420);
FastcallFunctionPointer(int*,sub_8226F0D0,(float*,int,char*),0x8226F0D0);
FastcallFunctionPointer(int*,LoadAndInitLuaResource,(DWORD IResource,DWORD std_str),0x82163620);







typedef struct DocMarathonStateS;








struct __declspec(align(4)) DocMarathonStateSO1
{
	DocMarathonStateS *DocMarathonState;
	int gap4;
	int field_8;
	int field_C;
	int field_10;
	_DWORD *pdword14;
};


struct __declspec(align(4)) DocMarathonStateS
{
	int vtable;
	int field_4;
	int field_8;
	int (__fastcall *GetGraphicDevice)(DocMarathonStateSO1 *);
	int field_10;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	void (__fastcall *pfunc34)(DocMarathonStateSO1 *, _DWORD, int);
	int gap38;
	int field_3C;
	int field_40;
	int field_44;
	int field_48;
	int field_4C;
	int *(__fastcall *pfunc50)(char *, DocMarathonStateSO1 *);
	int vtable1;
	int field_58;
	int (__fastcall *GetAllSceneParams)(DocMarathonStateSO1 *);
	int field_60;
	int (__fastcall *pfunc64)(DocMarathonStateSO1 *);
	int gap68;
	int field_6C;
	int field_70;
	int field_74;
	int field_78;
	int field_7C;
	int field_80;
	int field_84;
	int field_88;
	int field_8C;
	int field_90;
	int field_94;
	int field_98;
	int field_9C;
	int field_A0;
	int field_A4;
	int field_A8;
	int field_AC;
	int field_B0;
	int field_B4;
	int field_B8;
	int (__fastcall *pfuncBC)(DocMarathonStateSO1 *, int);
	int gapC0;
	int field_C4;
	void (__fastcall *pfuncC8)(DocMarathonStateSO1 *, int);
	int gapCC;
	int field_D0;
	int field_D4;
	int field_D8;
	int field_DC;
	int field_E0;
	int field_E4;
	int field_E8;
	int field_EC;
	int field_F0;
	int field_F4;
	int field_F8;
	int field_FC;
	int field_100;
	int field_104;
	int field_108;
	unsigned __int8 (__fastcall *pfunc10C)(DocMarathonStateSO1 *, const char *);
	int (__fastcall *pfunc110)(DocMarathonStateSO1 *);
	int gap114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int (__fastcall *pfunc128)(DocMarathonStateSO1 *);
	int gap12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	void *pfunc140;
};



namespace Lua{
	namespace Lib{
		static int ExtractParamBase(DWORD* a1,int a2){
			return ((int (__fastcall *)(DWORD*,int))0x825D5660 )(a1,a2);
		}
	};

};

class Marathon
{
public:
	Marathon(void);
	~Marathon(void);
public:
	static DWORD* NewObjectCopy(DWORD a1,DWORD a2);
	static _DWORD *__fastcall Marathon::NewObject(NORT *a1,int a2, int a3);
	static _DWORD *__fastcall Marathon::NewObject(NORT *a1,int a2);
	static DWORD* NewObjectCopy(DWORD a1,DWORD a2,DWORD a3);



	class Player{

	public:
		class IPlugIn{
		public:
			IPlugIn(char* str){
				Header = std::string(str);
			}
			std::string Header;
			virtual ~IPlugIn(){
				Header.clear();
			}

		};
		class IVarible{
		public:
		public: 
			IVarible()
			{

			}
			virtual ~IVarible(){

			};
			static const char str[];
		};
		class IDynamicLink{
		public: IDynamicLink()
				{

				}
			virtual ~IDynamicLink(){

			}
			virtual int S1(){
				return 0;
			}
		};
		class IFlagCommunicator{
		public:
			IFlagCommunicator(){

			}
			virtual ~IFlagCommunicator(){

			}
			virtual int IFC1(){
				return 0;
			}
			virtual int IFC2(){
				return 0;
			}
			virtual int IFC3(){
				return 0;
			}
			virtual int IFC4(){
				return 0;
			}
			virtual int IFC5(){
				return 0;
			}
			virtual int IFC6(){
				return 0;
			}
			virtual int IFC7(){
				return 0;
			}
			virtual int IFC8(){
				return 0;
			}
			virtual int IFC9(){
				return 0;
			}
			virtual int IFC10(){
				return 0;
			}
			virtual int IFC11(){
				return 0;
			}
			virtual int IFC12(){
				return 0;
			}


		};



		class State{
		public:
			class IContext:public IPlugIn,public IVarible,public IDynamicLink,public IFlagCommunicator{

			public:
				//IDynamicLink DynamicLink;
				//IFlagCommunicator FlagCommunicator;
				IContext():IPlugIn("state context"),IVarible(),IDynamicLink(),IFlagCommunicator()
				{

				}

				virtual ~IContext(){

				}
				virtual int IC1(){
					return 0;
				}
				virtual int IC2(){
					return 0;
				}




			};
			//Conditions
			class ICommonContextIF{
			public:
				float ForceNMCamPlr;
				float field34;
				float JumpKineticForce;
				float field3C; 
				//Other Structure For This
			public: ICommonContextIF(){

					}
			

				virtual ~ICommonContextIF(){

				}
				virtual int ICCIF1(){
					return 0;
				}
				virtual int ICCIF2(){
					return 0;
				}
				virtual int ICCIF3(){
					return 0;
				}
				virtual int ICCIF4(){
					return 0;	
				}
				virtual int ICCIF5(){
					return 0;
				}
				virtual int ICCIF6(){
					return 0;
				}
				static const float flt;
			};


			class ICommonContext:public IContext,public ICommonContextIF{
			public:

				//ICommonContextIF CommonContextIF; //NO OVERRIDE ACCESS
				int CurrentAnimation;
				float LockDownTimer;
				float field48;
				float field4C;
				float field50;
				int Input;
				float StickForce;
				float field5C;
				XMVECTOR StickControl;
				int AnimationState;
				float field74;
				float field78;
				float field7C;
				float field80;
				float field84;
				float field88;
				float field8C;

				ICommonContext():IContext(),ICommonContextIF(){

				}	
				

			
				virtual ~ICommonContext(){
				

				}
				virtual int ICCERR(){
					return 0;
				}
				virtual	void ICC1(double a2){
					BranchTo(0x82209FB8,void,this,a2);
				
				}
				


			};

			class CommonContext:ICommonContext{

			public:

				virtual ~CommonContext(){

				}
				CommonContext():ICommonContext(){

				}
			   int vo[420];




			};



			static boost::shared_ptr<CommonContext>& Zest(boost::shared_ptr<CommonContext>& a1,int a2){ 

				boost::shared_ptr<CommonContext> x(new CommonContext());
				a1 = x;
				return a1;
			};


		};

	};

	class PlayerState{
		public:

			




			struct __declspec(align(4)) CommonScore
			{
				int gap0;
				int field_4;
				int field_8;
				int field_C;
				int field_10;
				int field_14;
				int field_18;
				int field_1C;
				int field_20;
				int field_24;
				int Rings;
				int gap2C;
				int field_30;
				int field_34;
				int field_38;
				int field_3C;
				float float40;
				int gap44;
				int field_48;
				int field_4C;
				int field_50;
				int field_54;
				int field_58;
				int field_5C;
				int field_60;
				int field_64;
				int field_68;
				int field_6C;
				int field_70;
				int field_74;
				int field_78;
				int field_7C;
				int field_80;
				int field_84;
				int field_88;
				int field_8C;
				int field_90;
				int field_94;
				int field_98;
				int field_9C;
				int field_A0;
			};



			typedef struct CommonContext;


			struct __declspec(align(4)) struct_TableForce
			{
				int SetVector3;
				int SetVector4;
				int Get0x78;
				int Get0x74;
				int field_10;
				int field_14;
				int dword18;
			};


			struct __declspec(align(4)) struct_Table_Core
			{
				_BYTE gap0[4];
				void (__fastcall *CharacterControls)(CommonContext *);
				CommonContext *(__fastcall *CoreUpdate)(CommonContext *, double a2);
			};


			struct __declspec(align(8)) CommonContext
			{
				struct_Table_Core *Table_Core;
				_BYTE gap4[28];
				_DWORD Table2;
				_DWORD PhysicsLua;
				_DWORD TableCommon;
				struct_TableForce *TableForce;
				float ForceNMCamPlr;
				float field_34;
				float JumpKineticForce;
				float field_3C;
				int CurrentAnimation;
				float LockDownTimer;
				float field_48;
				float field_4C;
				float field_50;
				int Input;
				float StickForce;
				int field_5C;
				float StickLRMoveTrigger;
				float StickInputCircleSin;
				float StickLRMoveTriggerRV;
				float StickInputCircleSinRev;
				int AnimationState;
				int field_74;
				int field_78;
				int field_7C;
				float field_80;
				int field_84;
				int field_88;
				float field_8C;
				_DWORD TableCommon_0;
				_DWORD TableCommon_1;
				int dword98;
				int IsBarrierEnabled;
				_DWORD dwordA0;
				_DWORD dwordA4;
				_DWORD dwordA8;
				_DWORD dwordAC;
				float DamageInvincibleTime;
				float InvicibilityTimerWEffect;
				float SpeedUpTime;
				int dwordBC;
				float AngleMoveDataMB;
				float FallDataSome;
				int qwordC8;
				int field_CC;
				int qwordD0;
				int field_D4;
				int qwordD8;
				int field_DC;
				char wordE0;
				char field_E1;
				char field_E2;
				_BYTE IsControlLocked;
				char field_E4;
				char IsVulnerable;
				char field_E6;
				char field_E7;
				char wordE8;
				char field_E9;
				char field_EA;
				char field_EB;
				char field_EC;
				char field_ED;
				char field_EE;
				char field_EF;
				char wordF0;
				char field_F1;
				char field_F2;
				char field_F3;
				char field_F4;
				char field_F5;
				char field_F6;
				char field_F7;
				char field_F8;
				char field_F9;
				char wordFA;
				char field_FB;
				char field_FC;
				char field_FD;
				char field_FE;
				char field_FF;
				char field_100;
				char field_101;
				char byte102;
				char field_103;
				char IsBarrier;
				char field_105;
				char field_106;
				char field_107;
				char field_108;
				char field_109;
				char word10A;
				char field_10B;
				char field_10C;
				char field_10D;
				char field_10E;
				char field_10F;
				char field_110;
				char field_111;
				char gap112;
				char field_113;
				char field_114;
				char field_115;
				char field_116;
				char field_117;
				char field_118;
				char field_119;
				char field_11A;
				char field_11B;
				char field_11C;
				_BYTE field_11D;
				char field_11E;
				char field_11F;
				char field_120;
				char field_121;
				char field_122;
				char field_123;
				char field_124;
				char field_125;
				char field_126;
				char field_127;
				CommonScore *Score;
				char field_12C;
				char field_12D;
				char field_12E;
				char field_12F;
				int field_130;
				int field_134;
				int InputListenerNormal;
				int field_13C;
				int AmigoAIPlayer;
				int field_144;
				float float148;
				float float14C;
				float float150;
				float float154;
				float float158;
				float float15C;
				float float160;
				float float164;
				float float168;
				float float16C;
				float float170;
				float float174;
				float float178;
				float float17C;
				float float180;
				float float184;
				float float188;
				float float18C;
				float float190;
				float float194;
				float float198;
				float float19C;
				float float1A0;
				float float1A4;
				float float1A8;
				float float1AC;
				float float1B0;
				float float1B4;
				float float1B8;
				float float1BC;
				float float1C0;
				char field_1C4;
				char field_1C5;
				char field_1C6;
				char field_1C7;
				float float1C8;
				char field_1CC;
				char field_1CD;
				char field_1CE;
				char field_1CF;
				float float1D0;
				float float1D4;
				float float1D8;
				float float1DC;
				float float1E0;
				float float1E4;
				float float1E8;
				float float1EC;
				float float1F0;
				float float1F4;
				float float1F8;
				float float1FC;
				float float200;
				float float204;
				float float208;
				float float20C;
				float float210;
				float float214;
				float float218;
				float float21C;
				float float220;
				float float224;
				float float228;
				float float22C;
			};

			struct ContextPlayerSonic:public CommonContext
			{
				_DWORD CurrentGemImage;
				_DWORD Gauge;
				_DWORD dword238;
				_BYTE byte23C;
				_BYTE byte23D;
				_BYTE byte23E;
				_BYTE byte23F;
				_BYTE byte240;
				_BYTE byte241;
				_BYTE isShrink;
				_BYTE isThunderGuard;
				_BYTE byte244;
				_BYTE byte245;
				_BYTE byte246;
				_BYTE isSlowTime;
				_BYTE byte248;
				_BYTE byte249;
				char field_24A;
				char field_24B;
				_DWORD dword24C;
				int CurrentGem;
				float float254;
				float float258;
				float float25C;
				float float260;
				float float264;
				_BYTE gap268[8];
				float float270;
				float float274;
				float float278;
				float float27C;
				float float280;
				float float284;
				float float288;
				float float28C;
				float float290;
				float float294;
				float float298;
				float float29C;
				float float2A0;
				float float2A4;
				float float2A8;
			};
			struct ContextPlayerTails:public CommonContext
			{
				float float230;
				float float234;
				_BYTE byte238;
				_BYTE byte239;
				_BYTE byte23A;
				_BYTE byte23B;
				float float23C;
				float float240;
				float float244;
				float float248;
			};
			struct ContextPlayerShadow:public Marathon::PlayerState::CommonContext
			{
				_DWORD dword230;
				_DWORD dword234;
				int gap238;
				int field_23C;
				int field_240;
				int field_244;
				int field_248;
				int field_24C;
				int field_250;
				int field_254;
				int field_258;
				int field_25C;
				_BYTE byte260;
				_BYTE byte261;
				_BYTE byte262;
				_BYTE byte263;
				_BYTE byte264;
				_BYTE byte265;
				_BYTE byte266;
				_BYTE byte267;
			};



			/* 67 */
			
			struct StateBaseValuePC
			{
				int field_0;
				int field_4;
				int *(__fastcall *Init)(int *, int *); // Return Unknown Structure  (int*,StateBaseValueP*)
				int *(__fastcall *ChangeState)(int *, int);
				int *field_10;
				int *field_14;
				int *field_18;
				int *(__fastcall *MethodU1)(int *, int);
			};

			/* 66 */
			struct StateBaseValueP
			{
				StateBaseValuePC *StateModule;
				int field_4;
				int field_8;
				int field_C;
			};

		

	
	

			/* 48 */
			struct StateBaseS
			{
				int *StateTable;
				StateBaseValueP *basevalue;
				CommonContext *ContextBase;
			};


			struct StateBaseVS{ //Special For VS studio
				StateBaseValueP* basevalue;
				CommonContext* ContextBase;
			};


			struct State
			{
				StateBaseS StateBase;
				CommonContext *ContextPlayer;
			};


			class Object2{



			public:
		


				virtual ~Object2(){

				}
				virtual int* G01(){
					return (int*)0x8200139;
				}


				virtual int* OnStateStart()
				{
					return StateStart();
				}
				virtual int* OnStateUpdate(double a2){

					StatesCommonSub06();
					StateUpdate(a2);
				return 	StatesCommonSub07();

				}
		
				virtual int* OnStateEnd(){
				return	StateEnd();
				}
				virtual int* OnSomeIGuess(){

					return 0;
				}


				virtual int* StateStart(){
					return 0;
				}
				virtual int* StateUpdate(double a2){
					return 0;
				}
				virtual int* StateEnd(){
					return 0;
				}
				virtual int* StatesCommonSub06(){
					return 0;
				}
				virtual int* StatesCommonSub07(){
					return 0;
				}


			public: 


				StateBaseValueP* basevalue; //Object Module
				Object2(StateBaseValueP* ObjectModule)
				{
					basevalue = ObjectModule;
				}
			

			};









			class IContext{
		
			};




			class CommonObject:public Object2
			{

			public :
			
				
				virtual ~CommonObject(){

					}

				int* StatesCommonSub06() override{	

					return ((int* (__fastcall *)(int))0x8220CBC0 )((int)this);


					if ((this->CContext->qwordC8 & 4) != 0){

						this->CContext->IsVulnerable = 1;
					}

					if ((this->CContext->qwordC8 & 8) != 0){

						this->CContext->InvicibilityTimerWEffect = this->CContext->float1C8;
					}
					if ((this->CContext->qwordC8 & 0x40000) != 0){

						this->CContext->SpeedUpTime = this->CContext->field_1CC;
					}

					this->CContext->field_F3 = 0;
					this->CContext->field_F1 = 0;

					if (this->CContext->field_130){

						__asm{
addi r3,r31,0x2C
						}
						double v2 = ((double (*)(void))*(_DWORD *)(this->CContext->TableForce + 20))();
						if ( -(float)((float)v2
							- (float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)this->CContext->field_130 + 8))(this->CContext->field_130)) >= this->CContext->float1DC )
							this->CContext->field_DC |= 1u;
					}


					return 0;


				}
				int* StatesCommonSub07() override{

				return ((int* (__fastcall *)(int))0x8220CC28)((int)this);


					return 0;	
				}


				
 //Testing Later Will Be Removed
			public:
				
				CommonObject(StateBaseValueP* ObjectModule):Object2(ObjectModule){
					
					int v9[2];
					
					StateBaseValueP* z =  (StateBaseValueP*)this->basevalue->StateModule->Init(v9,(int*)ObjectModule);

					CommonContext* zx = (CommonContext*)&z->StateModule->field_0;

					this->CContext = reinterpret_cast<CommonContext*>(zx);
				   }
				CommonContext* CContext;
			};

			/* 65 */

			template <typename ContextT>
			class CommonObjectTemplate:CommonObject
			{
				ContextT* Context;

			public: 

				CommonObjectTemplate(StateBaseValueP* p):CommonObject(p)
				{
					Context = reinterpret_cast<ContextT>(this->CContext);
				}
			};

			//Testing Stuff


	



			class SonicObject:CommonObjectTemplate<CommonContext>
			{


			};



			 





			struct __declspec(align(4)) StateSlideSonic
			{
				State State;
				int field_10;
				int field_14;
				int field_18;
				int field_1C;
				int field_20;
				int field_24;
			};


			/* 68 */
		


	};



	public:class Effect{
	public:class Shadow{
		public:int* RunEffect(int OFFSET);
			   int* RunEffect(int OFFSET,int FOFFSET); //RunEffectsFunc ADDITIONAL 
			   
		};
	};
   public:class Model{

   public:
			  struct ListBase2D
			  {
				  int *node;
				  int count;
			  };
			  struct AnimStructBaseList
			  {
				  ListBase2D node;
				  int lastID;
			  };
			  struct AnimationsModelBase
			  {
				  ListBase2D Names1;
				  AnimStructBaseList Bind1;
				  ListBase2D Names2;
				  AnimStructBaseList Bind2;
				  ListBase2D field_28;
			  };
			  struct __declspec(align(4)) StatesAnimMap
			  {
				  int field_mapid;
				  int field_animspeed_pre;
				  int field_8_ExtraParams;
				  float field_C;
				  float field_10;
				  int field_14;
				  float field_18;
			  };
	
			


		  };
};



////////////////////////



#endif
