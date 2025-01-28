#pragma once

#include <xtl.h>

class IExportWeaponRequestFlag
{
public:
	IExportWeaponRequestFlag(void);
	virtual ~IExportWeaponRequestFlag(void);
	virtual DWORD IEWRFExportFlag(void)  = 0;
};
