#ifndef SONICTEAM__SOX__DEFS
#define SONICTEAM__SOX__DEFS

namespace Sonicteam{
	namespace SoX{

		#define IFileHandle_BFUNCTION_TYPE boost::function<bool(void*,unsigned __int64)>
		#define IFileLoader_BFUNCTION_TYPE IFileHandle_BFUNCTION_TYPE



		struct IEntityContainer;
		class RefCountObject;
		class ArcHandleMgr;
		class ArcFile;
		class ArcHandle;
		class FileSystemArc;
		class FileLoaderARC;
		class IFileLoader;
		class IFileHandle;
		class IResource;
		class IResourceMgr;
		template <typename T> struct RefCountObjContainer;

		struct IResourceMgrParam;
		class IResourceMgr;
	};
};


#endif