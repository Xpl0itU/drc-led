#include <wups.h>
#include <malloc.h>
#include <string.h>
#include <coreinit/filesystem.h>
#include <nn/acp/drcled_c.h>
#include <nn/act/client_cpp.h>

WUPS_PLUGIN_NAME("drc-led");
WUPS_PLUGIN_DESCRIPTION("Turns on LED on the GamePad");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("DaThinkingChair");
WUPS_PLUGIN_LICENSE("GPLv3");

static uint32_t pId;

INITIALIZE_PLUGIN() {
    pId = nn::act::GetPersistentId();
    ACPTurnOnDrcLed(pId, 1);
}