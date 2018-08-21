#include <uberspark.h>
#include <xmhf-hwm.h>

#include <xmhf.h>
#include <xmhfgeec.h>
#include <xg_richguest.h>


{
	"uobj-name": "xg_richguest",
	"uobj-type": "uVU_SLAB",
	"uobj-subtype": "XRICHGUEST",

	"uobj-uapifunctions":[],

	"uobj-callees": "",

	"uobj-uapicallees":[],

	"uobj-resource-devices":[
		{ 
			"type": "include",
			"opt1" : USMF_STR(0xffff),
			"opt2" : USMF_STR(0xffff) 
		},
		{ 
			"type": "exclude",
			"opt1" : USMF_STR(PCI_VENDOR_ID_LOGNIC),
			"opt2" : USMF_STR(PCI_DEVICE_ID_LOGNIC) 
		}

	],	

	"uobj-resource-memory":[
		{
			"access-type" : "read",
			"uobj-name" : "xc_init"
		},
		{
			"access-type" : "read",
			"uobj-name" : "xc_ihub"
		},
		{
			"access-type" : "write",
			"uobj-name" : "xc_init"
		},
		{
			"access-type" : "write",
			"uobj-name" : "xc_ihub"
		},
		{
			"access-type" : "read",
			"uobj-name" : "xh_syscalllog"
		},
		{
			"access-type" : "read",
			"uobj-name" : "xh_ssteptrace"
		}
	
	],	

	"uobj-exportfunctions": "",


	"uobj-binary-sections":[
		{ 
			"section-name": "code",
			"section-size": "0x0"
		},
		{ 
			"section-name": "data",
			"section-size": USMF_STR(__TARGET_BASE_XMHF)
		},
		{ 
			"section-name": "stack",
			"section-size": USMF_STR(__TARGET_MAX_XMHF)
		},
		{ 
			"section-name": "dmadata",
			"section-size": USMF_STR(__TARGET_MAX_SYS)
		}
	],	

	
	"c-files":	"",
		
	"v-harness": []
		
	
}










