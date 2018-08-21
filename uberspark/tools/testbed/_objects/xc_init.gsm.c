#include <uberspark.h>
#include <xmhf-hwm.h>

#include <geec_sentinel.h>
#include <uapi_gcpustate.h>
#include <xh_hyperdep.h>
#include <xh_syscalllog.h>
#include <xh_ssteptrace.h>
#include <xh_aprvexec.h>

{
	"uobj-name": "xc_init",
	"uobj-type": "VfT_SLAB",
	"uobj-subtype": "INIT",

	"uobj-uapifunctions":[],

	"uobj-callees": "	geec_sentinel
						uapi_gcpustate
						xg_richguest
						xh_hyperdep
						xh_syscalllog
						xh_ssteptrace
					",


	"uobj-uapicallees":[
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_VMREAD), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_VMWRITE), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		},
		{ 
			"uobj-name": "uapi_gcpustate",
			"uobj-uapifunctionid": USMF_STR(XMHF_HIC_UAPI_CPUSTATE_GUESTGPRSWRITE), 
			"opt1" : "(void)0;",
			"opt2" : "(1)" 
		}	
	],	


	"uobj-resource-devices":[],

	"uobj-resource-memory":[],	

	"uobj-exportfunctions": "",


	"uobj-binary-sections":[
		{ 
			"section-name": "code",
			"section-size": "0x200000"
		},
		{ 
			"section-name": "data",
			"section-size": "0x200000"
		},
		{ 
			"section-name": "stack",
			"section-size": "0x600000"
		},
		{ 
			"section-name": "dmadata",
			"section-size": "0x200000"
		}
	],	

	
	"c-files":	"",
		
	"v-harness": []
		
	
}








