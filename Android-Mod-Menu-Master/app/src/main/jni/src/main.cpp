#include <pthread.h>
#include <jni.h>
#include "KittyMemory/MemoryPatch.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Includes/obfuscate.h"

#if defined(__aarch64__)
#include <src/And64InlineHook/And64InlineHook.hpp>
#else

#include <src/Substrate/SubstrateHook.h>
#include <src/Substrate/CydiaSubstrate.h>

#endif


struct My_Patches {
    MemoryPatch LessRecoil;
    MemoryPatch LessRecoil1;
    MemoryPatch AimLock;
    MemoryPatch AimLock1;
    MemoryPatch AimLock2;
    MemoryPatch Wide;
    MemoryPatch Bypass;
    MemoryPatch Bypass1;
    MemoryPatch Bypass2;
    MemoryPatch Bypass3;
    MemoryPatch Bypass4;
    MemoryPatch Bypass5;
    MemoryPatch Bypass6;
    MemoryPatch Bypass7;
    MemoryPatch Bypass8;
    MemoryPatch Bypass9;
    MemoryPatch Bypass10;
    MemoryPatch Bypass11;
    MemoryPatch Bypass12;
    MemoryPatch Bypass13;
    MemoryPatch Bypass14;
    MemoryPatch Bypass15;
    MemoryPatch Bypass16;
    MemoryPatch Bypass17;
    MemoryPatch Bypass18;
    MemoryPatch ANTISHKAKE;
    MemoryPatch SMALLCROSS;
    MemoryPatch MAGICBULLET;
    MemoryPatch AUTOHEADSHOT;
    MemoryPatch FOG;
    MemoryPatch REMOVEG;
    MemoryPatch NIGHTMODE;
    MemoryPatch INSTANTHIT;
    MemoryPatch BLACKBODY;
    MemoryPatch BLUEFOG;
    MemoryPatch BLUEFOG1;
    MemoryPatch AIMBOT;
    MemoryPatch AIMBOT1;
    MemoryPatch AIMBOT2;
    MemoryPatch AIMBOT3;
    MemoryPatch AIMBOT4;
    MemoryPatch AIMBOT5;
    MemoryPatch LONGJUMP;
    MemoryPatch SPEEDHACK;
    MemoryPatch FLYCARS;
    MemoryPatch JUMPCARS;
    MemoryPatch JUMPCARS1;
    MemoryPatch ANTENA;
    MemoryPatch WALLSHOOT;
    MemoryPatch SPEEDVEHICLES;
    MemoryPatch HIGHDAMAGE;
    MemoryPatch HIGHDAMAGE1;

} hexPatches;

bool LessRecoil = false;
bool AimLock = false;
bool Bypass = false;
bool ANTISHKAKE = false;
bool MAGICBULLET = false;
bool SMALLCROSS = false;
bool AUTOHEADSHOT = false;
bool FOG = false;
bool REMOVEG = false;
bool NIGHTMODE = false;
bool INSTANTHIT = false;
bool BLACKBODY = false;
bool BLUEFOG = false;
bool AIMBOT = false;
bool LONGJUMP = false;
bool SPEEDHACK = false;
bool FLYCARS = false;
bool JUMPCARS = false;
bool ANTENA = false;
bool SPEEDVEHICLES = false;
bool WALLSHOOT = false;
bool HIGHDAMAGE = false;



#define libName OBFUSCATE("libUE4.so")

extern "C" {

bool isToastCalled = false;
JNIEXPORT void JNICALL
Java_uk_lgl_loadlib_LoadLib_Toast(JNIEnv *env, jobject thiz, jobject obj) {
    MakeToast(env, obj, OBFUSCATE("Lib loaded. Modded by Sami Gaming"), Toast::LENGTH_LONG);
    MakeToast(env, obj, OBFUSCATE("Lib loaded. Modded by Sami Gaming"), Toast::LENGTH_LONG);
    isToastCalled = true;
}

JNIEXPORT void JNICALL
Java_uk_lgl_modmenu_FloatingModMenuService_Changes(JNIEnv *env, jobject obj,
                                                   jint feature, jint value) {

    LOGD(OBFUSCATE("Feature: = %d"), feature);
    LOGD(OBFUSCATE("Value: = %d"), value);

    // You must count your features from 0 (YES, I MEAN ZERO), not 1

    switch (feature) {
        // The category was 0 so "case 0" is not used
        case 0:
            break;
        case 1:
            // INTERNAL BYPASS
            Bypass = !Bypass;
            if (Bypass) {
                hexPatches.Bypass.Modify();
                hexPatches.Bypass1.Modify();
                hexPatches.Bypass2.Modify();
                hexPatches.Bypass3.Modify();
                hexPatches.Bypass4.Modify();
                hexPatches.Bypass5.Modify();
                hexPatches.Bypass6.Modify();
                hexPatches.Bypass7.Modify();
                hexPatches.Bypass8.Modify();
                hexPatches.Bypass9.Modify();
                hexPatches.Bypass10.Modify();
                hexPatches.Bypass11.Modify();
                hexPatches.Bypass12.Modify();
                hexPatches.Bypass13.Modify();
                hexPatches.Bypass14.Modify();
                hexPatches.Bypass15.Modify();
                hexPatches.Bypass16.Modify();
                hexPatches.Bypass17.Modify();
                hexPatches.Bypass18.Modify();
                remove("/data/data/com.tencent.ig/files");
                remove("/data/data/com.pubg.krmobile/files");
                remove("/data/data/com.tencent.ig/app_crashrecord");
                remove("/data/data/com.pubg.krmobile/app_crashrecord");
                remove("src/HOME/java/com/google/errorprone/annotations");
                remove("src/HOME/java/com/google/errorprone/annotations");
                remove("src/HOME/java/com/google/errorprone/annotations/concurrent");
                remove("third_party.java_src.error_prone.project.annotations.Google_internal");
            } else {
                hexPatches.Bypass.Restore();
                hexPatches.Bypass1.Restore();
                hexPatches.Bypass2.Restore();
                hexPatches.Bypass3.Restore();
                hexPatches.Bypass4.Restore();
                hexPatches.Bypass5.Restore();
                hexPatches.Bypass6.Restore();
                hexPatches.Bypass7.Restore();
                hexPatches.Bypass8.Restore();
                hexPatches.Bypass9.Restore();
                hexPatches.Bypass10.Restore();
                hexPatches.Bypass11.Restore();
                hexPatches.Bypass12.Restore();
                hexPatches.Bypass13.Restore();
                hexPatches.Bypass14.Restore();
                hexPatches.Bypass15.Restore();
                hexPatches.Bypass16.Restore();
                hexPatches.Bypass17.Restore();
                hexPatches.Bypass18.Restore();
            }
            break;
        case 2:
            // REMOVE BAN FILES DURING MATCH
            // FOR PUBG KR IF YOU WANT TO USE THIS FOR OTHER VERSION THEN JUST CHANGE THE PACKAGE NAME
            // com.pubg.krmobile TO com.tenecent.ig
            remove("/sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/mnt/shell/0/emulated/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/cache/GCloud.ini");
            remove("/sdcard/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Logs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer-temp");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/1375135419_47_1.1.0.14556_20201210094036_1246353928_cures.ifs.res");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/apollo_reslist.flist");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/filelist.json");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/puffer_res.eifs");
            remove("/storage/emulated/0/Android/data/com.pubg.krmobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Saved/Paks/PufferFileList.json");
            remove("src/main/java/com/google/errorprone/annotations");
            remove("src/main/java/com/google/errorprone/annotations");
            remove("src/main/java/com/google/errorprone/annotations/concurrent");
            remove("third_party.java_src.error_prone.project.annotations.Google_internal");
            break;
        case 3: // Switch
            LessRecoil = !LessRecoil;
            if (LessRecoil) {
                hexPatches.LessRecoil.Modify();
                hexPatches.LessRecoil1.Modify();
            } else {
                hexPatches.LessRecoil.Restore();
                hexPatches.LessRecoil1.Restore();
            }
            break;
        case 4:
            AIMBOT = !AIMBOT;
            if (AIMBOT) {
                hexPatches.AIMBOT.Modify();
                hexPatches.AIMBOT1.Modify();
                hexPatches.AIMBOT2.Modify();
                hexPatches.AIMBOT3.Modify();
                hexPatches.AIMBOT4.Modify();
                hexPatches.AIMBOT5.Modify();
            } else {
                hexPatches.AIMBOT.Restore();
                hexPatches.AIMBOT1.Restore();
                hexPatches.AIMBOT2.Restore();
                hexPatches.AIMBOT3.Restore();
                hexPatches.AIMBOT4.Restore();
                hexPatches.AIMBOT5.Restore();
            }
            break;
        case 5: // Switch
            AimLock = !AimLock;
            if (AimLock) {
                hexPatches.AimLock.Modify();
                hexPatches.AimLock1.Modify();
                hexPatches.AimLock2.Modify();
            } else {
                hexPatches.AimLock.Restore();
                hexPatches.AimLock1.Restore();
                hexPatches.AimLock2.Restore();
            }
            break;
        case 6: // CAMERA VIEW FLOAT VALUES
            if (value == 0) {
                hexPatches.Wide.Restore();
            } else if (value == 1) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                                   "\x00\x00\x90\x43", 4);
                hexPatches.Wide.Modify();
            } else if (value == 2) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                                   "\x00\x00\x70\x43", 4);
                hexPatches.Wide.Modify();
            } else if (value == 3) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x65\x43", 4);
                hexPatches.Wide.Modify();
            }  else if (value == 4) {
                    hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                                  "\x00\x00\x60\x43", 4);
                    hexPatches.Wide.Modify();
            }  else if (value == 5) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x57\x43", 4);
                hexPatches.Wide.Modify();

            }  else if (value == 6) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x55\x43", 4);
                hexPatches.Wide.Modify();
            }  else if (value == 7) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x53\x43", 4);
                hexPatches.Wide.Modify();
            }  else if (value == 8) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x50\x43", 4);
                hexPatches.Wide.Modify();
            }  else if (value == 9) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x48\x43", 4);
                hexPatches.Wide.Modify();
            }  else if (value == 10) {
                hexPatches.Wide = MemoryPatch(libName, 0x3880250,
                                              "\x00\x00\x40\x43", 4);
                hexPatches.Wide.Modify();
            }
            break;
        case 7:
            ANTISHKAKE = !ANTISHKAKE;
            if (ANTISHKAKE) {
                hexPatches.ANTISHKAKE.Modify();
            } else {
                hexPatches.ANTISHKAKE.Restore();
            }
            break;
        case 8:
            SMALLCROSS = !SMALLCROSS;
            if (SMALLCROSS) {
                hexPatches.SMALLCROSS.Modify();
            } else {
                hexPatches.SMALLCROSS.Restore();
            }
            break;
        case 9:
            MAGICBULLET = !MAGICBULLET;
            if (MAGICBULLET) {
                hexPatches.MAGICBULLET.Modify();
            } else {
                hexPatches.MAGICBULLET.Restore();
            }
            break;
        case 10:
            AUTOHEADSHOT = !AUTOHEADSHOT;
            if (AUTOHEADSHOT) {
                hexPatches.AUTOHEADSHOT.Modify();
            } else {
                hexPatches.AUTOHEADSHOT.Restore();
            }
            break;
        case 11:
            REMOVEG = !REMOVEG;
            if (REMOVEG) {
                hexPatches.REMOVEG.Modify();
            } else {
                hexPatches.REMOVEG.Restore();
            }
            break;
        case 12:
            FOG = !FOG;
            if (FOG) {
                hexPatches.FOG.Modify();
            } else {
                hexPatches.FOG.Restore();
            }
            break;
        case 13:
            BLUEFOG = !BLUEFOG;
            if (BLUEFOG) {
                hexPatches.BLUEFOG.Modify();
                hexPatches.BLUEFOG1.Modify();
            } else {
                hexPatches.BLUEFOG.Restore();
                hexPatches.BLUEFOG1.Modify();
            }
            break;
        case 14:
            NIGHTMODE = !NIGHTMODE;
            if (NIGHTMODE) {
                hexPatches.NIGHTMODE.Modify();
            } else {
                hexPatches.NIGHTMODE.Restore();
            }
            break;
        case 15:
            BLACKBODY = !BLACKBODY;
            if (BLACKBODY) {
                hexPatches.BLACKBODY.Modify();
            } else {
                hexPatches.BLACKBODY.Restore();
            }
            break;
        case 16:
            INSTANTHIT = !INSTANTHIT;
            if (INSTANTHIT) {
                hexPatches.INSTANTHIT.Modify();
            } else {
                hexPatches.INSTANTHIT.Restore();
            }
            break;
        case 17:
            SPEEDHACK = !SPEEDHACK;
            if (SPEEDHACK) {
                hexPatches.SPEEDHACK.Modify();
            } else {
                hexPatches.SPEEDHACK.Restore();
            }
            break;
        case 18:
            SPEEDVEHICLES = !SPEEDVEHICLES;
            if (SPEEDVEHICLES) {
                hexPatches.SPEEDVEHICLES.Modify();
            } else {
                hexPatches.SPEEDVEHICLES.Restore();
            }
            break;
        case 19:
            ANTENA = !ANTENA;
            if (ANTENA) {
                hexPatches.ANTENA.Modify();
            } else {
                hexPatches.ANTENA.Restore();
            }
            break;
        case 20:
            WALLSHOOT = !WALLSHOOT;
            if (WALLSHOOT) {
                hexPatches.WALLSHOOT.Modify();
            } else {
                hexPatches.WALLSHOOT.Restore();
            }
            break;
        case 21:
            LONGJUMP = !LONGJUMP;
            if (LONGJUMP) {
                hexPatches.LONGJUMP.Modify();
            } else {
                hexPatches.LONGJUMP.Restore();
            }
            break;
        case 22:
            FLYCARS = !FLYCARS;
            if (FLYCARS) {
                hexPatches.FLYCARS.Modify();
            } else {
                hexPatches.FLYCARS.Restore();
            }
            break;
        case 23:
            JUMPCARS = !JUMPCARS;
            if (JUMPCARS) {
                hexPatches.JUMPCARS.Modify();
                hexPatches.JUMPCARS1.Modify();
            } else {
                hexPatches.JUMPCARS.Restore();
                hexPatches.JUMPCARS1.Modify();
            }
            break;
        case 24:
            HIGHDAMAGE = !HIGHDAMAGE;
            if (HIGHDAMAGE) {
                hexPatches.HIGHDAMAGE.Modify();
                hexPatches.HIGHDAMAGE1.Modify();
            } else {
                hexPatches.HIGHDAMAGE.Restore();
                hexPatches.HIGHDAMAGE1.Modify();
            }
            break;
    }
}
}

// ---------- Hooking ---------- //


void *hack_thread(void *) {
    LOGI(OBFUSCATE("Lib have been loaded"));



#if defined(__aarch64__) //Compile for arm64 lib only

#else


    //RECOIL
    hexPatches.LessRecoil = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0x13C44A0", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.LessRecoil1 = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x13C2D80", '-')),
                                                       OBFUSCATE("00 00 00 00"));

    //AIMLOCK
    hexPatches.AimLock = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x258B74C", '-')),
                                                       OBFUSCATE("00 00 00 00"));
    hexPatches.AimLock1 = MemoryPatch::createWithHex(libName,
                                                        string2Offset(OBFUSCATE_KEY("0x258B880", '-')),
                                                        OBFUSCATE("40 5E 89 4E"));
    hexPatches.AimLock2 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0x263E610", '-')),
                                                    OBFUSCATE("00 C0 F9 44"));

    //AIMBOT
    hexPatches.AIMBOT = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0x258B740", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.AIMBOT1 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0x263E53C", '-')),
                                                     OBFUSCATE("00 00 00 00"));
    hexPatches.AIMBOT2 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0x1036AF8", '-')),
                                                     OBFUSCATE("41 0A 01 EE"));
    hexPatches.AIMBOT3 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0x1038020", '-')),
                                                     OBFUSCATE("41 0A 00 EE"));
    hexPatches.AIMBOT4 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0x1038024", '-')),
                                                     OBFUSCATE("01 00 00 EA"));
    hexPatches.AIMBOT5 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0x1039284", '-')),
                                                     OBFUSCATE("01 00 00 7A"));


    //OTHER
    hexPatches.SMALLCROSS = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x13C4A54", '-')),
                                                   OBFUSCATE("00 00 00 00"));

    hexPatches.WALLSHOOT = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x7159D08", '-')),
                                                       OBFUSCATE("7C E1 FB 5E"));

    hexPatches.SPEEDVEHICLES = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x47D2314", '-')),
                                                       OBFUSCATE("00 00 00 00"));

    hexPatches.AUTOHEADSHOT = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x3CB1598", '-')),
                                                       OBFUSCATE("00 00 00 00"));
    hexPatches.FOG = MemoryPatch::createWithHex(libName,
                                                         string2Offset(OBFUSCATE_KEY("0x2DC0FC8", '-')),
                                                         OBFUSCATE("00 00 00 00"));
    hexPatches.REMOVEG = MemoryPatch::createWithHex(libName,
                                                string2Offset(OBFUSCATE_KEY("0x260CEC8", '-')),
                                                OBFUSCATE("00 00 00 00"));
    hexPatches.INSTANTHIT = MemoryPatch::createWithHex(libName,
                                                         string2Offset(OBFUSCATE_KEY("0x3912DB4", '-')),
                                                         OBFUSCATE("00 00 00 00"));
    hexPatches.NIGHTMODE = MemoryPatch::createWithHex(libName,
                                                string2Offset(OBFUSCATE_KEY("0x2F6858C", '-')),
                                                OBFUSCATE("00 00 00 00"));

    hexPatches.BLACKBODY = MemoryPatch::createWithHex(libName,
                                                      string2Offset(OBFUSCATE_KEY("0x2E4C0A8", '-')),
                                                      OBFUSCATE("00 00 60 41"));


    hexPatches.BLUEFOG = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x2DC0FBC", '-')),
                                                       OBFUSCATE("00 00 00 00"));
    hexPatches.BLUEFOG1 = MemoryPatch::createWithHex(libName,
                                                      string2Offset(OBFUSCATE_KEY("0x2DC0FCC", '-')),
                                                      OBFUSCATE("00 00 00 00"));

    hexPatches.HIGHDAMAGE = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0x14D7980", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.HIGHDAMAGE1 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0x3912DB4", '-')),
                                                     OBFUSCATE("00 00 00 00"));

    hexPatches.SPEEDHACK = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x38DA05C", '-')),
                                                       OBFUSCATE("00 00 00 00"));
    hexPatches.FLYCARS = MemoryPatch::createWithHex(libName,
                                                        string2Offset(OBFUSCATE_KEY("0x47D94A8", '-')),
                                                        OBFUSCATE("00 00 00 00"));

    hexPatches.JUMPCARS = MemoryPatch::createWithHex(libName,
                                                      string2Offset(OBFUSCATE_KEY("0x47D9508", '-')),
                                                      OBFUSCATE("00 00 00 00"));
    hexPatches.JUMPCARS1 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0x47D94A8", '-')),
                                                    OBFUSCATE("00 00 00 00"));


    hexPatches.LONGJUMP = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x11EC358", '-')),
                                                       OBFUSCATE("01 1A B7 EE"));

    hexPatches.ANTISHKAKE = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x1CF9E2C", '-')),
                                                   OBFUSCATE("46 00 00 00"));
    hexPatches.MAGICBULLET = MemoryPatch::createWithHex(libName,
                                                       string2Offset(OBFUSCATE_KEY("0x3CB2478", '-')),
                                                       OBFUSCATE("00 00 48 42"));




    //BYPASS UE4
    hexPatches.Bypass = MemoryPatch::createWithHex(libName,
                                                        string2Offset(OBFUSCATE_KEY("0x2565F264", '-')),
                                                        OBFUSCATE("00 00 7A 43"));
    hexPatches.Bypass1 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x3CB1598", '-')),
                                                   OBFUSCATE("00 00 40 42"));
    hexPatches.Bypass2 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x13C44A0", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass3 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x13C4A54", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass4 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x2DC0FC8", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass5 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x260CEC8", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass6 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0x3CB2478", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    // LOGO BYPASS
    /* hexPatches.Bypass7 = MemoryPatch::createWithHex(libName,
                                                   string2Offset(OBFUSCATE_KEY("0xe20d6b48", '-')),
                                                   OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass8 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0xeb56e830", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass9 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0xeb56e888", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass10 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0xdc5ed210", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass11 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0xcf28b450", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass12 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0xc620ea18", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass13 = MemoryPatch::createWithHex(libName,
                                                    string2Offset(OBFUSCATE_KEY("0xe4d43d18", '-')),
                                                    OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass14 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0xe4d43d18", '-')),
                                                     OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass15 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0xeb50c39c", '-')),
                                                     OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass16 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0xd95c432c", '-')),
                                                     OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass17 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0xd918190c", '-')),
                                                     OBFUSCATE("00 00 00 00"));
    hexPatches.Bypass18 = MemoryPatch::createWithHex(libName,
                                                     string2Offset(OBFUSCATE_KEY("0xdbb2b57c", '-')),
                                                     OBFUSCATE("00 00 00 00")); */


    // LIBTERSAFE
    hexPatches.Bypass8 = MemoryPatch::createWithHex("libtersafe.so", 0x348308,
                                                    "00 00 00 00");
    hexPatches.Bypass9 = MemoryPatch::createWithHex("libtersafe.so", 0x348080,
                                                    "00 00 00 00");
    hexPatches.Bypass10 = MemoryPatch::createWithHex("libtersafe.so", 0x3482a8,
                                                    "00 00 00 00");
    hexPatches.Bypass11 = MemoryPatch::createWithHex("libtersafe.so", 0x34829c,
                                                    "00 00 00 00");
    hexPatches.Bypass12 = MemoryPatch::createWithHex("libtersafe.so", 0x348050,
                                                    "00 00 00 00");
    hexPatches.Bypass13 = MemoryPatch::createWithHex("libtersafe.so", 0x348314,
                                                    "00 00 00 00");
    hexPatches.Bypass14 = MemoryPatch::createWithHex("libtersafe.so", 0x348044,
                                                    "00 00 00 00");
    hexPatches.Bypass15 = MemoryPatch::createWithHex("libtersafe.so", 0x348428,
                                                    "00 00 00 00");


    LOGI(OBFUSCATE("Hooked"));
#endif

    //Call bad function if isToastCalled is false. Only use with LoadLibWithoutMenu
    /*
    sleep(3);
    if (!isToastCalled){
        int *p = 0;
        *p = 0;
    }*/

    return NULL;
}

JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *globalEnv;
    vm->GetEnv((void **) &globalEnv, JNI_VERSION_1_6);

    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);

    return JNI_VERSION_1_6;
}