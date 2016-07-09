/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void cdma_properties(char const default_network[])
{
    property_set("ro.telephony.default_network", default_network);
    property_set("ro.ril.hsxpa", "4");
    property_set("ro.ril.enable.a53", "1");
    property_set("ro.ril.enable.gea3", "1");
    property_set("ro.ril.enable.r8fd", "1");
    property_set("ro.telephony.ipv6_capability", "1");
}

void gsm_properties(char const default_network[])
{
    property_set("ro.telephony.default_network", default_network);
    property_set("ro.ril.hsdpa.category", "24");
    property_set("ro.ril.hsupa.category", "6");
    property_set("ro.ril.hsxpa", "5");
    property_set("ro.ril.air.enabled", "1");
    property_set("ro.ril.enable.a52", "0");
    property_set("ro.ril.enable.gea3", "1");
    property_set("ro.telephony.ipv6_capability", "1");
}

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootmid[PROP_VALUE_MAX];
    char bootcid[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char carrier[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.boot.mid", bootmid);
    property_get("ro.boot.cid", bootcid);

            gsm_properties("9");
            property_set("ro.build.fingerprint", "htc/pmewl_00531/htc_pmewl:6.0.1/MMB29M/737608.1:user/release-keys");
            property_set("ro.build.description", "1.21.531.1 8.0_g CL737608 release-keys");
            property_set("ro.product.device", "htc_pmewl");
            property_set("ro.build.product", "htc_pmewl");
            property_set("ro.product.model", "HTC 10");
            property_set("ro.phone.min_match", "10");
            property_set("ro.ril.enable.dtm", "0");
            property_set("ro.ril.air.enabled", "1");
            property_set("ro.ril.oem.ecclist", "911");
            property_set("ro.ril.enable.amr.wideband", "1");
            property_set("ro.ril.enable.sdr", "0");
            property_set("ro.ril.disable.cpc", "1");
            property_set("ro.ril.enable.isr", "1");
            property_set("ro.ril.radio.svn", "1");
            property_set("ro.ril.def.agps.feature", "1");
            property_set("ro.ril.def.agps.mode", "1");
            property_set("ro.ril.ps_handover", "1");
            property_set("ro.ril.lte3gpp", "130");
            property_set("ro.ril.ltefgi.rel9", "3221225472");
            property_set("ro.ril.enable.ganlite", "0");
            property_set("ro.ril.set.mtusize", "1440");
            property_set("ro.ril.fd.pre_r8_tout.scr_off", "17000");
            property_set("ro.ril.fd.pre_r8_tout.scr_on", "0");
            property_set("ro.ril.fd.r8_tout.scr_off", "2500");
            property_set("ro.ril.fd.r8_tout.scr_on", "0");
            property_set("ro.ril.enable.r8fd", "1");
            property_set("ro.ril.enable.pre_r8fd", "1");
            property_set("wifi.hs20.support", "true");

    property_get("ro.product.device", device);
    INFO("Found bootcid %s, bootmid %s setting build properties for %s device\n", bootcid, bootmid, device);
}
