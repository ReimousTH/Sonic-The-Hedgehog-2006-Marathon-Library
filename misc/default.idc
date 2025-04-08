//
// Xbox360 Basefile Info - Created by XexTool
//

#include <idc.idc>
#include <x360_imports.idc>


static MakeNameForce(addr, name)
{
    auto num, name_fixed;
    if( MakeNameEx(addr, name, SN_NOWARN) )
        return;
    for(num=0; num<999; num++)
    {
        name_fixed = form("%s_%d", name, num);
        if( MakeNameEx(addr, name_fixed, SN_NOWARN) )
            return;
    }
}

static GetSectionAddr(sectName)
{
	auto seg_addr, seg_base;
	seg_base = SegByName(sectName);
	return SegByBase(seg_base);
}

static SetupSection(startAddr, endAddr, segClass, perms, name, base)
{
    SetSelector(base, 0);
    SegCreate(startAddr, endAddr, base, 1, 3, 2);
    SegClass(startAddr, segClass);
    SegRename(startAddr, name);
    SetSegmentAttr(startAddr, SEGATTR_PERM, perms); // 4=read, 2=write, 1=execute
    SetSegmentAttr(startAddr, SEGATTR_FLAGS, 0x10); // SFL_LOADER
    SegDefReg(startAddr, "%r26", 0);
    SegDefReg(startAddr, "%r27", 0);
    SegDefReg(startAddr, "%r28", 0);
    SegDefReg(startAddr, "%r29", 0);
    SegDefReg(startAddr, "%r30", 0);
    SegDefReg(startAddr, "%r31", 0);
}

static SetupSections()
{
    auto addr;

    SetupSection(0x82000600, 0x8211B310, "DATA", 4, ".rdata", 1);
    SetupSection(0x8211B400, 0x82151F60, "DATA", 4, ".pdata", 2);
    SetupSection(0x82160000, 0x82AEAA6C, "CODE", 5, ".text", 3);
    SetupSection(0x82AEAC00, 0x82AF45AC, "CODE", 5, ".embsec_", 4);
    SetupSection(0x82AF4600, 0x82AFEAB8, "CODE", 5, ".embsec_", 5);
    SetupSection(0x82AFEC00, 0x82B0090C, "CODE", 5, ".embsec_", 6);
    SetupSection(0x82B00A00, 0x82B06680, "CODE", 5, ".embsec_", 7);
    SetupSection(0x82B06800, 0x82B07B50, "CODE", 5, ".embsec_", 8);
    SetupSection(0x82B07C00, 0x82B088C8, "CODE", 5, ".embsec_", 9);
    SetupSection(0x82B08A00, 0x82B0ABB8, "CODE", 5, ".embsec_", 10);
    SetupSection(0x82B10000, 0x82D5E89C, "DATA", 6, ".data", 11);

    // remove unused "leftovers" of the original binary segment
    while( (addr = SegByBase(0)) != BADADDR )
        DelSeg(addr, SEGMOD_KILL|SEGMOD_SILENT);
}

static SetupResources()
{
    SetupSection(0x82D5E900, 0x82D9034B, "DATA", 4, "534507D6", 12);
}

static RemoveEmptySections()
{
    auto seg_addr, seg_num;
    for(seg_num=0; seg_num<500; seg_num=seg_num+1)
    {
        seg_addr = GetSectionAddr(form( "seg%03d", seg_num) );
        if(seg_addr != -1)
            SegDelete(seg_addr, 1);
    }
}


static SetupImportFunc(importAddr, funcAddr, importNum, name)
{
    auto func_name;
    func_name = DoNameGen(name, 0, importNum);

    MakeNameForce(importAddr, "__imp__" + func_name);
    MakeDword(importAddr);

    PatchWord(funcAddr, 0x3860);
    PatchWord(funcAddr + 4, 0x3880);
    MakeUnknown(funcAddr, 0x10, 0); // DOUNK_SIMPLE
    MakeCode(funcAddr);
    MakeNameForce(funcAddr, func_name);
    MakeFunction(funcAddr, funcAddr + 0x10);
    SetFunctionFlags(funcAddr, FUNC_LIB);
}

static SetupImportData(importAddr, importNum, name)
{
    auto data_name;
    data_name = DoNameGen(name, 0, importNum);

    MakeNameForce(importAddr, data_name);
    MakeDword(importAddr);
}

static setupImports_0_xam_xex_0()
{
    SetupImportFunc(0x82000600, 0x82AEA0AC, 0x1A6, "xam.xex");
    SetupImportFunc(0x82000604, 0x82AEA0BC, 0x1A8, "xam.xex");
    SetupImportFunc(0x82000608, 0x82AEA0CC, 0x1A7, "xam.xex");
    SetupImportFunc(0x8200060C, 0x82AEA0DC, 0x1A4, "xam.xex");
    SetupImportFunc(0x82000610, 0x82AEA0EC, 0x2BC, "xam.xex");
    SetupImportFunc(0x82000614, 0x82AEA0FC, 0x2CB, "xam.xex");
    SetupImportFunc(0x82000618, 0x82AEA10C, 0x2CA, "xam.xex");
    SetupImportFunc(0x8200061C, 0x82AEA11C, 0x2D9, "xam.xex");
    SetupImportFunc(0x82000620, 0x82AEA12C, 0x2DC, "xam.xex");
    SetupImportFunc(0x82000624, 0x82AEA13C, 0x3CD, "xam.xex");
    SetupImportFunc(0x82000628, 0x82AEA14C, 0x3CB, "xam.xex");
    SetupImportFunc(0x8200062C, 0x82AEA15C, 0x1A9, "xam.xex");
    SetupImportFunc(0x82000630, 0x82AEAA3C, 0x191, "xam.xex");
    SetupImportFunc(0x82000634, 0x82AEAA2C, 0x190, "xam.xex");
    SetupImportFunc(0x82000638, 0x82AEAA1C, 0x002, "xam.xex");
    SetupImportFunc(0x8200063C, 0x82AEAA0C, 0x001, "xam.xex");
    SetupImportFunc(0x82000640, 0x82AEA9FC, 0x219, "xam.xex");
    SetupImportFunc(0x82000644, 0x82AEA9EC, 0x1F4, "xam.xex");
    SetupImportFunc(0x82000648, 0x82AEA9DC, 0x1FC, "xam.xex");
    SetupImportFunc(0x8200064C, 0x82AEA64C, 0x28B, "xam.xex");
    SetupImportFunc(0x82000650, 0x82AEA65C, 0x3CC, "xam.xex");
    SetupImportFunc(0x82000654, 0x82AEA66C, 0x1F7, "xam.xex");
    SetupImportFunc(0x82000658, 0x82AEA67C, 0x210, "xam.xex");
    SetupImportFunc(0x8200065C, 0x82AEA68C, 0x282, "xam.xex");
    SetupImportFunc(0x82000660, 0x82AEA69C, 0x259, "xam.xex");
    SetupImportFunc(0x82000664, 0x82AEA6AC, 0x25A, "xam.xex");
    SetupImportFunc(0x82000668, 0x82AEA6BC, 0x262, "xam.xex");
    SetupImportFunc(0x8200066C, 0x82AEA6CC, 0x25C, "xam.xex");
    SetupImportFunc(0x82000670, 0x82AEA6DC, 0x265, "xam.xex");
    SetupImportFunc(0x82000674, 0x82AEA6EC, 0x28A, "xam.xex");
    SetupImportFunc(0x82000678, 0x82AEA6FC, 0x250, "xam.xex");
    SetupImportFunc(0x8200067C, 0x82AEA70C, 0x280, "xam.xex");
    SetupImportFunc(0x82000680, 0x82AEA9CC, 0x3D1, "xam.xex");
}

static setupImports_1_xboxkrnl_exe_0()
{
    SetupImportFunc(0x82000688, 0x82AEA73C, 0x088, "xboxkrnl.exe");
    SetupImportFunc(0x8200068C, 0x82AEA74C, 0x1F8, "xboxkrnl.exe");
    SetupImportFunc(0x82000690, 0x82AEA75C, 0x1F7, "xboxkrnl.exe");
    SetupImportFunc(0x82000694, 0x82AEA76C, 0x0AF, "xboxkrnl.exe");
    SetupImportFunc(0x82000698, 0x82AEA77C, 0x092, "xboxkrnl.exe");
    SetupImportFunc(0x8200069C, 0x82AEA78C, 0x074, "xboxkrnl.exe");
    SetupImportFunc(0x820006A0, 0x82AEA79C, 0x226, "xboxkrnl.exe");
    SetupImportFunc(0x820006A4, 0x82AEA7AC, 0x224, "xboxkrnl.exe");
    SetupImportFunc(0x820006A8, 0x82AEA7BC, 0x083, "xboxkrnl.exe");
    SetupImportFunc(0x820006AC, 0x82AEA7CC, 0x141, "xboxkrnl.exe");
    SetupImportFunc(0x820006B0, 0x82AEA7DC, 0x1F3, "xboxkrnl.exe");
    SetupImportFunc(0x820006B4, 0x82AEA7EC, 0x1F4, "xboxkrnl.exe");
    SetupImportFunc(0x820006B8, 0x82AEA7FC, 0x1F5, "xboxkrnl.exe");
    SetupImportFunc(0x820006BC, 0x82AEA80C, 0x154, "xboxkrnl.exe");
    SetupImportFunc(0x820006C0, 0x82AEA81C, 0x155, "xboxkrnl.exe");
    SetupImportFunc(0x820006C4, 0x82AEA82C, 0x052, "xboxkrnl.exe");
    SetupImportFunc(0x820006C8, 0x82AEA83C, 0x152, "xboxkrnl.exe");
    SetupImportFunc(0x820006CC, 0x82AEA84C, 0x153, "xboxkrnl.exe");
    SetupImportFunc(0x820006D0, 0x82AEA85C, 0x147, "xboxkrnl.exe");
    SetupImportFunc(0x820006D4, 0x82AEA86C, 0x05D, "xboxkrnl.exe");
    SetupImportFunc(0x820006D8, 0x82AEA87C, 0x119, "xboxkrnl.exe");
    SetupImportFunc(0x820006DC, 0x82AEA88C, 0x0FF, "xboxkrnl.exe");
    SetupImportFunc(0x820006E0, 0x82AEA89C, 0x0DA, "xboxkrnl.exe");
    SetupImportFunc(0x820006E4, 0x82AEA8AC, 0x0F6, "xboxkrnl.exe");
    SetupImportFunc(0x820006E8, 0x82AEA8BC, 0x0F5, "xboxkrnl.exe");
    SetupImportFunc(0x820006EC, 0x82AEA8CC, 0x0E7, "xboxkrnl.exe");
    SetupImportFunc(0x820006F0, 0x82AEA8DC, 0x021, "xboxkrnl.exe");
    SetupImportFunc(0x820006F4, 0x82AEA8EC, 0x020, "xboxkrnl.exe");
    SetupImportFunc(0x820006F8, 0x82AEA8FC, 0x0D5, "xboxkrnl.exe");
    SetupImportFunc(0x820006FC, 0x82AEA90C, 0x0F3, "xboxkrnl.exe");
    SetupImportFunc(0x82000700, 0x82AEA91C, 0x001, "xboxkrnl.exe");
    SetupImportData(0x82000704,             0x0AD, "xboxkrnl.exe");
    SetupImportFunc(0x82000708, 0x82AEA92C, 0x127, "xboxkrnl.exe");
    SetupImportFunc(0x8200070C, 0x82AEA93C, 0x142, "xboxkrnl.exe");
    SetupImportFunc(0x82000710, 0x82AEA94C, 0x12D, "xboxkrnl.exe");
    SetupImportFunc(0x82000714, 0x82AEA95C, 0x019, "xboxkrnl.exe");
    SetupImportFunc(0x82000718, 0x82AEA96C, 0x0DB, "xboxkrnl.exe");
    SetupImportFunc(0x8200071C, 0x82AEA97C, 0x133, "xboxkrnl.exe");
    SetupImportFunc(0x82000720, 0x82AEA98C, 0x0E4, "xboxkrnl.exe");
    SetupImportFunc(0x82000724, 0x82AEA99C, 0x143, "xboxkrnl.exe");
    SetupImportFunc(0x82000728, 0x82AEA9AC, 0x05A, "xboxkrnl.exe");
    SetupImportFunc(0x8200072C, 0x82AEA9BC, 0x197, "xboxkrnl.exe");
    SetupImportFunc(0x82000730, 0x82AEA71C, 0x085, "xboxkrnl.exe");
    SetupImportFunc(0x82000734, 0x82AEA63C, 0x1BD, "xboxkrnl.exe");
    SetupImportFunc(0x82000738, 0x82AEA62C, 0x25B, "xboxkrnl.exe");
    SetupImportFunc(0x8200073C, 0x82AEA61C, 0x1C7, "xboxkrnl.exe");
    SetupImportFunc(0x82000740, 0x82AEA60C, 0x00D, "xboxkrnl.exe");
    SetupImportFunc(0x82000744, 0x82AEA5FC, 0x09D, "xboxkrnl.exe");
    SetupImportFunc(0x82000748, 0x82AEA5EC, 0x08F, "xboxkrnl.exe");
    SetupImportFunc(0x8200074C, 0x82AEA5DC, 0x0B0, "xboxkrnl.exe");
    SetupImportFunc(0x82000750, 0x82AEA5CC, 0x06C, "xboxkrnl.exe");
    SetupImportFunc(0x82000754, 0x82AEA5BC, 0x06B, "xboxkrnl.exe");
    SetupImportFunc(0x82000758, 0x82AEA5AC, 0x05F, "xboxkrnl.exe");
    SetupImportData(0x8200075C,             0x1C1, "xboxkrnl.exe");
    SetupImportFunc(0x82000760, 0x82AEA59C, 0x26A, "xboxkrnl.exe");
    SetupImportFunc(0x82000764, 0x82AEA58C, 0x269, "xboxkrnl.exe");
    SetupImportFunc(0x82000768, 0x82AEA57C, 0x07D, "xboxkrnl.exe");
    SetupImportFunc(0x8200076C, 0x82AEA56C, 0x103, "xboxkrnl.exe");
    SetupImportFunc(0x82000770, 0x82AEA55C, 0x104, "xboxkrnl.exe");
    SetupImportFunc(0x82000774, 0x82AEA54C, 0x1C5, "xboxkrnl.exe");
    SetupImportData(0x82000778,             0x1C0, "xboxkrnl.exe");
    SetupImportFunc(0x8200077C, 0x82AEA53C, 0x1B1, "xboxkrnl.exe");
    SetupImportFunc(0x82000780, 0x82AEA52C, 0x1C9, "xboxkrnl.exe");
    SetupImportFunc(0x82000784, 0x82AEA51C, 0x1B4, "xboxkrnl.exe");
    SetupImportFunc(0x82000788, 0x82AEA50C, 0x1B9, "xboxkrnl.exe");
    SetupImportFunc(0x8200078C, 0x82AEA4FC, 0x1C6, "xboxkrnl.exe");
    SetupImportFunc(0x82000790, 0x82AEA4EC, 0x1C2, "xboxkrnl.exe");
    SetupImportFunc(0x82000794, 0x82AEA4DC, 0x1D5, "xboxkrnl.exe");
    SetupImportFunc(0x82000798, 0x82AEA4CC, 0x1D3, "xboxkrnl.exe");
    SetupImportFunc(0x8200079C, 0x82AEA4BC, 0x1BA, "xboxkrnl.exe");
    SetupImportFunc(0x820007A0, 0x82AEA4AC, 0x1CA, "xboxkrnl.exe");
    SetupImportFunc(0x820007A4, 0x82AEA49C, 0x015, "xboxkrnl.exe");
    SetupImportFunc(0x820007A8, 0x82AEA48C, 0x1DC, "xboxkrnl.exe");
    SetupImportData(0x820007AC,             0x158, "xboxkrnl.exe");
    SetupImportFunc(0x820007B0, 0x82AEA47C, 0x14D, "xboxkrnl.exe");
    SetupImportData(0x820007B4,             0x266, "xboxkrnl.exe");
    SetupImportFunc(0x820007B8, 0x82AEA46C, 0x1D9, "xboxkrnl.exe");
    SetupImportFunc(0x820007BC, 0x82AEA45C, 0x0BE, "xboxkrnl.exe");
    SetupImportFunc(0x820007C0, 0x82AEA44C, 0x1C3, "xboxkrnl.exe");
    SetupImportFunc(0x820007C4, 0x82AEA43C, 0x1B6, "xboxkrnl.exe");
    SetupImportFunc(0x820007C8, 0x82AEA42C, 0x1DF, "xboxkrnl.exe");
    SetupImportFunc(0x820007CC, 0x82AEA41C, 0x0B1, "xboxkrnl.exe");
    SetupImportFunc(0x820007D0, 0x82AEA40C, 0x0B4, "xboxkrnl.exe");
    SetupImportFunc(0x820007D4, 0x82AEA3FC, 0x04D, "xboxkrnl.exe");
    SetupImportFunc(0x820007D8, 0x82AEA3EC, 0x089, "xboxkrnl.exe");
    SetupImportFunc(0x820007DC, 0x82AEA3DC, 0x13B, "xboxkrnl.exe");
    SetupImportData(0x820007E0,             0x1BE, "xboxkrnl.exe");
    SetupImportFunc(0x820007E4, 0x82AEA3CC, 0x13F, "xboxkrnl.exe");
    SetupImportFunc(0x820007E8, 0x82AEA3BC, 0x028, "xboxkrnl.exe");
    SetupImportData(0x820007EC,             0x193, "xboxkrnl.exe");
    SetupImportFunc(0x820007F0, 0x82AEA3AC, 0x12B, "xboxkrnl.exe");
    SetupImportFunc(0x820007F4, 0x82AEA39C, 0x0DF, "xboxkrnl.exe");
    SetupImportFunc(0x820007F8, 0x82AEA38C, 0x0EF, "xboxkrnl.exe");
    SetupImportData(0x820007FC,             0x1AE, "xboxkrnl.exe");
    SetupImportData(0x82000800,             0x059, "xboxkrnl.exe");
    SetupImportFunc(0x82000804, 0x82AEA37C, 0x097, "xboxkrnl.exe");
    SetupImportFunc(0x82000808, 0x82AEA36C, 0x0FC, "xboxkrnl.exe");
    SetupImportData(0x8200080C,             0x01B, "xboxkrnl.exe");
    SetupImportFunc(0x82000810, 0x82AEA35C, 0x110, "xboxkrnl.exe");
    SetupImportFunc(0x82000814, 0x82AEA34C, 0x099, "xboxkrnl.exe");
    SetupImportFunc(0x82000818, 0x82AEA33C, 0x105, "xboxkrnl.exe");
    SetupImportFunc(0x8200081C, 0x82AEA32C, 0x135, "xboxkrnl.exe");
    SetupImportFunc(0x82000820, 0x82AEA31C, 0x199, "xboxkrnl.exe");
    SetupImportFunc(0x82000824, 0x82AEA30C, 0x194, "xboxkrnl.exe");
    SetupImportFunc(0x82000828, 0x82AEA2FC, 0x010, "xboxkrnl.exe");
    SetupImportFunc(0x8200082C, 0x82AEA2EC, 0x0D1, "xboxkrnl.exe");
    SetupImportFunc(0x82000830, 0x82AEA2DC, 0x0C4, "xboxkrnl.exe");
    SetupImportFunc(0x82000834, 0x82AEA2CC, 0x0BD, "xboxkrnl.exe");
    SetupImportFunc(0x82000838, 0x82AEA2BC, 0x0BA, "xboxkrnl.exe");
    SetupImportFunc(0x8200083C, 0x82AEA2AC, 0x12C, "xboxkrnl.exe");
    SetupImportFunc(0x82000840, 0x82AEA29C, 0x0D2, "xboxkrnl.exe");
    SetupImportFunc(0x82000844, 0x82AEA28C, 0x0E8, "xboxkrnl.exe");
    SetupImportFunc(0x82000848, 0x82AEA27C, 0x0F7, "xboxkrnl.exe");
    SetupImportFunc(0x8200084C, 0x82AEA26C, 0x0CF, "xboxkrnl.exe");
    SetupImportFunc(0x82000850, 0x82AEA25C, 0x0F0, "xboxkrnl.exe");
    SetupImportFunc(0x82000854, 0x82AEA24C, 0x0FD, "xboxkrnl.exe");
    SetupImportFunc(0x82000858, 0x82AEA23C, 0x084, "xboxkrnl.exe");
    SetupImportFunc(0x8200085C, 0x82AEA22C, 0x140, "xboxkrnl.exe");
    SetupImportFunc(0x82000860, 0x82AEA21C, 0x136, "xboxkrnl.exe");
    SetupImportFunc(0x82000864, 0x82AEA20C, 0x0EE, "xboxkrnl.exe");
    SetupImportFunc(0x82000868, 0x82AEA1FC, 0x12E, "xboxkrnl.exe");
    SetupImportFunc(0x8200086C, 0x82AEA1EC, 0x11B, "xboxkrnl.exe");
    SetupImportFunc(0x82000870, 0x82AEA1DC, 0x0DC, "xboxkrnl.exe");
    SetupImportFunc(0x82000874, 0x82AEA1CC, 0x1A5, "xboxkrnl.exe");
    SetupImportFunc(0x82000878, 0x82AEA1BC, 0x066, "xboxkrnl.exe");
    SetupImportFunc(0x8200087C, 0x82AEA1AC, 0x053, "xboxkrnl.exe");
    SetupImportFunc(0x82000880, 0x82AEA19C, 0x125, "xboxkrnl.exe");
    SetupImportFunc(0x82000884, 0x82AEA18C, 0x126, "xboxkrnl.exe");
    SetupImportFunc(0x82000888, 0x82AEA17C, 0x130, "xboxkrnl.exe");
    SetupImportFunc(0x8200088C, 0x82AEA16C, 0x0CC, "xboxkrnl.exe");
    SetupImportFunc(0x82000890, 0x82AEA72C, 0x0B3, "xboxkrnl.exe");
    SetupImportFunc(0x82000894, 0x82AEAA4C, 0x195, "xboxkrnl.exe");
    SetupImportFunc(0x82000898, 0x82AEAA5C, 0x12F, "xboxkrnl.exe");
}

static SetupImports()
{
    setupImports_0_xam_xex_0();
    setupImports_1_xboxkrnl_exe_0();
}


static SetupExportFunc(funcAddr, exportNum, funcName)
{
    MakeUnkn(funcAddr, 0);
    MakeCode(funcAddr); 
    MakeNameForce(funcAddr, funcName);
    MakeFunction(funcAddr, BADADDR);
    AddEntryPoint(exportNum, funcAddr, funcName, 1);
}

static SetupExportData(dataAddr, exportNum, name)
{
    auto data_name;
    data_name = DoNameGen(name, 0, exportNum);

    AddEntryPoint(exportNum, dataAddr, data_name, 0);
    MakeNameForce(dataAddr, data_name);
    MakeDword(dataAddr);
}

static SetupExports()
{
    auto name;
    name = GetInputFile();


    // set start entry point
    SetupExportFunc(0x82537AE0, 0x82537AE0, "start");
}

static SetupExportsByName()
{
}

static SetupRegSaves()
{
	auto currAddr, i;
	
	// find all saves of gp regs
	for(currAddr=0; currAddr != BADADDR; currAddr=currAddr+4)
	{
		// find "std %r14, -0x98(%sp)" followed by "std %r15, -0x90(%sp)"
		currAddr = FindBinary(currAddr, SEARCH_DOWN, "F9 C1 FF 68 F9 E1 FF 70");
		if(currAddr == BADADDR)
			break;
		for(i=14; i<=31; i++)
		{
			MakeUnknown(currAddr, 4, 0); // DOUNK_SIMPLE
			MakeCode(currAddr);
			if(i != 31)
				MakeFunction(currAddr, currAddr + 4);
			else
				MakeFunction(currAddr, currAddr + 0x0C);
			MakeNameForce(currAddr, form("__savegprlr_%d", i));
			currAddr = currAddr + 4;
		}
	}
	
	// find all loads of gp regs
	for(currAddr=0; currAddr != BADADDR; currAddr=currAddr+4)
	{
		// find "ld  %r14, var_98(%sp)" followed by "ld  %r15, var_90(%sp)"
		currAddr = FindBinary(currAddr, SEARCH_DOWN, "E9 C1 FF 68 E9 E1 FF 70");
		if(currAddr == BADADDR)
			break;
		for(i=14; i<=31; i++)
		{
			MakeUnknown(currAddr, 4, 0); // DOUNK_SIMPLE
			MakeCode(currAddr);
			if(i != 31)
				MakeFunction(currAddr, currAddr + 4);
			else
				MakeFunction(currAddr, currAddr + 0x10);
			MakeNameForce(currAddr, form("__restgprlr_%d", i));
			currAddr = currAddr + 4;
		}
	}
}

static ConvertToCode(startAddr, endAddr)
{
    auto addr;
    if(startAddr == BADADDR || endAddr == BADADDR || startAddr>endAddr)
        return;
    
    MakeUnknown(startAddr, endAddr-startAddr, 0); // DOUNK_SIMPLE
    for(addr=startAddr&0xFFFFFFFC; addr<endAddr; addr=addr+4)
    {
        MakeCode(addr);
    }
    AnalyzeArea(startAddr, endAddr);
}

static main()
{
    // ensure file was loaded in as binary
    // if it was loaded in as PE then addresses will be incorrect
    if( GetShortPrm(INF_FILETYPE) != FT_BIN )
    {
        Warning("The file must be loaded as a BINARY file to use this script.\n"
                "Close this database and create a new one, ensuring you\n"
                "select \"Binary File\" on IDAs \"Load a new file\" dialog.");
        return;
    }
    
    // ensure file was loaded in as PPC
    if( GetCharPrm(INF_PROCNAME+0) != 'P' ||
        GetCharPrm(INF_PROCNAME+1) != 'P' ||
        GetCharPrm(INF_PROCNAME+2) != 'C' ||
        GetCharPrm(INF_PROCNAME+3) != '\0' )
    {
        Warning("The file must be loaded for the PPC processor.\n"
                "Close this database and create a new one, ensuring you\n"
                "select \"PowerPC: ppc\" on IDAs \"Load a new file\" dialog.");
        return;
    }

    // set up resources
    if( 1 == AskYN(0, "Would you like to load reources as segments?") )
        SetupResources();

    // set up sections
    SetupSections();

    // remove empty sections
    RemoveEmptySections();

    // analyse code
    if( 1 == AskYN(1, "Would you like to analyse the file as code?") )
        ConvertToCode( GetSectionAddr(".text"), SegEnd(GetSectionAddr(".text")) );

    // set up imports
    SetupImports();

    // set up exports
    SetupExports();

    // set up exports by name
    SetupExportsByName();

    // setup all reg loads/stores
    SetupRegSaves();

    // done
    Message("done\n\n");
}

