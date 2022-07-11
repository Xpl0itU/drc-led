#include <wups.h>
#include <malloc.h>
#include <string.h>
#include <coreinit/filesystem.h>
#include <nn/acp/drcled_c.h>
#include <nn/act/client_cpp.h>

static uint32_t pId;

/**
    Mandatory plugin information.
    If not set correctly, the loader will refuse to use the plugin.
**/
WUPS_PLUGIN_NAME("DRC LED");
WUPS_PLUGIN_DESCRIPTION("This plugin turns on the GamePad LED.");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("DaThinkingChair");
WUPS_PLUGIN_LICENSE("GPLv3");

WUPS_FS_ACCESS()

WUPS_ALLOW_OVERLAY()

INITIALIZE_PLUGIN(){
    pId = nn::act::GetPersistentId();
    ACPTurnOnDrcLed(pId, 1);
}